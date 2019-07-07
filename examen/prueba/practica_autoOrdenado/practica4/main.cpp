//
//  main.cpp
//  act_7_2
//
//  Created by Sergio Redondo on 06/05/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//
#include "iostream"
#include "ArbolBinarioDeBusqueda.h"

using namespace std;


void insertRandomNumbers(ArbolBinarioDeBusqueda* arbol){
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        arbol->insertar(rand() % 100);
    }
}

int main () {
    
    ArbolBinarioDeBusqueda arbol;
    
    // Creamos la lista de inserciones  8,3,1,6,4,7,10,14,13
//    int inserciones[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
//
//    // Vamos insertando e imprimiendo
//    for (int i = 0; i < 9; i++) {
//        cout << "Insercion de " << inserciones[i] << ":\n";
//        arbol.insertar(inserciones[i]);
//    }
//    arbol.imprimir(INORDER);
//    arbol.imprimir(PREORDER);
//    arbol.imprimir(POSTORDER);
//
    //menu
    
    int num = 0;
    while (num != 6) {
        printf(" 1 Introducir número \n 2 Introducir 50 números aleatorios \n 3 Eliminar un número \n 4 Mostrar Inorder \n 5 Mostrar Preorder \n 6 Mostrar Postorder \n 7 Salir \n");
        std::cin >> num;
        if (num == 1) {
            int tmp = 0;
            std::cin >> tmp;
            arbol.insertar(tmp);
        }else if(num == 2){
            insertRandomNumbers(&arbol);
        }else if(num == 3){
            int tmp = 0;
            std::cin >> tmp;
            arbol.Eliminar(tmp);
            printf("\n");
        }else if(num == 4){
            arbol.imprimir(INORDER);
            printf("\n");
        }else if(num == 5){
            arbol.imprimir(PREORDER);
            printf("\n");
        }else if(num == 6){
            arbol.imprimir(POSTORDER);
            printf("\n");
        }else if(num>7){
            printf("Inserte un numero valido \n\n");
        }
    }
}
