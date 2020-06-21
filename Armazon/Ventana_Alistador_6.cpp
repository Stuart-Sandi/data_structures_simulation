#include "Ventana_Alistador_6.h"
#include "ui_Ventana_Alistador_6.h"

Ventana_Alistador_6::Ventana_Alistador_6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Alistador_6)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA ALISTADOR 6");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
    this->setWindowIcon( QIcon( ":/Imagenes/alistador_logo.png" ) );
    this->contador = 1;
}

Ventana_Alistador_6::~Ventana_Alistador_6()
{
    delete ui;
}

void Ventana_Alistador_6::on_pushButton_clicked()
{
    this->hide();
}

void Ventana_Alistador_6::agregarDatos(QString label1, QString data, QString label2, int val){
    if (data != ""){
        if (val == 0){
            this->ui->textBrowser->append(QString::number(this->contador)+"/ "+data+"\n");
            this->contador++;
        }else if (val == 1){
            this->ui->textBrowser->append(data+"\n\n");
        }else{}
    }
    this->ui->espera_Label->setText("PROCESANDO: "+label1);
    this->ui->espera_Label_2->setText("TOTAL PROCESADOS: "+label2);
}
