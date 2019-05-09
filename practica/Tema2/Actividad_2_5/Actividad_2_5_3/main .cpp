#include <iostream>
#include <iomanip>

int askSize()
{
    int sizeRow;
    do
    {
        std::cout << "Introduzca el tamaño de la matriz: >=2 ";
        std::cin >> sizeRow;
    } while (sizeRow < 2);

    return sizeRow;
}

int askNumOfArray()
{
    int sizeArr;
    do
    {
        std::cout << "Introduzca el tamaño del array: >=1 ";
        std::cin >> sizeArr;
    } while (sizeArr < 1);

    return sizeArr;
}

int **addRandomNumberToArray(int sizeRow, int sizeCol, int **arrMatrix)
{

    for (int i = 0; i < sizeRow; i++)
    {
        int *arrTemp = (int *)malloc(sizeCol * sizeof(int));
        for (int j = 0; j < sizeCol; j++)
        {
            arrTemp[j] = rand() % 100 + 1;
        }
        arrMatrix[i] = arrTemp;
    }

    return arrMatrix;
}

/* orderArrAlgInsertion
 * Movemos los elementos del array mientras que aux sea mas grande que la posicion actual
 * 
 * Parameters:  sizeRow    -> tamaño de la matriz >=1
 *              sizeCol    -> tamaño del array >=1
 *              arrTemp -> array con elementos a ordenar
*/
void orderArrInsertionSort(int sizeRow, int sizeCol, int **arrMatrix)
{

    int n, aux;
    for (int i = 0; i < sizeRow; i++)
    {

        //int *arrTemp = (int *)malloc(sizeCol * sizeof(int));
        for (int j = 1; j < sizeCol; j++) //recorremos desde 1 hasta i-1 porque la posicion 0 no hace falta
        {

            aux = arrMatrix[i][j]; //igualamos la variable aux al valor que vamos a comparar con los anteriores
            n = j - 1;

            //cout << "entra " << n << " " << arrTemp[n] << " " < < < < endl;
            while (n >= 0 & arrMatrix[i][n] > aux)
            {

                arrMatrix[i][n + 1] = arrMatrix[i][n];
                n--;
            }
            arrMatrix[i][n + 1] = aux;
        }
    }
}

int compareInt(const void *a, const void *b)
{
    /*if ( *(int*)a <  *(int*)b ) {return -1;}
  else if ( *(int*)a == *(int*)b ) {return 0;}
  else if ( *(int*)a >  *(int*)b ) {return 1;}*/
    if (*(int *)a < *(int *)b)
    {
        return -1;
    }
    else if (*(int *)a == *(int *)b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void orderArrQSort(int sizeRow, int sizeCol, int **arrMatrix)
{
    for (int i = 0; i < sizeRow; i++)
    {
        qsort(arrMatrix[i], sizeCol, sizeof(int), compareInt);
    }
}

void copyMatrix(int sizeRow, int sizeCol, int **arrMatrix, int **arrMatrixCopy)
{
    for (int i = 0; i < sizeRow; i++)
    {
        arrMatrixCopy[i] = (int *)malloc(sizeof(int) * sizeCol);

        memcpy(arrMatrixCopy[i], arrMatrix[i], sizeof(int) * sizeCol);
    }
}

float testTimeInsertion(int sizeRow, int sizeCol, int **arrMatrix)
{
    float startTime, endTime, totalTime;

    startTime = clock();
    orderArrInsertionSort(sizeRow, sizeCol, arrMatrix);
    endTime = clock();
    totalTime = totalTime + (endTime - startTime);

    return (totalTime / sizeRow) / CLOCKS_PER_SEC;
}

float testTimeQSort(int sizeRow, int sizeCol, int **arrMatrix)
{
    float startTime, endTime, totalTime;

    startTime = clock();
    orderArrQSort(sizeRow, sizeCol, arrMatrix);
    endTime = clock();
    totalTime = totalTime + (endTime - startTime);

    return (totalTime / sizeRow) / CLOCKS_PER_SEC;
}

void writeOnConsole(int sizeRow, int sizeCol, int **arrMatrix)
{
    if (sizeCol > 10)
        std::cout << "<Demasiados componentes para mostrar>" << std::endl;
    else
        for (int i = 0; i < sizeRow; i++)
        {
            for (int j = 0; j < sizeCol; j++)
            {
                std::cout << arrMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    std::cout << std::endl;
}

int main()
{
    int sizeRow, sizeCol;
    float averageTimeQSort, averageTimeInsertion;
    int **arrMatrix, **arrMatrixCopy;
    srand(time(NULL));

    sizeRow = askSize();
    sizeCol = askNumOfArray();
    arrMatrix = (int **)malloc(sizeRow * sizeof((int *)malloc(sizeCol * sizeof(int))));
    arrMatrixCopy = (int **)malloc(sizeRow * sizeof((int *)malloc(sizeCol * sizeof(int))));

    addRandomNumberToArray(sizeRow, sizeCol, arrMatrix);
    copyMatrix(sizeRow, sizeCol, arrMatrix, arrMatrixCopy);

    std::cout << "arrMatriz sin ordenar" << std::endl;

    writeOnConsole(sizeRow, sizeCol, arrMatrix);

    averageTimeQSort = testTimeInsertion(sizeRow, sizeCol, arrMatrix);
    std::cout << std::setprecision(5) << std::fixed << "Insercion tarda: " << averageTimeInsertion << std::endl;

    std::cout << "arrMatriz ordenada" << std::endl;

    writeOnConsole(sizeRow, sizeCol, arrMatrix);

    std::cout << "arrMatrizCopy sin ordenar" << std::endl;

    writeOnConsole(sizeRow, sizeCol, arrMatrixCopy);
    averageTimeInsertion = testTimeQSort(sizeRow, sizeCol, arrMatrixCopy);

    std::cout << std::setprecision(5) << std::fixed << "Qsort tarda: " << averageTimeQSort << std::endl;

    std::cout << "arrMatrizCopy ordenado" << std::endl;

    writeOnConsole(sizeRow, sizeCol, arrMatrixCopy);

    return 0;
}
