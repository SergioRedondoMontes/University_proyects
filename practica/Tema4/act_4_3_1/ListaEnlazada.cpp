#include "ListaEnlazada.h"
#include <stddef.h>
#include <iostream>

ListaEnlazada::ListaEnlazada()
{
    this->lista = NULL;
    this->n = 0;
}

Nodo *ListaEnlazada::getNodo(int posicion)
{
    assert(n > 0 && posicion < n && posicion >= 0);

    Nodo *nextNode;
    nextNode = lista;
    for (int i = 0; i < posicion; i++)
    {
        nextNode = nextNode->siguienteNodo;
    }
    return nextNode;
}

int ListaEnlazada::getValor(int posicion)
{
    assert(n > 0 && posicion < n && posicion >= 0);
    Nodo *actualNode = getNodo(posicion);
    return actualNode->elemento;
}
int ListaEnlazada::getN()
{
    return this->n;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor)
{
    assert(posicion < n && posicion >= 0);
    Nodo *actualNode = (Nodo *)malloc(sizeof(Nodo));
    actualNode = getNodo(posicion);
    actualNode->elemento = nuevoValor;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor)
{
    assert(posicion <= n && posicion >= 0);

    Nodo *nodoNuevo = new Nodo;
    nodoNuevo->elemento = nuevoValor;

    if (posicion == 0)
    {
        nodoNuevo->siguienteNodo = lista;
        lista = nodoNuevo;
    }
    else
    {
        Nodo *nodoAnterior = getNodo(posicion - 1);
        nodoNuevo->siguienteNodo = nodoAnterior->siguienteNodo;
        nodoAnterior->siguienteNodo = nodoNuevo;
    }

    this->n++;
}
void ListaEnlazada::eliminar(int posicion)
{
    assert(n > 0 && posicion < n && posicion >= 0);

    Nodo *nodoEliminar;

    if (posicion == 0)
    {
        nodoEliminar = lista;
        Nodo *nodoSiguiente = nodoEliminar->siguienteNodo;
        lista = nodoSiguiente;
    }
    else
    {
        Nodo *nodoAnterior = getNodo(posicion - 1);
        nodoEliminar = nodoAnterior->siguienteNodo;
        Nodo *nodoSiguiente = nodoAnterior->siguienteNodo;
        nodoAnterior->siguienteNodo = nodoSiguiente;
    }

    delete (nodoEliminar);

    this->n--;
}

void ListaEnlazada::invertir()
{
    if (getN() < 0)
        return;

    Nodo *anteriorNode, *actualNode, *siguienteNodo;
    anteriorNode = lista;
    actualNode = anteriorNode->siguienteNodo;

    do
    {
        siguienteNodo = actualNode->siguienteNodo;
        actualNode->siguienteNodo = anteriorNode;
        anteriorNode = actualNode;
        actualNode = siguienteNodo;
    } while (siguienteNodo != NULL);

    lista->siguienteNodo = NULL;
    lista = anteriorNode;
}

ListaEnlazada::~ListaEnlazada()
{
    while (n > 0)
    {
        eliminar(0);
    }
}
