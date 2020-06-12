#ifndef SIMULACION_H
#define SIMULACION_H
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <QList>
#include <QMutex>
#include <QDateTime>

//STRUCTS
#include <ListaClientes.h>
#include <ListaArticulos.h>
#include <ColaPedidos.h>
#include <funcionesArchivos.h>

//VENTANAS
#include <Ventana_Pedidos.h>

//THREADS
#include <ThreadColaPedidos.h>
#include <ThreadBalanceador.h>


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
    ThreadBalanceador * tBalanceador;

    //MUTEX
    QMutex mutex1;//MUTEX ENCARGADO DE LA COLA DE PEDIDOS
    QMutex mutex2;//MUTEX ENCARGADO DE LAS FABRICAS

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
        this->tColaPedidos = new ThreadColaPedidos(this->colaPedidos,this->colaPedidosPrioriodad, &this->listaCodigosPedidos,this->clientes,this->articulos, &this->mutex1);
        this->tBalanceador = new ThreadBalanceador(this->colaPedidos,this->colaPedidosPrioriodad,&this->mutex1,&this->mutex2);
    }
    int cargarListas();
    void iniciarSimulacion();
};

#endif // SIMULACION_H
