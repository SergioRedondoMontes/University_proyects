#include "Racional.h"
#include "iostream"
#include "cmath" // Para usar abs()
#include "cassert" // Para utilizar la macro "assert()"
using namespace std;


int Racional::calcularMaximoComunDivisor(int operando1, int operando2) {
	assert(operando1 >= 0 && operando2 >= 0);
	// Calculamos el m�ximo com�n divisor de dos naturales usando el algoritmo de Euclides
	while (operando2 != 0) {
		int resto = operando1 % operando2; // Resto de la divisi�n entera entre los dos operandos
		operando1 = operando2;
		operando2 = resto;
	}
	return(operando1);
}

Racional::Racional(int numerador, int denominador) {
	assert(denominador != 0); // Denominador distinto de cero

	// Calculamos el signo de la fracci�n y lo ponemos en el numerador
	// Por lo tanto hacemos que el denominador siempre sea positivo
	if (denominador < 0) {
		denominador = -denominador;
		numerador = -numerador;
	}

	// Guardamos el numerador y el denominador en el objeto actual
	this->numerador = numerador;
	this->denominador = denominador;
}

Racional Racional::sumar(Racional sumando) {
	// Sumamos dos fracciones: la del objeto actual (this) y la pasada como par�metro
	// Para simplificar, las llamaremos numerador1/denominador1 y numerador2/denominador2
	int numerador1 = numerador;
	int denominador1 = denominador;
	int numerador2 = sumando.getNumerador();
	int denominador2 = sumando.getDenominador();

	int nuevoDenominador; // Nuevo denominador de la fraccion resultante
	int nuevoNumerador;   // Nuevo numerador de la fracci�n resultante

	// El nuevo denominador com�n del resultado idealmente seria el m�nimo comun m�ltiplo, pero
	// para simplificar hacemos que sea la multiplicaci�n de ambos denominadores
	nuevoDenominador = denominador1 * denominador2;

	// A partir del nuevo denominador com�n, calculamos los nuevos numeradores de los sumandos
	numerador1 = numerador1 * denominador2;
	numerador2 = numerador2 * denominador1;

	// Calculamos el numerador del resultado
	nuevoNumerador = numerador1 + numerador2;

	// Creamos la fracci�n resultado y lo devolvemos
	Racional resultado(nuevoNumerador, nuevoDenominador);
	return (resultado);
}

Racional Racional::multiplicar(Racional multiplicador) {
	// Calculamos el nuevo numerador y denominador del resultado
	int nuevoNumerador = numerador * multiplicador.getNumerador();
	int nuevoDenominador = denominador * multiplicador.getDenominador();

	// Creamos el resultado y lo devolvemos
	Racional resultado(nuevoNumerador, nuevoDenominador);
	return (resultado);
}

int Racional::getNumerador() {
	return(numerador);
}

int Racional::getDenominador() {
	return(denominador);
}

void Racional::simplificar() {
	int maximoComunDivisor; // m�ximo com�n divisor del valor absoluto del denominador y del valor absoluto del denominador
	maximoComunDivisor = calcularMaximoComunDivisor(abs(numerador), abs(denominador));
	numerador = numerador / maximoComunDivisor;
	denominador = denominador / maximoComunDivisor;
}

void Racional::escribir() {
	if (numerador == 0 || denominador == 1) cout << numerador;
	else cout << numerador << "/" << denominador;
}