//#include <QtGui/QApplication> //<--------- remove
#include <QtWidgets/QApplication> //<--------- adiciona
#include <QGLFormat>
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QGLFormat format = QGLFormat::defaultFormat();
    format.setSampleBuffers(true);
    format.setSamples(8);
    if (!format.sampleBuffers()) {
        qWarning("Multisample buffer is not supported.");
    }
    QGLFormat::setDefaultFormat(format);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
