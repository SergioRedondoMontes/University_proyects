/////////////////////////////////////
// Algoritmos y Estructuras de Datos
// Solución examen final CO 2019
// Autos: Leila S. Shafti
/////////////////////////////////////

#include "Arbol.h"
using namespace std;

int main()
{

	Arbol * raiz = new Arbol(1);


	/*
			1
		   / \
		  /   \
		 2     4
		  \   /
		  3  5
	*/

	if (raiz->Insertar(2, 0, -1) == false)  //aniadir 2 a la izquierda de 0
		cout << "Error al insertar 2, 0, -1." << endl; // debe dar error
	if (raiz->Insertar(2, 1, -1) == false)  //aniadir 2 a la izquierda de 1
		cout << "Error al insertar 2, 1, -1." << endl;
	if (raiz->Insertar(4, 1, 1) == false)   // aniadir 4 a la derecha de 1
		cout << "Error al insertar 4, 1, 1." << endl;
	if (raiz->Insertar(3, 2, 1) == false)    // aniadir 3 a la derecha de 2
		cout << "Error al insertar 3, 2, 1." << endl;
	if (raiz->Insertar(5, 4, -1) == false)    // aniadir 5 a la izquierda de 4
		cout << "Error al insertar 5, 4, -1." << endl;
	if (raiz->Insertar(6, 4, -1) == false)   // aniadir 6 a la izquierda de 4
		cout << "Error al insertar 6, 4, -1." << endl; // debe dar error
	if (raiz->Insertar(8, 6, -1) == false)   // aniadir 8 a la izquierda de 6
		cout << "Error al insertar 8, 6, -1." << endl; // debe dar error

	if (raiz->Simetrico()) cout << "El arbol es simetrico" << endl;
	else cout << "El arbol no es simetrico" << endl;


	cout << "Anyadir mas hijos." << endl;
	if (raiz->Insertar(6, 3, -1) == false)   // aniadir 6 a la izquierda de 3
		cout << "Error al insertar 6, 3, -1." << endl; // 
	if (raiz->Insertar(7, 5, -1) == false)   // aniadir 7 a la izquierda de 5
		cout << "Error al insertar 7, 5, -1." << endl; // 


	/*
             1
            / \
           /   \
          2     4
           \   /
           3  5
          /  /
         6  7
       */


	if (raiz->Simetrico()) cout << "El arbol es simetrico" << endl;
	else cout << "El arbol no es simetrico" << endl;
}
