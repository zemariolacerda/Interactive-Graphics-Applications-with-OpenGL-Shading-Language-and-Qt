# Interactive-Graphics-Applications-with-OpenGL-Shading-Language-and-Qt
### Qt SDK 1.2.1 (Qt Creator IDE 2.4.1 + Qt Framework 4.8.1):
[Download](https://drive.google.com/file/d/1FUsWaRXAQ5Wg0AHjIMmGzsssDZ-4O3Nv/view?usp=sharing) Qt SDK 1.2.1 Linux:

1. Executando pela interface gráfica:
   1. Faça o download do arquivo .run;
   2. Clique com o botão direito, *Propriedades* -> *Permissões* -> Marque a opção que permite executar o arquivo como programa -> *Fechar*;
   3. Clique 2x para executar o arquivo;
2. Pelo terminal:
```
$ cd /local/do/arquivo/chmod +x qt-creator-opensource-linux-x86_64-4.8.0.run 
```
```
$ ./qt-creator-opensource-linux-x86_64-4.8.0.run
```
[Download](https://drive.google.com/file/d/1uAPWVDFjSLSmYABIIqvSzXsdgpdeSZPl/view?usp=sharing) Qt SDK 1.2.1 Windows:
1. Instalação padrão do windows.
### Criando um novo projeto:
1. Crie um novo projeto:
    ![alt text](https://i.imgur.com/KUAiNTM.png)
2. Selecione as opções destacadas:
    &nbsp;
    ![alt text](https://i.imgur.com/3bUjjbR.png)
3. Defina o nome do seu projeto e o diretório em que ele será salvo:
    ![alt text](https://i.imgur.com/8QwCiJq.png)
4. Deixe a opção Desktop marcada e avance:
    ![alt text](https://i.imgur.com/TkD0306.png)
5. Deixe com as opcões automáticas e avance:
    ![alt text](https://i.imgur.com/XZ6CcYJ.png)
6. Adicione versionamento ao seu código (opicional) e finalize.
    ![alt text](https://i.imgur.com/KlJONE0.png)
7. Adicione "opengl" no arquivo **`myqtglproject.pro`** que foi gerado:
    ```c++
    #-------------------------------------------------
    #
    # Project created by QtCreator 2021-04-30T12:16:42
    #
    #-------------------------------------------------

    QT       += core gui opengl // <---- adicione!

    TARGET = myqtglproject
    TEMPLATE = app


    SOURCES += main.cpp\
            mainwindow.cpp

    HEADERS  += mainwindow.h

    FORMS    += mainwindow.ui

    ```
### Criando a interface gráfica:
1. Crie a classe **GLWidget**:
    1. *File* -> *New File or Project* e selecione as seguintes opções:
        ![alt text](https://i.imgur.com/KwO3U6i.png)
    2. Preencha os campos da classe e avance:
        ![alt text](https://i.imgur.com/fkGFYJZ.png)
    3. Finalize:                                          
        ![alt text](https://i.imgur.com/ypiFjqL.png)
2. Dê include em **`<QtOpenGL>`** e declare os métodos **initializeGL()**, **resizeGL()** e **paintGL()** no arquivo **`glwidget.h`**:
    ```c++
    #ifndef GLWIDGET_H
    #define GLWIDGET_H

    #include <QGLWidget>
    #include <QtOpenGL>

    class GLWidget : public QGLWidget
    {
        Q_OBJECT
    public:
        explicit GLWidget(QWidget *parent = 0);
        
    signals:
        
    public slots:
    
    protected:
        void initializeGL();
        void resizeGL(int width, int height);
        void paintGL();
    };

    #endif // GLWIDGET_H
    ```
3. Implemente-os no arquivo **`glwidget.cpp`**:
    ```c++
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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    ```
4. Clique 2x no arquivo **`mainwindow.ui`** para entrar na aba *Design* e arraste um *widget* para o objeto **centralWidget**:
    ![alt text](https://i.imgur.com/SzKKmbD.png)
5. Promova o *widget* para **GLWidget**:
    1. Clique com o botão direito no widget e selecione *Promote to ...*
        ![alt text](https://i.imgur.com/TXriXOz.png)
    2. Em *Promoted class name* coloque *GLWidget*, clique em *Add* e *Promote*:
        ![alt text](https://i.imgur.com/oj1n8HG.png)
6. Altere o atributo  *focusPolicy* do *widget* para *StrongFocus*:                                                     
    ![alt text](https://i.imgur.com/BehT2ZA.png)
7. Para rodar o programa, use o atalho '*ctrl + R* ' ou clique no ícone *Run*:
    ![alt text](https://i.imgur.com/svI7nqT.png)
8. Caso tudo ocorra bem, uma janela será criada na sua tela. Caso encontre problemas, veja se existe alguma solução na parte de problemas encontrados.
    ![alt text](https://i.imgur.com/6pIcMDp.png)
9. Criando um botão de sair:
    1. Arraste um *Push Button* para o objeto **centralWidget** e renomeie para *Exit* (clique 2x no botão):
        ![alt text](https://i.imgur.com/iwzuGHP.png)
    2. Selecione o *Signals & Slots Editor*:
        ![alt text](https://i.imgur.com/k2Epv4Z.png)
    3. Adicione um novo *signal/slot*:
        ![alt text](https://i.imgur.com/MJ6Zgn5.png)
    4. Configure da seguinte maneira:
        ![alt text](https://i.imgur.com/ajN8vII.png)
10. Criando um *checkbox* para alternar a cor do fundo do widget de preto para branco:
    1. Arraste um *Check Box* para **centralWidget** e o renomeie para "Toggle background color".
        ![alt text](https://i.imgur.com/ZSIUzkC.png)
    2. Altere seu estado para *checked*:                                                                       
        ![alt text](https://i.imgur.com/2tvGfMW.png)
    3. Declarando um *slot* customizado para nosso checkbox no arquivo  **`glwidget.h`**:
        ```c++
        ...
        class GLWidget : public QGLWidget
        {
        ...
        public slots:
            void toggleBackgroundColor(bool toBlack);
        ...
        };

        #endif // GLWIDGET_H
        ```
    4. Implementando um *slot* customizado para nosso checkbox no arquivo  **`glwidget.cpp`**:
        ```c++
        void GLWidget::toggleBackgroundColor(bool toBlack) {
            if (toBlack){
                glClearColor(0, 0, 0, 1);
            } else {
                glClearColor(1, 1, 1, 1);
            }
            updateGL();
        }
        ```
    5. Inserindo a assinatura do *slot* customizado **toggleBackgroundColor(bool)** na lista de *Signals/Slots*:
        1. Clique com o botão direito em *widgets* na aba *Design* e selecione *Change signals/slots...*:
            ![alt text](https://i.imgur.com/fsWNhga.png)
        2. Adicione o *slot* customizado:
            ![alt text](https://i.imgur.com/YODvnna.png)
    6. Uma nova conexão *Signal/Slot* com a seguinte configuração deve ser criada:
        ![alt text](https://i.imgur.com/jp2KrFA.png)
    7. Teste sua janela!                                                                     
        ![alt text](https://i.imgur.com/scHr1JY.png)
        ![alt text](https://i.imgur.com/waIfljq.png)

### Carregando um modelo geométrico:
1. Clique 2x em **Type Here** e altere para **File** para criar uma opção de menu e aperte Enter. Logo depois, crie uma opção de submenu com o nome **Open**:
    ![alt text](https://i.imgur.com/opFT3yJ.png)
2. Declare o *slot* **showFileOpenDialog()** e os métodos **readOFFFile()**, **genNormals()**, **genTexCoordsCylinder()** e **genTangents()** no arquivo **`glwidget.h`** e dê include em alguns arquivos:
    ```c++
    ...
    #include <iostream>
    #include <fstream>
    #include <limits>
    ...
    class GLWidget : public QGLWidget
    {
    ...
    public slots:
        ...
        void showFileOpenDialog();
    ...

    private:
        void readOFFFile(const QString &fileName);
        void genNormals();
        void genTexCoordsCylinder();
        void genTangents();
        
        unsigned int numVertices;
        unsigned int numFaces;
        QVector4D *vertices;
        QVector3D *normals;
        QVector2D *texCoords;
        QVector4D *tangents;
        unsigned int *indices;
    ...
    };

    #endif // GLWIDGET_H
    ```
3. Implemente o *slot* **showFileOpenDialog()** e os métodos **readOFFFile()**, **genNormals()**, **genTexCoordsCylinder()** e **genTangents()** no arquivo **`glwidget.cpp`**:
    ```c++
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
                min.setX(qMin(min.x(), x));
                min.setY(qMin(min.y(), y));
                min.setZ(qMin(min.z(), z));

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
    ```
4. Insira a assinatura do *slot* customizado **showFileOpenDialog()** na lista de Signals/Slots (**Criando a interface gráfica** - passo 10.v).
5. Uma nova conexão *Signal/Slot* com a seguinte configuração deve ser criada:
    ![alt text](https://i.imgur.com/iSPzZw8.png)

### Encapsulando recursos:
1. Vá em *File* -> *New File or Project* e selecione as seguintes opções:
    ![alt text](https://i.imgur.com/xHycfDz.png)
2. Nomeie como **resources.qrc**:                                                                
    ![alt text](https://i.imgur.com/WbroGts.png)
3. Crie um prefixo para listar shaders e texturas no arquivo **`resources.qrc`**:
    ![alt text](https://i.imgur.com/xLv9ash.png)
4. 
    1. Faça o download dos [shaders](https://drive.google.com/drive/folders/1FZtlo_l-5p9dA7pOUrtqRoSRNyaWGSmE?usp=sharing) e [texturas](https://drive.google.com/drive/folders/1bwNAa2ZpigvoxJhDM8Qawr8_BPsX3UzD?usp=sharing) e coloque os arquivos no diretório do projeto. 
    2. Adicione-os ao projeto pelo Qt (clique com o botão direito no diretório raiz do projeto). 
    3. Clique em *Add* -> *Add Files* e selecione os arquivos (arquivos de textura terminam com .png e os arquivos de *shader* terminam com .glsl):
        ![alt text](https://i.imgur.com/1mX36Em.png)
5. Declaramos algumas variáveis e os métodos **createShaders()** e **destroyShaders()** no arquivo **`glwidget.h`**:
    ```c++
    class GLWidget : public QGLWidget
    {
    ...
    private:
        ...
        void createShaders();
        void destroyShaders();

        QGLShader *vertexShader;
        QGLShader *fragmentShader;
        QGLShaderProgram *shaderProgram;
        unsigned int currentShader;
    ...
    };

    #endif // GLWIDGET_H
    ```
7. Implementamos estes métodos no arquivo **`glwidget.cpp`**:
    ```c++
    void GLWidget::createShaders() {
        destroyShaders();

        QString vertexShaderFile[] = {
            ":/shaders/vgouraud.glsl",
            ":/shaders/vphong.glsl",
            ":/shaders/vtexture.glsl",
            ":/shaders/vnormal.glsl"
        };
        QString fragmentShaderFile[] = {
            ":/shaders/fgouraud.glsl",
            ":/shaders/fphong.glsl",
            ":/shaders/ftexture.glsl",
            ":/shaders/fnormal.glsl"
        };

        vertexShader = new QGLShader(QGLShader::Vertex);
        if (!vertexShader->compileSourceFile(vertexShaderFile[currentShader])) {
            qWarning() << vertexShader->log();
        }

        fragmentShader = new QGLShader(QGLShader::Fragment);
        if (!fragmentShader->compileSourceFile(fragmentShaderFile[currentShader])) {
            qWarning() << fragmentShader->log();
        }

        shaderProgram = new QGLShaderProgram;
        shaderProgram->addShader(vertexShader);
        shaderProgram->addShader(fragmentShader);

        if (!shaderProgram->link()) {
            qWarning() << shaderProgram->log() << endl;
        }
    }

    void GLWidget::destroyShaders() {
        delete vertexShader;
        vertexShader = NULL;

        delete fragmentShader;
        fragmentShader = NULL;

        if (shaderProgram) {
            shaderProgram -> release();
            delete shaderProgram;
            shaderProgram = NULL;
        }
    }
    ```
### Carregando objetos
1. Declaramos os métodos **createVBOs()**, **destroyVBOs()** e algumas variáveis no arquivo **`glwidget.h`**:
    ```c++
    class GLWidget : public QGLWidget
    {
    ...
    private:
        ...
        void createVBOs();
        void destroyVBOs();

        QGLBuffer *vboVertices;
        QGLBuffer *vboNormals;
        QGLBuffer *vboTexCoords;
        QGLBuffer *vboTangents;
        QGLBuffer *vboIndices;
    ...
    };

    #endif // GLWIDGET_H
    ```
2. Implementamos os métodos **createVBOs()** e **destroyVBOs()** no arquivo **`glwidget.cpp`**:
    ```c++
    void GLWidget::createVBOs() {
        destroyVBOs();

        vboVertices = new QGLBuffer(QGLBuffer::VertexBuffer);
        vboVertices->create();
        vboVertices->bind();
        vboVertices->setUsagePattern(QGLBuffer::StaticDraw);
        vboVertices->allocate(vertices, numVertices * sizeof(QVector4D));
        delete[] vertices;
        vertices = NULL;

        vboNormals = new QGLBuffer(QGLBuffer::VertexBuffer);
        vboNormals->create();
        vboNormals->bind();
        vboNormals->setUsagePattern(QGLBuffer::StaticDraw);
        vboNormals->allocate(normals, numVertices * sizeof(QVector3D));

        delete[] normals;
        normals = NULL;

        vboTexCoords = new QGLBuffer(QGLBuffer::VertexBuffer);
        vboTexCoords->create();
        vboTexCoords->bind();
        vboTexCoords->setUsagePattern(QGLBuffer::StaticDraw);
        vboTexCoords->allocate(texCoords, numVertices * sizeof(QVector2D));

        delete[] texCoords;
        texCoords = NULL;

        vboTangents = new QGLBuffer(QGLBuffer::VertexBuffer);
        vboTangents->create();
        vboTangents->bind();
        vboTangents->setUsagePattern(QGLBuffer::StaticDraw);
        vboTangents->allocate(tangents, numVertices * sizeof(QVector4D));

        delete[] tangents;
        tangents = NULL;

        vboIndices = new QGLBuffer(QGLBuffer::IndexBuffer);
        vboIndices->create();
        vboIndices->bind();
        vboIndices->setUsagePattern(QGLBuffer::StaticDraw);
        vboIndices->allocate(indices, numFaces * 3 * sizeof(unsigned int));

        delete[] indices;
        indices = NULL;
    }

    void GLWidget::destroyVBOs() {
        if (vboVertices) {
            vboVertices->release();
            delete vboVertices;
            vboVertices = NULL;
        }

        if (vboNormals) {
            vboNormals->release();
            delete vboNormals;
            vboNormals = NULL;
        }

        if (vboTexCoords) {
            vboTexCoords->release();
            delete vboTexCoords;
            vboTexCoords = NULL;
        }

        if (vboTangents) {
            vboTangents->release();
            delete vboTangents;
            vboTangents = NULL;
        }

        if (vboIndices) {
            vboIndices->release();
            delete vboIndices;
            vboIndices = NULL;
        }
    }
    ```
### Eventos do mouse e teclado
1. Declaramos algumas variáveis e os seguintes métodos no arquivo **`glwidget.h`**:
    -  **keyPressEvent()**: responsável pela por alternar entre os efeitos do *shader* com as teclas 0 (Gourad shading), 1 (Phong shading), 2 (Phong + textura), 3 (mapeamento normal), esc (sair da aplicação).
    - **mouseMoveEvent()**, **mousePressEvent()**, **mouseReleaseEvent()**: métodos que manipulam os eventos do mouse para a classe *TrackBall* que iremos criar em seguida.
    - **wheelEvent()**: implementaremos uma operação de zoom com a manipulação do *scroll* do mouse.
        ```c++
        ...
        #include "trackball.h";
        ...
        class GLWidget : public QGLWidget
        {
        ...
        protected:
            ...
            void mouseMoveEvent(QMouseEvent * event);
            void mousePressEvent(QMouseEvent * event);
            void mouseReleaseEvent(QMouseEvent * event);
            void wheelEvent(QWheelEvent * event);
            void keyPressEvent(QKeyEvent * event);
        ...
        private:
            ...
            TrackBall trackBall;

            double zoom;
        };

        #endif // GLWIDGET_H
        ```
2. Em seguida, implementamos estes métodos no arquivo **`glwidget.cpp`**:
    ```c++
    void GLWidget::keyPressEvent(QKeyEvent * event) {
        switch (event->key()) {
        case Qt::Key_0:
            currentShader = 0;
            createShaders();
            updateGL();
            break;
        case Qt::Key_1:
            currentShader = 1;
            createShaders();
            updateGL();
            break;
        case Qt::Key_2:
            currentShader = 2;
            createShaders();
            updateGL();
            break;
        case Qt::Key_3:
            currentShader = 3;
            createShaders();
            updateGL();
            break;
        case Qt::Key_Escape:
            qApp->quit();
        }
    }

    void GLWidget::mouseMoveEvent(QMouseEvent * event) {
        trackBall.mouseMove(event->posF());
    }

    void GLWidget::mousePressEvent(QMouseEvent * event) {
        if (event->button() & Qt::LeftButton)
            trackBall.mousePress(event->posF());
    }

    void GLWidget::mouseReleaseEvent(QMouseEvent * event) {
        if (event->button() == Qt::LeftButton)
            trackBall.mouseRelease(event->posF());
    }

    void GLWidget::wheelEvent(QWheelEvent * event) {
        zoom += 0.001 * event->delta();
    }
    ```
### Classe TrackBall
1. Criaremos a classe TrackBall conforme o item 1 da seção **Criando a interface gráfica**:
    ![alt text](https://i.imgur.com/55BZVy1.png)
2. Arquivo **`trackball.h`**:
    ```c++
    #ifndef TRACKBALL_H
    #define TRACKBALL_H

    #include <QVector3D>
    #include <QQuaternion>
    #include <QTime>

    #include <cmath>

    class TrackBall {
    public:
        TrackBall();
        void mouseMove(const QPointF & p);
        void mousePress(const QPointF & p);
        void mouseRelease(const QPointF & p);
        void resizeViewport(int width, int height);
        QQuaternion getRotation();

    private:
        QQuaternion rotation;
        QVector3D axis;
        double velocity;

        QVector3D lastPos3D;
        QTime lastTime;
        bool trackingMouse;

        double viewportWidth;
        double viewportHeight;

        const double rad2deg;

        QVector3D mousePosTo3D(const QPointF & p);
    };

    #endif
    ```
3. **`trackball.cpp`**:
    ```c++
    #include "trackball.h"

    TrackBall::TrackBall(): rad2deg(180.0 / M_PI) {
        velocity = 0.0;
        trackingMouse = false;
        lastTime = QTime::currentTime();
    }

    void TrackBall::mouseMove(const QPointF &p) {
        if (!trackingMouse) {
            return;
        }

        QTime currentTime = QTime::currentTime();
        int msecs = lastTime.msecsTo(currentTime);
        if (msecs) {
            QVector3D vp = mousePosTo3D(p);
            QVector3D currentPos3D = QVector3D(vp.x(), vp.y(), 0.0);
            double lenSqr = currentPos3D.lengthSquared();
            (lenSqr >= 1.0) ? currentPos3D.normalize():currentPos3D.setZ(sqrt(1.0 - lenSqr));

            axis = QVector3D::crossProduct(lastPos3D, currentPos3D);
            double angle = rad2deg * axis.length();
            velocity = angle / msecs;
            axis.normalize();
            rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;

            lastPos3D = currentPos3D;
            lastTime = currentTime;
        }
    }

    void TrackBall::mousePress(const QPointF & p) {
        rotation = getRotation();
        trackingMouse = true;
        lastTime = QTime::currentTime();

        lastPos3D = mousePosTo3D(p);
        double lenSqr = lastPos3D.lengthSquared();
        (lenSqr >= 1.0) ? lastPos3D.normalize():lastPos3D.setZ(sqrt(1.0 - lenSqr));

        velocity = 0.0;
    }

    void TrackBall::mouseRelease(const QPointF & p) {
        mouseMove(p);
        trackingMouse = false;
    }

    void TrackBall::resizeViewport(int width, int height) {
        viewportWidth = static_cast < double > (width);
        viewportHeight = static_cast < double > (height);
    }

    QQuaternion TrackBall::getRotation() {
        if (trackingMouse) {
            return rotation;
        }

        QTime currentTime = QTime::currentTime();
        double angle = velocity * lastTime.msecsTo(currentTime);
        return QQuaternion::fromAxisAndAngle(axis, angle) * rotation;
    }

    QVector3D TrackBall::mousePosTo3D(const QPointF & p) {
        return QVector3D(2.0 * p.x() / viewportWidth - 1.0, 1.0 - 2.0 * p.y() / viewportHeight, 0.0);
    }
    ```
### Classes vetor e matriz:
1. No método **resizeGL()** que haviamos criado anteriormente, iremos configurar a *projectionMatrix* da seguinte forma:
    ```c++
    void GLWidget::resizeGL(int width, int height) {
        glViewport(0, 0, width, height);
        
        projectionMatrix.setToIdentity();
        projectionMatrix.perspective(60.0, static_cast <qreal> (width) / static_cast <qreal> (height), 0.1, 20.0);
        
        trackBall.resizeViewport(width, height);
        
        updateGL();
    }
    ```
2. Também precisamos declarar a variável projectionMatrix no arquivo **`glwidget.h`**:
    ```c++
    class GLWidget : public QGLWidget
    {
    ...
    private:
        ...
        QMatrix4x4 projectionMatrix;
    ...
    };

    #endif // GLWIDGET_H
    ```
### *Signals/Slots* - parte 2
Iremos emitir um sinal para o widget mudar de cor para recolorirmos a janela. Ao invés de definirmos um *signal/slot* no modo *Design*, faremos agora direto no código. Criaremos o método **animate()** e adicionaremos algumas linhas de código no método **readOFFFile()**
1. Declarando **animate()** e algumas variáveis no arquivo **`glwidget.h`**:
    ```c++
    class GLWidget : public QGLWidget
    {
    ...
    signals:
        void statusBarMessage(QString ns);
    ...
    public slots:
        ...
        void animate();
    ...
    private:
        int texID[2];
        QTimer timer;
    ...
    };
    ```
2. Criando o método **animate()** e editando o método **readOFFFile()** no arquivo **`glwidget.cpp`**:
    ```c++
    void GLWidget::animate() {
        updateGL();
    }

    void GLWidget::readOFFFile(const QString &fileName) {
        ...
        emit statusBarMessage(QString("Samples %1, Faces %2").arg(numVertices).arg(numFaces));
    }
    ```
### Mapeamento de Textura
1. Alteramos o método **initializeGL()** no arquivo **`glwidget.cpp`** da seguinte forma:
    ```c++
    void GLWidget::initializeGL() {
        glEnable(GL_DEPTH_TEST);
        QImage texColor = QImage(":/textures/bricksDiffuse.png");
        QImage texNormal = QImage(":/textures/bricksNormal.png");
        glActiveTexture(GL_TEXTURE0);
        texID[0] = bindTexture(texColor);
        glActiveTexture(GL_TEXTURE1);
        texID[1] = bindTexture(texNormal);
        connect( & timer, SIGNAL(timeout()), this, SLOT(animate()));
        timer.start(0);
    }
    ```
### O método paintGL()
1. O método será chamado toda vez que a cena OpenlGL precisar ser reexibida. Declaramos no arquivo **`glwidget.h`** alguns componentes que o método irá utilizar: 
    ```c++
    ...
    #include "camera.h"
    #include "light.h"
    #include "material.h"
    ...
    class GLWidget : public QGLWidget
    {
    ...
    private:
        ...
        Camera camera;
        Light light;
        Material material;

        QMatrix4x4 modelViewMatrix;
    ...
    };
    ```
2. Terminamos de implementar o método **paintGL()** no arquivo **`glwidget.cpp`**:
    ```c++
    void GLWidget::paintGL() {
        ...
        if (!vboVertices)
            return;
        modelViewMatrix.setToIdentity();
        modelViewMatrix.lookAt(camera.eye, camera.at, camera.up);
        modelViewMatrix.translate(0, 0, zoom);
        modelViewMatrix.rotate(trackBall.getRotation());

        shaderProgram->bind();

        shaderProgram->setUniformValue("modelViewMatrix", modelViewMatrix);
        shaderProgram->setUniformValue("projectionMatrix", projectionMatrix);
        shaderProgram->setUniformValue("normalMatrix", modelViewMatrix.normalMatrix());

        QVector4D ambientProduct = light.ambient * material.ambient;
        QVector4D diffuseProduct = light.diffuse * material.diffuse;
        QVector4D specularProduct = light.specular * material.specular;

        shaderProgram->setUniformValue("lightPosition", light.position);
        shaderProgram->setUniformValue("ambientProduct", ambientProduct);
        shaderProgram->setUniformValue("diffuseProduct", diffuseProduct);
        shaderProgram->setUniformValue("specularProduct", specularProduct);
        shaderProgram->setUniformValue("shininess", static_cast <GLfloat> (material.shininess));
        shaderProgram->setUniformValue("texColorMap", 0);
        shaderProgram->setUniformValue("texNormalMap", 1);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texID[0]);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texID[1]);

        vboVertices->bind();
        shaderProgram->enableAttributeArray("vPosition");
        shaderProgram->setAttributeBuffer("vPosition", GL_FLOAT, 0, 4, 0);

        vboNormals->bind();
        shaderProgram->enableAttributeArray("vNormal");
        shaderProgram->setAttributeBuffer("vNormal", GL_FLOAT, 0, 3, 0);

        vboTexCoords->bind();
        shaderProgram->enableAttributeArray("vTexCoord");
        shaderProgram->setAttributeBuffer("vTexCoord", GL_FLOAT, 0, 2, 0);

        vboTangents->bind();
        shaderProgram->enableAttributeArray("vTangent");
        shaderProgram->setAttributeBuffer("vTangent", GL_FLOAT, 0, 4, 0);

        vboIndices->bind();

        glDrawElements(GL_TRIANGLES, numFaces * 3, GL_UNSIGNED_INT, 0);

        vboIndices->release();
        vboTangents->release();
        vboTexCoords->release();
        vboNormals->release();
        vboVertices->release();
        shaderProgram->release();
    }
    ```
2. Criamos as classes **Camera**, **Light** e **Material** (Criando a interface gráfica - passo 1):
    1. **`camera.h`**:
        ```c++
        #ifndef CAMERA_H
        #define CAMERA_H

        #include <QVector3D>

        class Camera {
        public:
            Camera();

            QVector3D eye;
            QVector3D at;
            QVector3D up;
        };
        #endif // CAMERA_H
        ```
    2. **`camera.cpp`**:
        ```c++
        #include "camera.h"

        Camera::Camera() {
            eye = QVector3D(0.0, 0.0, 1.0);
            at = QVector3D(0.0, 0.0, 0.0);
            up = QVector3D(0.0, 1.0, 0.0);
        }
        ```
    3. **`light.h`**:
        ```c++
        #ifndef LIGHT_H
        #define LIGHT_H

        #include <QVector4D>

        class Light {
        public:
            Light();
            
            QVector4D position;
            QVector4D ambient;
            QVector4D diffuse;
            QVector4D specular;
        };

        #endif // LIGHT_H
        ```
    4. **`light.cpp`**:
        ```c++
        #include "light.h"

        Light::Light() {
            position = QVector4D(3.0, 3.0, 3.0, 0.0);
            ambient = QVector4D(0.1, 0.1, 0.1, 1.0);
            diffuse = QVector4D(0.9, 0.9, 0.9, 1.0);
            specular = QVector4D(0.9, 0.9, 0.9, 1.0);
        }
        ```
    5. **`material.h`**:
        ```c++
        #ifndef MATERIAL_H
        #define MATERIAL_H

        #include <QVector4D>

        class Material {
        public:
            Material();
            QVector4D ambient;
            QVector4D diffuse;
            QVector4D specular;
            double shininess;
        };

        # endif // MATERIAL_H
        ```
    6. **`material.cpp`**:
        ```c++
        #include "material.h"
        Material::Material() {
            ambient = QVector4D(1.0, 1.0, 1.0, 1.0);
            diffuse = QVector4D(0.6, 0.6, 0.6, 1.0);
            specular = QVector4D(0.4, 0.4, 0.4, 1.0);
            shininess = 200.0;
        }
        ```
### Formatando o contexto para o OpenGL
1. Faremos isso no arquivo **`main.cpp`**:
    ```c++
    #include <QtGui/QApplication>
    #include <QGLFormat>
    #include "mainwindow.h"

    int main(int argc, char *argv[]) {
        QGLFormat format = QGLFormat::defaultFormat();
        format.setSampleBuffers(true);
        format.setSamples(8);
        if (!format.sampleBuffers())
            qWarning("Multisample buffer is not supported.");
        QGLFormat::setDefaultFormat(format);

        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
    }
    ```
### Construtor e destrutor da classe **GLWidget**:
1. Declarando o destrutor no arquivo **`glwidget.h`** (o construtor já havia sido declarado anteriormente):
    ```c++
    ...
    class GLWidget : public QGLWidget
    {
        ...
    public:
        virtual ~GLWidget();
    ...
    };
    ```
2. Implementando o construtor (apenas edite o método) e o destrutor da classe **GLWidget** no arquivo **`glwidget.cpp`**:
    ```c++
    GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
    {
        vertices = NULL;
        normals = NULL;
        texCoords = NULL;
        tangents = NULL;
        indices = NULL;

        vboVertices = NULL;
        vboNormals = NULL;
        vboTexCoords = NULL;
        vboTangents = NULL;
        vboIndices = NULL;

        shaderProgram = NULL;
        vertexShader = NULL;
        fragmentShader = NULL;
        currentShader = 0;
        zoom = 0.0;
    }

    GLWidget::~GLWidget()
    {
        destroyVBOs();
        destroyShaders();
    }
    ```

### Resultado final
Podemos testar a aplicação com alguns [objetos](https://drive.google.com/drive/folders/1DSj4Bx5Fo06-ZxT8Sek2oJYMNSs4qVF_?usp=sharing) OFF:
![alt text](https://i.imgur.com/grvn4PN.png)

### Problemas encontrados (Linux Mint):
> - *error while loading shared libraries: libpng12.so.0: cannot open shared object file: No such file or directory'*
>
> > **Solução:**
> > Instale o [libpng12.so.0](https://drive.google.com/file/d/1QzUx0cGfO4GMsZ-vEye1lfcTACBRX5J6/view?usp=sharing).
>
>&nbsp;
> - *QGtkStyle was unable to detect the current GTK+ theme*
>
> > **Solução:**
> > Instale o [libgnome2-common](https://drive.google.com/file/d/1iTAk2RAyR8ao7NktYuxJX59hCi4fXyz3/view?usp=sharing) e reinicie seu computador.
>
>&nbsp;
> - *error: GL/gl.h: No such file or directory*
> > ```
> > $ apt-file update
> > ```
> > ```
> > $ apt-file search "gl.h"
> > ```
> > ```
> > $ apt-get install libmesa-dev
> > ```

### Referência:
J. P. Gois and H. C. Batagelo, Interactive graphics applications with opengl shading language and qt. 25th Conference  on Graphics, Patterns and Images Tutorials (SIBGRAPI-T 2012). Agosto, 2012. pp. 1–20. Disponível em http://www.decom.ufop.br/sibgrapi2012/eproceedings/tutorials/t3-survey_paper.pdf. Acessado em 28/09/2020.
