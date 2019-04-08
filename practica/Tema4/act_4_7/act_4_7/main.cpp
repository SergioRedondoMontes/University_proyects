#include "iostream"
#include "Pila.h"
#include "impresionListasEnlazadas.h"
#include <string>

using namespace std;

int postfija(string str){
    Pila pila;
    int num1, num2;
    char tmp;
    
    for (int i = 0; i < str.size(); i++) {
        tmp = str.at(i);
        if (tmp == '+') {
            
            num1 = pila.pop();
            num2 = pila.pop();
            pila.push(num1+num2);
            
        }else  if (tmp == '*'){
            
            num1 = pila.pop();
            num2 = pila.pop();
            pila.push(num1*num2);
            
        }
        else{
            pila.push(tmp-'0');
        }
        
    }
    return pila.pop();
}

int main()
{
    string str;
    cin >> str;
    cout << postfija(str) << endl;
	return 0;
}
