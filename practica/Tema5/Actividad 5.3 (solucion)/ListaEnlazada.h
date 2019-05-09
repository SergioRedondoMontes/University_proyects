#pragma once
#include "Nodo.h"

// Clase que representa a una lista enlazada simple. No tiene restricción de tamaño
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento (un int), y un puntero al siguiente nodo
class ListaEnlazada
{
	// Puntero que apuntará al primer nodo de la lista, o será NULL si la lista está vacía
	Nodo *lista;

	// Numero actual de elementos que tiene la lista
	// Precondición: n>=0
	int n;

	// Posición y puntero del nodo que devolvió la última llamada a getNodo()
	int posicionUltimoNodoAccedido;
	Nodo *punteroUltimoNodoAccedido;

	// Obtiene un nodo de la lista
	// Parámetro: la posición del nodo
	// Retorno: un puntero al nodo que está en dicha posición
	// Precondiciones: 
	// - la posición debe estar en el intervalo [0, n-1]
	// - La lista no esta vacia (n>0)
	// Complejidad temporal: O(n). Como máximo hace n/2 iteraciones porque decide si ir hacia delante o hacia atrás
	// Complejidad espacial: O(1)
	Nodo * getNodo (int posicion);

	// Ordena una lista doblemente enlazada y circular utilizando merge sort recursivo
	// Parámetro: lista enlazada que se quiere ordenar
	// Precondiciones:
	// - lista!=NULL
	// - lista->getN() >= 1
	// Complejidad temporal: O(nlgn)
	// Complejidad espacial: O(lgn), pues tenemos M(n)=1+M(n/2) por las llamadas recursivas
	void ordenarPorMergeSortRecursivo(ListaEnlazada *lista);

	// Divide listaCompleta en dos mitades. La primera mitad la mueve a sublista1 y la segunda mitad la mueve a sublista2
	// Después de la división y del reparto, listaCompleta se queda vacía
	// Parámetros:
	// - listaCompleta: lista original en donde están los elementos que vamos a repartir
	// - sublista1: lista a donde moveremos la primera mitad de listaCompleta
	// - sublista2: lista a donde moveremos la segunda mitad de listaCompleta
	// Precondiciones:
	// - listaCompleta != NULL && sublista1 != NULL && sublista2 != NULL
	// - listaCompleta->n >= 2 (si es menor, no hay nada que repartir)
	// - sublista1->n == 0 && sublista2->n == 0 (ambas sublistas de destino están vacías)
	// Complejidad temporal: O(n), siendo n el tamaño de listaCompleta
	// Complejidad espacial: O(1), pues quitamos los nodos de listaCompleta a medida que los ponemos en las sublistas
	void repartirPorMergeSort(ListaEnlazada *listaCompleta, ListaEnlazada *sublista1, ListaEnlazada *sublista2);

	// Combina los elementos de dos listas ordenadas (origen1 y origen2) para dejarlos en una lista destino que también 
	// quedará ordenada. Después del proceso origen1 y origen2 quedarán vacías.
	// Parámetros:
	// - origen1 y origen2: listas ordenadas que contienen los elementos a combinar en destino
	// - destino: lista vacía en donde meteremos los elementos de origen1 y origen2 de tal modo que queden ordenados
	// Precondiciones:
	// - origen1 != NULL && origen2 != NULL && destino != NULL
	// - origen1->getN() >= 1 && origen2->getN() >= 1
	// - destino->getN() == 0
	// - isOrdenada(origen1) && isOrdenada(origen2)
	// Complejidad temporal: O(n), siendo n la suma de elementos que hay en origen1 y origen2
	// Complejidad espacial: O(1), pues quitamos los nodos de origen1 y origen2 a medida que los vamos metiendo en destino
	void combinarPorMergeSort(ListaEnlazada *origen1, ListaEnlazada *origen2, ListaEnlazada *destino);

	// Comprueba si la lista está ordenada de menor a mayor
	// Parámetro: lista que queremos comprobar si está ordenada o no
	// Retorno: verdadero si está ordenada de menor a mayor, falso en caso contrario
	// Precondición: lista!=NULL
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	bool isOrdenada(ListaEnlazada *lista);

	// Ordena una lista doblemente enlazada y circular utilizando quick sort recursivo
	// Parámetro: lista enlazada que se quiere ordenar
	// Precondiciones:
	// - lista!=NULL
	// - lista->getN() >= 1
	// Complejidad temporal: O(n^2), porque en el peor caso T(n)=1+2n+T(n-1)
	// Complejidad espacial: O(n), porque en el peor caso M(n)=1+M(n-1)
	void ordenarPorQuickSortRecursivo(ListaEnlazada *lista);

