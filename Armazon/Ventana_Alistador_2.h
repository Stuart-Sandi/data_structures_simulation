#ifndef VENTANA_ALISTADOR_2_H
#define VENTANA_ALISTADOR_2_H

#include <QMainWindow>

namespace Ui {
class Ventana_Alistador_2;
}

class Ventana_Alistador_2 : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Alistador_2(QWidget *parent = nullptr);
    ~Ventana_Alistador_2();

public slots:
    void agregarDatos(QString,QString,QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Alistador_2 *ui;
};

#endif // VENTANA_ALISTADOR_2_H
