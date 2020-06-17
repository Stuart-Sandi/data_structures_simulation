#ifndef VENTANA_FACTURADOR_H
#define VENTANA_FACTURADOR_H

#include <QMainWindow>

namespace Ui {
class Ventana_Facturador;
}

class Ventana_Facturador : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Facturador(QWidget *parent = nullptr);
    ~Ventana_Facturador();

public slots:
    void agregarDatosCola(QString,QString,QString,int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Facturador *ui;
};

#endif // VENTANA_FACTURADOR_H
