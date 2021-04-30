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
