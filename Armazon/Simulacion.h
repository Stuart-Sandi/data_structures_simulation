#ifndef SIMULACION_H
#define SIMULACION_H
#include <ListaClientes.h>
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <QList>


struct Simulacion{
    ListaClientes * clientes;
    Simulacion(){
        this->clientes = new ListaClientes();
    }
    int cargarListas();
};

#endif // SIMULACION_H
