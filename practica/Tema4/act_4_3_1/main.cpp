#include "iostream"
//#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
using namespace std;

int main()
{

	// Creamos una lista que nos servir� para las pruebas
	ListaEnlazada lista;

	lista.insertar(0, 1);
	lista.insertar(1, 2);
	lista.insertar(2, 3);
	lista.insertar(3, 4);
	lista.invertir();
	imprimirListaEnlazada(&lista);
	return 0;
}
