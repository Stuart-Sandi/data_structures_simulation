#ifndef VENTANA_FABRICAB_H
#define VENTANA_FABRICAB_H

#include <QMainWindow>

namespace Ui {
class Ventana_FabricaB;
}

class Ventana_FabricaB : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_FabricaB(QWidget *parent = nullptr);
    ~Ventana_FabricaB();

private:
    Ui::Ventana_FabricaB *ui;
};

#endif // VENTANA_FABRICAB_H
