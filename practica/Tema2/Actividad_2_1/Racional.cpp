#include "Racional.h"

Racional::Racional(int a, int b)
{
    this->numerador = a;
    this->denominador = b;
}

int Racional::getNumerador() { return this->numerador; }
int Racional::getDenominador() { return this->denominador; }

int Racional::calcularMCD(int numerador, int denominador) // 18 / 14
{
    while (denominador != 0)
    {
        int resto = numerador % denominador; // Resto de la divisiÛn entera entre los dos operandos
        numerador = denominador;
        denominador = resto;
    }
    return (numerador);
}

Racional Racional::suma(Racional a)
{

    int denominador = this->denominador * a.denominador;
    int numerador = (this->numerador * a.denominador) + (a.numerador * this->denominador);

    return Racional(numerador, denominador);
}

Racional Racional::multiplicacion(Racional a)
{
    int numerador = this->numerador * a.numerador;
    int denominador = this->denominador * a.denominador;

    return Racional(numerador, denominador);
}

Racional Racional::simplificar()
{
    int mcd = calcularMCD(this->numerador, this->denominador);

    return Racional(this->numerador / mcd, this->denominador / mcd);
}
