//
//  ArbolBinarioDeBusqueda.h
//  act_7_2
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//
#pragma once
#include "Nodo.h"

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
    
    
    // Elimina el primer nodo que se encuentre con un elemento dado
    // Parámetro: elemento a eliminar
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    void eliminar (int elementoAEliminar);
    
    // Imprime el árbol en forma de esquema tabulado
    // Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    void imprimir();
    
    // Destruye el árbol, liberando la memoria de todos los nodos
    // Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    ~ArbolBinarioDeBusqueda();
    
protected:
    
    // Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulación. Esta pensado para ser recursivo
    // Parámetros:
    // - subarbol: nodo raíz del subarbol que queremos imprimir
    // - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
    // - orientacion indica si subarbol (primer parametro) es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
    // Precondiciones:
    // - subarbol != NULL
    // - numeroTabulaciones>=0
    // - orientacion == 1 || orientacion == -1 || orientacion == 0
    // Complejidad temporal: O(n), tanto con la mejor topología (T(n)=1+2T(n/2)) como con la peor (T(n)=1+T(n-1))
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    // (n es el número de nodos del subarbol)
    void imprimirRecursivo (Nodo *subarbol, int numeroTabulaciones, int orientacion);
    
    // Elimina recursivamente los nodos de un subarbol
    // Parámetro: el nodo raíz del subarbol a eliminar
    // Precondición: subarbol != NULL
    // Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    // (n es el número de nodos del subarbol)
    void eliminarSubarbol (Nodo *raizSubarbol);
    
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
    
    // Buscar el maximo de un subarbol (ir por la rama derecha hasta llegar a la ultima hoja)
    // Parámetro: raiz del subarbol en donde buscar
    // Retorno: puntero al nodo que contiene el máximo
    // Precondicion: raizSubarbol != NULL
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    // (n es el número de nodos del subarbol)
    Nodo *buscarMaximo (Nodo *raizSubarbol);
    
    // Buscar el minimo de un subarbol (ir por la rama izquierda hasta llegar a la ultima hoja)
    // Parámetro: raiz del subarbol en donde buscar
    // Retorno: puntero al nodo que contiene el minimo
    // Precondicion: raizSubarbol != NULL
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    // (n es el número de nodos del subarbol)
    Nodo *buscarMinimo (Nodo *raizSubarbol);
    
    // Elimina el nodo pasado como parametro. Lo sustituye por un descendiente suyo (recursivamente)
    // Parámetros:
    // - nodoParaEliminar: puntero al nodo que queremos eliminar
    // Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
    // Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
    // (n es el número de nodos del subarbol que empieza en nodoParaEliminar)
    void eliminarNodo (Nodo *nodoParaEliminar);
};
