#include <iostream>
#include <iomanip>
#include "shortable_int_Array.h"

int askSize()
{
    int sizeRow;
    do
    {
        std::cout << "Introduzca el tamaño del array: >=2 ";
        std::cin >> sizeRow;
    } while (sizeRow < 2);

    return sizeRow;
}

int main()
{
    //clock variables
    unsigned long startBubble, finishBubble, startSelection, finishSelection;
    int size = askSize();

    ShortableIntArray a(size);

    a.addRandomNumberToArray();

    std::cout << "El vector original es el siguiente:" << std::endl;
    if (size > 10)
        std::cout << "<Demasiados componentes para mostrar>" << std::endl;
    else
        a.writeOnConsole();

    startBubble = clock();
    std::cout << "Clocks de inicio con ordenacion por Burbuja: " << startBubble << std::endl;
    a.orderArrAlgBubble();
    finishBubble = clock();
    std::cout << "Clocks de fin con ordenacion por Burbuja: " << finishBubble << std::endl;
    std::cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
    std::cout << std::setprecision(5) << std::fixed << "Con ordenacion por burbuja ha tardado " << (finishBubble - startBubble) / (float)CLOCKS_PER_SEC << " segundos en ordenarlo." << std::endl;
    if (size > 10)
        std::cout << "<Demasiados componentes para mostrar>" << std::endl;
    else
        a.writeOnConsole();
    std::cout << std::endl;
    std::cout << std::endl;

    ShortableIntArray b(size);

    b.addRandomNumberToArray();
    startSelection = clock();
    std::cout << "Clocks de inicio con ordenacion por Seleccion: " << startSelection << std::endl;
    b.orderArraAlgSelectionSort();
    finishSelection = clock();
    std::cout << "Clocks de fin con ordenacion por Seleccion: " << finishSelection << std::endl;
    std::cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
    std::cout << std::setprecision(5) << std::fixed << "Con ordenacion por seleccion ha tardado " << (finishSelection - startSelection) / (float)CLOCKS_PER_SEC << " segundos en ordenarlo." << std::endl;
    if (size > 10)
        std::cout << "<Demasiados componentes para mostrar>" << std::endl;
    else
        b.writeOnConsole();

    return 0;
}