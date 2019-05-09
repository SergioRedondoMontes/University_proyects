#include "ListaEnlazada.h"
#include "cassert"
using namespace std;

Nodo * ListaEnlazada::getNodo (int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion <= n-1);

	Nodo *resultado = NULL; // Aquí guardaremos el puntero al nodo resultado 
	
	// Si el nodo que queremos buscar es igual que el último accedido
	if (posicion == posicionUltimoNodoAccedido && posicionUltimoNodoAccedido!=-1) 
		resultado=punteroUltimoNodoAccedido;

	// Si el nodo que queremos buscar es el siguiente al último accedido
	else if (posicion == posicionUltimoNodoAccedido+1 && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido->siguienteNodo;
	}

	// Si el nodo que queremos buscar es el anterior al último accedido
	else if (posicion == posicionUltimoNodoAccedido - 1 && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido->anteriorNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a él iterando hacia delante	
	else if (posicion <= n / 2) {
		resultado = lista; // Hacemos que el resultado apunte al primer nodo
		for (int i = 0; i < posicion; i++) resultado = resultado->siguienteNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a él iterando hacia atrás	
	else {
		resultado = lista->anteriorNodo; // Hacemos que el resultado apunte al último nodo
		for (int i = n-1; i > posicion; i--) 
			resultado = resultado->anteriorNodo;
	}

	// Actualizamos los atributos del ultimo nodo accedido
	posicionUltimoNodoAccedido = posicion;
	punteroUltimoNodoAccedido = resultado;

	return (resultado);
}

ListaEnlazada::ListaEnlazada() {
	lista = NULL; 
	n=0;
	posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}

int ListaEnlazada::getValor(int posicion) {
	assert(n > 0);
	assert (posicion >= 0 && posicion <= n-1); 
	// Obtenemos el nodo que contiene el elemento
	Nodo *nodoQueContieneResultado = getNodo (posicion);
	return (nodoQueContieneResultado->elemento);
}

void ListaEnlazada::setValor(int posicion, int nuevoValor) {
	assert(n > 0);
	assert (posicion >= 0 && posicion <= n-1); 
	getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN() {
	return (n);
}

void ListaEnlazada::insertar (int posicion, int nuevoValor) {
	assert (posicion >= 0 && posicion <= n); 

	// Creamos el nuevo nodo con el nuevo valor
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->elemento = nuevoValor;

	// Si la lista estaba vacia...
	if (n==0) {
		nuevoNodo->siguienteNodo = nuevoNodo;
		nuevoNodo->anteriorNodo = nuevoNodo;
	}

	// Si la lista no está vacía
	else {
		// Primero obtenemos el nodo que está a continuación del que queremos insertar
		// Nota que, si queremos insertar al final, su siguiente es el primero
		Nodo *nodoSiguiente; // Nodo a continuación del que queremos insertar
		if (posicion == n) nodoSiguiente = lista;
		else nodoSiguiente = getNodo(posicion);

		// Obtenemos el nodo anterior al que queremos insertar
		// Tengamos cuidado en hacerlo en O(1)
		Nodo *nodoAnterior = nodoSiguiente->anteriorNodo;

		// Actualizamos los punteros del nuevo nodo
		nuevoNodo->anteriorNodo=nodoAnterior;
		nuevoNodo->siguienteNodo=nodoSiguiente;

		// Actualizamos los punteros de los dos nodos que rodean al nuevo nodo
		// El puntero siguiente del anterior y el puntero anterior del siguiente apuntarán ambos al nuevo nodo
		nodoSiguiente->anteriorNodo=nuevoNodo;
		nodoAnterior->siguienteNodo=nuevoNodo;
	} // Fin else
	
	// Si estamos insertando al principio de la lista, hay que modificar el puntero a la lista
	if (posicion == 0) lista = nuevoNodo;

	// Incrementamos el numero de elementos
	n++;

	// Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}


void ListaEnlazada::eliminar (int posicion) {
	assert(n > 0);
	assert (posicion >= 0 && posicion <= n-1); 

	// Obtenemos el nodo que queremos eliminar
	Nodo *nodoAEliminar = getNodo(posicion);

	// Si la lista sólo tiene un elemento, actualizamos el atributo lista pues la lista se queda vacia
	if (n == 1) lista = NULL;

	// Si la lista tiene más de un elemento, hacemos el caso general
	else {

		// Obtenemos los dos nodos que le rodean
		Nodo *nodoAnterior = nodoAEliminar->anteriorNodo;
		Nodo *nodoSiguiente = nodoAEliminar->siguienteNodo;
		
		// Modificamos los punteros de cada uno de los dos nodos que rodean al que queremos eliminar
		nodoAnterior->siguienteNodo=nodoSiguiente;
		nodoSiguiente->anteriorNodo=nodoAnterior;
		
		// Si el nodo a eliminar era el 0, tenemos que actualizar el atributo lista
		if (posicion == 0) lista = nodoSiguiente;
	} // Fin else

	// Liberamos la memoria del nodo
	delete(nodoAEliminar);

	// Actualizamos n
	n--;

	// Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar) {
	assert(listaAConcatenar != NULL);

	// Tamaño de la lista a concatenar. Por convención, cuando tenemos
	// dos listas, el tamaño de una es "n" y el de la otra es "m"
	int m = listaAConcatenar->getN();

	// Vamos insertando al final elemento a elemento. Fíjate en que insertar un elemento al final
	// es O(1) porque la lista es circular, y por lo tanto podemos acceder al ultimo nodo en O(1)
	// si hemos hecho bien getNodo()
	// - Complejidad temporal O(m). Las sucesivas llamadas a listaAConcatenar->getValor(i) son O(1)
	//   porque getNodo() recuerda el último nodo accedido
	// - Complejidad espacial O(m), porque creamos m nodos nuevos
	for (int i = 0; i < m; i++) {
		int elementoACopiar = listaAConcatenar->getValor(i);
		insertar(n, elementoACopiar);
	}
}

int ListaEnlazada::buscar(int elementoABuscar) {
	int posicion = 0; // Posición actual en donde buscamos
	bool encontrado = false; // Nos indica si hemos encontrado o no el elemento

	// Buscamos el elemento hasta que lo encontremos o hasta que lleguemos al final
	while (!encontrado && posicion < n) {
		// Cada llamada a getValor() es O(1) porque getNodo() recuerda el último nodo accedido
		if (getValor(posicion) == elementoABuscar) encontrado = true;
		posicion++;
	}

	// Devolvemos la posición si lo hemos encontrado, o -1 en caso contrario
	if (encontrado) return (posicion - 1);
	else return (-1);
}

void ListaEnlazada::ordenarPorMergeSort() {
	// Si la lista está vacía o tiene un solo nodo, ya está ordenada y no hay que hacer nada
	if (n >= 2) ordenarPorMergeSortRecursivo(this);
}

void ListaEnlazada::ordenarPorMergeSortRecursivo(ListaEnlazada *lista) {
	assert(lista != NULL && lista->getN() >= 1);

	// Sólo hacemos algo si la lista tiene al menor 2 nodos 
	// Por tanto no hay llamada recursiva (caso trivial) cuando se tiene 1 nodo o menos
	if (lista->getN() >= 2) {

		// Listas que contendrán a cada una de las dos partes en que dividiremos la lista enlazada
		ListaEnlazada sublista1, sublista2;

		// Dividimos la lista en dos partes y las movemos respectivamente a sublista1 y sublista2
		// Tiempo O(n) espacio O(1), siendo n el tamaño de lista
		repartirPorMergeSort(lista, &sublista1, &sublista2);

		// Hacemos la llamada recursiva para ordenar ambas sublistas por separado
		ordenarPorMergeSortRecursivo(&sublista1);
		ordenarPorMergeSortRecursivo(&sublista2);

		// Combinamos ambas sublistas y dejamos el resultado en "lista"
		// Tiempo O(n) espacio O(1), siendo n la suma de los tamaños de sublista1 y sublista2
		combinarPorMergeSort(&sublista1, &sublista2, lista);

	} // Fin if (lista.getN() >= 2)
}

void ListaEnlazada::repartirPorMergeSort(ListaEnlazada * listaCompleta, ListaEnlazada * sublista1, ListaEnlazada * sublista2)
{
	assert(listaCompleta != NULL && sublista1 != NULL && sublista2 != NULL);
	assert(listaCompleta->getN() >= 2);
	assert(sublista1->getN() == 0 && sublista2->getN() == 0);

	// Guardamos el tamaño de la lista completa
	int n = listaCompleta->getN();

	// Ponemos la primera mitad de listaCompleta en sublista1	
	while (listaCompleta->getN() > n / 2) {
		int elementoAMover = listaCompleta->getValor(0); // Obtenemos el primer elemento
		sublista1->insertar(sublista1->getN(), elementoAMover); // Lo añadimos al final de la sublista
		listaCompleta->eliminar(0); // Lo eliminamos de la listaCompleta
	}

	// Ponemos la segunda mitad de listaCompleta en sublista2
	while (listaCompleta->getN() > 0) {
		int elementoAMover = listaCompleta->getValor(0); // Obtenemos el primer elemento
		sublista2->insertar(sublista2->getN(), elementoAMover); // Lo añadimos al final de la sublista
		listaCompleta->eliminar(0); // Lo eliminamos de la listaCompleta
	}

}

void ListaEnlazada::combinarPorMergeSort(ListaEnlazada * origen1, ListaEnlazada * origen2, ListaEnlazada * destino) {

	assert(origen1 != NULL && origen2 != NULL && destino != NULL);
	assert(origen1->getN() >= 1 && origen2->getN() >= 1);
	assert(destino->getN() == 0);
	assert(isOrdenada(origen1));
	assert(isOrdenada(origen2));

	// Vamos cogiendo el menor elemento del principio de ambas sublistas, hasta que una de ellas quede vacía
	while (origen1->getN() > 0 && origen2->getN() > 0) {

		// Calculamos cuál es la sublista que en su primera posición contiene el menor elemento
		ListaEnlazada *sublistaConMenor;
		if (origen1->getValor(0) <= origen2->getValor(0)) sublistaConMenor = origen1;
		else sublistaConMenor = origen2;

		// Ahora sacamos ese menor elemento de la lista y lo metemos en el resultado
		int menor = sublistaConMenor->getValor(0);
		sublistaConMenor->eliminar(0); // Tenemos que eliminarle para no gastar memoria adicional

		// Insertamos el menor en el resultado
		destino->insertar(destino->getN(), menor);

	}

	// Ahora una de las sublistas está vacía. Averiguamos cuál
	ListaEnlazada *sublistaNoVacia;
	if (origen1->getN() == 0) sublistaNoVacia = origen2;
	else sublistaNoVacia = origen1;

	// Insertamos la no vacía a continuación del resultado 
	// No podemos usar concatenar() porque entonces estaríamos gastando memoria adicional
	while (sublistaNoVacia->getN() > 0) {
		destino->insertar(destino->getN(), sublistaNoVacia->getValor(0));
		sublistaNoVacia->eliminar(0); // Tenemos que ir eliminando a medida que vamos añadiendo en el otro lado, para no gastar memoria adicional
	}

}

bool ListaEnlazada::isOrdenada(ListaEnlazada *lista) {
	assert(lista != NULL);

	// Comparamos cada elemento con el inmediatamente menor, a ver si están bien colocados
	for (int i = 1; i < lista->getN(); i++) {
		// Si el elemento anterior es menor o igual que el posterior, entonces vamos bien.
		// Y al contrario: si el elemento anterior es mayor que el posterior, 
		// entonces están mal colocados y por lo tanto la lista no está bien ordenada.
		// OJO: cada vuelta del bucle for es O(1) en vez de O(n) porque getNodo() (llamado por getValor())
		// recuerda el último nodo accedido, por si el siguiente al que accedemos es el 
		// inmediatamente posterior o anterior (es nuestro caso). Además, para que esto funcione
		// bien, tenemos que llamar primero a getValor(i-1) y luego a getValor(i), no al revés.
		// De este modo nos sale una secuencia continua de posiciones: posiciones 0, 1, 2, 3, 4...
		// En esta secuencia, como hay continuidad, cada acceso se hace en O(1).
		// Pero si lo hiciéramos al revés, tendríamos 1, 0, 2, 1, 3, 2... vemos que entre 0 y 2 o 
		// entre 1 y 3 no hay continuidad, por lo tanto se necesitaría O(n) para calcular el 2 después
		// del 0 y de nuevo O(n) para el 3 después del 1.
		if (lista->getValor(i - 1) > lista->getValor(i)) return(false);
	}
	return(true); // Si hemos llegado hasta aquí es porque está ordenada
}

void ListaEnlazada::ordenarPorQuickSort() {
	// Si la lista está vacía o tiene un solo nodo, ya está ordenada y no hay que hacer nada
	if (n >= 2) ordenarPorQuickSortRecursivo(this);
}

void ListaEnlazada::ordenarPorQuickSortRecursivo(ListaEnlazada *lista) {
	assert(lista != NULL && lista->getN() >= 1);

	int n = lista->getN(); // Tamaño de la lista pasada como parametro

	// Sólo hacemos algo si la lista tiene al menor 2 nodos 
	// Por tanto no hay llamada recursiva (caso trivial) cuando se tiene 1 nodo
	if (n >= 2) {

		// Listas que contendrán a cada una de las dos partes en que dividiremos la lista enlazada
		ListaEnlazada sublista1, sublista2;

		// Calculamos el pivote. Tiempo y espacio O(1)
		float pivote = getPivote(lista);

		// Repartimos los elementos segun el pivote. Tiempo O(n) y espacio O(1)
		repartirPorQuickSort(pivote, lista, &sublista1, &sublista2);

		// Hacemos la llamada recursiva para ordenar ambas sublistas por separado
		ordenarPorQuickSortRecursivo(&sublista1);
		ordenarPorQuickSortRecursivo(&sublista2);

		// Unimos las dos sublistas en la lista de origen. Tiempo y espacio O(1)
		combinarPorQuickSort(&sublista1, &sublista2, lista);

	} // Fin if (lista.getN() >= 2)
}

float ListaEnlazada::getPivote(ListaEnlazada * lista) {
	assert(lista != NULL);
	assert(lista->getN() >= 2);
	// Elegimos el pivote como la media entre el primero y el último
	int primero = lista->getValor(0); // Primer elemento
	int ultimo = lista->getValor(lista->getN() - 1); // Ultimo elemento
	float resultado = (primero + ultimo) / (float)2; // Media entre primero y ultimo. OJO: para que el resultado sea float, hacemos que el denominador lo sea
	return (resultado);
}

void ListaEnlazada::repartirPorQuickSort(float pivote, ListaEnlazada * listaCompleta, ListaEnlazada * sublista1, ListaEnlazada * sublista2) {

	assert(listaCompleta != NULL && sublista1 != NULL && sublista2 != NULL);
	assert(listaCompleta->getN() >= 2);
	assert(sublista1->getN() == 0 && sublista2->getN() == 0);

	// Repartimos los elementos según el pivote. Empezamos por el primero y acabamos por el último.
	// De este modo, el último elemento que metemos es el pivote. Como los elementos que son iguales que el pivote
	// los metemos en la sublista que menos elementos tenga, y como el último que comprobamos es el pivote, de este modo
	// nos aseguramos que la lista que menos elementos tenga al menos tenga tamaño 1
	while (listaCompleta->getN() > 0) {

		// Obtenemos el elemento a repartir y lo eliminamos de la lista
		int elemento = listaCompleta->getValor(0); // Elemento a repartir
		listaCompleta->eliminar(0);

		// Averiguamos en qué sublista meter el elemento
		ListaEnlazada *sublistaEnDondeMeter; // Sublista en donde meteremos el elemento a repartir
		if (elemento < pivote) sublistaEnDondeMeter = sublista1;
		else if (elemento > pivote) sublistaEnDondeMeter = sublista2;
		else { 
			// Si el elemento es igual que el pivote, lo metemos en la sublista que menos elementos tenga
			if (sublista1->getN() < sublista2->getN()) sublistaEnDondeMeter = sublista1;
			else sublistaEnDondeMeter = sublista2;
		}

		// Metemos el elemento al final de la sublista adecuada
		sublistaEnDondeMeter->insertar(sublistaEnDondeMeter->getN(), elemento);
	}

}

void ListaEnlazada::combinarPorQuickSort(ListaEnlazada * origen1, ListaEnlazada * origen2, ListaEnlazada * destino) {
	
	assert(origen1 != NULL && origen2 != NULL && destino != NULL);
	assert(origen1->getN() >= 1 && origen2->getN() >= 1);
	assert(destino->getN() == 0);
	assert(isOrdenada(origen1));
	assert(isOrdenada(origen2));

	// Concatenamos ambas listas de forma eficiente, en O(1) tanto en tiempo como en espacio. 
	// Para ello no podemos usar concatenar, pues no cumple con estos requisitos de tiempo y espacio.
	// Primero averiguamos los cuatro nodos clave (primero y último de cada una de las sublistas), y después los enlazamos entre sí
	// Recordemos que cada una de las dos sublistas al menos tiene 1 nodo
	Nodo *primeroSublista1 = origen1->getNodo(0);
	Nodo *ultimoSublista1 = origen1->getNodo(origen1->getN() - 1);
	Nodo *primeroSublista2 = origen2->getNodo(0);
	Nodo *ultimoSublista2 = origen2->getNodo(origen2->getN() - 1);

	// Enlazamos los nodos entre ellos. Recordemos que la lista es doblemente enlazada y circular
	ultimoSublista1->siguienteNodo=primeroSublista2;
	primeroSublista2->anteriorNodo=ultimoSublista1;
	primeroSublista1->anteriorNodo=ultimoSublista2;
	ultimoSublista2->siguienteNodo=primeroSublista1;

	// Configuramos la lista resultado, que es la que nos pasaron por parámetro
	destino->lista = primeroSublista1;
	destino->n = origen1->getN() + origen2->getN();

	// Configuramos las sublistas para que ya no apunten a esos nodos.
	origen1->lista = NULL;
	origen1->n = 0;
	origen2->lista = NULL;
	origen2->n = 0;

}

ListaEnlazada::~ListaEnlazada() {
	// Eliminamos el primer elemento de la lista. Esta operación la repetimos n veces
	// Eliminar el primer elemento de la lista es O(1)
	while (n>0) eliminar(0);
}



