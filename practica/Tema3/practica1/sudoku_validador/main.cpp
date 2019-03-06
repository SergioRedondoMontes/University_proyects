#include <iostream>

int **createSudoku()
{
    srand(time(NULL));
    int **board = (int **)malloc(9 * sizeof((char *)malloc(9 * sizeof(int))));
    int *temp = (int *)malloc(sizeof(int) * 9);
    int *temp2 = (int *)malloc(sizeof(int) * 9);
    int *temp3 = (int *)malloc(sizeof(int) * 9);
    int *temp4 = (int *)malloc(sizeof(int) * 9);
    int *temp5 = (int *)malloc(sizeof(int) * 9);
    int *temp6 = (int *)malloc(sizeof(int) * 9);
    int *temp7 = (int *)malloc(sizeof(int) * 9);
    int *temp8 = (int *)malloc(sizeof(int) * 9);
    int *temp9 = (int *)malloc(sizeof(int) * 9);

    temp[0] = 5;
    temp[1] = 3;
    temp[2] = -1;
    temp[3] = -1;
    temp[4] = 7;
    temp[5] = -1;
    temp[6] = -1;
    temp[7] = -1;
    temp[8] = -1;

    temp2[0] = 6;
    temp2[1] = -1;
    temp2[2] = -1;
    temp2[3] = 1;
    temp2[4] = 9;
    temp2[5] = 5;
    temp2[6] = -1;
    temp2[7] = -1;
    temp2[8] = -1;

    temp3[0] = -1;
    temp3[1] = 9;
    temp3[2] = 8;
    temp3[3] = -1;
    temp3[4] = -1;
    temp3[5] = -1;
    temp3[6] = -1;
    temp3[7] = 6;
    temp3[8] = -1;

    temp4[0] = 8;
    temp4[1] = -1;
    temp4[2] = -1;
    temp4[3] = -1;
    temp4[4] = 6;
    temp4[5] = -1;
    temp4[6] = -1;
    temp4[7] = -1;
    temp4[8] = 3;

    temp5[0] = 4;
    temp5[1] = -1;
    temp5[2] = -1;
    temp5[3] = 8;
    temp5[4] = -1;
    temp5[5] = 3;
    temp5[6] = -1;
    temp5[7] = -1;
    temp5[8] = 1;

    temp6[0] = 7;
    temp6[1] = -1;
    temp6[2] = -1;
    temp6[3] = -1;
    temp6[4] = 2;
    temp6[5] = -1;
    temp6[6] = -1;
    temp6[7] = -1;
    temp6[8] = 6;

    temp7[0] = -1;
    temp7[1] = 6;
    temp7[2] = -1;
    temp7[3] = -1;
    temp7[4] = 7;
    temp7[5] = -1;
    temp7[6] = 2;
    temp7[7] = 8;
    temp7[8] = -1;

    temp8[0] = -1;
    temp8[1] = -1;
    temp8[2] = -1;
    temp8[3] = 4;
    temp8[4] = 1;
    temp8[5] = 9;
    temp8[6] = -1;
    temp8[7] = -1;
    temp8[8] = 5;

    temp9[0] = -1;
    temp9[1] = -1;
    temp9[2] = -1;
    temp9[3] = -1;
    temp9[4] = 8;
    temp9[5] = -1;
    temp9[6] = -1;
    temp9[7] = 7;
    temp9[8] = 9;

    board[0] = temp;
    board[1] = temp2;
    board[2] = temp3;
    board[3] = temp4;
    board[4] = temp5;
    board[5] = temp6;
    board[6] = temp7;
    board[7] = temp8;
    board[8] = temp9;

    return board;
}

void writeOnConsole(int **board, int posX, int posY)
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

int main(int argc, char const *argv[])
{
    int **board = createSudoku();
    writeOnConsole(board, 9, 9);
    return 0;
}
