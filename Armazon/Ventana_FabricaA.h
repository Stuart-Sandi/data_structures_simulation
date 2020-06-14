#ifndef VENTANA_FABRICAA_H
#define VENTANA_FABRICAA_H

#include <QMainWindow>

namespace Ui {
class Ventana_FabricaA;
}

class Ventana_FabricaA : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_FabricaA(QWidget *parent = nullptr);
    ~Ventana_FabricaA();

public slots:
    void agregarDatosCola(QString);//ACTUALIZA EL ENCOLAMIENTO
    void agregarDatosArticuloPreparando(QString, int);
    void agregarDatosCola(QString,QString);//ACTUALIZA LOS DATOS DE LA COLA EN LA VENTANA

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_FabricaA *ui;
};

#endif // VENTANA_FABRICAA_H
