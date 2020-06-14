#include "Ventana_Cola_Alisto.h"
#include "ui_Ventana_Cola_Alisto.h"

Ventana_Cola_Alisto::Ventana_Cola_Alisto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Cola_Alisto)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA COLA DE ALISTO");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
}

Ventana_Cola_Alisto::~Ventana_Cola_Alisto()
{
    delete ui;
}
