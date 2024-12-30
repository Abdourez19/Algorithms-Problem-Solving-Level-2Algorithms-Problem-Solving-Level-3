#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

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
			arr[i][j] = randOmNumber(1, 20);
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

int MinNumber(int arr[3][3], short rows, short cols)
{
	int min = arr[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] <= min )
				min = arr[i][j];
		}
	}
	return min;
}

int MaxNumber(int arr[3][3], short rows, short cols)
{
	int max = arr[0][0]; 

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j]; 
		}
	}
	return max;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];

	fillArrayWithRandomNumbers(arr, 3, 3);
	cout << "\nMatrix 1: \n";
	printMatrix(arr, 3, 3);


	cout << "\nMinimum Number is: " << MinNumber(arr, 3, 3);

	cout << "\nMax Number is: " << MaxNumber(arr, 3, 3);
	

	cout << endl;
	return 0;
}