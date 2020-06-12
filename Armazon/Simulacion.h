#ifndef SIMULACION_H
#define SIMULACION_H
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <QList>
#include <QMutex>
#include <QDateTime>

#include <ListaClientes.h>
#include <ListaArticulos.h>
#include <ColaPedidos.h>
#include <funcionesArchivos.h>
#include <ThreadColaPedidos.h>
#include <Ventana_Pedidos.h>


struct Simulacion{

    //STRUCTS
    ListaClientes * clientes;
    ListaArticulos * articulos;
    QStringList listaCodigosPedidos;
    ColaPedidos * colaPedidos;
    ColaPedidos * colaPedidosPrioriodad;
    funcionesArchivos * fA;
    //VENTANAS
    Ventana_Pedidos * ventanaPedidos;

    //THREADS
    ThreadColaPedidos * tColaPedidos;

    QMutex mutex1;

    Simulacion(){
        //STRUCTS
        this->clientes = new ListaClientes();
        this->articulos = new ListaArticulos();
        this->colaPedidos = new ColaPedidos();
        this->colaPedidosPrioriodad = new ColaPedidos();
        this->fA = new funcionesArchivos();
        //VENTANAS
        this->ventanaPedidos = new Ventana_Pedidos();


        //THREADS
        this->tColaPedidos = new ThreadColaPedidos(this->colaPedidos,this->colaPedidosPrioriodad, &this->listaCodigosPedidos,this->clientes,this->articulos, &mutex1);
    }
    int cargarListas();
    void iniciarSimulacion();
};

#endif // SIMULACION_H
