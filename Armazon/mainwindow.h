#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <funcionesArchivos.h>
#include <Simulacion.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Simulacion * simulacion;
    funcionesArchivos * fA;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_iniciar_Button_clicked();

    void on_ojo_Cola_Pedidos_clicked();

    void on_pausar_Balanceador_clicked();

    void on_ojo_Balanceador_clicked();

    void on_ojo_FabricaA_clicked();

    void on_ojo_FabricaB_clicked();

    void on_ojo_FabricaC_clicked();

    void on_ojo_FabricaComo_clicked();

    void on_ojo_Cola_Alisto_clicked();

    void on_pausar_FabricaA_clicked();

    void on_pausar_FabricaB_clicked();

    void on_pausar_FabricaC_clicked();

    void on_pausar_FabricaComo_clicked();

    void on_ojo_Bodega_clicked();

    void on_ojo_alistador_clicked();

    void on_comboBox_activated(int index);

    void on_pausar_Alistadores_clicked();

    void on_detener_Button_clicked();

    void on_pausar_Bodega_clicked();

    void on_pausar_Alistados_clicked();

    void on_ojo_Alistados_clicked();

    void on_pausar_Facturador_clicked();

    void on_ojo_Facturador_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
