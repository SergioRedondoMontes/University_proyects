
#include <iostream>

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

int askNumOfArray()
{
    int sizeArr;
    do
    {
        std::cout << "Introduzca el numero de arrays: >=1 ";
        std::cin >> sizeArr;
    } while (sizeArr < 1);

    return sizeArr;
}

int *addRandomNumberToArray(int size, int *arrTemp)
{
    for (int i = 0; i < size; i++)
        arrTemp[i] = rand() % 100;
    return arrTemp;
}

/* orderArrAlgInsertion
 * Movemos los elementos del array mientras que aux sea mas grande que la posicion actual
 * 
 * Parameters:  Size    -> tamaño del array >=1
 *              arrTemp -> array con elementos a ordenar
*/
void orderArrAlgInsertion(int size, int *arrTemp)
{
    int n, aux;
    for (int i = 1; i < size; i++) //recorremos desde 1 hasta i-1 porque la posicion 0 no hace falta
    {
        aux = arrTemp[i]; //igualamos la variable aux al valor que vamos a comparar con los anteriores
        n = i - 1;
        while (n >= 0 & arrTemp[n] > aux)
        {
            arrTemp[n + 1] = arrTemp[n];
            n--;
        }
        arrTemp[n + 1] = aux;
    }
}

void writeOnConsole(int size, int *arrTemp)
{
    if (size > 10)
        std::cout << "<Demasiados componentes para mostrar>" << std::endl;
    else
        for (int j = 0; j < size; j++)
        {
            std::cout << arrTemp[j] << " ";
        }
    std::cout << std::endl;
}

int main()
{
    int size, numArr;
    int *arrVector = (int *)malloc(size * sizeof(int));
    int *arrVector2 = (int *)malloc(size * sizeof(int));

    srand(time(NULL));

    size = askSize();
    numArr = askNumOfArray();

    addRandomNumberToArray(size, &*arrVector);
    writeOnConsole(size, arrVector);
    orderArrAlgInsertion(size, arrVector);
    writeOnConsole(size, arrVector);
    //borrar
    addRandomNumberToArray(size, &*arrVector2);
    writeOnConsole(size, arrVector2);
    orderArrAlgInsertion(size, arrVector2);
    writeOnConsole(size, arrVector2);

    return 0;
}
