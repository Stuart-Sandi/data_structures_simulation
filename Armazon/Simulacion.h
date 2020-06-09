#ifndef SIMULACION_H
#define SIMULACION_H
#include <ListaClientes.h>
#include <ListaArticulos.h>
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <QList>


struct Simulacion{
    ListaClientes * clientes;
    ListaArticulos * articulos;
    Simulacion(){
        this->clientes = new ListaClientes();
        this->articulos = new ListaArticulos();
    }
    int cargarListas();
};

#endif // SIMULACION_H
