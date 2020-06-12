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
}

Ventana_Pedidos::~Ventana_Pedidos()
{
    delete ui;
}

//ESTA ES LA FUNCION QUE CAMBIA LOS VALORES DE LA VENTANA DE PEDIDOS
void Ventana_Pedidos::agregarDatos(QString data,QString cantidad){
    this->ui->textBrowser->append("Atendiendo pedido #"+data);
    this->ui->encolar_Label->setText("En Cola: "+cantidad);
}

void Ventana_Pedidos::agregarDatos2(QString cant1,QString cant2){
    this->ui->encolar_Label->setText("En Cola: "+cant1);
    this->ui->desencolar_Labe->setText("Desencolado: "+cant2);
}

void Ventana_Pedidos::on_pushButton_clicked()
{
    this->hide();
}
