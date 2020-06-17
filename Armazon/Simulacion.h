#ifndef SIMULACION_H
#define SIMULACION_H
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <QList>
#include <queue>
#include <QMutex>
#include <QDateTime>

//STRUCTS
#include <ListaClientes.h>
#include <ListaArticulos.h>
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
#include <Ventana_Bodega.h>
#include <Ventana_Alistador_1.h>
#include <Ventana_Alistador_2.h>
#include <Ventana_Alistador_3.h>
#include <Ventana_Alistador_4.h>
#include <Ventana_Alistador_5.h>
#include <Ventana_Alistador_6.h>
#include <Ventana_Alistados.h>
#include <Ventana_Facturador.h>

//THREADS
#include <ThreadColaPedidos.h>
#include <ThreadBalanceador.h>
#include <ThreadFabrica.h>
#include <ThreadFabricaEspecial.h>
#include <ThreadColaAlisto.h>
#include <ThreadAlistador.h>
#include <ThreadBodega.h>
#include <ThreadEmpacador.h>
#include <ThreadRobotFacturador.h>


struct Simulacion{

    //STRUCTS
    ListaClientes * clientes;
    ListaArticulos * articulos;
    QStringList listaCodigosPedidos;
    ColaPedidos * colaPedidos;
    ColaPedidos * colaPedidosPrioriodad;
    ColaPedidos * colaAlistados;
    ColaPedidos * colaFacturacion;
    ColaArticulos * colaA, *colaB, *colaC;
    QList <ColaArticulos*> colasArticulos;
    QList <ThreadAlistador*> listaAlistadores;
    QList <Pedido*> pedidos;
    QQueue <ThreadAlistador*> colaAlistadores;
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
    Ventana_Bodega * ventanaBodega;
    Ventana_Alistador_1 * ventanaAlistador1;
    Ventana_Alistador_2 * ventanaAlistador2;
    Ventana_Alistador_3 * ventanaAlistador3;
    Ventana_Alistador_4 * ventanaAlistador4;
    Ventana_Alistador_5 * ventanaAlistador5;
    Ventana_Alistador_6 * ventanaAlistador6;
    Ventana_Alistados * ventanaAlistados;
    Ventana_Facturador * ventanaFacturador;


    //THREADS
    ThreadColaPedidos * tColaPedidos;
    ThreadBalanceador * tBalanceador;
    ThreadFabrica * tFabricaA;
    ThreadFabrica * tFabricaB;
    ThreadFabrica * tFabricaC;
    ThreadFabricaEspecial * tFabricaComodin;
    ThreadColaAlisto * tColaAlisto;
    ThreadAlistador * tAlistador1;
    ThreadAlistador * tAlistador2;
    ThreadAlistador * tAlistador3;
    ThreadAlistador * tAlistador4;
    ThreadAlistador * tAlistador5;
    ThreadAlistador * tAlistador6;
    ThreadBodega * tBodega;
    ThreadEmpacador * tEmpacador;
    ThreadRobotFacturador * tRobot;


    //MUTEX
    QMutex mutex1;//MUTEX ENCARGADO DE LA COLA DE PEDIDOS
    QMutex mutex2;//MUTEX ENCARGADO DE LAS FABRICAS
    QMutex mutex3;//MUTEX ENCARGADO DE LOS PROCESOS DE ALISTO
    QMutex mutex4;//MUTEX ENCARGADO DE LOS PROCESOS DE FACTURACION

