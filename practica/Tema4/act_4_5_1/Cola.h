#include "ListaEnlazada.h"

class Cola : public ListaEnlazada
{
private:
  /* data */
public:
  Cola(/* args */);
  void push(int nuevoValor); /* mete un elemento en la cima de la pila */
  int pop();                 /* devuelve el elemento de la cima de la pila y lo borra de ahí */
  int verCima();             /* como pop, pero sin borrar el elemento */
  bool isVacia();            /* devuelve true o false según la pila esté vacía o no. Pop y verCima tendrán la
precondición de que la pila no esté vacía.  */
  ~Cola();
};
