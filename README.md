# Interactive-Graphics-Applications-with-OpenGL-Shading-Language-and-Qt

### Qt SDK 1.2.1 (Qt Creator IDE 2.4.1 + Qt Framework 4.8.1):
##### [Qt SDK 1.2.1 Linux](https://drive.google.com/file/d/1FUsWaRXAQ5Wg0AHjIMmGzsssDZ-4O3Nv/view?usp=sharing):

1. Executando pela interface gráfica:
   1. Faça o download do arquivo .run;
   2. Clique com o botão direito, *Propriedades* -> *Permissões* -> Marque a opção que permite executar o arquivo como programa -> *Fechar*;
   3. Clique 2x para executar o arquivo;
&nbsp;
2. Pelo terminal:
```
$ cd /local/do/arquivo/chmod +x qt-creator-opensource-linux-x86_64-4.8.0.run 
```
```
$ ./qt-creator-opensource-linux-x86_64-4.8.0.run
```
##### [Qt SDK 1.2.1 Windows](https://drive.google.com/file/d/1uAPWVDFjSLSmYABIIqvSzXsdgpdeSZPl/view?usp=sharing):
1. Instalação padrão do windows.
&nbsp;
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

QT       += core gui opengl

TARGET = myqtglproject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

```
### Criando a interface gráfica:
1. Clique 2x no arquivo **`mainwindow.ui`**
![alt text](https://i.imgur.com/0SRmi4d.png)
2. Crie a classe **GLWidget**:
    1. *File* -> *New File or Project* e selecione as seguintes opções:
![alt text](https://i.imgur.com/KwO3U6i.png)
    2. Preencha os campos da classe e avance:
![alt text](https://i.imgur.com/fkGFYJZ.png)
    3. Finalize:                                          
&nbsp;
![alt text](https://i.imgur.com/ypiFjqL.png)
3. Inclua **`<QtOpenGL>`** e declare os métodos **initializeGL()**, **resizeGL()** e **paintGL()** no arquivo **glwidget.h**:
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
4. Implemente-os no arquivo **glwidget.cpp**:
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
    glClear(GL_COLOR_BUFFER_BIT);
}
```
5. Arraste um *widget* para o objeto **centralWidget** (clique 2x no arquivo **mainwindow.ui** para entrar na aba *Design*):
![alt text](https://i.imgur.com/bcbGu7f.gif)
6. Promova o *widget* para **GLWidget**:
    1. Clique com o botão direito no widget e selecione *Promote to ...*
    2. Em *Promoted class name* coloque *GLWidget*, clique em *Add* e *Promote*:
   ![alt text](https://i.imgur.com/9p8i7kg.gif)
7. Para rodar o programa, use o atalho '*ctrl + r*' ou clique no icone *Run*:
![alt text](https://i.imgur.com/svI7nqT.png)
8. Caso tudo ocorra bem, uma janela será criada na sua tela. Caso encontre problemas, veja se existe alguma solução na parte de problemas encontrados.
![alt text](https://i.imgur.com/6pIcMDp.png)
9. Criando um botão de sair:
    1. Arraste um *Push Button* para o objeto **centralWidget** e renomeie para *Exit*:
   ![alt text](https://i.imgur.com/o5pnkun.gif)
    2. Selecione o *Signals & Slots Editor*:
   ![alt text](https://i.imgur.com/k2Epv4Z.png)
    3. Adicione um novo *signal/slot*:
   ![alt text](https://i.imgur.com/MJ6Zgn5.png)
    4. Configure da seguinte maneira:
   ![alt text](https://i.imgur.com/3Y1WnHP.png)
10. Criando um *checkbox* para alternar a cor do fundo do widget de preto para branco:
    1. Arraste um *Check Box* para **centralWidget** e o renomeie para "Toggle background color".
    ![alt text](https://i.imgur.com/ZSIUzkC.png)
    2. Declarando um *slot* customizado para nosso checkbox no arquivo  **glwidget.h**:
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
    3. Definindo um *slot* customizado para nosso checkbox no arquivo  **glwidget.cpp**:
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
    4. Inserindo a assinatura do *slot* customizado **toggleBackgroundColor(bool)** na lista de *Signals/Slots*:
    ![alt text](https://i.imgur.com/jmsu4gr.gif)
    5. Uma nova conexão Signal/Slot com a seguinte configuração deve ser criada:
    ![alt text](https://i.imgur.com/QmPiQRQ.png)

11. Carregando um modelo geométrico:
    1. Clique 2x em **Type Here** e altere para **File** para criar uma opção de menu. Logo depois, crie uma opção de submenu com o nome **Open**:
    ![alt text](https://i.imgur.com/3LdXOzi.gif)
    2. Declare o slot **showFileOpenDialog()** e os métodos **readOFFFile()**, **genNormals()**, **genTexCoordsCylinder()** e **genTangents()** no arquivo **glwidget.h** e dê include em alguns arquivos:
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
    3. Definindo o *slot* **showFileOpenDialog()** e os métodos **readOFFFile()**, **genNormals()**, **genTexCoordsCylinder()** e **genTangents()** no arquivo **glwidget.cpp**:
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
    ```
    4. Insira a assinatura do slot customizado **showFileOpenDialog()** na lista de Signals/Slots (Passo 10-iv).
    5. Uma nova conexão Signal/Slot com a seguinte configuração deve ser criada:
    ![alt text](https://i.imgur.com/TGEvXkd.png)

    6. Teste sua janela!

12. Encapsulando recursos:
    1. Vá em *File* -> *New File or Project* e selecione as seguintes opções:
    ![alt text](https://i.imgur.com/xHycfDz.png)
    2. Nomeie como **resources.qrc**:
    ![alt text](https://i.imgur.com/WbroGts.png)
    3. Crie um prefixo para listar shaders e texturas no arquivo **resources.qrc**:
    ![alt text](https://i.imgur.com/WEZ3h9l.gif)
    4. Agora, iremos criar nossos shaders da seguinte maneira:

&nbsp;
### Problemas encontrados (Debian):
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

