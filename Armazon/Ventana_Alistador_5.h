#ifndef VENTANA_ALISTADOR_5_H
#define VENTANA_ALISTADOR_5_H

#include <QMainWindow>

namespace Ui {
class Ventana_Alistador_5;
}

class Ventana_Alistador_5 : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Alistador_5(QWidget *parent = nullptr);
    ~Ventana_Alistador_5();

public slots:
    void agregarDatos(QString,QString,QString,int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Alistador_5 *ui;
};

#endif // VENTANA_ALISTADOR_5_H
