//
//  main.cpp
//  practica3
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <iostream>
#include "Orden.h"
#include <ctime>

int main(int argc, const char* argv[]) {
    // insert code here...
    int size;
    std::cout << "Insertar el size: ";
    std::cin >> size;
    
    // Es necesario *?
    ListaContigua generic, selectionAsc, selectionDesc, insertionAsc, insertionDesc, bubbleAsc, bubbleDesc, mergeAsc, mergeDesc, quickAsc, quickDesc, rangeAsc, rangeDesc;//por hacer range
    Orden orden;
    
    float numeroClicksInicio, numeroClicksFin, segundosTranscurridos;
    
    
    
    srand(time(NULL));
    //int *temp = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        generic.insertarAlFinal(rand() % 100);
    }
    
//    orden.mostrarLista(&generic);
    //Caso general
    selectionAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.selectionSort(&selectionAsc, ASC);
    //    orden.mostrarLista(&selectionAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por Seleccion en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&selectionAsc, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Mejor caso
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.selectionSort(&selectionAsc, ASC);
    //    orden.mostrarLista(&selectionAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por Seleccion en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&selectionAsc, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Peor caso
    selectionDesc = ListaContigua(selectionAsc);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.selectionSort(&selectionDesc, DESC);
//    orden.mostrarLista(&selectionDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por Seleccion en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&selectionDesc, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Caso general
    insertionAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.insertionSort(&insertionAsc, ASC);
    //    orden.mostrarLista(&insertionAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por insertionSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&insertionAsc, ASC) == false) printf(">>>> EL ALGORITMO insertionSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Mejor caso
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.insertionSort(&insertionAsc, ASC);
    //    orden.mostrarLista(&insertionAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por insertionSort en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&insertionAsc, ASC) == false) printf(">>>> EL ALGORITMO insertionSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Peor caso
    insertionDesc = ListaContigua(selectionAsc);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.insertionSort(&insertionDesc, DESC);
//    orden.mostrarLista(&insertionDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por insertionSort en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&insertionDesc, DESC) == false) printf(">>>> EL ALGORITMO insertionSort DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Caso general
    bubbleAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.bubbleSort(&bubbleAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por bubbleSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&bubbleAsc, ASC) == false) printf(">>>> EL ALGORITMO bubbleSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    
    //Mejor caso
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.bubbleSort(&bubbleAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por bubbleSort en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&bubbleAsc, ASC) == false) printf(">>>> EL ALGORITMO bubbleSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Peor caso
    bubbleDesc = ListaContigua(bubbleAsc);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.bubbleSort(&bubbleDesc, DESC);
//    orden.mostrarLista(&bubbleDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por bubbleSort en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&bubbleDesc, DESC) == false) printf(">>>> EL ALGORITMO bubbleSort DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    
    //Caso general
    mergeAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.mergeSort(&mergeAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por mergeSort en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&mergeAsc, ASC) == false) printf(">>>> EL ALGORITMO mergeSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Mejor caso
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.mergeSort(&mergeAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por mergeSort en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&mergeAsc, ASC) == false) printf(">>>> EL ALGORITMO mergeSort ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Peor caso
    mergeDesc = ListaContigua(mergeAsc);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.mergeSort(&mergeDesc, DESC);
//    orden.mostrarLista(&mergeDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por mergeSort en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&mergeDesc, DESC) == false) printf(">>>> EL ALGORITMO mergeSort DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    
    //Caso genral
    quickAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.quickSort(&quickAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por QUICK SORT en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&quickAsc, ASC) == false) printf(">>>> EL ALGORITMO QUICK SORT ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Mejor caso
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.quickSort(&quickAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por QUICK SORT en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&quickAsc, ASC) == false) printf(">>>> EL ALGORITMO QUICK SORT ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Peor caso
    quickDesc = ListaContigua(quickAsc);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.quickSort(&quickDesc, DESC);
//    orden.mostrarLista(&quickDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por QUICK SORT en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&quickDesc, DESC) == false) printf(">>>> EL ALGORITMO QUICK SORT DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    
    //Caso genral
    rangeAsc = ListaContigua(generic);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.rangeSort(&quickAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por RANGE SORT en caso general he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&quickAsc, ASC) == false) printf(">>>> EL ALGORITMO RANGE SORT ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Mejor caso
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.rangeSort(&rangeAsc, ASC);
    //    orden.mostrarLista(&bubbleAsc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por RANGE SORT en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&rangeAsc, ASC) == false) printf(">>>> EL ALGORITMO RANGE SORT ASC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    //Peor caso
    rangeDesc = ListaContigua(rangeAsc);
    numeroClicksInicio = clock();
    //    orden.mostrarLista(&generic);
    orden.rangeSort(&rangeDesc, DESC);
//    orden.mostrarLista(&rangeDesc);
    numeroClicksFin = clock();
    segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
    printf("Con ordenacion por RANGE SORT en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
    if (orden.isOrdenada(&quickDesc, DESC) == false) printf(">>>> EL ALGORITMO RANGE SORT DESC NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");
    
    
    
    return 0;
}
