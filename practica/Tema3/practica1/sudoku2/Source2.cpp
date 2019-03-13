//  Created by Sergio Redondo & JAIME MARTINEZ on 20/02/19.

#include <iostream>
#include <stdio.h>
using namespace std;

//Función que te imprime el tablero, primero sin hacer y luego la volvemos a llamar en la función "HacerSudoku" y nos lo imprime ya hecho
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

//Función que te devuelve true o flase en función si el numero puede ir en esa posición o no
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
	//Recorre del 1 al 9 para encontrar cual es el numero correcto para la posicion
	for (int i = 1; i <= 9; i++)
	{
		//LLamamos a la función esValida que nos comprueba si el número es correcto o no
		if (esValido(sudoku, fila, columna, i))
		{
			//Si es correcto, se sustituye el valor que tenga en ese momento sudoku[fila][columna] por el valor que tenga i
			sudoku[fila][columna] = i;

			//Hasta que la fila no sea mayor que 8, aumentamos la fila para probar la siguiente posición
			if (fila < 8)
			{
				if (HacerSudoku(sudoku, fila + 1, columna))
					return true;
				else
					sudoku[fila][columna] = -1; //En caso del que no podamos colocar el valor actual
			}
			//Se pone a 0 la fila y se aumenta una columna ya que hemos llegado al final de la fila
			else if (fila == 8 && columna != 8)
			{
				if (HacerSudoku(sudoku, 0, columna + 1))
					return true;
				else
					sudoku[fila][columna] = -1;
			}

			else if (fila == 8 && columna == 8)
			{
				//Si la función es true, se imprimirá el sudoku ya realizado
				cout << "El sudoku resuelto es:\n\n";
				ImprimirTablero(sudoku, fila, columna);
				return true;
			}
		}
		else
		{
			if (sudoku[fila][columna] != -1)
			{
				//Hasta que la fila no sea mayor que 8, aumentamos la fila para probar la siguiente posición 
				if (fila < 8)
				{
					if (HacerSudoku(sudoku, fila + 1, columna))
						return true;
					else
						return false;
				}
				//Se pone a 0 la fila y se aumenta una columna ya que hemos llegado al final de la fila
				else if (fila == 8 && columna != 8)
				{
					if (HacerSudoku(sudoku, 0, columna + 1))
						return true;

					else
						return false;
				}
				else if (fila == 8 && columna == 8)
				{
					//Si la función es true, se imprimirá el sudoku ya realizado
					cout << "El sudoku resuelto es:\n\n";
					ImprimirTablero(sudoku, fila, columna);

					return true;
				}
			}
		}
	}

	return false;
}

//Función que llama a la función para resolver el sudoku
void resolverSudoku(int sudoku[9][9])
{
	HacerSudoku(sudoku, 0, 0);
}

int main()
{
	int fila = 0, columna = 0;

	//Definimos el sudoku sin hacer
	int sudoku[9][9] = { {4, 3, -1, -1, 7, -1, -1, -1, -1},
						{6, -1, -1, 1, 9, 5, -1, -1, -1},
						{-1, 9, 8, -1, -1, -1, -1, 6, -1},
						{8, -1, -1, -1, 6, -1, -1, -1, 3},
						{4, -1, -1, 8, -1, 3, -1, -1, 1},
						{7, -1, -1, -1, 2, -1, -1, -1, 6},
						{-1, 6, -1, -1, -1, -1, 2, 8, -1},
						{-1, -1, -1, 4, 1, 9, -1, -1, 5},
						{-1, -1, -1, -1, 8, -1, -1, 7, 9} };

	cout << "El sudoku sin resolver es:\n\n\n";
	ImprimirTablero(sudoku, fila, columna); //Imprimimos el tablero sin resolver
	cout << endl
		<< endl
		<< endl;

	if (HacerSudoku(sudoku, fila, columna) == true) {}
	else
		cout << "El sudoku no tiene solucion\n\n\n"; // Si la función da false, lo imprimirá ya que no tiene solución el sudoku

	return 0;
}