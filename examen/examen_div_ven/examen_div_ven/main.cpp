//
//  main.cpp
//  examen_div_ven
//
//  Created by Sergio Redondo on 19/06/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <iostream>


using namespace std;



//bool esOrdenada(int a[], int _size){
//    int size = _size;
//    std::cout << "SIZE: " << size << std::endl;
//
//    if(size>2){
//
//        if((size/2)%2 == 0){
//            size = size/2;
//            int b[size];
//            int c[size];
//            int tmp = 0;
//            for (int i = 0; i<size; i++) {
//                b[i] = a[i];
//                std::cout << "b: " << b[i] << " I: " << i << std::endl;
//            }
//             std::cout << "sizeB: " << size << std::endl;
//            for (int i = size; i<size*2; i++) {
//                c[tmp] = a[i];
//                std::cout << "c: " << c[tmp] << std::endl;
//                tmp++;
//            }
//            std::cout << "sizec: " << size << std::endl;
//
//            esOrdenada(b,size);
//            esOrdenada(c,size);
//        }
//
//    }else{
////        std::cout << "ELSE................... " << std::endl;
//        return true;
//    }
////    std::cout << "false................... " << std::endl;
//
//    return false;
//}


/*
 Comprobamos los extremos de los pequeños arrays para ver si estan ordenados de menor a mayor.
 */
bool checkArr(int a[], int size){
    if (a[size-1]<=a[size]) {
        cout << "0: " << a[size-1] << "    1: " << a[size] << endl;
        return true;
    }else{
        return false;
    }
}



bool esOrdenada(int a[], int size){
    int sizeTmp = size/2;
    if(checkArr(a, sizeTmp)){
        if(sizeTmp>1){
            int b[sizeTmp];
            int c[sizeTmp];
            int tmp = 0;
            for (int i = 0; i<sizeTmp; i++) {
                b[i] = a[i];
                std::cout << "b: " << b[i] << " I: " << i << std::endl;
            }
             std::cout << "sizeB: " << sizeTmp << std::endl;
            for (int i = sizeTmp; i<sizeTmp*2; i++) {
                c[tmp] = a[i];
                std::cout << "c: " << c[tmp] << std::endl;
                tmp++;
            }
            std::cout << "sizec: " << sizeTmp << std::endl;
            if(!esOrdenada(b,sizeTmp)) return false;
            if(!esOrdenada(c,sizeTmp)) return false;
            return true;
        }else{
            return true;
        }
    }else{
        return false;
    }
}



int main(int argc, const char * argv[]) {
    int size = 6;
    int a[size];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 5;
    a[5] = 6;
//    a[6] = 6;
//    a[7] = 7;

    std::cout << esOrdenada(a, size) << std::endl;

    // insert code here...
    return 0;
}