    Simulacion(){
        //STRUCTS
        this->clientes = new ListaClientes();
        this->articulos = new ListaArticulos();
        this->colaPedidos = new ColaPedidos();
        this->colaPedidosPrioriodad = new ColaPedidos();
        this->colaAlisto = new ColaPedidos();
        this->colaAlistados = new ColaPedidos();
        this->colaA = new ColaArticulos("A");
        this->colaB = new ColaArticulos("B");
        this->colaC = new ColaArticulos("C");
        this->colasArticulos.append(this->colaA);
        this->colasArticulos.append(this->colaB);
        this->colasArticulos.append(this->colaC);
        this->fA = new funcionesArchivos();
        this->colaFacturacion = new ColaPedidos();

        //VENTANAS
        this->ventanaPedidos = new Ventana_Pedidos();
        this->ventanaBalanceador = new Ventana_Balanceador();
        this->ventanaFabricaA = new Ventana_FabricaA();
        this->ventanaFabricaB = new Ventana_FabricaB();
        this->ventanaFabricaC = new Ventana_FabricaC();
        this->ventanaFabricaComodin = new Ventana_Fabrica_Comodin();
        this->ventanaColaAlisto = new Ventana_Cola_Alisto();
        this->ventanaBodega = new Ventana_Bodega();
        this->ventanaAlistador1 = new Ventana_Alistador_1();
        this->ventanaAlistador2 = new Ventana_Alistador_2();
        this->ventanaAlistador3 = new Ventana_Alistador_3();
        this->ventanaAlistador4 = new Ventana_Alistador_4();
        this->ventanaAlistador5 = new Ventana_Alistador_5();
        this->ventanaAlistador6 = new Ventana_Alistador_6();
        this->ventanaAlistados = new Ventana_Alistados();
        this->ventanaFacturador = new Ventana_Facturador();

        //THREADS
        this->tColaPedidos = new ThreadColaPedidos(this->colaPedidos,this->colaPedidosPrioriodad, &this->listaCodigosPedidos,this->clientes,this->articulos, &this->mutex1);
        this->tBalanceador = new ThreadBalanceador(this->colaPedidos,this->colaPedidosPrioriodad,this->colaAlisto,&this->pedidos,this->articulos,this->colasArticulos,&this->mutex1,&this->mutex2);
        this->tFabricaA = new ThreadFabrica(this->colaA,this->articulos,"A",&this->mutex2);
        this->tFabricaB = new ThreadFabrica(this->colaB,this->articulos,"B",&this->mutex2);
        this->tFabricaC = new ThreadFabrica(this->colaC,this->articulos,"C",&this->mutex2);
        this->tFabricaComodin = new ThreadFabricaEspecial(this->colaA,this->colaB,this->articulos,&this->mutex2);
        this->tColaAlisto = new ThreadColaAlisto(&this->pedidos,this->colaAlisto,&this->mutex2);

        //THREAD ALISTADORES
        this->tAlistador1 = new ThreadAlistador("Alistador 1",this->colaAlistados,&this->mutex3, "1");
        this->tAlistador2 = new ThreadAlistador("Alistador 2",this->colaAlistados,&this->mutex3, "2");
        this->tAlistador3 = new ThreadAlistador("Alistador 3",this->colaAlistados,&this->mutex3, "3");
        this->tAlistador4 = new ThreadAlistador("Alistador 4",this->colaAlistados,&this->mutex3, "4");
        this->tAlistador5 = new ThreadAlistador("Alistador 5",this->colaAlistados,&this->mutex3, "5");
        this->tAlistador6 = new ThreadAlistador("Alistador 6",this->colaAlistados,&this->mutex3, "6");

        //AGREGA LOS THREADS ALISTADORES A LA LISTA
        this->listaAlistadores.append(this->tAlistador1);
        this->listaAlistadores.append(this->tAlistador2);
        this->listaAlistadores.append(this->tAlistador3);
        this->listaAlistadores.append(this->tAlistador4);
        this->listaAlistadores.append(this->tAlistador5);
        this->listaAlistadores.append(this->tAlistador6);

        //AGREGA LOS THREADS ALISTADORES A LA COLA
        this->colaAlistadores.enqueue(this->tAlistador1);
        this->colaAlistadores.enqueue(this->tAlistador2);
        this->colaAlistadores.enqueue(this->tAlistador3);
        this->colaAlistadores.enqueue(this->tAlistador4);
        this->colaAlistadores.enqueue(this->tAlistador5);
        this->colaAlistadores.enqueue(this->tAlistador6);

        //THREAD BODEGA
        this->tBodega = new ThreadBodega(this->colaAlisto,this->listaAlistadores,this->colaAlistadores,&this->mutex2);

        this->tRobot = new ThreadRobotFacturador(this->colaFacturacion,&this->mutex4);
        this->tEmpacador = new ThreadEmpacador(this->colaAlistados,this->colaFacturacion, &this->mutex3, &this->mutex4);

    }
    int cargarListas();
    void iniciarSimulacion();
    void detenerSimulacion();
};

#endif // SIMULACION_H
