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
#include <Ventana_Balanceador.h>
#include <Ventana_FabricaA.h>
#include <Ventana_FabricaB.h>
#include <Ventana_FabricaC.h>
#include <Ventana_Fabrica_Comodin.h>
#include <Ventana_Cola_Alisto.h>

//THREADS
#include <ThreadColaPedidos.h>
#include <ThreadBalanceador.h>
#include <ThreadFabrica.h>
#include <ThreadFabricaEspecial.h>
#include <ThreadColaAlisto.h>


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
    Ventana_Balanceador * ventanaBalanceador;
    Ventana_FabricaA * ventanaFabricaA;
    Ventana_FabricaB * ventanaFabricaB;
    Ventana_FabricaC * ventanaFabricaC;
    Ventana_Fabrica_Comodin * ventanaFabricaComodin;
    Ventana_Cola_Alisto * ventanaColaAlisto;

    //THREADS
    ThreadColaPedidos * tColaPedidos;
    ThreadBalanceador * tBalanceador;
    ThreadFabrica * tFabricaA;
    ThreadFabrica * tFabricaB;
    ThreadFabrica * tFabricaC;
    ThreadFabricaEspecial * tFabricaComodin;
    ThreadColaAlisto * tColaAlisto;


    //MUTEX
    QMutex mutex1;//MUTEX ENCARGADO DE LA COLA DE PEDIDOS
    QMutex mutex2;//MUTEX ENCARGADO DE LAS FABRICAS
    QMutex mutex3;//MUTEX ENCARGADO DE LOS PROCESOS DE ALISTO

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
        this->ventanaBalanceador = new Ventana_Balanceador();
        this->ventanaFabricaA = new Ventana_FabricaA();
        this->ventanaFabricaB = new Ventana_FabricaB();
        this->ventanaFabricaC = new Ventana_FabricaC();
        this->ventanaFabricaComodin = new Ventana_Fabrica_Comodin();
        this->ventanaColaAlisto = new Ventana_Cola_Alisto();

        //THREADS
        this->tColaPedidos = new ThreadColaPedidos(this->colaPedidos,this->colaPedidosPrioriodad, &this->listaCodigosPedidos,this->clientes,this->articulos, &this->mutex1);
        this->tBalanceador = new ThreadBalanceador(this->colaPedidos,this->colaPedidosPrioriodad,this->colaAlisto,this->pedidos,this->articulos,this->colasArticulos,&this->mutex1,&this->mutex2);
        this->tFabricaA = new ThreadFabrica(this->colaA,this->articulos,"A",&this->mutex2);
        this->tFabricaB = new ThreadFabrica(this->colaB,this->articulos,"B",&this->mutex2);
        this->tFabricaC = new ThreadFabrica(this->colaC, this->articulos,"C", &this->mutex2);
        this->tFabricaComodin = new ThreadFabricaEspecial(this->colaA,this->colaB,this->articulos,&this->mutex2);
        this->tColaAlisto = new ThreadColaAlisto(this->pedidos,this->colaAlisto,&this->mutex2,&this->mutex3);



    }
    int cargarListas();
    void iniciarSimulacion();
};

#endif // SIMULACION_H
