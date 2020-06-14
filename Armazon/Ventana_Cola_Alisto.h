#ifndef VENTANA_COLA_ALISTO_H
#define VENTANA_COLA_ALISTO_H

#include <QMainWindow>

namespace Ui {
class Ventana_Cola_Alisto;
}

class Ventana_Cola_Alisto : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Cola_Alisto(QWidget *parent = nullptr);
    ~Ventana_Cola_Alisto();

private:
    Ui::Ventana_Cola_Alisto *ui;
};

#endif // VENTANA_COLA_ALISTO_H
