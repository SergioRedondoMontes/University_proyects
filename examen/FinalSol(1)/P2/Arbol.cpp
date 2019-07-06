/////////////////////////////////////
// Algoritmos y Estructuras de Datos
// Solución examen final CO 2019
// Autos: Leila S. Shafti
/////////////////////////////////////

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
	delete this;  // OJO: es mejor quitar esta línea y ponerlo en el programa main donde se reserva memoria para la raiz, aunque esto también funciona correctamente. 
}



// Precondición: se supone que no hay valores repetidos
// el examen dice que no have falta escribir assert para comprobar la precondición 
Arbol * Arbol::buscar(int valor) {
	if (this == NULL) return NULL;
	if (this->valor == valor) return this;

	Arbol *res = this->izq->buscar(valor);
	if (res != NULL) return res;
	res = this->der->buscar(valor);
	if (res != NULL) return res;
	return NULL;
}

bool Arbol::Insertar(int valor, int padre, int orientacion) {
	Arbol *Arbolpadre = this->buscar(padre);
	if (Arbolpadre == NULL)
		return false;

	if (orientacion == HIJO_IZQ && Arbolpadre->izq == NULL)
	{
		Arbol *nuevoArbol = new Arbol(valor);
		Arbolpadre->izq = nuevoArbol;
		return true;
	}
	else if (orientacion == HIJO_DER && Arbolpadre->der == NULL)
	{
		Arbol *nuevoArbol = new Arbol(valor);
		Arbolpadre->der = nuevoArbol;
		return true;
	}
	else
		return false;

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

