#include "Mystr.h"
#include <iostream>
#include <cstring>

using namespace std;

Mystr::Mystr(){
    _size = 2;
    _arr = (char *)malloc(_size * sizeof(char));
}

Mystr::Mystr(const char *arrCopia)
{
    _size = (int)strlen(arrCopia);
    _capacity = _size+1 * 2;
    //tengo que reservar el doble de memoria o lo hace por defecto c++ al guardar un string en un char array
    _arr = (char *)malloc(_capacity * sizeof(char) );
    memcpy(_arr, arrCopia, _capacity);
    //que termine en /0 es una precondicion o lo tengo que hacer yo
    _arr[_size + 1] = '\0';
}

Mystr::Mystr(const Mystr &arrCopia)
{
    _size = (int)strlen(arrCopia._arr);
    _capacity = _size;
    //tengo que reservar el doble de memoria o lo hace por defecto c++ al guardar un string en un char array
    _arr = (char *)malloc(_capacity * sizeof(char));
    memcpy(_arr, arrCopia._arr,_capacity);
    //que termine en /0 es una precondicion o lo tengo que hacer yo
    _arr[_size + 1] = '\0';
}


 // Sobre carga
 //Usar la función Compare.
 bool Mystr::operator==(const Mystr &other)
 {
     if (Compare(other) == 0) {
         return true;
     }
 return false;
 }
 
 //Puede ser el opuesto a ==
 bool Mystr::operator!=(const Mystr &other) {
     if (Compare(other) != 0) {
         return true;
     }
     return false;
 }
 
 //Usar la función Compare (del siguiente apartado)
 bool Mystr::operator<(const Mystr &other) {
     if (Compare(other) == -1) {
         return true;
     }
     return false;
 }
 
 //Usar la función Compare (del siguiente apartado)
 bool Mystr::operator>(const Mystr &other) {
     if (Compare(other) == 1) {
         return true;
     }
     return false;
 }
 
 //Puede ser el opuesto a >
 bool Mystr::operator<=(const Mystr &other) {
     if (Compare(other) != 1) {
         return true;
     }
     return false;
 }
 
 //Puede ser el opuesto a <
 bool Mystr::operator>=(const Mystr &other) {
     if (Compare(other) != -1) {
         return true;
     }
     return false;
 }
 
 //Devuelve el caracter en el elemento “index”.
 char &Mystr::operator[](int index) {
     return _arr[index];
 }
 
 //Concatena una cadena a otra.
 Mystr Mystr::operator+(const Mystr &other) {
     return Concatenate(other);
 }

//Tamaño del array de caracteres. Se recomienda usar strlen en vez de
// almacenar el largo de la cadena en el objeto
unsigned int Mystr::Length(){return _size;}

//La capacidad de la memoria reservada.
unsigned int Mystr::Capacity(){return _capacity;}

//Busca todos los caracteres iguales a “find” y los
//sustituye por replaceBy. Devuelve el número de caracteres remplazados.
int Mystr::Replace(char find, char replaceBy){
    int count = 0;
    for (int i = 0; i < _size; i++) {
        if (_arr[i] == find) {
            _arr[i] = replaceBy;
            count++;
        }
    }
    
    return count;
}

//Devuelve 0 si ambas cadenas son iguales, 1 si la primera
// cadena es mayor que la de “other”, -1 si la de “other” es mayor que la primera.
//-Se puede usar strcmp
int Mystr::Compare(const Mystr &other){
    return strcmp(_arr, other._arr);
}

//Busca todos los caracteres iguales a “find” y los borra. Devuelve el
//número de caracteres borrados. *Atender al decremento de la capacidad*
int Mystr::Remove(char find){
    int count = 0;
    string aux;
    for (int i = 0; i < _size; i++) {
        if (_arr[i] == find) {
            count++;
        }else{
            aux += _arr[i];
        }
    }
    _size = (int)aux.size();
    if (_size >= Length()/4) {
        _arr = (char *)realloc(_arr, _size*2);
        strcpy(_arr, aux.c_str());
        _capacity = Length()/4;
    }else{
        strcpy(_arr, aux.c_str());
    }
    
    return count;
}

