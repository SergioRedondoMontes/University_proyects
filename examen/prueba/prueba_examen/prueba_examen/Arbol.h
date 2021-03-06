#pragma once

#include <assert.h>
#include <stdio.h>
#include <iostream>

#define HIJO_IZQ -1
#define HIJO_DER 1

class Arbol {
	int valor;
	Arbol *izq;  //sub-arbol izquierdo
	Arbol *der;  //sub-arbol derecho
	void deleteArbol();// elimina los dos subarboles izquierda y derecha del nodo
    Arbol *buscarValor(Arbol *arbol,int valor);
    bool espejo(Arbol *I, Arbol *D); // comprueba si un arbol es espejo de otro


public:
	Arbol(int valor);
	~Arbol();
	bool Insertar(int valorNuevo, int valorPadre, int Orientacion);  
	bool Simetrico();   
};
