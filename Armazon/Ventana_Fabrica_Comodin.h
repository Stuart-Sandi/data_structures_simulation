#ifndef VENTANA_FABRICA_COMODIN_H
#define VENTANA_FABRICA_COMODIN_H

#include <QMainWindow>

namespace Ui {
class Ventana_Fabrica_Comodin;
}

class Ventana_Fabrica_Comodin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Fabrica_Comodin(QWidget *parent = nullptr);
    ~Ventana_Fabrica_Comodin();

private:
    Ui::Ventana_Fabrica_Comodin *ui;
};

#endif // VENTANA_FABRICA_COMODIN_H
