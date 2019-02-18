#include "racional.h"

Racional::Racional(int numerador, int denominador)
{
    this->_numerador = numerador;
    this->_denominador = denominador;
}

float Racional::getValor()
{
    return this->_numerador / (double)this->_denominador;
}

int Racional::getNumerador() { return this->_numerador; }
int Racional::getDenominador() { return this->_denominador; }

Racional::~Racional()
{
}
