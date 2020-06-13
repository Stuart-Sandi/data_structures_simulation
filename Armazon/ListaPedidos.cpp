#include "ListaPedidos.h"

void ListaPedidos::insertarCliente(Pedido * nuevo){
    if (this->primerNodo == NULL){
        this->primerNodo = this->ultimoNodo = nuevo;
    }else{
        this->ultimoNodo->next = nuevo;
        nuevo->before = this->ultimoNodo;
        this->ultimoNodo = nuevo;
    }
}

Pedido * ListaPedidos::sacarCliente(QString codigo){
    Pedido * tmp = this->primerNodo;
    while (tmp != NULL){
        if (tmp->numeroPedido == codigo){
            if (tmp == this->primerNodo){
                this->primerNodo = tmp->next;
                this->primerNodo->before = NULL;
            }else if (tmp == this->ultimoNodo){
                this->ultimoNodo = tmp->before;
                this->ultimoNodo->next = NULL;
            }
            else{
                tmp->before->next = tmp->next;
                tmp->next->before =tmp->before;
            }
            tmp->next = NULL;
            tmp->before = NULL;
            return tmp;
        }
        tmp = tmp->next;
    }
    return tmp;
}

void ListaPedidos::cantidadEnLista(){
    Pedido * tmp = this->primerNodo;
    int cont = 0;
    while(tmp != NULL){
        cont++;
        tmp = tmp->next;
    }
    qDebug()<<"Cantidad actual en la lista pedidos: "<<cont;
}
