#ifndef VENTANA_ALISTADOR_6_H
#define VENTANA_ALISTADOR_6_H

#include <QMainWindow>

namespace Ui {
class Ventana_Alistador_6;
}

class Ventana_Alistador_6 : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Alistador_6(QWidget *parent = nullptr);
    ~Ventana_Alistador_6();

public slots:
    void agregarDatos(QString,QString,QString,int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Alistador_6 *ui;
};

#endif // VENTANA_ALISTADOR_6_H
