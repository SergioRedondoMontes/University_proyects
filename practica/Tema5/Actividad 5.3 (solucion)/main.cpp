#include "iostream"
#include "ListaEnlazada.h"
#include "cstdlib" // Para srand y rand
#include "ctime" // Para time()
#include "impresionListasEnlazadas.h"

using namespace std;


void main() {

	int n; // Tamaño de la lista

	// Inicializamos el generador de numeros aleatorios con el numero de segundos transcurrido desde 1970
	srand(time(NULL));

	// Pedimos el tamaño del vector
	cout << "Introduce el tamano de la lista (numero mayor o igual que 1): ";
	cin >> n;

	// Creamos los vectores y los rellenamos
	ListaEnlazada listaOrdenadaPorMergeSort, listaOrdenadaPorQuickSort; // Listas originales que ordenaremos con cada uno de los algoritmos
	for (int i = 0; i < n; i++) {
		int numeroAInsertar = rand() % 100; // Numero aleatorio que insertaremos en ambas listas
		listaOrdenadaPorMergeSort.insertar(0, numeroAInsertar); 
		listaOrdenadaPorQuickSort.insertar(0, numeroAInsertar);
	}

	// Imprimimos la lista sin ordenar
	cout << "\nLa lista original es la siguiente:\n";
	imprimirListaEnlazada(&listaOrdenadaPorMergeSort);
	cout << endl;

	// Lo ordenamos por MergeSort
	unsigned long int numeroClicksInicio = clock();
	cout << "Clocks de inicio con ordenacion por MergeSort: " << numeroClicksInicio << endl;
	listaOrdenadaPorMergeSort.ordenarPorMergeSort();
	unsigned long int numeroClicksFin = clock();
	cout << "Clocks de fin con ordenacion por MergeSort:    " << numeroClicksFin << endl;
	cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;

	// Calculamos el tiempo que ha llevado la ordenación
	// Hacemos el dividendo float para que la división sea real y no entera
	// La cte CLOKS_PER_SEC (en ctime) nos dice el numero de clocks por segundo
	float segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;

	// Imprimimos el tiempo transcurrido con tres decimales
	printf("Con ordenacion por MergeSort he tardado %.3f segundos en ordenarlo.\nLa lista resultado es:\n", segundosTranscurridos);
	imprimirListaEnlazada(&listaOrdenadaPorMergeSort);
	cout << endl;
	
	// Lo ordenamos por QuickSort
	numeroClicksInicio = clock();
	cout << "Clocks de inicio con ordenacion por QuickSort: " << numeroClicksInicio << endl;
	listaOrdenadaPorQuickSort.ordenarPorQuickSort();
	numeroClicksFin = clock();
	cout << "Clocks de fin con ordenacion por QuickSort:    " << numeroClicksFin << endl;
	cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;

	// Calculamos el tiempo que ha llevado la ordenación
	// Hacemos el dividendo float para que la división sea real y no entera
	// La cte CLOKS_PER_SEC (en ctime) nos dice el numero de clocks por segundo
	segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;

	// Imprimimos el tiempo transcurrido con tres decimales
	printf("Con ordenacion por QuickSort he tardado %.3f segundos en ordenarlo.\nLa lista resultado es:\n", segundosTranscurridos);
	imprimirListaEnlazada(&listaOrdenadaPorQuickSort);
	cout << endl;
	
}



