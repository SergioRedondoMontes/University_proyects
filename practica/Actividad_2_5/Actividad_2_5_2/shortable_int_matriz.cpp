#include <iostream>
#include "shortable_int_matriz.h"

ShortableIntMatriz::ShortableIntMatriz(int sizeRow, int sizeCol)
{
    this->_sizeRow = sizeRow;
    this->_sizeCol = sizeCol;
    this->_arrMatrix = (int **)malloc(sizeRow * sizeof((int *)malloc(sizeCol * sizeof(int))));
}

/* addRandomNumberToMatrix
 * Este método añade números aleatorios al array interno, para
 * poder hacer esto tenemos que recorrer la primera dimension y crear
 * un array, que al insertarlo en la primera dimension destruimos.
*/
void ShortableIntMatriz::addRandomNumberToMatrix()
{
    srand(time(NULL));

    for (int i = 0; i < _sizeRow; i++)
    {
        int *arrTemp = (int *)malloc(_sizeCol * sizeof(int));
        for (int j = 0; j < _sizeCol; j++)
        {
            arrTemp[j] = rand() + 1;
        }
        _arrMatrix[i] = arrTemp;
    }
}
/* orderArrAlgBubbles
 * Este método ordena un array usando el algoritmo burbuja.
 * Ordenamos el array empezando por la primera posicion, comparando cada par de elementos 
 * contiguos y si ambos no estan ordenados se cambian sus posiciones y así sucesivamente hasta
 * ordenar el array.
 */
void ShortableIntMatriz::orderArrAlgBubblesReverse()
{
    int temp;
    for (int i = 0; i < _sizeRow; i++)
    {
        for (int h = _sizeCol; h > 0; h--)
        {
            for (int j = _sizeCol - 1; j > 0; j--)
            {
                if (_arrMatrix[i][j] < _arrMatrix[i][j - 1])
                {
                    temp = _arrMatrix[i][j];
                    _arrMatrix[i][j] = _arrMatrix[i][j - 1];
                    _arrMatrix[i][j - 1] = temp;
                }
            }
        }
    }
}

/*writeOnConsole
* Recoremos la matriz con dos for pata imprimir los datos que contiene
* el array interno.
*/
void ShortableIntMatriz::writeOnConsole()
{
    for (int i = 0; i < _sizeRow; i++)
    {
        for (int j = 0; j < _sizeCol; j++)
        {
            std::cout << _arrMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

ShortableIntMatriz::~ShortableIntMatriz()
{
}

/*
void ShortableIntMatriz::orderArrAlgBubbles()
{
    int temp;
    for (int i = 0; i < _sizeRow; i++)
    {
        for (int h = 1; h < _sizeCol; h++)
        {
            for (int j = 0; j < _sizeCol - 1; j++)
                if (_arrMatrix[i][j] > _arrMatrix[i][j + 1])
                {
                    temp = _arrMatrix[i][j];
                    _arrMatrix[i][j] = _arrMatrix[i][j + 1];
                    _arrMatrix[i][j + 1] = temp;
                }
        }
    }
}
*/