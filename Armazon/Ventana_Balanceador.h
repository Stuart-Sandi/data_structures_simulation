#ifndef VENTANA_BALANCEADOR_H
#define VENTANA_BALANCEADOR_H

#include <QMainWindow>

namespace Ui {
class Ventana_Balanceador;
}

class Ventana_Balanceador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Balanceador(QWidget *parent = nullptr);
    ~Ventana_Balanceador();

private:
    Ui::Ventana_Balanceador *ui;
};

#endif // VENTANA_BALANCEADOR_H
