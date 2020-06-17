#ifndef VENTANA_ALISTADOS_H
#define VENTANA_ALISTADOS_H

#include <QMainWindow>

namespace Ui {
class Ventana_Alistados;
}

class Ventana_Alistados : public QMainWindow
{
    Q_OBJECT

public:
    int contador;
    explicit Ventana_Alistados(QWidget *parent = nullptr);
    ~Ventana_Alistados();

public slots:
    void agregarDatosCola(QString,QString,QString,int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Alistados *ui;
};

#endif // VENTANA_ALISTADOS_H
