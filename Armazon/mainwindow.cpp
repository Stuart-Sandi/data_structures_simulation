#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    simulacion = new Simulacion();
    simulacion->cargarListas();
    simulacion->clientes->imprimir();
}

MainWindow::~MainWindow()
{
    delete ui;
}

