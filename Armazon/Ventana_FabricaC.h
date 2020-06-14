#ifndef VENTANA_FABRICAC_H
#define VENTANA_FABRICAC_H

#include <QMainWindow>

namespace Ui {
class Ventana_FabricaC;
}

class Ventana_FabricaC : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_FabricaC(QWidget *parent = nullptr);
    ~Ventana_FabricaC();

private:
    Ui::Ventana_FabricaC *ui;
};

#endif // VENTANA_FABRICAC_H
