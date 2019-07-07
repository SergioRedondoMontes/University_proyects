//
//  main.cpp
//  div_ven_examples
//
//  Created by Sergio Redondo on 07/07/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <iostream>

/*
 La estructura de los siguientes ejemplos está formada por:
 
 Límite inferior(li): indica el comienzo de aplicación del algoritmo
 Límite superior(ls): indica el fin de aplicación del algoritmo
 Mitad: parámetro pivote del algoritmo para ir dividiéndo el vector en sucesivas mitades, es decir, dividir el problema inicial en subproblemas más sencillos
  */

/*
 Mayor elemento de un vector: este algoritmo «DyV» va reduciendo en mitades el vector para conseguir el mayor elemento de cada mitad y así sucesivamente hasta llegar al vector completo.Finalmente, se compara que máximo de cada parte es mayor de los dos y éste sería el mayor elemento del vector.
 */
int mayor(int *v,int li, int ls){
    if(li==ls)
        return v[li];
    else{
        int mitad = (li+ls)/2;
        int maxIzq = mayor(v,li,mitad);
        int maxDcha = mayor(v,mitad+1,ls);
        if(maxIzq>maxDcha)
            return maxIzq;
        else
            return maxDcha;
    }
}

/*
 Menor elemento de un vector: algoritmo idéntico al anterior, sin embargo, en esta ocasión nos quedamos con el menor de cada mitad.
 */
int menor(int *v,int li, int ls){
    if(li==ls)
        return v[li];
    else{
        int mitad = (li+ls)/2;
        int minIzq = menor(v,li,mitad);
        int minDcha = menor(v,mitad+1,ls);
        if(minIzq<minDcha)
            return minIzq;
        else
            return minDcha;
    }
}

/*
 Búsqueda de un elemento en un vector ordenado: a continuación se pueden apreciar la versión iterativa(sin aplicar DyV) y la recursiva aplicando la técnica.
 */
bool buscarRecursivo(int *v, int li,int ls,int e){
    bool encontrado = false;
    int mitad;
    
    if(li==ls){
        /*La longitud del vector es 1, por lo tanto
         el elemento solo puede estar en la primera posición*/
        encontrado = v[li]==e;
    }else{
        mitad = (li+ls)/2;//Posición mitad del vector
        if(v[mitad]==e)//Está en la mitad
            encontrado = true;
        else if(v[mitad]<e)//Es mayor que la mitad
            //Llamada recursiva con la segunda mitad del vector
            encontrado = buscarRecursivo(v,mitad+1,ls,e);
        else//Es menor que la mitad
            //Llamada recursiva con la primera mitad del vector
            encontrado = buscarRecursivo(v,li,mitad-1,e);
    }
    return encontrado;
}

/*
 Valor medio de un vector de enteros: algoritmo que aplica la técnica de forma muy parecida a los métodos anteriores, asimismo sería dividir y aplicar la operación por mitades.
 */
double media(int *v,int li, int ls){
    if(li==ls)
        return v[li];
    else{
        int mitad = (li+ls)/2;
        double mediaIzq = media(v,li,mitad);
        double mediaDcha = media(v,mitad+1,ls);
        return (mediaIzq+mediaDcha)/2;
    }
}





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
