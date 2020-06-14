#include "Ventana_Balanceador.h"
#include "ui_Ventana_Balanceador.h"

Ventana_Balanceador::Ventana_Balanceador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Balanceador)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA BALACEADOR");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);

    this->contador = 1;
}

Ventana_Balanceador::~Ventana_Balanceador()
{
    delete ui;
}

void Ventana_Balanceador::agregarDatos(QString data,QString cantidad){
    this->ui->textBrowser->append(QString::number(this->contador)+"/"+" Pedido atendido#"+data);
    this->contador++;
    this->ui->espera_Label->setText("En Espera: "+cantidad);
}

void Ventana_Balanceador::agregarDatos2(QString espera, QString finalizado){
    this->ui->espera_Label->setText("En Espera: "+espera);
    this->ui->final_Label->setText("Finalizados: "+finalizado);
}
void Ventana_Balanceador::on_pushButton_clicked()
{
    this->hide();
}
