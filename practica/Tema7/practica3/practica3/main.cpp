//
//  main.cpp
//  practica3
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <iostream>
#include "Orden.h"
    
int main(int argc, const char * argv[]) {
    // insert code here...
    int size;
    std::cout << "Insertar el size: ";
    std::cin >> size;
    
    // Es necesario *?
    ListaContigua generic, selectionAsc, selectionDesc, insertionAsc, insertionDesc, bubbleAsc, bubbleDesc, mergeAsc, mergeDesc, quickAsc, quickDesc, rangeAsc, rangeDesc;
    Orden orden;
    
    float numeroClicksInicio, numeroClicksFin, segundosTranscurridos;
    
    srand(time(NULL));
    //int *temp = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        generic.insertarAlFinal(rand() % 100);
    }
    
    orden.mostrarLista(&generic);

    selectionAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
//    orden.mostrarLista(&generic);
    orden.selectionSort(&selectionAsc, ASC);
    orden.mostrarLista(&selectionAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por Seleccion en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&selectionAsc, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");


    selectionDesc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.selectionSort(&selectionDesc, DESC);
        orden.mostrarLista(&selectionDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por Seleccion en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&selectionDesc, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");


    insertionAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
//    orden.mostrarLista(&generic);
    orden.insertionSort(&insertionAsc, ASC);
    orden.mostrarLista(&insertionAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por insertionSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&insertionAsc, ASC) == false) printf(">>>> EL ALGORITMO insertionSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

    insertionDesc = ListaContigua(generic);
    numeroClicksInicio = clock();
//    orden.mostrarLista(&generic);
    orden.insertionSort(&insertionDesc, DESC);
    orden.mostrarLista(&insertionDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por insertionSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&insertionDesc, DESC) == false) printf(">>>> EL ALGORITMO insertionSort DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");


    bubbleAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
//    orden.mostrarLista(&generic);
    orden.bubbleSort(&bubbleAsc, ASC);
    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por bubbleSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&bubbleAsc, ASC) == false) printf(">>>> EL ALGORITMO bubbleSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

    bubbleDesc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.bubbleSort(&bubbleDesc, DESC);
        orden.mostrarLista(&bubbleDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por bubbleSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&bubbleDesc, DESC) == false) printf(">>>> EL ALGORITMO bubbleSort DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");




    mergeAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.mergeSort(&mergeAsc, ASC);
        orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por mergeSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&mergeAsc, ASC) == false) printf(">>>> EL ALGORITMO mergeSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");


    mergeDesc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.mergeSort(&mergeDesc, DESC);
        orden.mostrarLista(&mergeDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por mergeSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&mergeDesc, DESC) == false) printf(">>>> EL ALGORITMO mergeSort DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");



    quickAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.quickSort(&quickAsc, ASC);
        orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por QUICK SORT en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&quickAsc, ASC) == false) printf(">>>> EL ALGORITMO QUICK SORT ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

    quickDesc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.quickSort(&quickDesc, DESC);
        orden.mostrarLista(&quickDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por QUICK SORT en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&quickDesc, DESC) == false) printf(">>>> EL ALGORITMO QUICK SORT DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

    
    rangeAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.quickSort(&rangeAsc, ASC);
        orden.mostrarLista(&rangeAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por range SORT en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&rangeAsc, ASC) == false) printf(">>>> EL ALGORITMO range SORT ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    rangeDesc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.quickSort(&rangeDesc, DESC);
    orden.mostrarLista(&rangeDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por range SORT en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&rangeDesc, DESC) == false) printf(">>>> EL ALGORITMO range SORT DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
   
    return 0;
}
