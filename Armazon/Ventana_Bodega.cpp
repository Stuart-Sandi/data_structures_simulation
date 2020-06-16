#include "Ventana_Bodega.h"
#include "ui_Ventana_Bodega.h"

Ventana_Bodega::Ventana_Bodega(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Bodega)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA BALACEADOR");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
}

Ventana_Bodega::~Ventana_Bodega()
{
    delete ui;
}

void Ventana_Bodega::asignarDatos(QString dataText, QString activos, QString pausados){
    this->ui->textBrowser->setText(dataText);
    this->ui->activos_label->setText("ACTIVOS: "+activos);
    this->ui->pausados_label->setText("PAUSADOS: "+pausados);
}

void Ventana_Bodega::on_pushButton_clicked()
{
    this->hide();
}
