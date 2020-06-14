#ifndef VENTANA_COLA_ALISTO_H
#define VENTANA_COLA_ALISTO_H

#include <QMainWindow>

namespace Ui {
class Ventana_Cola_Alisto;
}

class Ventana_Cola_Alisto : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Cola_Alisto(QWidget *parent = nullptr);
    ~Ventana_Cola_Alisto();

public slots:
    void agregarDatos(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA
    void agregarDatos2(QString,QString);//ASIGNA LOS DATOS DE CANTIDAD EN COLA Y CANTIDAD DESENCOLADOS

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Cola_Alisto *ui;
};

#endif // VENTANA_COLA_ALISTO_H
