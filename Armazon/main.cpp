#include "mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    QDir d = QFileInfo("../Armazon").absoluteDir();
    QString absolute=d.absolutePath() + "/Armazon";

    QStringList lista = QDir(absolute).entryList();
    qDebug() << lista;

    return a.exec();
}
