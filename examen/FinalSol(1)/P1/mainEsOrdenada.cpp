/////////////////////////////////////
// Algoritmos y Estructuras de Datos
// Solución examen final CO 2019
// Autos: Leila S. Shafti
/////////////////////////////////////

#include <iostream>
using namespace std;

// comprobar con "devide y venceras" si la lista desde la posicion i 
// hasta f (ambos incluidas) está ordenada.
// calculo de complejidad temporal:
// T(n) = 2T(n/2) + O(1)
// Aplicando el Teorema Maestro la complejidad es O(n)
bool esOrdenadaRec(int a[], int i, int f)
{
	if (i >= f) // si hay uno o cero elementos en el array
		return true;

	int mid = (i + f) / 2; // encontrar el punto medio
	bool res1, res2;
	res1 = esOrdenadaRec(a, i, mid); // comprobar la primera mitad
	res2 = esOrdenadaRec(a, mid + 1, f); // comprobar la segunda mitad
	if (res1 == true && res2 == true && a[mid] <= a[mid + 1]) // si ambos partes están ordenadas y ademas el ultimo elemento de la primera parte es menor que el primero de la segunda parte
		return true;
	else return false;
}


// comprobar si la lista está ordenada utilizando un algoritmo recurivo basado a "divide y venceras"
bool esOrdenada(int a[], int n) {
	return esOrdenadaRec(a, 0, n-1); // llamada recursiva
}

int main()
{

	int a[6] = { 1,2,3,-1,5,6 };
	int b[7] = { 1,2,3,4,5,6,7 };
	int c[8] = { 3,4,5,6,0,1,2,3 };
	int d[7] = { 4,5,6,1,2,3,4 };
	int e[6] = { 1,2,3,4,5,0 };
	int f[7] = { 1,2,3,4,5,6,0 };
	int g[7] = { 3,4,5,6,1,2,3 };


	cout << esOrdenada(a, 6) << endl;
	cout << esOrdenada(b, 7) << endl;
	cout << esOrdenada(c, 8) << endl;
	cout << esOrdenada(d, 7) << endl;
	cout << esOrdenada(e, 6) << endl;
	cout << esOrdenada(f, 7) << endl;
	cout << esOrdenada(g, 7) << endl;



}
