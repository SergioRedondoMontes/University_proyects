#include <iostream>
#include "shortable_int_matriz.h"

int askSizeRow()
{
    int sizeRow;
    do
    {
        std::cout << "Introduzca el tamaño de la matriz: ";
        std::cin >> sizeRow;
    } while (sizeRow < 1);

    return sizeRow;
}

int askSizeCol()
{
    int sizeCol;
    do
    {
        std::cout << "Introduzca el tamaño del array: ";
        std::cin >> sizeCol;
    } while (sizeCol < 1);

    return sizeCol;
}

int main()
{
    //clock variables
    unsigned long startBubble, finishBubble;
    int sizeRow = askSizeRow();
    int sizeCol = askSizeCol();

    ShortableIntMatriz a(sizeRow, sizeCol);

    a.addRandomNumberToMatrix();
    a.writeOnConsole();
    startBubble = clock();
    std::cout << "Clocks de inicio con ordenacion por Burbuja: " << startBubble << std::endl;

    a.orderArrAlgBubblesReverse();
    finishBubble = clock();
    std::cout << "Clocks de fin con ordenacion por Burbuja: " << (finishBubble) << std::endl;
    a.writeOnConsole();

    return 0;
}