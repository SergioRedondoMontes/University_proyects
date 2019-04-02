#include "iostream"
#include "Cola.h"
#include "impresionListasEnlazadas.h"

using namespace std;

int main()
{

	Cola cola;		  // Creaci�n de la pila que utilizaremos
	int teclaPulsada; // Contendr� la tecla que pulsamos (de 1 a 4)
	//int numeroIntroducido; // Numero flotante que introduciremos por teclado cuando hagamos push

	// Imprimimos el men�
	cout << "MENU:" << endl;
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Cima" << endl;
	cout << "4. Salir" << endl;

	do
	{

		cout << "Por favor, introduce una opcion del 1 al 4: ";

		cin >> teclaPulsada;
		switch (teclaPulsada)
		{
		case (1):
			int numeroIntroducido; // Numero que introduciremos por teclado cuando hagamos push
			cout << "Introduce un numero: ";
			cin >> numeroIntroducido;
			cola.push(numeroIntroducido);
			cout << "Cola completa: ";
			imprimirListaEnlazada(&cola);
			break;
		case (2):
			if (cola.isVacia())
				cout << "La cola esta vacia, por lo tanto no se puede hacer pop" << endl;
			else
				cout << "La cima de la cola es " << cola.pop() << endl;
			cout << "cola completa: ";
			imprimirListaEnlazada(&cola);
			break;
		case (3):
			if (cola.isVacia())
				cout << "La cola esta vacia, por lo tanto no se puede ver la cima" << endl;
			else
				cout << "La cima de la cola es " << cola.verCima() << endl;
			cout << "cola completa: ";
			imprimirListaEnlazada(&cola);
			break;
		} // Fin switch

	} while (teclaPulsada != 4);

	return 0;
}
