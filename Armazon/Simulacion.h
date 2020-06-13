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
#include <ListaPedidos.h>
#include <ColaPedidos.h>
#include <ColaArticulos.h>
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
    ListaPedidos * pedidos;
    QStringList listaCodigosPedidos;
    ColaPedidos * colaPedidos;
    ColaPedidos * colaPedidosPrioriodad;
    ColaArticulos * colaA, *colaB, *colaC;
    QList <ColaArticulos*> colasArticulos;
    ColaPedidos *colaAlisto;
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
        this->pedidos = new ListaPedidos();
        this->colaPedidos = new ColaPedidos();
        this->colaPedidosPrioriodad = new ColaPedidos();
        this->colaAlisto = new ColaPedidos();
        this->colaA = new ColaArticulos();
        this->colaB = new ColaArticulos();
        this->colaC = new ColaArticulos();
        this->colasArticulos.append(this->colaA);
        this->colasArticulos.append(this->colaB);
        this->colasArticulos.append(this->colaC);
        this->fA = new funcionesArchivos();

        //VENTANAS
        this->ventanaPedidos = new Ventana_Pedidos();

        //THREADS
        this->tColaPedidos = new ThreadColaPedidos(this->colaPedidos,this->colaPedidosPrioriodad, &this->listaCodigosPedidos,this->clientes,this->articulos, &this->mutex1);
        this->tBalanceador = new ThreadBalanceador(this->colaPedidos,this->colaPedidosPrioriodad,this->colaAlisto,this->pedidos,this->articulos,this->colasArticulos,&this->mutex1,&this->mutex2);
    }
    int cargarListas();
    void iniciarSimulacion();
};

#endif // SIMULACION_H
