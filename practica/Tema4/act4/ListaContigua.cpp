#include <iostream>
#include "ListaContigua.h"

ListaContigua::ListaContigua(){
    this -> capacidad = 0;
    this -> n = 0;
    this -> vector = NULL;
}

bool ListaContigua::isLlena(){   
    return (this->capacidad == this->n); 
}
void ListaContigua::setValor(int posicion, int nuevoValor){
    assert(posicion >=  0 && posicion < n);
    this->vector[posicion] = nuevoValor;
}

void ListaContigua::insertarAlFinal (int nuevoValor){
    if (isLlena()) {
        this->capacidad = this->capacidad + INCREMENTO;
        this->vector = (int *)realloc(this->vector,capacidad*sizeof(this->vector));
    }
        this->vector[this->n] = nuevoValor;
        this-> n = this->n +1;
    
    
}

void ListaContigua::eliminarAlFinal(){
    this->n = this->n - 1;
    if ((this->capacidad - n) > INCREMENTO) {
        this->capacidad = this-> capacidad - INCREMENTO; 
        this->vector = (int *)realloc(this->vector,capacidad*sizeof(this->vector));
    }
    
}

int ListaContigua::getValor(int posicion){
    assert(posicion >=  0 && posicion < n);
    return this -> vector[posicion];
}

int ListaContigua::getN(){
    return this->n;
}

int ListaContigua::getCapacidad(){
    return this->capacidad;
}



ListaContigua::~ListaContigua(){
    free(this -> vector);
}