//Devuelve la subcadena de “num” caracteres empezando por elfinal.
Mystr Mystr::Right(unsigned int num){
    string aux;
    for (int i = _size-num; i < _size ; i++) {
        aux += _arr[i];
    }
    return Mystr(aux.c_str());
}

//Devuelve la subcadena comprendida entre el inicio y “num”.
Mystr Mystr::Left(unsigned int num){
    string aux;
    for (int i = 0; i < num ; i++) {
        aux += _arr[i];
    }
    return Mystr(aux.c_str());
}

// Devuelve la subcadena partiendo de initialIndex hasta llegar a finalIndex.
Mystr Mystr::Substring(unsigned int initialIndex, unsigned int finalIndex){
    string aux;
    for (int i = initialIndex; i < finalIndex ; i++) {
        aux += _arr[i];
    }
    return Mystr(aux.c_str());
}

//Elimina los espacios en blanco que haya por la derecha del texto. Devuelve el
//número de espacios eliminados. *Atender al decremento de la capacidad*
int Mystr::TrimRight(){
    int count = 0;
    while(_arr[_size -1] == ' '){
        _arr[_size-1] = '\0';
        count++;
        _size--;
    }
    _size = (int)strlen(_arr);
    if (_size >= Length()/4) {
        _arr = (char *)realloc(_arr, _size*2);
        _capacity = Length()/4;
    }
    return count;
}

//Elimina los espacios en blanco que haya por la izquierda del texto. Devuelve el
//número de espacios eliminados. *Atender al decremento de la capacidad*
int Mystr::TrimLeft(){
    int i = 0,count = 0;
    
    while(_arr[i] == ' '){
        count++;
        i++;
    }
    string aux = Right(_size-count)._arr;
    _size = _size-count;
    if (_size >= Length()/4) {
        _arr = (char *)realloc(_arr, _size*2);
        _capacity = Length()/4;
    }
    strcpy(_arr, aux.c_str());
    return count;
}

 //Elimina los espacios en blanco en ambos lados del texto. Devuelve el número de
 //espacios eliminados. *Atender al decremento de la capacidad*
int Mystr::Trim(){
    return TrimRight()+ TrimLeft();
}
 //Convierte todos los caracteres en letras mayúsculas. Devuelve el número de
 //caracteres que han sido cambiados a mayúsculas. Se permite usar toupper de C.
int Mystr::ToUpper(){
    int count = 0;
    for (int i = 0; i < _size; i++) {
        if ( islower(_arr[i])) {
            _arr[i] = toupper(_arr[i]);
            count++;
        }
    }
    return count;
}


 //Convierte todos los caracteres en letras minúsculas. Devuelve el número de
 //caracteres que han sido cambiados a minúsculas. Se permite usar tolower de C.
int Mystr::ToLower(){
    int count = 0;
    for (int i = 0; i < _size; i++) {
        if (isupper(_arr[i])) {
            _arr[i] = tolower(_arr[i]);
            count++;
        }
    }
    return count;
}

 //Devuelve true si la cadena empieza con “other”.
bool Mystr::StartsWith(const Mystr &other){
    if (Left(other._size).Compare(other._arr) == 0) {
        return true;

    }
    return false;
}

 //Devuelve true si la cadena termina con “other”.
bool Mystr::EndsWith(const Mystr &other){
    if (Right(other._size).Compare(other._arr) == 0) {
        return true;
        
    }
    return false;
}

 //Concatena la cadena añadiendo “other” de manera
 //consecutiva. *Atender al incremento de la capacidad de la primera cadena*
Mystr Mystr::Concatenate(const Mystr &other){
    string a = _arr;
    a += other._arr;
    return Mystr(a.c_str());
}

 //Concatena la cadena introduciendola entre medias, empezando en la posición indicada
 //por index. *Atender al incremento de la capacidad de la primera cadena*
Mystr Mystr::Introduce(const Mystr &other, int unsigned index){
    string a = Substring(0, index)._arr;
    a += other._arr;
    a += Substring(index, _size)._arr;
    return Mystr(a.c_str());
}

void Mystr::imprimir(){
    cout << _arr << endl;
}

Mystr::~Mystr(){
    free(_arr);
}

