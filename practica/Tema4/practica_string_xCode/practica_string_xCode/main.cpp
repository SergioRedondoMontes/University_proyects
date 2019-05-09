#include "impresionListasEnlazadas.h"



using namespace std;

int main()
{
//    Mystr a = Mystr("casa");
//    a.print();
//    Mystr b = Mystr("verde");
//    if (a != b) {
//        cout << "iguales" << endl;
//    }else{
//        cout << "no iguales" << endl;
//
//    }
//    Mystr(a+b).print();
//    cout << a[2];
    /*
     1. " DOWN DOWN END_ ”
     2. “ RULETA MOLA MAZO EHHH “
     3. “ NOOO CONFUNDAS ESTA TAREA “
     4. “ PEPE PAPA PIPI POPO PUPU “
     5. “ UP__ UP__ UP__ “
     */
    
    Mystr down = Mystr("DOWN");
    Mystr up = Mystr("UP__");
    Mystr end = Mystr("END_");
    Mystr uno = Mystr(" DOWN DOWN END_ ");
    Mystr dos = Mystr(" RULETA MOLA MAZO EHHH ");
    Mystr tres = Mystr(" NOOO CONFUNDAS ESTA TAREA ");
    Mystr cuatro = Mystr(" PEPE PAPA PIPI POPO PUPU ");
    Mystr cinco = Mystr(" UP__ UP__ UP__ ");
    ListaEnlazada lista;
    lista.insertar(0, uno);
    lista.insertar(1, dos);
    lista.insertar(2, tres);
    lista.insertar(3, cuatro);
    lista.insertar(4, cinco);
    imprimirListaEnlazada(&lista);
    bool exit = false, direction = false;
    int index = 0, num = 4;
    while (!exit) {
        Mystr aux = lista.getValor(index);
        aux.Trim();
        aux.print();
        if (aux.StartsWith(down)) {
            direction = false;
        }else if(aux.StartsWith(up)){
            direction = true;
        }else if(aux.StartsWith(end)){
            exit = true;
        }
         lista.setValor(index, aux.Right(aux.Length()-num));
        
        if(direction){
            index--;
        }else{
            index++;
        }
    }
    
    
    return 0;
}
