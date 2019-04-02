#include "Cola.h"
#include "iostream"

Cola::Cola(/* args */)
{
}
/* mete un elemento en la cima de la pila */
void Cola::push(int nuevovalor)
{
    insertar(0, nuevovalor);
}

/* devuelve el elemento de la cima de la pila y lo borra de ahí */
int Cola::pop()
{
    assert(!isVacia());
    int valor, n;
    n = getN() - 1;
    valor = verCima();
    eliminar(n);
    return valor;
}

/* como pop, pero sin borrar el elemento */
int Cola::verCima()
{
    assert(!isVacia());
    return getValor(getN() - 1);
}

/* devuelve true o false según la pila esté vacía o no. Pop y verCima tendrán la
precondición de que la pila no esté vacía.  */
bool Cola::isVacia()
{
    return getN() == 0;
}

Cola::~Cola()
{
}
