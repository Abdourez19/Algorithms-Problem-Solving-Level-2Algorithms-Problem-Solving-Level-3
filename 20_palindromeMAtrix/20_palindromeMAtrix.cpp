#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

void printMatrix(int arr[3][3], short row, short col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

bool isPalindromMatix(int arr[3][3], short row, short col)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col/2; j++)
		{
			if (arr[i][j] != arr[i][col - 1 - j])
				return false;
		}
	}
	return true;
}


void printResult(int arr[3][3], short row, short col)
{
	if (!isPalindromMatix(arr, row, col))
		cout << "\nMatrix is not palindrome! \n";
	else 
		cout << "\nYES: Matrix is palindrome! \n";
}



int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = { {1,2,1},{4,5,4},{7,3,7} };

	cout << "\nMatrix 1: \n";
	printMatrix(arr, 3, 3);

	printResult(arr, 3, 3);

	cout << endl;
	return 0;
}