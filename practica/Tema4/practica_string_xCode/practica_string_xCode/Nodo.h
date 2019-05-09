#include "Mystr.h"
// Estructura que representa un nodo de una lista enlazada
struct Nodo
{
	Mystr elemento; // El elemento que guarda el nodo
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
	Nodo *anteriorNodo; // Puntero al anterior nodo de la lista enlazada
};
