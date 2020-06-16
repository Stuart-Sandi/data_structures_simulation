#ifndef VENTANA_BODEGA_H
#define VENTANA_BODEGA_H

#include <QMainWindow>

namespace Ui {
class Ventana_Bodega;
}

class Ventana_Bodega : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Bodega(QWidget *parent = nullptr);
    ~Ventana_Bodega();

public slots:
    void asignarDatos(QString,QString,QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_Bodega *ui;
};

#endif // VENTANA_BODEGA_H
