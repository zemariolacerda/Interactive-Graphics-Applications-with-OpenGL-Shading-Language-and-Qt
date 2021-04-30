# Interactive-Graphics-Applications-with-OpenGL-Shading-Language-and-Qt

### Qt SDK 1.2.1 (Qt Creator IDE 2.4.1 + Qt Framework 4.8.1):
##### [Qt SDK 1.2.1 Linux](https://drive.google.com/file/d/1N-isT6CBftVWJHY3Told2Efpx9Fsy9y-/view?usp=sharing):

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
5. Arraste um *widget* para o objeto **centralWidget**:
![alt text](https://i.imgur.com/bcbGu7f.gif)
6. Promova o *widget* para **GLWidget**:
   1. Clique com o botão direito no widget e selecione *Promote to ...*
   2. Em *Promoted class name* coloque *GLWidget*, clique em *Add* e *Promote*:
   ![alt text](https://i.imgur.com/9p8i7kg.gif)
7. Para rodar o programa, use o atalho '*ctrl + r*' ou clique no icone *Run*:
![alt text](https://i.imgur.com/svI7nqT.png)
8. Caso tudo ocorra bem, uma janela será criada na sua tela. Caso encontre problemas, veja se existe alguma solução na parte de problemas encontrados.
![alt text](https://i.imgur.com/6pIcMDp.png)

&nbsp;
### Problemas encontrados (Debian):
> *error while loading shared libraries: libpng12.so.0: cannot open shared object file: No such file or directory'*
>
> > **Solução**
> > Instale o libpng12.so.0:
> > ```
> > https://drive.google.com/file/d/1QzUx0cGfO4GMsZ-vEye1lfcTACBRX5J6/view?usp=sharing
> > ```
>&nbsp;
> &nbsp;
> *QGtkStyle was unable to detect the current GTK+ theme*
>
> > **Solução**
> > Instale o libgnome2-common e reinicie:
> > ```
> > https://drive.google.com/file/d/1iTAk2RAyR8ao7NktYuxJX59hCi4fXyz3/view?usp=sharing
> > ```
