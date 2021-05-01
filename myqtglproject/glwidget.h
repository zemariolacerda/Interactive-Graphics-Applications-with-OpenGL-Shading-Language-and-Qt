#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>

#include <iostream>
#include <fstream>
#include <limits>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    void toggleBackgroundColor(bool toBlack);
    void showFileOpenDialog();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

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

};

#endif // GLWIDGET_H
