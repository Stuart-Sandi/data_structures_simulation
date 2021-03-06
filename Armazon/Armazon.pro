QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ColaArticulos.cpp \
    ColaPedidos.cpp \
    ListaArticulos.cpp \
    ListaClientes.cpp \
    Simulacion.cpp \
    ThreadAlistador.cpp \
    ThreadBalanceador.cpp \
    ThreadBodega.cpp \
    ThreadColaAlisto.cpp \
    ThreadColaPedidos.cpp \
    ThreadEmpacador.cpp \
    ThreadFabrica.cpp \
    ThreadFabricaEspecial.cpp \
    Ventana_Alistador_1.cpp \
    Ventana_Alistador_2.cpp \
    Ventana_Alistador_3.cpp \
    Ventana_Alistador_4.cpp \
    Ventana_Alistador_5.cpp \
    Ventana_Alistador_6.cpp \
    ThreadRobotFacturador.cpp \
    Ventana_Alistados.cpp \
    Ventana_Balanceador.cpp \
    Ventana_Bodega.cpp \
    Ventana_Cola_Alisto.cpp \
    Ventana_FabricaA.cpp \
    Ventana_FabricaB.cpp \
    Ventana_FabricaC.cpp \
    Ventana_Fabrica_Comodin.cpp \
    Ventana_Facturador.cpp \
    Ventana_Pedidos.cpp \
    funcionesArchivos.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Cliente.h \
    ColaArticulos.h \
    ColaPedidos.h \
    ListaArticulos.h \
    ListaClientes.h \
    Simulacion.h \
    ThreadAlistador.h \
    ThreadBalanceador.h \
    ThreadBodega.h \
    ThreadColaAlisto.h \
    ThreadColaPedidos.h \
    ThreadEmpacador.h \
    ThreadFabrica.h \
    ThreadFabricaEspecial.h \
    ThreadRobotFacturador.h \
    Ventana_Alistador_1.h \
    Ventana_Alistador_2.h \
    Ventana_Alistador_3.h \
    Ventana_Alistador_4.h \
    Ventana_Alistador_5.h \
    Ventana_Alistador_6.h \
    Ventana_Alistados.h \
    Ventana_Balanceador.h \
    Ventana_Bodega.h \
    Ventana_Cola_Alisto.h \
    Ventana_FabricaA.h \
    Ventana_FabricaB.h \
    Ventana_FabricaC.h \
    Ventana_Fabrica_Comodin.h \
    Ventana_Facturador.h \
    Ventana_Pedidos.h \
    articulo.h \
    funcionesArchivos.h \
    mainwindow.h \
    pedido.h

FORMS += \
    Ventana_Alistador_1.ui \
    Ventana_Alistador_2.ui \
    Ventana_Alistador_3.ui \
    Ventana_Alistador_4.ui \
    Ventana_Alistador_5.ui \
    Ventana_Alistador_6.ui \
    Ventana_Alistados.ui \
    Ventana_Balanceador.ui \
    Ventana_Bodega.ui \
    Ventana_Cola_Alisto.ui \
    Ventana_FabricaA.ui \
    Ventana_FabricaB.ui \
    Ventana_FabricaC.ui \
    Ventana_Fabrica_Comodin.ui \
    Ventana_Facturador.ui \
    Ventana_Pedidos.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc
