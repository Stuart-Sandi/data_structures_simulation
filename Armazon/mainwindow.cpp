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

    //VENTANA COLA DE PEDIDOS
    connect(this->simulacion->tColaPedidos,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaPedidos,SLOT(agregarDatos(QString,QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaPedidos,SLOT(agregarDatos2(QString,QString)));

    this->simulacion->iniciarSimulacion();//INICIA LA SIMULACION
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
    qDebug()<<"A:"<<this->simulacion->colasArticulos[0]->cantidadEnCola();
    qDebug()<<"B:"<<this->simulacion->colasArticulos[1]->cantidadEnCola();
    qDebug()<<"C:"<<this->simulacion->colasArticulos[2]->cantidadEnCola();
}
