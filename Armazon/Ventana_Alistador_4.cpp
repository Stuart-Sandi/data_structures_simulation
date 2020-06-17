#include "Ventana_Alistador_4.h"
#include "ui_Ventana_Alistador_4.h"

Ventana_Alistador_4::Ventana_Alistador_4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Alistador_4)
{
    ui->setupUi(this);
    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("VENTANA ALISTADOR 4");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(390,390);
    this->contador = 1;
}

Ventana_Alistador_4::~Ventana_Alistador_4()
{
    delete ui;
}

void Ventana_Alistador_4::on_pushButton_clicked()
{
    this->hide();
}

void Ventana_Alistador_4::agregarDatos(QString label1, QString data, QString label2, int val){
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
