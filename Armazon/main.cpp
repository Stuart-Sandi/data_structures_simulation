#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //VALIDA SI LAS LISTAS DE CLIENTES Y ARTICULOS ESTAN BIEN PARA INICIAR LA SIMULACION
    int validar = w.simulacion->cargarListas();
    if (validar == 1){
        QMessageBox::critical(0,"Error","La lista de clientes es incorrecta, favor revisar y volver a abrir el programa");
        w.close();
    }else if (validar == 2){
        QMessageBox::critical(0,"Error","La lista de articulos es incorrecta, favor revisar y volver a abrir el programa");
        w.close();
    }else{
        QMessageBox::information(0,"Informacion","La lista de clientes y articulos se cargaron satisfactoriamente");
    }

    return a.exec();
}
