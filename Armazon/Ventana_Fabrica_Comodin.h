#ifndef VENTANA_FABRICA_COMODIN_H
#define VENTANA_FABRICA_COMODIN_H

#include <QMainWindow>

namespace Ui {
class Ventana_Fabrica_Comodin;
}

class Ventana_Fabrica_Comodin : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Fabrica_Comodin(QWidget *parent = nullptr);
    ~Ventana_Fabrica_Comodin();

public slots:
    void agregarDatosCola(QString);//ACTUALIZA EL ENCOLAMIENTO
    void agregarDatosArticuloPreparando(QString, int);
    void agregarDatosCola(QString,QString);//ACTUALIZA LOS DATOS DE LA COLA EN LA VENTANA

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Fabrica_Comodin *ui;
};

#endif // VENTANA_FABRICA_COMODIN_H
