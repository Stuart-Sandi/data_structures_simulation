#ifndef VENTANA_FABRICAA_H
#define VENTANA_FABRICAA_H

#include <QMainWindow>

namespace Ui {
class Ventana_FabricaA;
}

class Ventana_FabricaA : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_FabricaA(QWidget *parent = nullptr);
    ~Ventana_FabricaA();

private:
    Ui::Ventana_FabricaA *ui;
};

#endif // VENTANA_FABRICAA_H
