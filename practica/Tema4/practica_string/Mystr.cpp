#include "Mystr.h"
#include <string>

Mystr::Mystr(char *arrCopia)
{
    int size = strlen(arrCopia);
    //tengo que reservar el doble de memoria o lo hace por defecto c++ al guardar un string en un char array
    _arr = (char *)malloc(size * sizeof(char) * 2);
    strcpy(_arr, arrCopia);
    //que termine en /0 es una precondicion o lo tengo que hacer yo
    _arr[size + 1] = '/0';
}

Mystr::~Mystr()
{
}

/* Sobre carga */
//Usar la función Compare.
inline bool Mystr::operator==(const Mystr &other)
{ // do actual comparison
}

//Puede ser el opuesto a ==
inline bool Mystr::operator!=(const Mystr &other) {}

//Usar la función Compare (del siguiente apartado)
inline bool Mystr::operator<(const Mystr &other) {}

//Usar la función Compare (del siguiente apartado)
inline bool Mystr::operator>(const Mystr &other) {}

//Puede ser el opuesto a >
inline bool Mystr::operator<=(const Mystr &other) {}

//Puede ser el opuesto a <
inline bool Mystr::operator>=(const Mystr &other) {}

//Devuelve el caracter en el elemento “index”.
inline char &Mystr::operator[](int index) {}

//Concatena una cadena a otra.
inline Mystr Mystr::operator+(const Mystr &other) {}
