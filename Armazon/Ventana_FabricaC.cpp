#include "Ventana_FabricaC.h"
#include "ui_Ventana_FabricaC.h"

Ventana_FabricaC::Ventana_FabricaC(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_FabricaC)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA FABRICA C");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
}

Ventana_FabricaC::~Ventana_FabricaC()
{
    delete ui;
}
