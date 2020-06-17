#ifndef VENTANA_ALISTADOR_4_H
#define VENTANA_ALISTADOR_4_H

#include <QMainWindow>

namespace Ui {
class Ventana_Alistador_4;
}

class Ventana_Alistador_4 : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Alistador_4(QWidget *parent = nullptr);
    ~Ventana_Alistador_4();

public slots:
    void agregarDatos(QString,QString,QString,int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Alistador_4 *ui;
};

#endif // VENTANA_ALISTADOR_4_H
