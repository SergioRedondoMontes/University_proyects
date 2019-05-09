//
//  ArbolBinarioDeBusqueda.cpp
//  act_7_2
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <stdio.h>
#include <assert.h>     /* assert */
#include "ArbolBinarioDeBusqueda.h"

ArbolBinarioDeBusqueda::ArbolBinarioDeBusqueda(){
    this->raiz = NULL;
    this->n = 0;
    this->orientacionSiguienteEliminacion = 0;
}

void ArbolBinarioDeBusqueda::insertar (int nuevoElemento){
    
    Nodo *nodo = new Nodo();
    nodo = buscarHueco(this->raiz, nuevoElemento);
    
    Nodo *aux = new Nodo();
    aux->contenido = nuevoElemento;
    aux->padre = nodo;
    aux->hijoDerecho = NULL;
    aux->hijoIzquierdo = NULL;
    
    if(nodo->contenido < nuevoElemento){
        nodo->hijoDerecho = aux;
    }else{
        nodo->hijoIzquierdo = aux;
    }
    
}


Nodo* ArbolBinarioDeBusqueda::buscar(int elementoABuscar){
    return  NULL;
}

void ArbolBinarioDeBusqueda::eliminar (int elementoAEliminar){
    
}

void ArbolBinarioDeBusqueda::imprimir(){
    
}

ArbolBinarioDeBusqueda::~ArbolBinarioDeBusqueda(){
    
}


//metodos protected
void imprimirRecursivo (Nodo *subarbol, int numeroTabulaciones, int orientacion);
void eliminarSubarbol (Nodo *raizSubarbol);



Nodo* ArbolBinarioDeBusqueda::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){
    assert(raizSubarbol != NULL);
    if (raizSubarbol->contenido < elementoAInsertar) {
        if(raizSubarbol->hijoDerecho != NULL){
            return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
        }else{
            return raizSubarbol;
        }
    }else{
        if(raizSubarbol->hijoIzquierdo != NULL){
            return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
        }else{
            return raizSubarbol;
        }
    }
}

Nodo *buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar){
    
        return NULL;
}

Nodo *buscarMaximo (Nodo *raizSubarbol);
Nodo *buscarMinimo (Nodo *raizSubarbol);
void eliminarNodo (Nodo *nodoParaEliminar);




