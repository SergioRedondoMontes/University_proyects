#include "impresionListasEnlazadas.h"
#include <iostream>

void imprimirListaEnlazada(ListaEnlazada *lista){
    for(int i = 0; i < lista->getN(); i++){
        std::cout << lista->getValor(i) << " ";
    }
    std::cout << std::endl;
}