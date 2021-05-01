#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLWidget::initializeGL() {
}

void GLWidget::resizeGL(int width, int height) {
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void GLWidget::toggleBackgroundColor(bool toBlack) {
    if (toBlack){
        glClearColor(0, 0, 0, 1);
    } else {
        glClearColor(1, 1, 1, 1);
    }
    updateGL();
}

void GLWidget::showFileOpenDialog() {
    QByteArray fileFormat = "off";
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath(),
                                            QString("%1 Files (*.%2)").arg(QString(fileFormat.toUpper())).arg(QString(fileFormat)));
    if (!fileName.isEmpty()) {
        readOFFFile(fileName);

        genNormals();
        genTexCoordsCylinder();
        genTangents();

        createVBOs();
        createShaders();

        updateGL();
    }
}

void GLWidget::readOFFFile(const QString &fileName) {
    std::ifstream stream;
    stream.open(fileName.toAscii(), std::ifstream::in);

    if (!stream.is_open()) {
        qWarning("Cannot open file.");
        return;
    }

    std::string line;

    stream >> line;
    stream >> numVertices >> numFaces >> line;

    delete[] vertices;
    vertices = new QVector4D[numVertices];

    delete[] vertices;
    vertices = new QVector4D[numVertices];

    delete[] indices;
    indices = new unsigned int[numFaces * 3];

    if (numVertices > 0) {
        double minLim = std::numeric_limits<double>::min();
        double maxLim = std::numeric_limits<double>::max();
        QVector4D max(minLim, minLim, minLim, 1.0);
        QVector4D min(maxLim, maxLim, maxLim, 1.0);

        for (unsigned int i = 0; i < numVertices; i++) {
            double x, y, z;
            stream >> x >> y >> z;
            max.setX(qMax(max.x(), x));
            max.setY(qMax(max.y(), y));
            max.setZ(qMax(max.z(), z));
            min.setX(qMax(min.x(), x));
            min.setY(qMax(min.y(), y));
            min.setZ(qMax(min.z(), z));

            vertices[i] = QVector4D(x, y, z, 1.0);
        }

        QVector4D midpoint = (min + max) * 0.5;
        double invdiag = 1 / (max - min).length();

        for (unsigned int i = 0; i < numVertices; i++) {
            vertices[i] = (vertices[i] - midpoint)*invdiag;
            vertices[i].setW(1);
        }
    }

    for (unsigned int i = 0; i < numFaces; i++) {
        unsigned int a, b, c;
        stream >> line >> a >> b >> c;
        indices[i * 3    ] = a;
        indices[i * 3 + 1] = b;
        indices[i * 3 + 2] = c;
    }

    stream.close();
}

void GLWidget::genNormals() {
    delete[] normals;
    normals = new QVector3D[numVertices];

    for (unsigned int i = 0; i < numFaces; i++) {
        unsigned int i1 = indices[i * 3    ];
        unsigned int i2 = indices[i * 3 + 1];
        unsigned int i3 = indices[i * 3 + 2];

        QVector3D v1 = vertices[i1].toVector3D();
        QVector3D v2 = vertices[i2].toVector3D();
        QVector3D v3 = vertices[i3].toVector3D();

        QVector3D faceNormal = QVector3D::crossProduct(v2 - v1, v3 - v1);
        normals[i1] += faceNormal;
        normals[i2] += faceNormal;
        normals[i3] += faceNormal;
    }

    for (unsigned int i = 0; i < numVertices; i++) {
        normals[i].normalize();
    }
}

void GLWidget::genTexCoordsCylinder() {
    delete[] texCoords;
    texCoords = new QVector2D[numVertices];

    double minLim = std::numeric_limits<double>::min();
    double maxLim = std::numeric_limits<double>::max();
    QVector2D max(minLim, minLim);
    QVector2D min(maxLim, maxLim);

    for (unsigned int i = 0; i < numVertices; i++) {
        QVector2D pos = vertices[i].toVector2D();
        max.setX(qMax(max.x(), pos.x()));
        max.setY(qMax(max.y(), pos.y()));
        min.setX(qMin(min.x(), pos.x()));
        min.setY(qMin(min.y(), pos.y()));
    }

    QVector2D size = max - min;
    for (unsigned int i = 0; i < numVertices; i++) {
        double x = 2.0 * (vertices[i].x() - min.x()) / size.x() - 1.0;
        texCoords[i] = QVector2D(acos(x) / M_PI, (vertices[i].y() - min.y()) / size.y());
    }
}

void GLWidget::genTangents() {
    delete[] tangents;

    tangents = new QVector4D[numVertices];
    QVector3D *bitangents = new QVector3D[numVertices];

    for (unsigned int i = 0; i < numFaces; i++) {
        unsigned int i1 = indices[i * 3    ];
        unsigned int i2 = indices[i * 3 + 1];
        unsigned int i3 = indices[i * 3 + 2];

        QVector3D E = vertices[i1].toVector3D();
        QVector3D F = vertices[i2].toVector3D();
        QVector3D G = vertices[i3].toVector3D();

        QVector2D stE = texCoords[i1];
        QVector2D stF = texCoords[i2];
        QVector2D stG = texCoords[i3];

        QVector3D P = F - E;
        QVector3D Q = G - E;

        QVector2D st1 = stF - stE;
        QVector2D st2 = stG - stE;

        QMatrix2x2 M;
        M(0, 0) = st2.y(); M(0, 1) = -st1.y();
        M(1, 0) = -st2.x(); M(1, 1) = st1.x();
        M *= (1.0 / (st1.x()*st2.y() - st2.x()*st1.y()));

        QVector4D T = QVector4D(M(0, 0)*P.x()+M(0, 1)*Q.x(),
                                M(0, 0)*P.y()+M(0, 1)*Q.y(),
                                M(0, 0)*P.z()+M(0, 1)*Q.z(),
                                0.0);
        QVector3D B = QVector3D(M(1, 0)*P.x()+M(1, 1)*Q.x(),
                                M(1, 0)*P.y()+M(1, 1)*Q.y(),
                                M(1, 0)*P.z()+M(1, 1)*Q.z());

        tangents[i1] += T;
        tangents[i2] += T;
        tangents[i3] += T;

        bitangents[i1] += B;
        bitangents[i2] += B;
        bitangents[i3] += B;
    }

    for (unsigned int i = 0; i < numVertices; i++) {
        const QVector3D& n = normals[i];
        const QVector4D& t = tangents[i];

        tangents[i] = (t - n * QVector3D::dotProduct(n, t.toVector3D())).normalized();

        QVector3D b = QVector3D::crossProduct(n, t.toVector3D());
        double hand = QVector3D::dotProduct(b, bitangents[i]);
        tangents[i].setW((hand < 0.0) ? -1.0 : 1.0);
    }

    delete[] bitangents;
}
