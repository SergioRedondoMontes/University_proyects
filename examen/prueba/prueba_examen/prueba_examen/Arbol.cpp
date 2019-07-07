#include "Arbol.h"

Arbol::Arbol(int valor) {
	this->valor = valor;
	izq = NULL;
	der = NULL;
}


Arbol::~Arbol() {
	if (this != NULL) this->deleteArbol();
}

void Arbol::deleteArbol()
{
	if (this->izq != NULL) this->izq->deleteArbol();
	if (this->der != NULL) this->der->deleteArbol();
	delete this;
}

/*prueba*/

Arbol *Arbol::buscarValor(Arbol *arbol,int valor){
    if(arbol == NULL)return  NULL;
    if(arbol->valor == valor) return arbol;
    
    Arbol *res = arbol->izq->buscarValor(arbol->izq, valor);
    if(res != NULL) return res;
    res = arbol->der->buscarValor(arbol->der, valor);
    if(res != NULL) return res;
    
    return NULL;
}

bool Arbol::Insertar(int valorNuevo, int valorPadre, int Orientacion)
{
    Arbol *padre = this->buscarValor(this,valorPadre);
    if(padre == NULL){
        return  false;
    }
    
    if(Orientacion == HIJO_IZQ && padre->izq == NULL){
        Arbol *nuevoArbol = new Arbol(valorNuevo);
        padre->izq = nuevoArbol;
        return  true;
    }else if(Orientacion == HIJO_DER && padre->der == NULL)
    {
        Arbol *nuevoArbol = new Arbol(valorNuevo);
        padre->der = nuevoArbol;
        return  true;
    }
    else{
        return false;
    }
}



bool Arbol::espejo(Arbol *I, Arbol *D) {
    if (I == NULL && D == NULL)
        return true;
    if (I != NULL && D != NULL && espejo(I->izq, D->der) && espejo(I->der, D->izq))
        return true;
    else return false;
}

bool Arbol::Simetrico() {
    return espejo(this->izq, this->der);
}

