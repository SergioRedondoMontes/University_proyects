//
//  ArbolBinarioDeBusqueda.h
//  act_7_2
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//
#pragma once
#include "Nodo.h"

#define INORDER 0
#define PREORDER 1
#define POSTORDER 2

// Árbol binario de búsqueda. Se permiten duplicados, y éstos van hacia la izquierda
class ArbolBinarioDeBusqueda
{
    Nodo *raiz; // Raiz del árbol, o NULL si el arbol está vacío
    int n; // Numero de nodos del arbol
    int orientacionSiguienteEliminacion; // Orientacion (-1 si es izquierdo, 1 si es derecho) que tendrá que tener la siguiente eliminación a realizar
    
public:
    
    // Construye un árbol binario de búsqueda vacío
    // Complejidad temporal y espacial: O(1)
    ArbolBinarioDeBusqueda();
    
    // Inserta un elemento (siempre se insertará como hoja)
    // Parámetro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    void insertar (int nuevoElemento);
    
    // Busca un elemento en el arbol binario de busqueda
    // Parámetros:
    // - elementoABuscar es la clave del nodo que queremos encontrar
    // Retorno: puntero al nodo que contiene el elementoABuscar, o NULL si no lo encuentra
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    Nodo *buscar(int elementoABuscar);
    
    bool Eliminar(int valor);
    
    // Imprime el árbol en forma de esquema tabulado
    // Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    void imprimir(int orden);
    
    // Destruye el árbol, liberando la memoria de todos los nodos
    // Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    ~ArbolBinarioDeBusqueda();
    
protected:
    
    //método privado, llamado desde el método imprimir con el nodo raíz por parámetros
    void imprimirRec(Nodo* root, int orden);
    
    // Busca recursivamente el padre del hueco en donde podemos insertar un nuevo elemento dado
    // Parámetros:
    // - raizSubarbol indica la raíz del subarbol en donde buscar
    // - elementoAInsertar indica el elemento que nos gustaría insertar y cuyo hueco queremos encontrar
    // Retorno: puntero al nodo padre del hueco en donde podríamos poner elementoAInsertar
    // Precondicion: raizSubarbol != NULL
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    // (n es el número de nodos del subarbol)
    Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);
    
    // Busca un elemento en el arbol binario de busqueda
    // Parámetros:
    // - raizSubarbol indica el subarbol en donde buscar
    // - elementoABuscar es la clave del nodo que queremos encontrar
    // Retorno: puntero al nodo que contiene el elementoABuscar, o NULL si no lo encuentra
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    // (n es el número de nodos del subarbol)
    Nodo *buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar);
    
    bool eliminarArbol(Nodo *nodoEliminar);
    Nodo *minimo(Nodo *nodo);
    void reemplazar(Nodo *nodoArbol, Nodo *nodoNuevo);
    void destruirNodo(Nodo *nodo);

};
