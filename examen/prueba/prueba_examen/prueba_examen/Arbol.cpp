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


