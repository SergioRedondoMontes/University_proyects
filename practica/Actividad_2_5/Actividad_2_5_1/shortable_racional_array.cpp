#include <iostream>
#include "shortable_racional_array.h"

ShortableRacionalArray::ShortableRacionalArray(int size)
{
    this->_size = size;
    this->_arrRacionals = (Racional *)malloc(size * sizeof(Racional));
}

/* addRandomNumToArr
 * Este método añade números aleatorios al array
 *  
 * Precondición: El tamaño tiene que ser >= 1
 * 
 * -> RETURN: nada
*/
void ShortableRacionalArray::addRandomRacionalToArrRacionals()
{
    srand(time(NULL));
    for (int i = 0; i < this->_size; i++)
        this->_arrRacionals[i] = Racional(rand(), rand() + 1);
}

/* compareRacional
 *Este método ordena de mayor a menor los racionales
 */
int compareRacional(const void *a, const void *b)
{
    Racional racional1(*(Racional *)a);
    Racional racional2(*(Racional *)b);

    float num1, num2;
    num1 = racional1.getValor();
    num2 = racional2.getValor();

    if (num1 > num2)
    {
        return -1;
    }
    else if (num1 == num2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void ShortableRacionalArray::orderArrRacionals()
{
    qsort(this->_arrRacionals, this->_size, sizeof(Racional), compareRacional);
}

void ShortableRacionalArray::writeOnConsole()
{
    for (int i = 0; i < _size; i++)
    {

        std::cout << (*(_arrRacionals + i)).getNumerador() << " / " << (*(_arrRacionals + i)).getDenominador() << " ";
    }
    std::cout << std::endl;
}

ShortableRacionalArray::~ShortableRacionalArray()
{
}
