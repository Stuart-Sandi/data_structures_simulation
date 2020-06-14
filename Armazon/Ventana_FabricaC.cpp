#include "Ventana_FabricaC.h"
#include "ui_Ventana_FabricaC.h"

Ventana_FabricaC::Ventana_FabricaC(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_FabricaC)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA FABRICA C");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
    this->contador = 1;
}

Ventana_FabricaC::~Ventana_FabricaC()
{
    delete ui;
}

void Ventana_FabricaC::agregarDatosCola(QString data){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
}

void Ventana_FabricaC::agregarDatosArticuloPreparando(QString dato,int dato2){
    if (dato2 ==0){
        this->ui->textBrowser->append(QString::number(this->contador)+"/ Preparando "+dato);
        this->contador++;
    }else{
        this->ui->textBrowser->append("Se prepararon las "+dato);
    }
}

void Ventana_FabricaC::agregarDatosCola(QString data,QString data2){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
    this->ui->finalizados_label->setText("FINALIZADO: "+data2);
}

void Ventana_FabricaC::on_pushButton_clicked()
{
    this->hide();
}
