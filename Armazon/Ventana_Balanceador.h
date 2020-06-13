#ifndef VENTANA_BALANCEADOR_H
#define VENTANA_BALANCEADOR_H

#include <QMainWindow>

namespace Ui {
class Ventana_Balanceador;
}

class Ventana_Balanceador : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Balanceador(QWidget *parent = nullptr);
    ~Ventana_Balanceador();

public slots:
    void agregarDatos(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA
    void agregarDatos2(QString,QString);//ASIGNA LOS DATOS DE CANTIDAD EN COLA Y CANTIDAD DESENCOLADOS

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Balanceador *ui;
};

#endif // VENTANA_BALANCEADOR_H
