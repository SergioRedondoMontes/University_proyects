
#include "ListaContigua.h"
#include "impresionListasContiguas.h"

void imprimirListaContigua (ListaContigua *lista){
    for(int i = 0; i < lista->getN(); i++)
    {
        std::cout << lista->getValor(i) << std::endl;
    }
    
}