#include "Ventana_FabricaB.h"
#include "ui_Ventana_FabricaB.h"

Ventana_FabricaB::Ventana_FabricaB(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_FabricaB)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA FABRICA B");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
}

Ventana_FabricaB::~Ventana_FabricaB()
{
    delete ui;
}
