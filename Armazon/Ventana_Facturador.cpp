#include "Ventana_Facturador.h"
#include "ui_Ventana_Facturador.h"

Ventana_Facturador::Ventana_Facturador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Facturador)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA FACTURADOR");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
    this->contador = 1;
}

Ventana_Facturador::~Ventana_Facturador()
{
    delete ui;
}

void Ventana_Facturador::agregarDatosCola(QString dato1, QString dato2,QString dato3 ,int val){

    if (val == 0){
        this->ui->textBrowser->append(QString::number(this->contador)+"/ Facturando el pedido: "+dato3);
        this->contador++;
    }else if(val == 1){
       this->ui->textBrowser->append("Se facturó el pedido: "+dato3+"\n");
    }else{}
    if (val != 0){
        this->ui->activos_label->setText("EN COLA FACTURADOS: "+dato1);
    }
    this->ui->activos_label_2->setText("FINALIZADOS: "+dato2);
}

void Ventana_Facturador::on_pushButton_clicked()
{
    this->hide();
}
