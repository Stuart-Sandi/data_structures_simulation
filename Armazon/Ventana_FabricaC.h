#ifndef VENTANA_FABRICAC_H
#define VENTANA_FABRICAC_H

#include <QMainWindow>

namespace Ui {
class Ventana_FabricaC;
}

class Ventana_FabricaC : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_FabricaC(QWidget *parent = nullptr);
    ~Ventana_FabricaC();

public slots:
    void agregarDatosCola(QString);//ACTUALIZA EL ENCOLAMIENTO
    void agregarDatosArticuloPreparando(QString, int);
    void agregarDatosCola(QString,QString);//ACTUALIZA LOS DATOS DE LA COLA EN LA VENTANA

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_FabricaC *ui;
};

#endif // VENTANA_FABRICAC_H
