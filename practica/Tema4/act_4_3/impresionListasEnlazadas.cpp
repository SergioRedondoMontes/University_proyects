#include "impresionListasEnlazadas.h"
#include <iostream>

void imprimirListaEnlazada(ListaEnlazada *lista)
{
    assert(lista != NULL);

    int size = lista->getN();
    if (size == 0)
    {
        std::cout << "lista vacia" << std::endl;
    }
    else
    {
        if (size > 20)
        {
            std::cout << "Lista demasiado alrga" << std::endl;
        }
        else
        {
            std::cout << lista->getValor(0) << " ";
            for (int i = 1; i < size; i++)
            {
                std::cout << "," << lista->getValor(i) << " ";
            }
            std::cout << std::endl;
        }
    }
}
