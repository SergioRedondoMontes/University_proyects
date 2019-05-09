//
//  Orden.hpp
//  practica3
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <stdio.h>
#include "ListaContigua.h"


#define ASC 0 // de menor a mayor
#define DESC 1 // de mayor a menor

class Orden{

public:
    
    void selectionSort(ListaContigua *lista, int orden);
    void insertionSort(ListaContigua *lista, int orden);
    void bubbleSort(ListaContigua *lista, int orden);
    void mergeSort(ListaContigua *lista, int orden);
    void quickSort(ListaContigua *lista, int orden);
    void rangeSort(ListaContigua *lista, int orden);
    void mostrarLista(ListaContigua *lista);
    bool isOrdenada(ListaContigua *lista, int orden);
    
protected:
    void swapData(ListaContigua *lista, int i, int min);
    void merge(ListaContigua *lista, int orden, int l, int m, int r);
    void mergeSortRecursive(ListaContigua *lista, int orden, int l, int r);
    int partition (ListaContigua *lista, int orden, int low, int high);
    void quickSortRecursive(ListaContigua *lista, int orden, int low, int high);
};
