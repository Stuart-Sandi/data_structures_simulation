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
    this->contador = 1;
}

Ventana_FabricaB::~Ventana_FabricaB()
{
    delete ui;
}

void Ventana_FabricaB::agregarDatosCola(QString data){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
}

void Ventana_FabricaB::agregarDatosArticuloPreparando(QString dato,int dato2){
    if (dato2 ==0){
        this->ui->textBrowser->append(QString::number(this->contador)+"/ Preparando "+dato);
        this->contador++;
    }else{
        this->ui->textBrowser->append("Se prepararon las "+dato);
    }
}

void Ventana_FabricaB::agregarDatosCola(QString data,QString data2){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
    this->ui->finalizados_label->setText("FINALIZADO: "+data2);
}

void Ventana_FabricaB::on_pushButton_clicked()
{
    this->hide();
}
