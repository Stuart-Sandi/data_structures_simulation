#ifndef VENTANA_FABRICAB_H
#define VENTANA_FABRICAB_H

#include <QMainWindow>

namespace Ui {
class Ventana_FabricaB;
}

class Ventana_FabricaB : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_FabricaB(QWidget *parent = nullptr);
    ~Ventana_FabricaB();

public slots:
    void agregarDatosCola(QString);//ACTUALIZA EL ENCOLAMIENTO
    void agregarDatosArticuloPreparando(QString, int);
    void agregarDatosCola(QString,QString);//ACTUALIZA LOS DATOS DE LA COLA EN LA VENTANA

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_FabricaB *ui;
};

#endif // VENTANA_FABRICAB_H
