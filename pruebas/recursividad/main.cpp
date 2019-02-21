#include <iostream>
#include <string>

bool is_empty(char **board, int posX, int posY)
{
    if (board[posX][posY] == '-')
    {
        return true;
    }
    return false;
}
bool is_valid(char **board, int size, int posX, int posY)
{
    if (posX < size || posY < size)
    {
        return true;
    }
    return false;
}

bool buscar(char **board, int size, int posX, int posY)
{
    if (posX == size - 1 && posY == size - 1)
    {
        board[posX][posY] = '>';
        return true;
    }
    if (is_empty(board, posX, posY))
    {
        if (is_valid(board, size, posX, posY))
        {
            board[posX][posY] = '>';
        }
        else
        {
            return false;
        }
        if (buscar(board, size, posX, posY + 1))
        {
            return true;
        }
        else if (buscar(board, size, posX + 1, posY))
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
}

int main()
{
    int posX, posY, size;
    posX = 3;
    posY = 3;
    size = 3;
    char **board = (char **)malloc(posX * sizeof((char *)malloc(posY * sizeof(char))));

    fillMatrix(board, posX, posY);

    board[0][1] = '#';
    board[1][1] = '#';

    writeOnConsole(board, posX, posY);

    buscar(board, size, 0, 0);

    writeOnConsole(board, posX, posY);

    return 0;
}
