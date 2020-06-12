#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>

#include <Simulacion.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Simulacion * simulacion;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_iniciar_Button_clicked();

    void on_ojo_Cola_Pedidos_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
