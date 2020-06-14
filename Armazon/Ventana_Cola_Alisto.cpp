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
    this->contador = 1;
}

Ventana_Cola_Alisto::~Ventana_Cola_Alisto()
{
    delete ui;
}

//ESTA ES LA FUNCION QUE CAMBIA LOS VALORES DE LA VENTANA DE PEDIDOS
void Ventana_Cola_Alisto::agregarDatos(QString data,QString cantidad){
    this->ui->textBrowser->append(QString::number(this->contador)+"/"+" Pedido atendido#"+data);
    this->contador++;
    this->ui->encola_label->setText("EN COLA: "+cantidad);
}

void Ventana_Cola_Alisto::agregarDatos2(QString cant1,QString cant2){
    this->ui->encola_label->setText("EN COLA: "+cant1);
    this->ui->desencola_label->setText("DESENCOLADO: "+cant2);
}

void Ventana_Cola_Alisto::on_pushButton_clicked()
{
    this->hide();
}
