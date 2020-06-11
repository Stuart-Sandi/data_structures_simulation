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


void MainWindow::on_pushButton_clicked()
{
    /*
     * ESTE BOTON ES EL ENCARGADO DE INICIAR LA SIMULACION LLAMANDO A LA FUNCION QUE INICIA LOS HILOS
     */
    this->ui->pushButton->setEnabled(false);
    this->ui->pushButton_2->setEnabled(true);
    this->simulacion->iniciarSimulacion();
}
