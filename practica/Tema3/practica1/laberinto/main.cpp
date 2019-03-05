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

bool is_empty(char **board, int posX, int posY)
{

    if (board[posX][posY] == '-')
    {
        return true;
    }
    return false;
}

bool is_valid(Cell cellSize, int posX, int posY)
{

    if (posX < cellSize.getCell1() || posY < cellSize.getCell2())
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

bool buscar(char **board, Cell cellSize, int posX, int posY)
{
    if (posX == cellSize.getCell1() - 1 && posY == cellSize.getCell2() - 1)
    {
        if (is_empty(board, posX, posY))
        {
            board[posX][posY] = '>';
            return true;
        }
        else
        {
            return false;
        }
    }
    if (checkEnds(posX, posY))
    {
        if (is_empty(board, posX, posY))
        {
            if (is_valid(cellSize, posX, posY))
            {
                board[posX][posY] = '>';
            }
            else
            {
                return false;
            }
            if (buscar(board, cellSize, posX - 1, posY)) //Arriba
            {
                return true;
            }
            else if (buscar(board, cellSize, posX, posY + 1)) //Derecha
            {
                return true;
            }
            else if (buscar(board, cellSize, posX + 1, posY)) //Abajo
            {
                return true;
            }
            else if (buscar(board, cellSize, posX, posY - 1)) //Izquierda
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

    Cell cellSize, cellStart, cellEnd, cellLocked;

    //Pedir tamaño
    do
    {
        cellSize.setCell1(askCol());
    } while (cellSize.getCell1() < 1);

    do
    {
        cellSize.setCell2(askRow());
    } while (cellSize.getCell2() < 1);

    //pedir indices
    do
    {
        std::cout << "Indices de la celda bloqueada (para salir, introducir 0 0)";
        cellLocked = askCell();
        //std::cout << "cell1: " << cellLocked.getCell1() << " cell2: " << cellLocked.getCell2();
        if ((cellLocked.getCell1() != 0 || cellLocked.getCell2() != 0) && (cellLocked.getCell1() < posX && cellLocked.getCell2() < posY))
        {
            board[cellLocked.getCell1()][cellLocked.getCell2()] = '#';
        }
        else
        {
            std::cout << "Introduzca una celda válida!!" << std::endl;
        }
        std::cout << std::endl;
    } while (cellLocked.getCell1() != 0 || cellLocked.getCell2() != 0);

    //Pedir celda inicio
    do
    {
        std::cout << "Celda inicial? ";
        cellStart = askCell();

    } while (cellStart.getCell1() < 0 || cellStart.getCell2() < 0 || cellStart.getCell1() >= cellSize.getCell1() || cellStart.getCell2() >= cellSize.getCell2());
    std::cout << cellStart.getCell1() << " inicio " << cellStart.getCell2() << std::endl;

    //Pedir celda fin
    do
    {
        std::cout << "Celda final? ";
        cellEnd = askCell();

    } while (cellEnd.getCell1() < 0 || cellEnd.getCell2() < 0 || cellEnd.getCell1() >= cellSize.getCell1() || cellEnd.getCell2() >= cellSize.getCell2());
    std::cout << cellEnd.getCell1() << " fin " << cellEnd.getCell2() << std::endl;

    writeOnConsole(board, posX, posY);

    if (buscar(board, cellSize, 0, 0))
    {
        writeOnConsole(board, posX, posY);
    }
    else
    {
        std::cout << "El laberinto no tiene solucion" << std::endl;
    }

    return 0;
}
