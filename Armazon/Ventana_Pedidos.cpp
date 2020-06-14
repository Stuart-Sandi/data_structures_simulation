#include "Ventana_Pedidos.h"
#include "ui_Ventana_Pedidos.h"

Ventana_Pedidos::Ventana_Pedidos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Pedidos)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA PEDIDOS");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);

    this->contador = 1;
}

Ventana_Pedidos::~Ventana_Pedidos()
{
    delete ui;
}

//ESTA ES LA FUNCION QUE CAMBIA LOS VALORES DE LA VENTANA DE PEDIDOS
void Ventana_Pedidos::agregarDatos(QString data,QString cantidad){
    this->ui->textBrowser->append(QString::number(this->contador)+"/"+" Pedido atendido#"+data);
    this->contador++;
    this->ui->encolar_Label->setText("EN COLA: "+cantidad);
}

void Ventana_Pedidos::agregarDatos2(QString cant1,QString cant2){
    this->ui->encolar_Label->setText("EN COLA: "+cant1);
    this->ui->desencolar_Labe->setText("DESENCOLADO: "+cant2);
}

void Ventana_Pedidos::on_pushButton_clicked()
{
    this->hide();
}
