#include "Ventana_FabricaA.h"
#include "ui_Ventana_FabricaA.h"

Ventana_FabricaA::Ventana_FabricaA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_FabricaA)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA FABRICA A");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
}

Ventana_FabricaA::~Ventana_FabricaA()
{
    delete ui;
}
