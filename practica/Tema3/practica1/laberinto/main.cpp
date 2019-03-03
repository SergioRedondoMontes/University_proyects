#include <iostream>
#include <string>
#include "cell.h"

//  Created by Sergio Redondo on 20/02/19.

int askRow()
{
    int sizeRow;
    do
    {
        std::cout << "Numero de filas? ";
        std::cin >> sizeRow;
    } while (sizeRow < 1);

    return sizeRow;
}

int askCol()
{
    int sizeCol;
    do
    {
        std::cout << "Numero de Columnas? ";
        std::cin >> sizeCol;
    } while (sizeCol < 1);

    return sizeCol;
}

Cell askCell()
{
    Cell a;

    int cell1, cell2;

    std::cin >> cell1;
    a.setCell1(cell1);
    std::cin >> cell2;
    a.setCell2(cell2);

    return a;
}

// Cell askStart()
// {
//     Cell a;
//     int cell1, cell2;
//     do
//     {
//         std::cout << "Celda inicial? ";
//         std::cin >> cell1;
//         a.setCell1(cell1);
//         std::cin >> cell2;
//         a.setCell2(cell2);
//     } while (cell1 != 0 && cell2 != 0);

//     return a;
// }

// Cell askEnd()
// {
//     Cell a;
//     int cell1, cell2;
//     do
//     {
//         std::cout << "Celda final? ";
//         std::cin >> cell1;
//         a.setCell1(cell1);
//         std::cin >> cell2;
//         a.setCell2(cell2);
//     } while (cell1 != 0 && cell2 != 0);

//     return a;
// }

bool is_empty(char **board, int posX, int posY)
{

    if (board[posX][posY] == '-')
    {
        return true;
    }
    return false;
}

bool is_valid(int size, int posX, int posY)
{

    if (posX < size || posY < size)
    {
        return true;
    }

    return false;
}

bool checkEnds(int posX, int posY)
{
    if (posX < 0 || posY < 0) // evitamos que se salga del tamaño del array
    {
        return false;
    }
    return true;
}

bool buscar(char **board, int size, int posX, int posY)
{
    if (posX == size - 1 && posY == size - 1)
    {
        board[posX][posY] = '>';
        return true;
    }
    if (checkEnds(posX, posY))
    {
        if (is_empty(board, posX, posY))
        {
            if (is_valid(size, posX, posY))
            {
                board[posX][posY] = '>';
            }
            else
            {
                return false;
            }
            if (buscar(board, size, posX - 1, posY)) //Arriba
            {
                return true;
            }
            else if (buscar(board, size, posX + 1, posY)) //Abajo
            {
                return true;
            }
            else if (buscar(board, size, posX, posY - 1)) //Izquierda
            {
                return true;
            }
            else if (buscar(board, size, posX, posY + 1)) //Derecha
            {
                return true;
            }
            else
            {
                board[posX][posY] = '?';
                return false;
            }
        }
        else
        {

            return false;
        }
    }
    else
    {
        return false;
    }
}

void fillMatrix(char **board, int posX, int posY)
{
    for (int i = 0; i < posX; i++)
    {
        char *arrTemp = (char *)malloc(posY * sizeof(char));
        for (int j = 0; j < posY; j++)
        {
            arrTemp[j] = '-';
        }
        board[i] = arrTemp;
    }
}

void writeOnConsole(char **board, int posX, int posY)
{
    for (int i = 0; i < posX; i++)
    {
        for (int j = 0; j < posY; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int posX, posY, size;
    posX = 5;
    posY = 5;
    size = 5;
    char **board = (char **)malloc(posX * sizeof((char *)malloc(posY * sizeof(char))));

    fillMatrix(board, posX, posY);
    /*
    board[0][1] = '#';
    board[1][1] = '#';
*/
    //////////////////////////////////////////////////cambiar los ask para que solo sea uno (start,end,cellLocked)
    Cell a;
    do
    {
        std::cout << "Indices de la celda bloqueada (para salir, introducir 0 0)";
        a = askCell();
        std::cout << "cell1: " << a.getCell1() << " cell2: " << a.getCell2();
        if (a.getCell1() != 0 || a.getCell2() != 0)
        {
            std::cout << "eeeooooo";
            board[a.getCell1()][a.getCell2()] = '#';
        }
        std::cout << std::endl;
    } while (a.getCell1() != 0 || a.getCell2() != 0);

    writeOnConsole(board, posX, posY);

    buscar(board, size, 1, 0);

    writeOnConsole(board, posX, posY);

    return 0;
}
