//
//  Orden.cpp
//  practica3
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include "Orden.h"
#include <iostream>

void Orden::selectionSort(ListaContigua *lista, int orden){
    int min;
    for (int i = 0; i < lista->getN(); i++)
    {
        min = i;
        for (int j = i + 1; j < lista->getN(); j++)
        {
            if(orden == ASC){
                if (lista->getValor(min) > lista->getValor(j))
                {
                    min = j;
                }
            }else{
                if (lista->getValor(min) < lista->getValor(j))
                {
                    min = j;
                }
            }
            
        }
        swapData(lista, i, min);
    }
}

void Orden::swapData(ListaContigua *lista, int i, int min)
{
    int aux;
    aux =  lista->getValor(i);
    lista->setValor(i, lista->getValor(min));
    lista->setValor(min, aux);
}

void Orden::insertionSort(ListaContigua *lista, int orden){
    int n, aux;
    int index =lista->getN();
    for (int j = 1; j < index; j++)
    {
        aux = lista->getValor(j);
        n = j - 1;
        if(orden == ASC){
            while (n >= 0 && lista->getValor(n) > aux)
            {
                
                lista->setValor(n + 1, lista->getValor(n));
                n--;
            }
            lista->setValor(n + 1, aux);
        }else{
            while (n >= 0 && lista->getValor(n) < aux)
            {
                
                lista->setValor(n + 1, lista->getValor(n));
                n--;
            }
            lista->setValor(n + 1, aux);
        }
        
    }
}


void Orden::bubbleSort(ListaContigua *lista, int orden){
    int temp;
    
    for (int h = 1; h < lista->getN(); h++)
    {
        for (int j = 0; j < lista->getN() - 1; j++){
            if(orden == ASC){
                if (lista->getValor(j) > lista->getValor(j+1))
                {
                    temp = lista->getValor(j);
                    lista->setValor(j, lista->getValor(j+1));
                    lista->setValor(j+1, temp);
                }
            }else{
                if (lista->getValor(j) < lista->getValor(j+1))
                {
                    temp = lista->getValor(j);
                    lista->setValor(j, lista->getValor(j+1));
                    lista->setValor(j+1, temp);
                }
            }
            
        }
    }
}
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void Orden::merge(ListaContigua *lista, int orden, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays
    int L[n1], R[n2]; */
    ListaContigua L, R;
    
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L.insertarAlFinal(lista->getValor(l+i));
    for (j = 0; j < n2; j++)
        R.insertarAlFinal(lista->getValor(m + 1+ j));
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    
    
    while (i < n1 && j < n2)
    {
        if (orden == ASC) {
            if (L.getValor(i) <= R.getValor(j))
            {
                lista->setValor(k, L.getValor(i));
                i++;
            }
            else
            {
                lista->setValor(k, R.getValor(j));
                j++;
            }
            k++;
        }else{
            if (L.getValor(i) >= R.getValor(j))
            {
                lista->setValor(k, L.getValor(i));
                i++;
            }
            else
            {
                lista->setValor(k, R.getValor(j));
                j++;
            }
            k++;
        }
        
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        lista->setValor(k, L.getValor(i));
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        lista->setValor(k, R.getValor(j));
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void Orden::mergeSortRecursive(ListaContigua *lista, int orden, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSortRecursive(lista, orden, l, m);
        mergeSortRecursive(lista, orden, m+1, r);
        
        merge(lista, orden, l, m, r);
    }
}
void Orden::mergeSort(ListaContigua *lista, int orden){
    mergeSortRecursive(lista, orden, 0, lista->getN()-1);
}

void Orden::quickSort(ListaContigua *lista, int orden){
    quickSortRecursive(lista, orden, 0, lista->getN()-1);
}

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int Orden::partition (ListaContigua *lista, int orden, int low, int high)
{
    int pivot = lista->getValor(high);    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
         if (orden == ASC) {
             // If current element is smaller than or
             // equal to pivot
             if (lista->getValor(j) <= pivot)
             {
                 i++;    // increment index of smaller element
                 /*           swap(&arr[i], &arr[j]);            */
                 int temp = lista->getValor(i);
                 lista->setValor(i, lista->getValor(j));
                 lista->setValor(j, temp);
                 
             }
         }
         else{
             // If current element is smaller than or
             // equal to pivot
             if (lista->getValor(j) >= pivot)
             {
                 i++;    // increment index of smaller element
                 /*           swap(&arr[i], &arr[j]);            */
                 int temp = lista->getValor(i);
                 lista->setValor(i, lista->getValor(j));
                 lista->setValor(j, temp);
                 
             }
        }
        
    }
//    swap(&arr[i + 1], &arr[high]);
    int temp = lista->getValor(i+1);
    lista->setValor(i+1, lista->getValor(high));
    lista->setValor(high, temp);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low  --> Starting index,
 high  --> Ending index */
void Orden::quickSortRecursive(ListaContigua *lista, int orden, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(lista, orden, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSortRecursive(lista, orden, low, pi - 1);
        quickSortRecursive(lista, orden, pi + 1, high);
    }
}

void Orden::rangeSort(ListaContigua *lista, int orden){
    int arr[100], index = 0;;
    
    for (int i = 0; i < 100; i++) {
        arr[i]=0;
    }
    
    for (int i = 0; i < lista->getN(); i++) {
        arr[lista->getValor(i)]++;
    }
    
    if (orden == ASC) {
        for (int i = 0; i < 100; i++) {
                for (int j = 0; j < arr[i]; j++) {
                    lista->setValor(index,i);
                    index++;
                }
        }
    }else{
        for (int i = 99; i >= 0; i--) {
            for (int j = 0; j < arr[i]; j++) {
                lista->setValor(index,i);
                index++;
            }
        }
    }
}

void Orden::mostrarLista(ListaContigua *lista){
    for(int i = 0; i < lista->getN(); i++){
        std::cout << lista->getValor(i) << " ";
    }
    std::cout << std::endl;
}

bool Orden::isOrdenada(ListaContigua *lista, int orden){
    
    for (int i = 1; i < lista->getN(); i++) {
        
        if(orden == ASC){
            if (lista->getValor(i - 1) > lista->getValor(i)) return(false);
        }else{
            if (lista->getValor(i - 1) < lista->getValor(i)) return(false);
        }
    }
    return true;
}
