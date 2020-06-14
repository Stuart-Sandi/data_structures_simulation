#include "Ventana_Fabrica_Comodin.h"
#include "ui_Ventana_Fabrica_Comodin.h"

Ventana_Fabrica_Comodin::Ventana_Fabrica_Comodin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Fabrica_Comodin)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA FABRICA COMODIN");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
}

Ventana_Fabrica_Comodin::~Ventana_Fabrica_Comodin()
{
    delete ui;
}
