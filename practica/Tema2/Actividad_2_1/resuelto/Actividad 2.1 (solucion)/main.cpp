// Actividad 2.1: programa que hace algunas operaciones con fracciones
#include "iostream"
#include "Racional.h"

using namespace std; 

int main() 
{ 
	// Variables para guardar numerador y denominador que capturamos por teclado
	int numerador, denominador;

	// Pedimos y creamos el primer racional
	do {
		cout << "Introduzca numerador y denominador (separado por espacios) del racional a.\nEl denominador debe ser distinto de cero: ";
		cin >> numerador;
		cin >> denominador;
	} while (denominador==0);
	Racional a(numerador,denominador);
	cout << "Racional a: ";
	a.escribir();
	cout << endl;

	// Pedimos y creamos el segundo racional
	do {
		cout << "Introduzca numerador y denominador (separado por espacios) del racional b.\nEl denominador debe ser distinto de cero: ";
		cin >> numerador;
		cin >> denominador;
	} while (denominador==0);
	Racional b(numerador,denominador);
	cout << "Racional b: ";
	b.escribir();
	cout << endl;


	// Realizamos la suma y lo imprimimos
	Racional resultado = a.sumar(b); // Resultado de las operaciones
	cout << "Racional a+b: ";
	resultado.escribir();
	cout << "\n";

	// Simplificamos y lo escribimos
	resultado.simplificar();
	cout << "Racional a+b simplificado: "; 
	resultado.escribir();
	cout << endl;

	// Realizamos la multiplicación y lo escribimos
	resultado = a.multiplicar(b);
	cout << "Racional a*b: ";
	resultado.escribir();
	cout << "\n";

	// Simplificamos y lo escribimos
	resultado.simplificar();
	cout << "Racional a*b simplificado: ";
	resultado.escribir();
	cout << endl;
	return 0;
}
