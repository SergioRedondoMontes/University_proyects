#include "Pila.h"
#include "iostream"

/* mete un elemento en la cima de la pila */
void Pila::push(int nuevovalor)
{
    insertar(0, nuevovalor);
}

/* devuelve el elemento de la cima de la pila y lo borra de ahí */
int Pila::pop()
{
    assert(!isVacia());
    int valor;
    valor = verCima();
    eliminar(0);
    return valor;
}

/* como pop, pero sin borrar el elemento */
int Pila::verCima()
{
    assert(!isVacia());
    return getValor(0);
}

/* devuelve true o false según la pila esté vacía o no. Pop y verCima tendrán la
precondición de que la pila no esté vacía.  */
bool Pila::isVacia()
{
    return getN() == 0;
}
