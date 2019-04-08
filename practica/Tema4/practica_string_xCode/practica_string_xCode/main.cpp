#include <iostream>
#include <string>
#include "Mystr.h"

using namespace std;

int main()
{
    Mystr a = Mystr("casa");
    a.imprimir();
    Mystr b = Mystr("verde");
    if (a != b) {
        cout << "iguales" << endl;
    }else{
        cout << "no iguales" << endl;

    }
    Mystr(a+b).imprimir();
    cout << a[2];
    
    return 0;
}
