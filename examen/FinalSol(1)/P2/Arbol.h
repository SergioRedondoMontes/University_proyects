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
	bool espejo(Arbol *I, Arbol *D); // comprueba si un arbol es espejo de otro
	Arbol *buscar(int valor);  // busca y devuelve el puntero a nodo con el valor, o NULL si no lo encuentra
public:
	Arbol(int valor);
	~Arbol();
	bool Insertar(int valorNuevo, int valorPadre, int Orientacion);  // insertar valorNuevo como un nodo hijo izquierdo o rerecho de valorPadre según la orientación
	bool Simetrico();   // comprueba si un arbol es simetrico
};


