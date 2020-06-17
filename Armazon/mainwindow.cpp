#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //PROPIEDADES DE LA VENTANA PRINCIPAL
    this->setWindowTitle("ARMAZON SIMULATION");
    this->setWindowFlags(Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setFixedSize(1300,687);

    simulacion = new Simulacion();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_iniciar_Button_clicked()
{
    /*
     * ESTE BOTON ES EL ENCARGADO DE INICIAR LA SIMULACION LLAMANDO A LA FUNCION QUE INICIA LOS HILOS
     */
    this->ui->iniciar_Button->setEnabled(false);
    this->ui->detener_Button->setEnabled(true);

    //HACE LOS CONNECTS ENTRE HILOS Y VENTANAS


    //################CONNECTS##################
    //VENTANA COLA DE PEDIDOS
    connect(this->simulacion->tColaPedidos,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaPedidos,SLOT(agregarDatos(QString,QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaPedidos,SLOT(agregarDatos2(QString,QString)));

    //VENTANA BALANCEADOR
    connect(this->simulacion->tBalanceador,SIGNAL(datosBalanceador1(QString,QString)),this->simulacion->ventanaBalanceador,SLOT(agregarDatos(QString,QString)));
    connect(this->simulacion->tColaAlisto,SIGNAL(datosBalanceador(QString,QString)),this->simulacion->ventanaBalanceador,SLOT(agregarDatos2(QString,QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaA(QString)),this->simulacion->ventanaFabricaA,SLOT(agregarDatosCola(QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaB(QString)),this->simulacion->ventanaFabricaB,SLOT(agregarDatosCola(QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaC(QString)),this->simulacion->ventanaFabricaC,SLOT(agregarDatosCola(QString)));
    connect(this->simulacion->tBalanceador,SIGNAL(datosColaAB(QString)),this->simulacion->ventanaFabricaComodin,SLOT(agregarDatosCola(QString)));


    //VENTANA FABRICA A
    connect(this->simulacion->tFabricaA,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaA,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaA,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaA, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA FABRICA B
    connect(this->simulacion->tFabricaB,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaB,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaB,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaB, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA FABRICA C
    connect(this->simulacion->tFabricaC,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaC,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaC,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaC, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA FABRICA ESPECIAL
    connect(this->simulacion->tFabricaComodin,SIGNAL(asignarPreparando(QString, int)),this->simulacion->ventanaFabricaComodin,SLOT(agregarDatosArticuloPreparando(QString, int)));
    connect(this->simulacion->tFabricaComodin,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaFabricaComodin, SLOT(agregarDatosCola(QString,QString)));

    //VENTANA COLA ALISTO
    connect(this->simulacion->tColaAlisto,SIGNAL(datosCola(QString,QString)),this->simulacion->ventanaColaAlisto,SLOT(agregarDatos(QString,QString)));
    connect(this->simulacion->tBodega,SIGNAL(datosAlisto(QString,QString)),this->simulacion->ventanaColaAlisto,SLOT(agregarDatos2(QString,QString)));

    //VENTANA BODEGA
    connect(this->simulacion->tBodega,SIGNAL(datosBodega(QString,QString,QString)),this->simulacion->ventanaBodega,SLOT(asignarDatos(QString,QString,QString)));

    //VENTANA ALISTADORES
    connect(this->simulacion->tAlistador1,SIGNAL(datosAlistador(QString,QString,QString)),this->simulacion->ventanaAlistador1,SLOT(agregarDatos(QString,QString,QString)));
    connect(this->simulacion->tAlistador2,SIGNAL(datosAlistador(QString,QString,QString)),this->simulacion->ventanaAlistador2,SLOT(agregarDatos(QString,QString,QString)));
    connect(this->simulacion->tAlistador3,SIGNAL(datosAlistador(QString,QString,QString)),this->simulacion->ventanaAlistador3,SLOT(agregarDatos(QString,QString,QString)));
    connect(this->simulacion->tAlistador4,SIGNAL(datosAlistador(QString,QString,QString)),this->simulacion->ventanaAlistador4,SLOT(agregarDatos(QString,QString,QString)));
    connect(this->simulacion->tAlistador5,SIGNAL(datosAlistador(QString,QString,QString)),this->simulacion->ventanaAlistador5,SLOT(agregarDatos(QString,QString,QString)));
    connect(this->simulacion->tAlistador6,SIGNAL(datosAlistador(QString,QString,QString)),this->simulacion->ventanaAlistador6,SLOT(agregarDatos(QString,QString,QString)));

    //VENTANA ALISTADOS
    connect(this->simulacion->tEmpacador,SIGNAL(datosCola(QString,QString,QString,int)),this->simulacion->ventanaAlistados,SLOT(agregarDatosCola(QString,QString,QString,int)));

    //VENTANA FACTURACION
    connect(this->simulacion->tRobot,SIGNAL(datosCola(QString,QString,QString,int)),this->simulacion->ventanaFacturador,SLOT(agregarDatosCola(QString,QString,QString,int)));

    //############INICIA LA SIMULACION############
    this->simulacion->iniciarSimulacion();
}

void MainWindow::on_ojo_Cola_Pedidos_clicked()
{
    this->simulacion->ventanaPedidos->show();
}

void MainWindow::on_pausar_Balanceador_clicked()
{
    this->simulacion->tBalanceador->pausa = !this->simulacion->tBalanceador->pausa;
    if (this->simulacion->tBalanceador->pausa == false){
        this->ui->pausar_Balanceador->setText("Pausar");
    }else{
        this->ui->pausar_Balanceador->setText("Continuar");
    }
}

void MainWindow::on_ojo_Balanceador_clicked()
{
    this->simulacion->ventanaBalanceador->show();
}

void MainWindow::on_ojo_FabricaA_clicked()
{
    this->simulacion->ventanaFabricaA->show();
}

void MainWindow::on_ojo_FabricaB_clicked()
{
    this->simulacion->ventanaFabricaB->show();
}

void MainWindow::on_ojo_FabricaC_clicked()
{
    this->simulacion->ventanaFabricaC->show();
}

void MainWindow::on_ojo_FabricaComo_clicked()
{
    this->simulacion->ventanaFabricaComodin->show();
}

void MainWindow::on_ojo_Cola_Alisto_clicked()
{
    this->simulacion->ventanaColaAlisto->show();
}

void MainWindow::on_pausar_FabricaA_clicked()
{
    this->simulacion->tFabricaA->pausa = !this->simulacion->tFabricaA->pausa;
    if (this->simulacion->tFabricaA->pausa == false){
        this->ui->pausar_FabricaA->setText("Pausar");
    }else{
        this->ui->pausar_FabricaA->setText("Continuar");
    }
}

void MainWindow::on_pausar_FabricaB_clicked()
{
    this->simulacion->tFabricaB->pausa = !this->simulacion->tFabricaB->pausa;
    if (this->simulacion->tFabricaB->pausa == false){
        this->ui->pausar_FabricaB->setText("Pausar");
    }else{
        this->ui->pausar_FabricaB->setText("Continuar");
    }
}

void MainWindow::on_pausar_FabricaC_clicked()
{
    this->simulacion->tFabricaC->pausa = !this->simulacion->tFabricaC->pausa;
    if (this->simulacion->tFabricaC->pausa == false){
        this->ui->pausar_FabricaC->setText("Pausar");
    }else{
        this->ui->pausar_FabricaC->setText("Continuar");
    }
}

void MainWindow::on_pausar_FabricaComo_clicked()
{
    this->simulacion->tFabricaComodin->pausa = !this->simulacion->tFabricaComodin->pausa;
    if (this->simulacion->tFabricaComodin->pausa == false){
        this->ui->pausar_FabricaComo->setText("Pausar");
    }else{
        this->ui->pausar_FabricaComo->setText("Continuar");
    }
}

void MainWindow::on_ojo_Bodega_clicked()
{
    this->simulacion->ventanaBodega->show();
}

void MainWindow::on_ojo_alistador_clicked()
{
    int i = this->ui->comboBox->currentIndex();
    switch (i) {
        case 0:
            QMessageBox::critical(this,"Error","Debe seleccionar un alistador del ComboBox");
            break;

        case 1:
            this->simulacion->ventanaAlistador1->show();
            break;

        case 2:
            this->simulacion->ventanaAlistador2->show();
            break;

        case 3:
            this->simulacion->ventanaAlistador3->show();
            break;

        case 4:
            this->simulacion->ventanaAlistador4->show();
            break;

        case 5:
            this->simulacion->ventanaAlistador5->show();
            break;

        case 6:
            this->simulacion->ventanaAlistador6->show();
            break;
    }

}

void MainWindow::on_comboBox_activated(int index)
{
    bool validar = false;
    switch (index) {
        case 0:
            this->ui->pausar_Alistadores->setEnabled(false);
            break;

        case 1:
            this->ui->pausar_Alistadores->setEnabled(true);
            validar = this->simulacion->tAlistador1->pausa;
            break;

        case 2:
            this->ui->pausar_Alistadores->setEnabled(true);
            validar = this->simulacion->tAlistador2->pausa;
            break;

        case 3:
            this->ui->pausar_Alistadores->setEnabled(true);
            validar = this->simulacion->tAlistador3->pausa;
            break;

        case 4:
            this->ui->pausar_Alistadores->setEnabled(true);
            validar = this->simulacion->tAlistador4->pausa;
            break;

        case 5:
            this->ui->pausar_Alistadores->setEnabled(true);
            validar = this->simulacion->tAlistador5->pausa;
            break;

        case 6:
            this->ui->pausar_Alistadores->setEnabled(true);
            validar = this->simulacion->tAlistador6->pausa;
            break;
    }
    if (validar){
        this->ui->pausar_Alistadores->setText("Continuar");
    }
    else{
        this->ui->pausar_Alistadores->setText("Pausar");
    }
}

void MainWindow::on_pausar_Alistadores_clicked()
{
    int i = this->ui->comboBox->currentIndex();
    bool validar = false;
    switch (i) {
        case 0:
            QMessageBox::critical(this,"Error","Debe seleccionar un alistador del ComboBox");
            break;

        case 1:
            this->simulacion->tAlistador1->pausa = !this->simulacion->tAlistador1->pausa;
            validar = this->simulacion->tAlistador1->pausa;
            break;

        case 2:
            this->simulacion->tAlistador2->pausa = !this->simulacion->tAlistador2->pausa;
            validar = this->simulacion->tAlistador2->pausa;
            break;

        case 3:
            this->simulacion->tAlistador3->pausa = !this->simulacion->tAlistador3->pausa;
            validar = this->simulacion->tAlistador3->pausa;
            break;

        case 4:
            this->simulacion->ventanaAlistador4->show();
            this->simulacion->tAlistador4->pausa = !this->simulacion->tAlistador4->pausa;
            validar = this->simulacion->tAlistador4->pausa;
            break;

        case 5:
            this->simulacion->tAlistador5->pausa = !this->simulacion->tAlistador5->pausa;
            validar = this->simulacion->tAlistador5->pausa;
            break;

        case 6:
            this->simulacion->tAlistador6->pausa = !this->simulacion->tAlistador6->pausa;
            validar = this->simulacion->tAlistador6->pausa;
            break;
    }
    if (validar){
        this->ui->pausar_Alistadores->setText("Continuar");
    }
    else{
        this->ui->pausar_Alistadores->setText("Pausar");
    }
}

void MainWindow::on_detener_Button_clicked()
{
    QMessageBox::information(0,"¡¡GRACIAS!!","Gracias por utilizar nuestro software.\n ¡¡Vuelva pronto!!");
    this->simulacion->detenerSimulacion();
    this->close();
}

void MainWindow::on_pausar_Bodega_clicked()
{
    this->simulacion->tBodega->pausa = !this->simulacion->tBodega->pausa;
    if (this->simulacion->tBodega->pausa == false){
        this->ui->pausar_Bodega->setText("Pausar");
    }else{
        this->ui->pausar_Bodega->setText("Continuar");
    }
}

void MainWindow::on_pausar_Alistados_clicked()
{
    this->simulacion->tEmpacador->pausa = !this->simulacion->tEmpacador->pausa;
    if (this->simulacion->tEmpacador->pausa == false){
        this->ui->pausar_Alistados->setText("Pausar");
    }else{
        this->ui->pausar_Alistados->setText("Continuar");
    }
}

void MainWindow::on_ojo_Alistados_clicked()
{
    this->simulacion->ventanaAlistados->show();
}

void MainWindow::on_pausar_Facturador_clicked()
{
    this->simulacion->tRobot->pausa = !this->simulacion->tRobot->pausa;
    if (this->simulacion->tRobot->pausa == false){
        this->ui->pausar_Facturador->setText("Pausar");
    }else{
        this->ui->pausar_Facturador->setText("Continuar");
    }
}

void MainWindow::on_ojo_Facturador_clicked()
{
    this->simulacion->ventanaFacturador->show();
}
