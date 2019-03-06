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

bool checkEnds(int posX, int posY, Cell cellSize)
{
    if (posX < 0 || posY < 0 || posX > cellSize.getCell1() || posY > cellSize.getCell2()) // evitamos que se salga del tamaño del array
    {
        return false;
    }
    return true;
}

bool buscar(char **board, Cell cellSize, int posX, int posY, Cell cellEnd)
{
    if (posX == cellEnd.getCell1() && posY == cellEnd.getCell2())
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
    if (checkEnds(posX, posY, cellSize))
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
            if (buscar(board, cellSize, posX - 1, posY, cellEnd)) //Arriba
            {
                return true;
            }
            else if (buscar(board, cellSize, posX, posY + 1, cellEnd)) //Derecha
            {
                return true;
            }
            else if (buscar(board, cellSize, posX + 1, posY, cellEnd)) //Abajo
            {
                return true;
            }
            else if (buscar(board, cellSize, posX, posY - 1, cellEnd)) //Izquierda
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

    char **board;

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

    board = (char **)malloc(cellSize.getCell1() * sizeof((char *)malloc(cellSize.getCell2() * sizeof(char))));
    fillMatrix(board, cellSize.getCell1(), cellSize.getCell2());

    //pedir indices
    do
    {
        std::cout << "Indices de la celda bloqueada (para salir, introducir 0 0)";
        cellLocked = askCell();
        //std::cout << "cell1: " << cellLocked.getCell1() << " cell2: " << cellLocked.getCell2();
        if ((cellLocked.getCell1() != 0 || cellLocked.getCell2() != 0) && (cellLocked.getCell1() < cellSize.getCell1() && cellLocked.getCell2() < cellSize.getCell2()))
        {
            board[cellLocked.getCell1()][cellLocked.getCell2()] = '#';
        }
        else if (cellLocked.getCell1() == 0 && cellLocked.getCell2() == 0)
        {
            /* code */
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
        if (cellStart.getCell1() < 0 || cellStart.getCell2() < 0 || cellStart.getCell1() >= cellSize.getCell1() || cellStart.getCell2() >= cellSize.getCell2())
        {
            std::cout << "Introduzca una celda válida!!" << std::endl;
        }
        else
        {

            std::cout << "Celda inicial? ";
            cellStart = askCell();
        }

    } while (cellStart.getCell1() < 0 || cellStart.getCell2() < 0 || cellStart.getCell1() >= cellSize.getCell1() || cellStart.getCell2() >= cellSize.getCell2());

    //Pedir celda fin
    do
    {
        if (cellEnd.getCell1() < 0 || cellEnd.getCell2() < 0 || cellEnd.getCell1() >= cellSize.getCell1() || cellEnd.getCell2() >= cellSize.getCell2())
        {
            std::cout << "Introduzca una celda válida!!" << std::endl;
        }
        else
        {
            std::cout << "Celda final? ";
            cellEnd = askCell();
        }

    } while (cellEnd.getCell1() < 0 || cellEnd.getCell2() < 0 || cellEnd.getCell1() >= cellSize.getCell1() || cellEnd.getCell2() >= cellSize.getCell2());

    writeOnConsole(board, cellSize.getCell1(), cellSize.getCell2());

    if (buscar(board, cellSize, cellStart.getCell1(), cellStart.getCell2(), cellEnd))
    {
        writeOnConsole(board, cellSize.getCell1(), cellSize.getCell2());
    }
    else
    {
        std::cout << "El laberinto no tiene solucion" << std::endl;
    }

    return 0;
}
