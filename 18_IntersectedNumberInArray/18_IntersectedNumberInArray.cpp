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

bool isNumberInMatrix(int ArrOneElement, int arr2[3][3] , short row, short col)
{

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (arr2[i][j] == ArrOneElement)
				return true;
	return false;
} 


void printIntersctedNumbers(int arr1[3][3], int arr2[3][3], short row, short col)
{
	cout << "\nIntersected Numbers are : \n";
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			if (isNumberInMatrix(arr1[i][j], arr2, 3, 3))
				cout  <<setw(3) <<arr1[i][j] << "     ";  
}




int main()
{
	srand((unsigned)time(NULL));
	int arr1[3][3], arr2[3][3];

	fillArrayWithRandomNumbers(arr1, 3, 3);
	cout << "\nMatrix 1: \n";
	printMatrix(arr1, 3, 3);


	fillArrayWithRandomNumbers(arr2, 3, 3); 
	cout << "\nMatrix 2: \n";
	printMatrix(arr2, 3, 3); 

	printIntersctedNumbers(arr1, arr2, 3, 3);
	
	cout << endl;
	return 0;
}