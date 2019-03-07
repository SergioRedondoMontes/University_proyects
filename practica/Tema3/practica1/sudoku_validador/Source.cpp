#include <iostream>
#include <stdio.h>
using namespace std;

//Funcion que te imprime el tablero, primero sin hacer y luego la volvemos a llamar en la funcion "HacerSudoku" y nos lo imprime hecho
void ImprimirTablero(int sudoku[9][9], int fila, int columna)
{
	for (int fila = 0; fila < 9; fila++)
	{
		for (int columna = 0; columna < 9; columna++)
		{
			if (columna == 0)
				cout << " |";
			if (sudoku[fila][columna] == -1)
				cout << "   *";
			else
				cout << "   " << sudoku[fila][columna];
			if (columna == 2 || columna == 5 || columna == 8)
				cout << "  |";
		}

		if (fila == 2 || fila == 5 || fila == 8)
		{
			if (fila == 8)
			{
			}
			else
				cout << "\n                 ";
		}
		if (fila <= 8)
			cout << endl;
		cout << " |              |              |              |";
		cout << endl;
	}
}

//Funcion que te devuelve true o flase en funcion si ha encontrado el numero o no
bool esValido(int sudoku[9][9], int fila, int columna, int valor)
{
	if (sudoku[fila][columna] != -1)
		return false;

	for (int i = 0; i < 9; i++)
	{
		if (sudoku[fila][i] == valor)
			return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (sudoku[i][columna] == valor)
			return false;
	}

	int despFila = (fila / 3) * 3;
	int despColumna = (columna / 3) * 3;

	for (int i = despFila; i < despFila + 3; i++)
	{
		for (int j = despColumna; j < despColumna + 3; j++)
		{
			if (sudoku[i][j] == valor)
				return false;
		}
	}

	return true;
}

bool HacerSudoku(int sudoku[9][9], int fila, int columna)
{
	//Te recorre el array valores para encontrar cual es el numero correcto para la posicion
	for (int i = 1; i <= 9; i++)
	{

		if (esValido(sudoku, fila, columna, i))
		{ //LLamamos a la funcion esValida que nos comprueba si el numero es correcto o no

			sudoku[fila][columna] = i;

			if (fila < 8)
			{
				if (HacerSudoku(sudoku, fila + 1, columna))
					return true;
				else
					sudoku[fila][columna] = -1;
			}
			else if (fila == 8 && columna != 8)
			{
				if (HacerSudoku(sudoku, 0, columna + 1))
					return true;
				else
					sudoku[fila][columna] = -1;
			}
			else if (fila == 8 && columna == 8)
			{
				//ImprimirTablero(sudoku, fila, columna);

				return true;
			}
		}
		else
		{
			if (sudoku[fila][columna] != -1)
			{
				if (fila < 8)
				{
					if (HacerSudoku(sudoku, fila + 1, columna))
						return true;
					else
						return false;
				}
				else if (fila == 8 && columna != 8)
				{
					if (HacerSudoku(sudoku, 0, columna + 1))
						return true;

					else
						return false;
				}
				else if (fila == 8 && columna == 8)
				{
					//ImprimirTablero(sudoku, fila, columna);
					return true;
				}
			}
		}
	}

	return false;
}

bool resolverSudoku(int sudoku[9][9])
{
	return HacerSudoku(sudoku, 0, 0);
}

int main()
{
	int fila = 0, columna = 0;

	//Definimos el sudoku sin hacer
	int sudoku[9][9] = {{5, 3, -1, -1, 7, -1, -1, -1, -1},
						{6, -1, -1, 1, 9, 5, -1, -1, -1},
						{-1, 9, 8, -1, -1, -1, -1, 6, -1},
						{8, -1, -1, -1, 6, -1, -1, -1, 3},
						{4, -1, -1, 8, -1, 3, -1, -1, 1},
						{7, -1, -1, -1, 2, -1, -1, -1, 6},
						{-1, 6, -1, -1, -1, -1, 2, 8, -1},
						{-1, -1, -1, 4, 1, 9, -1, -1, 5},
						{-1, -1, -1, -1, 8, -1, -1, 7, 9}};

	cout << "El sudoku sin resolver es: \n\n\n";
	ImprimirTablero(sudoku, fila, columna); //Imprimimos el tablero sin resolver
	cout << endl
		 << endl
		 << endl;
	if (resolverSudoku(sudoku))
	{
		cout << "El sudoku resuelto es:\n\n";
		ImprimirTablero(sudoku, fila, columna);
	}
	else
	{
		cout << "El sudoku no tiene solucion." << endl;
	}
	//cout << "El sudoku resuelto es:\n\n";
	//HacerSudoku(sudoku, fila, columna);

	return 0;
}
