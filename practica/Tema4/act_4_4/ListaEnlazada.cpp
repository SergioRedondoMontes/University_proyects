#include <iostream>
#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada()
{
    this->n = 0;
    this->lista = nullptr;
    this->lastAccess = -1;
    this->ultimoAcceso = nullptr;
}

Nodo *ListaEnlazada::getNodo(int posicion)
{

    if (lastAccess != -1)
    {
        if (posicion - 1 == lastAccess && posicion - 1 > 0)
        {
            ultimoAcceso = ultimoAcceso->anteriorNodo;
            return ultimoAcceso;
        }
        else if (posicion + 1 == lastAccess && posicion + 1 < n)
        {
            ultimoAcceso = ultimoAcceso->siguienteNodo;
            return ultimoAcceso;
        }
        else if (posicion == lastAccess)
        {
            return ultimoAcceso;
        }
    }

    int media = n / 2;
    if (posicion <= media)
    {
        Nodo *aux = lista;
        for (int i = 0; i < posicion; i++)
        {
            aux = aux->siguienteNodo;
        }
        ultimoAcceso = aux;
        return aux;
    }
    else
    {
        Nodo *aux = lista->anteriorNodo;
        // std::cout << "POSIcion: " << posicion << std::endl;
        // std::cout << "n: " << n << std::endl;
        // std::cout << "POSI: " << index << std::endl;
        for (int i = n - 1; i > posicion; i--)
        {
            aux = aux->anteriorNodo;
        }
        ultimoAcceso = aux;
        return aux;
    }

    //assert(posicion >= 0 && this->n>0);
}
// std::cout << "AUX Sig:" << aux->siguienteNodo->elemento << " AUX Ant: " << aux->anteriorNodo->elemento << std::endl;

int ListaEnlazada::getValor(int posicion)
{
    //assert(posicion >= 0 && this->n>0);
    return getNodo(posicion)->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor)
{
    //assert(posicion >= 0 && this->n>0);
    getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN()
{
    return this->n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor)
{
    Nodo *temp = (Nodo *)malloc(sizeof(Nodo));
    temp->elemento = nuevoValor;
    //std::cout << std::endl;
    //std::cout << "Insert " << posicion << " value " << nuevoValor << std::endl;
    if (lista == nullptr)
    {
        temp->siguienteNodo = temp;
        temp->anteriorNodo = temp;
        this->lista = temp;
    }
    else
    {

        if (posicion == 0)
        {
            temp->anteriorNodo = lista->anteriorNodo;
            temp->siguienteNodo = lista;

            lista->anteriorNodo->siguienteNodo = temp;
            lista->anteriorNodo = temp;

            lista = temp;
        }
        else
        {
            Nodo *aux = getNodo(posicion - 1);

            temp->siguienteNodo = aux->siguienteNodo;
            temp->anteriorNodo = aux;
            aux->siguienteNodo->anteriorNodo = temp;
            aux->siguienteNodo = temp;
        }
    }

    this->n++;
}

void ListaEnlazada::eliminar(int posicion)
{

    Nodo *drop = getNodo(posicion);

    if (n == 1)
    {
        this->lista = nullptr;
    }
    else
    {
        drop->anteriorNodo->siguienteNodo = drop->siguienteNodo;
        drop->siguienteNodo->anteriorNodo = drop->anteriorNodo;

        // std::cout << "Ant: " << drop->siguienteNodo->anteriorNodo->elemento << std::endl;
        // std::cout << "Sig: " << drop->siguienteNodo->siguienteNodo->elemento << std::endl;

        if (posicion == 0)
            lista = drop->siguienteNodo;
    }

    free(drop);
    this->n--;
}

ListaEnlazada::~ListaEnlazada()
{
}