//
//  ArbolBinarioDeBusqueda.cpp
//  act_7_2
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <stdio.h>
#include <assert.h>     /* assert */
#include "iostream"
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
    
    if (this->raiz == NULL) {
        nodo = aux;
        this->raiz = nodo;
    }else if(nodo->padre == NULL){
        if(nodo->contenido < nuevoElemento){
            nodo->hijoDerecho = aux;
        }else{
            nodo->hijoIzquierdo = aux;
        }
    } else{
        if(nodo->contenido < nuevoElemento){
            nodo->hijoDerecho = aux;
        }else{
            nodo->hijoIzquierdo = aux;
        }
    }
    
    
}

Nodo* ArbolBinarioDeBusqueda::buscar(int elementoABuscar){
    return  buscarRecursivo(this->raiz, elementoABuscar);
}


bool ArbolBinarioDeBusqueda::Eliminar(int valor){
    Nodo *arbolBorrar = new Nodo();
    arbolBorrar = buscar(valor);
    if(arbolBorrar == NULL) return false;
    else{
        if(eliminarArbol(arbolBorrar)) return true;
        else return false;
        return false;
    }
}


void ArbolBinarioDeBusqueda::imprimir(int orden){
    imprimirRec(this->raiz, orden);
}

ArbolBinarioDeBusqueda::~ArbolBinarioDeBusqueda(){
    
}



//metodos protected
void ArbolBinarioDeBusqueda::imprimirRec(Nodo* root, int orden){
    if (orden == INORDER) {
        if(root != NULL){
            imprimirRec(root->hijoIzquierdo, orden);
            std::cout << root->contenido << ", ";
            imprimirRec(root->hijoDerecho, orden);
        }
    }else if(orden == PREORDER){
        // 8,3,1,6,4,7,10,14,13
        if(root != NULL){
            std::cout << root->contenido << ", ";
            if(root->hijoIzquierdo != NULL){
                imprimirRec(root->hijoIzquierdo, orden);
            }
            if(root->hijoDerecho != NULL){
                imprimirRec(root->hijoDerecho, orden);
            }
            
        }
    }else if(orden == POSTORDER){
        //1,4,7,6,3,13,14,10,8
        if(root->hijoIzquierdo != NULL){
            imprimirRec(root->hijoIzquierdo, orden);
        }
        if(root->hijoDerecho != NULL){
            imprimirRec(root->hijoDerecho, orden);
        }
        std::cout << root->contenido << ", ";
    }
}


Nodo* ArbolBinarioDeBusqueda::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){
    if (raizSubarbol == NULL) {
        return raizSubarbol;
    }else{
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
}

Nodo* ArbolBinarioDeBusqueda::buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar){
    if (raizSubarbol == NULL) {
        return NULL;
    }
    if (elementoABuscar == raizSubarbol->contenido) {
        return  raizSubarbol;
    }else if (elementoABuscar > raizSubarbol->contenido) {
        return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
    }else{
        return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
    }
}



bool ArbolBinarioDeBusqueda::eliminarArbol(Nodo *arbolEliminar){
    if (arbolEliminar->hijoIzquierdo && arbolEliminar->hijoDerecho) {
        Nodo *menor = new Nodo();
        menor = minimo(arbolEliminar->hijoDerecho);
        arbolEliminar->contenido = menor->contenido;
        eliminarArbol(menor);
        return true;
    }else if (arbolEliminar->hijoIzquierdo){
        reemplazar(arbolEliminar, arbolEliminar->hijoIzquierdo);
        destruirNodo(arbolEliminar);
        return true;
        
    }else if (arbolEliminar->hijoDerecho){
        reemplazar(arbolEliminar, arbolEliminar->hijoDerecho);
        destruirNodo(arbolEliminar);
        return true;
        
    }else{
        reemplazar(arbolEliminar, arbolEliminar->hijoDerecho);
        destruirNodo(arbolEliminar);
        return true;
        
    }
    return false;
}

Nodo *ArbolBinarioDeBusqueda::minimo(Nodo *arbol){
    if(arbol == NULL) return NULL;
    if(arbol->hijoIzquierdo) return minimo(arbol->hijoIzquierdo);
    else return arbol;
}

void ArbolBinarioDeBusqueda::reemplazar(Nodo *arbol, Nodo *nodoNuevo){
    if(arbol->padre){
        if (arbol->contenido == arbol->padre->hijoIzquierdo->contenido){
            arbol->padre->hijoIzquierdo = nodoNuevo;
        }else if (arbol->contenido == arbol->padre->hijoDerecho->contenido){
            arbol->padre->hijoDerecho = nodoNuevo;
            
        }
    }else if (nodoNuevo){
        nodoNuevo->padre = arbol->padre;
    }
}

void ArbolBinarioDeBusqueda::destruirNodo(Nodo *nodo){
    nodo->hijoDerecho = NULL;
    nodo->hijoIzquierdo = NULL;
    
    delete nodo;
}





