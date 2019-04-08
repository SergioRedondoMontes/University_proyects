#include "iostream"
#include "Pila.h"
#include "impresionListasEnlazadas.h"
#include <string>

using namespace std;

int main()
{
    Pila pila;
    string str;
    int num1, num2;
    char tmp;
    
    cout << "enter string";
    cin >> str;
    
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
    cout << pila.pop() << endl;
    
	return 0;
}
