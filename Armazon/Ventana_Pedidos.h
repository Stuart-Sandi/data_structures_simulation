#ifndef VENTANA_PEDIDOS_H
#define VENTANA_PEDIDOS_H

#include <QMainWindow>

namespace Ui {
class Ventana_Pedidos;
}

class Ventana_Pedidos : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Pedidos(QWidget *parent = nullptr);
    ~Ventana_Pedidos();

public slots:
    void agregarDatos(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA
    void agregarDatos2(QString,QString);//ASIGNA LOS DATOS DE CANTIDAD EN COLA Y CANTIDAD DESENCOLADOS

private slots:
    void on_pushButton_clicked();


private:
    Ui::Ventana_Pedidos *ui;
};

#endif // VENTANA_PEDIDOS_H
