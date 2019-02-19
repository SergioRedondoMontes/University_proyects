#include <iostream>
#include "shortable_int_Array.h"

ShortableIntArray::ShortableIntArray(int size)
{
    this->_size = size;
    this->_arrVector = (int *)malloc(size * sizeof(int));
}

/* addRandomNumberToMatrix
 * Este método añade números aleatorios al array interno, para
 * poder hacer esto tenemos que recorrer la primera dimension y crear
 * un array, que al insertarlo en la primera dimension destruimos.
*/
void ShortableIntArray::addRandomNumberToArray()
{
    srand(time(NULL));
    for (int i = 0; i < _size; i++)
        _arrVector[i] = rand();
}

/* orderArrAlgBubbles
 * Este método ordena un array usando el algoritmo burbuja.
 * Ordenamos el array empezando por la primera posicion, comparando cada par de elementos 
 * contiguos y si ambos no estan ordenados se cambian sus posiciones y así sucesivamente hasta
 * ordenar el array.
 */
void ShortableIntArray::orderArrAlgBubble()
{
    int temp;

    for (int h = 1; h < _size; h++)
    {
        for (int j = 0; j < _size - 1; j++)
            if (_arrVector[j] > _arrVector[j + 1])
            {
                temp = _arrVector[j];
                _arrVector[j] = _arrVector[j + 1];
                _arrVector[j + 1] = temp;
            }
    }
}

/*orderArraAlgSelectionSort
 *Este método ordena un array usando el algoritmo por seleccion.
 * Buscamos el mínimo elemento del array y lo cambiamos por el primer elemento del array.
 * Buscamos el siguiente elemento más pequeno y lo cambiamos por el segundo elemento del array,
 * hacemos esto hasta ordenar el array.
 */
void ShortableIntArray::orderArraAlgSelectionSort()
{
    int min;
    for (int i = 0; i < _size; i++)
    {
        min = i;
        for (int j = i + 1; j < _size; j++)
        {

            if (_arrVector[min] > _arrVector[j])
            {
                min = j;
            }
        }
        swapData(i, min);
    }
}

/*swapData
 * Este método es privado y solo se usa en el método orderArraAlgSelectionSort
 * intercambia el dato de la posicion "i" con el dato de la posicion "min"
 * "i" hace referencia a la posicion del array que vamos a cambiar con la posicion
 * "min" en la que se encuantra el dato mínimo.
*/
void ShortableIntArray::swapData(int i, int min)
{
    int aux;
    aux = _arrVector[i];
    _arrVector[i] = _arrVector[min];
    _arrVector[min] = aux;
}

/*writeOnConsole
* Recorremos el array para imprimir los datos que contiene
*/
void ShortableIntArray::writeOnConsole()
{

    for (int j = 0; j < _size; j++)
    {
        std::cout << _arrVector[j] << " ";
    }
    std::cout << std::endl;
}

ShortableIntArray::~ShortableIntArray()
{
}
