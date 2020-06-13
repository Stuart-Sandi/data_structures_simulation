#include "Ventana_Balanceador.h"
#include "ui_Ventana_Balanceador.h"

Ventana_Balanceador::Ventana_Balanceador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Balanceador)
{
    ui->setupUi(this);
}

Ventana_Balanceador::~Ventana_Balanceador()
{
    delete ui;
}
