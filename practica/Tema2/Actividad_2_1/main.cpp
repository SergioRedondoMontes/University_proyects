#include <iostream>
#include <string>
#include "Racional.h"

using namespace std;

int main()
{
    int numerador, denominador;

    Racional numero(18, 12);
    Racional numero2(1, 1);

    Racional resMulti = numero.multiplicacion(numero2).simplificar();
    numerador = resMulti.getNumerador();
    denominador = resMulti.getDenominador();
    cout << "Multiplicacion " << numerador << "/" << denominador << endl;

    Racional resSuma = numero.suma(numero2).simplificar();
    numerador = resSuma.getNumerador();
    denominador = resSuma.getDenominador();
    cout << "Suma " << numerador << "/" << denominador << endl;
}