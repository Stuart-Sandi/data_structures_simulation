#ifndef NODOCOLAPEDIDO_H
#define NODOCOLAPEDIDO_H
#include <pedido.h>

struct NodoPedido{
    NodoPedido * next;
    Pedido * pedido;
    NodoPedido(Pedido * pPedido){
        this->pedido = pPedido;
        this->next = NULL;
    }
};

#endif // NODOCOLAPEDIDO_H