	// Calcula el pivote para implementar el algoritmo de QuickSort
	// Parámetro: lista a partir de la cual calcularemos el pivote
	// Retorno: pivote calculado
	// Precondiciones:
	// - lista!=NULL
	// - lista->getN() >= 2
	// Complejidad temporal y espacial: O(1)
	float getPivote(ListaEnlazada *lista);

	// Divide listaCompleta en dos sublistas, repartiendo los elementos a una sublista u otra. 
	// Se pasa un pivote. Los elementos menores que él van a la primera sublista y los mayores a la otra.
	// Los iguales van a la sublista que en ese momento tenga menos elementos
	// Después del reparto, listaCompleta se queda vacía
	// Parámetros:
	// - pivote: numero que usaremos para repartir los elementos
	// - listaCompleta: lista original en donde están los elementos que vamos a repartir
	// - sublista1: lista a donde moveremos los menores que el pivote
	// - sublista2: lista a donde moveremos los mayores que el pivote
	// Precondiciones:
	// - listaCompleta != NULL && sublista1 != NULL && sublista2 != NULL
	// - listaCompleta->n >= 2 (si es menor, no hay nada que repartir)
	// - sublista1->n == 0 && sublista2->n == 0 (ambas sublistas de destino están vacías)
	// Complejidad temporal: O(n), siendo n el tamaño de listaCompleta
	// Complejidad espacial: O(1), pues quitamos los nodos de listaCompleta a medida que los ponemos en las sublistas
	void repartirPorQuickSort(float pivote, ListaEnlazada *listaCompleta, ListaEnlazada *sublista1, ListaEnlazada *sublista2);

	// Pone origen1 y origen2, una detrás de otra, en destino 
	// Después del proceso origen1 y origen2 quedarán vacías.
	// Parámetros:
	// - origen1 y origen2: listas ordenadas que pondremos una detrás de otra en el destino
	// - destino: lista vacía en donde meteremos los elementos de origen1 y origen2
	// Precondiciones:
	// - origen1 != NULL && origen2 != NULL && destino != NULL
	// - origen1->getN() >= 1 && origen2->getN() >= 1
	// - destino->getN() == 0
	// - isOrdenada(origen1) && isOrdenada(origen2)
	// Complejidad temporal y espacial: O(1)
	void combinarPorQuickSort(ListaEnlazada *origen1, ListaEnlazada *origen2, ListaEnlazada *destino);

public:

	// Constructor. Crea una lista de tamaño 0
	// Complejidad temporal y espacial: O(1)
	ListaEnlazada();

	// Devuelve un elemento de la lista en determinada posición
	// Parámetro: la posición del elemento
	// Retorno: una copia del elemento encontrado en esa posición
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la lista
	// Parámetros:
	// - posicion: la posición del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tamaño actual de la lista
	// Complejidad temporal y espacial: O(1)
	int getN(); 

	// Inserta un nuevo elemento en una posición de la lista
	// Los elementos que había desde la posición hasta el final de la lista se desplazarán una posición a la derecha
	// Parámetros:
	// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones: posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void insertar (int posicion, int nuevoValor);

	// Elimina un elemento en una posición dada.
	// Los elementos que había desde posicion+1 hasta el final de la lista se desplazarán una posición a la izquierda
	// Parámetros:
	// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void eliminar (int posicion);

	// Concatena una lista al final de la lista actual
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Parámetro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondición: listaAConcatenar!=NULL
	// Complejidad temporal: O(m), siendo m = listaAConcatenar.getN()
	// Complejidad espacial: O(m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaEnlazada *listaAConcatenar);

	// Busca la posición de un elemento en la ListaContigua
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(int elementoABuscar);

	// Ordena la lista de menor a mayor, utilizando el algoritmo MergeSort recursivo
	// Complejidad temporal: O(nlgn), porque llama a ordenarPorMergeSortRecursivo()
	// Complejidad espacial: O(lgn), porque llama a ordenarPorMergeSortRecursivo()
	void ordenarPorMergeSort();

	// Ordena la lista de menor a mayor, utilizando el algoritmo QuickSort recursivo
	// Complejidad temporal: O(n^2), porque es la misma que ordenarPorQuickSortRecursivo()
	// Complejidad espacial: O(n), porque es la misma que ordenarPorQuickSortRecursivo()
	void ordenarPorQuickSort();

	// Destructor. Libera memoria
	// Complejidad temporal: O(n)
	~ListaEnlazada();
};







