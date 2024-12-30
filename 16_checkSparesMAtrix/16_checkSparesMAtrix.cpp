#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int randOmNumber(int from, int to)
{
	int number;
	number = rand() % (to - from + 1) + from;
	return number;
}

void fillArrayWithRandomNumbers(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = randOmNumber(0, 2);
		}
	}
}

void printMatrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

int numberCountInMatrix(int arr[3][3], int number, short row, short col)
{
	int counter = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == number)
					counter++;
			}
		}
	return counter;
}

bool checkifSparesMAtrix(int arr[3][3], short row, short col)
{
	return (numberCountInMatrix(arr, 0, row, col) > (row * col) / 2);
}

void printResultOfSpares(int arr[3][3], short row, short col)
{
	if (checkifSparesMAtrix(arr, row, col))
		cout << "\nYes, it's spares matrix!\n";
	else 
		cout << "\nNO, it's NOT spares matrix!\n";
}



int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];

	fillArrayWithRandomNumbers(arr, 3, 3);
	cout << "Matrix 1: \n";
	printMatrix(arr, 3, 3);

	printResultOfSpares(arr, 3, 3);

	cout << endl;

	return 0;
}