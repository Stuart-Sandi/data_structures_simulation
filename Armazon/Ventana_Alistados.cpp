#include "Ventana_Alistados.h"
#include "ui_Ventana_Alistados.h"

Ventana_Alistados::Ventana_Alistados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Alistados)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA PEDIDOS ALISTADOS");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
    this->setWindowIcon( QIcon( ":/Imagenes/pedidosAlistados_logo.png" ) );
    this->contador = 1;
}

Ventana_Alistados::~Ventana_Alistados()
{
    delete ui;
}

void Ventana_Alistados::agregarDatosCola(QString dato1, QString dato2, QString dato3, int val){
    if (val == 0){
        this->ui->textBrowser->append(QString::number(this->contador)+"/ Atendiendo pedido: "+dato3);
        this->contador++;
    }
    else if (val == 1){
        this->ui->textBrowser->append("Se atendió el pedido: "+dato3+"\n");
    }
    else{}
    if (val != 0){
        this->ui->espera_Label->setText("EN COLA ALISTADOS: "+dato1);
    }
    this->ui->espera_Label_2->setText("PROCESADO: "+dato2);
}

void Ventana_Alistados::on_pushButton_clicked()
{
    this->hide();
}
