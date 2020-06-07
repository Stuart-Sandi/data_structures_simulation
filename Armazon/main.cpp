#include "mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <ListaClientes.h>
#include <Cliente.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    QDir d = QFileInfo("../Armazon").absoluteDir();
    QString absolute=d.absolutePath() + "/Armazon";

    QStringList lista = QDir(absolute).entryList();
    //qDebug() << lista;

    ListaClientes * l = new ListaClientes();
    Cliente * c1 = new Cliente("001","Mario",10);
    Cliente * c2 = new Cliente("001","Mario",10);
    Cliente * c3 = new Cliente("002","Ernesto",1);
    qDebug()<<l->insertarCliente(c1);// = 1
    qDebug()<<l->insertarCliente(c2);//NO SE INSERTA PORQUE EL CODIGO DE MARIO YA EXISTE = 0
    qDebug()<<l->insertarCliente(c3);// = 1
    qDebug()<<endl;
    l->imprimir();

    return a.exec();
}
