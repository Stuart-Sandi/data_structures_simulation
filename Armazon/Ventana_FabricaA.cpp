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
    this->contador = 1;
}

Ventana_FabricaA::~Ventana_FabricaA()
{
    delete ui;
}

void Ventana_FabricaA::agregarDatosCola(QString data){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
}

void Ventana_FabricaA::agregarDatosArticuloPreparando(QString dato,int dato2){
    if (dato2 ==0){
        this->ui->textBrowser->append(QString::number(this->contador)+"/ Preparando "+dato);
        this->contador++;
    }else{
        this->ui->textBrowser->append("Se prepararon las "+dato);
    }
}

void Ventana_FabricaA::agregarDatosCola(QString data,QString data2){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
    this->ui->finalizado_label->setText("FINALIZADO: "+data2);
}

void Ventana_FabricaA::on_pushButton_clicked()
{
    this->hide();
}
