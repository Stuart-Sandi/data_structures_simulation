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
    explicit Ventana_Pedidos(QWidget *parent = nullptr);
    ~Ventana_Pedidos();

public slots:
    void agregarDatos(QString,QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Pedidos *ui;
};

#endif // VENTANA_PEDIDOS_H
