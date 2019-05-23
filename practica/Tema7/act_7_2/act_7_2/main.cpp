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

int main () {
    
    ArbolBinarioDeBusqueda arbol;
    
    // Creamos la lista de inserciones
    int inserciones[] = {5, 1, 6, 3, 7, 2, 4};
    
    // Vamos insertando e imprimiendo
    for (int i=0; i<7; i++) {
        cout << "Insercion de " << inserciones[i] << ":\n";
        arbol.insertar(inserciones[i]);
        arbol.imprimir();
    }
//    
//    cout << "Eliminamos 5\n";
//    arbol.eliminar(5);
//    arbol.imprimir();
//    
//    cout << "Eliminamos 6\n";
//    arbol.eliminar(6);
//    arbol.imprimir();
//    
//    cout << "Eliminamos 4\n";
//    arbol.eliminar(4);
//    arbol.imprimir();
//    
//    cout << "Eliminamos 7\n";
//    arbol.eliminar(7);
//    arbol.imprimir();
//    
    
}
