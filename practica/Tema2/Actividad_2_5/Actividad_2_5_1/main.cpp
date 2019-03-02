#include <iostream>
#include "shortable_racional_array.h"

int askSize()
{
    int size;
    do
    {
        std::cout << "Introduzca el tamaño del array: ";
        std::cin >> size;
    } while (size < 1);

    return size;
}

int main()
{
    int size = askSize();

    ShortableRacionalArray arr(size);
    arr.addRandomRacionalToArrRacionals();
    arr.writeOnConsole();
    arr.orderArrRacionals();
    arr.writeOnConsole();

    return 0;
}