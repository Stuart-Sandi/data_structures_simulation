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
    this->contador = 1;
}

Ventana_Fabrica_Comodin::~Ventana_Fabrica_Comodin()
{
    delete ui;
}

void Ventana_Fabrica_Comodin::agregarDatosCola(QString data){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
}

void Ventana_Fabrica_Comodin::agregarDatosArticuloPreparando(QString dato,int dato2){
    if (dato2 ==0){
        this->ui->textBrowser->append(QString::number(this->contador)+"/ Preparando "+dato);
        this->contador++;
    }else{
        this->ui->textBrowser->append("Se prepararon las "+dato);
    }
}

void Ventana_Fabrica_Comodin::agregarDatosCola(QString data,QString data2){
    this->ui->espera_Label->setText("EN ESPERA: "+data);
    this->ui->finalizados_label->setText("FINALIZADO: "+data2);
}

void Ventana_Fabrica_Comodin::on_pushButton_clicked()
{
    this->hide();
}
