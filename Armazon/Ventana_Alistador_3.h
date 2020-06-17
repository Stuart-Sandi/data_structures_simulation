#ifndef VENTANA_ALISTADOR_3_H
#define VENTANA_ALISTADOR_3_H

#include <QMainWindow>

namespace Ui {
class Ventana_Alistador_3;
}

class Ventana_Alistador_3 : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Alistador_3(QWidget *parent = nullptr);
    ~Ventana_Alistador_3();

public slots:
    void agregarDatos(QString,QString,QString,int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Alistador_3 *ui;
};

#endif // VENTANA_ALISTADOR_3_H
