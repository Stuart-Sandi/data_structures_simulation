#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("ARMAZON SIMULATION");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(1300,687);

    simulacion = new Simulacion();
    //simulacion->clientes->imprimir();//IMPRIME LISTA DE CLIENTES
    //simulacion->articulos->imprimir();//IMPRIME LISTA DE ARTICULOS
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_iniciar_Button_clicked()
{
    /*
     * ESTE BOTON ES EL ENCARGADO DE INICIAR LA SIMULACION LLAMANDO A LA FUNCION QUE INICIA LOS HILOS
     */
    this->ui->iniciar_Button->setEnabled(false);
    this->ui->detener_Button->setEnabled(true);

    //HACE LOS CONNECTS ENTRE HILOS Y VENTANAS


    //################CONNECTS##################
    //VENTANA COLA DE PEDIDOS
    connect(this->simulacion->tColaPedidos,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaPedidos,SLOT(agregarDatos(QString,QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaPedidos,SLOT(agregarDatos2(QString,QString)));

    //VENTANA BALANCEADOR
    connect(this->simulacion->tBalanceador,SIGNAL(datosBalanceador1(QString,QString)),this->simulacion->ventanaBalanceador,SLOT(agregarDatos(QString,QString)));
    connect(this->simulacion->tColaAlisto,SIGNAL(datosBalanceador(QString,QString)),this->simulacion->ventanaBalanceador,SLOT(agregarDatos2(QString,QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaA(QString)),this->simulacion->ventanaFabricaA,SLOT(agregarDatosCola(QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaB(QString)),this->simulacion->ventanaFabricaB,SLOT(agregarDatosCola(QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaC(QString)),this->simulacion->ventanaFabricaC,SLOT(agregarDatosCola(QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaAB(QString)),this->simulacion->ventanaFabricaComodin,SLOT(agregarDatosCola(QString)));


    //VENTANA FABRICA A
    connect(this->simulacion->tFabricaA,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaA,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaA,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaA, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA FABRICA B
    connect(this->simulacion->tFabricaB,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaB,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaB,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaB, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA FABRICA C
    connect(this->simulacion->tFabricaC,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaC,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaC,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaC, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA FABRICA ESPECIAL
    connect(this->simulacion->tFabricaComodin,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaComodin,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaComodin,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaComodin, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA COLA ALISTO
    connect(this->simulacion->tColaAlisto,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaColaAlisto,SLOT(agregarDatos(QString,QString)));


    //############INICIA LA SIMULACION############
    this->simulacion->iniciarSimulacion();
}

void MainWindow::on_ojo_Cola_Pedidos_clicked()
{
    this->simulacion->ventanaPedidos->show();
}

void MainWindow::on_pausar_Balanceador_clicked()
{
    this->simulacion->tBalanceador->pausa = !this->simulacion->tBalanceador->pausa;
    if (this->simulacion->tBalanceador->pausa == false){
        this->ui->pausar_Balanceador->setText("Pausar");
    }else{
        this->ui->pausar_Balanceador->setText("Continuar");
    }
}

void MainWindow::on_ojo_Balanceador_clicked()
{
    this->simulacion->ventanaBalanceador->show();
    qDebug()<<"A:"<<this->simulacion->colasArticulos[0]->cantidadEnCola();
    qDebug()<<"B:"<<this->simulacion->colasArticulos[1]->cantidadEnCola();
    qDebug()<<"C:"<<this->simulacion->colasArticulos[2]->cantidadEnCola();
}

void MainWindow::on_ojo_FabricaA_clicked()
{
    this->simulacion->ventanaFabricaA->show();
}

void MainWindow::on_ojo_FabricaB_clicked()
{
    this->simulacion->ventanaFabricaB->show();
}

void MainWindow::on_ojo_FabricaC_clicked()
{
    this->simulacion->ventanaFabricaC->show();
}

void MainWindow::on_ojo_FabricaComo_clicked()
{
    this->simulacion->ventanaFabricaComodin->show();
}

void MainWindow::on_ojo_Cola_Alisto_clicked()
{
    this->simulacion->ventanaColaAlisto->show();
}

void MainWindow::on_pausar_FabricaA_clicked()
{
    this->simulacion->tFabricaA->pausa = !this->simulacion->tFabricaA->pausa;
    if (this->simulacion->tFabricaA->pausa == false){
        this->ui->pausar_FabricaA->setText("Pausar");
    }else{
        this->ui->pausar_FabricaA->setText("Continuar");
    }
}

void MainWindow::on_pausar_FabricaB_clicked()
{
    this->simulacion->tFabricaB->pausa = !this->simulacion->tFabricaB->pausa;
    if (this->simulacion->tFabricaB->pausa == false){
        this->ui->pausar_FabricaB->setText("Pausar");
    }else{
        this->ui->pausar_FabricaB->setText("Continuar");
    }
}

void MainWindow::on_pausar_FabricaC_clicked()
{
    this->simulacion->tFabricaC->pausa = !this->simulacion->tFabricaC->pausa;
    if (this->simulacion->tFabricaC->pausa == false){
        this->ui->pausar_FabricaC->setText("Pausar");
    }else{
        this->ui->pausar_FabricaC->setText("Continuar");
    }
}

void MainWindow::on_pausar_FabricaComo_clicked()
{
    this->simulacion->tFabricaComodin->pausa = !this->simulacion->tFabricaComodin->pausa;
    if (this->simulacion->tFabricaComodin->pausa == false){
        this->ui->pausar_FabricaComo->setText("Pausar");
    }else{
        this->ui->pausar_FabricaComo->setText("Continuar");
    }
}
