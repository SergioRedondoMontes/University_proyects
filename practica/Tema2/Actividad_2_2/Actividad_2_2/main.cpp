#include <iostream>
#include <stdio.h>  /* printf, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;

/* addRandomNumToArr
 * Este método añade números aleatorios al array
 *  
 * Precondición: El tamaño tiene que ser >= 1
 * 
 * -> PARAMETERS: tamaño del array y array de tipo int 
 * -> RETURN: nada
*/
void addRandomNumToArr(int size, int *arrDisordered)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arrDisordered[i] = rand();
}

/* algBubble
 * Este método ordena un array usando el algoritmo burbuja 
 * Ordenamos el array empezando por la primera posicion, comparando cada par de elementos 
 * contiguos y si ambos no estan ordenados se cambian sus posiciones y así sucesivamente hasta
 * ordenar el array.
 *
 * Precondición: El array no puede ser nulo y el tamaño tiene que ser >= 1
 * 
 * -> PARAMETERS: tamaño del array y array de int 
 * -> RETURN: array ordeando
*/
int *algBubble(int size, int *arrNumbers)
{
    int temp;
    for (int i = 1; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (arrNumbers[j] > arrNumbers[j + 1])
            {
                temp = arrNumbers[j];
                arrNumbers[j] = arrNumbers[j + 1];
                arrNumbers[j + 1] = temp;
            }

    return arrNumbers;
}

/* compareInt
 *Este método ordena de menor a mayor
 */
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

/* printArray
 * Este método imprime el arrray
 *
 * Precondición: El array no puede ser nulo y el tamaño tiene que ser >= 1
 * 
 * -> PARAMETERS: tamaño del array y array de int 
 * -> RETURN: nada
*/
void printArray(int size, int *arrOrdered)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arrOrdered + i));
    }
    cout << endl
         << endl;
}

int main()
{

    int *arrDisordered, *arrBubbleOrdered, *arrQShortOrdered, size;
    unsigned long startBubble, finishBubble, startQShort, finishQShort;

    do
    {
        cout << "Introduce el tamaño del vector <numero mayor o igual que 1>" << endl;
        cin >> size;
    } while (size < 1); //pedimos un tamaño hasta que sea mayor o igual a 1

    arrDisordered = (int *)malloc(size * sizeof(int));
    arrBubbleOrdered = (int *)malloc(size * sizeof(int));
    arrQShortOrdered = (int *)malloc(size * sizeof(int));

    addRandomNumToArr(size, arrDisordered);

    cout << "El vector original es el siguiente:" << endl;
    if (size > 10)
    {
        cout << "<Demasiados componentes para mostrar>" << endl;
    }
    else
    {
        printArray(size, arrDisordered);
    }

    memcpy(arrQShortOrdered, arrDisordered, sizeof(int) * size);

    //Burbuja
    startBubble = clock();
    cout << "Clocks de inicio con ordenacion por Burbuja: " << (startBubble) / (float)CLOCKS_PER_SEC << endl;
    arrBubbleOrdered = algBubble(size, arrDisordered);
    finishBubble = clock();
    cout << "Clocks de fin con ordenacion por Burbuja: " << (finishBubble) / (float)CLOCKS_PER_SEC << endl;
    cout << "Con ordenacion por burbuja he tardado " << (finishBubble - startBubble) / (float)CLOCKS_PER_SEC << " segundos en ordenarlo." << endl;
    cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
    cout << "El vector resultado es:" << endl;
    if (size > 10)
    {
        cout << "<Demasiados componentes para mostrar>" << endl;
    }
    else
    {
        printArray(size, arrBubbleOrdered);
    }

    //QShort
    startQShort = clock();
    cout << "Clocks de inicio con ordenacion por QuickShort: " << (startQShort) / (float)CLOCKS_PER_SEC << endl;
    qsort(arrQShortOrdered, size, sizeof(int), compareInt);
    finishQShort = clock();
    cout << "Clocks de fin con ordenacion por QuickShort: " << (finishQShort) / (float)CLOCKS_PER_SEC << endl;
    cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
    cout << "Con ordenacion por QuickShort he tardado " << (finishQShort - startQShort) / (float)CLOCKS_PER_SEC << " segundos en ordenarlo." << endl;
    cout << "El vector resultado es:" << endl;
    if (size > 10)
    {
        cout << "<Demasiados componentes para mostrar>" << endl;
    }
    else
    {
        printArray(size, arrQShortOrdered);
    }
}
