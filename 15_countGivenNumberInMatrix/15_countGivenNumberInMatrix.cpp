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
			arr[i][j] = randOmNumber(1, 10);
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

bool checkNumberExistsInMAtrix(int arr[3][3],int number, short row, short col )
{ 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == number) 
				return true;
		}
	}
	return false;
}

int numberCountInMatrix(int arr[3][3],int number, short row, short col)
{
	int counter = 0;

	if (checkNumberExistsInMAtrix(arr, number ,row, col))
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == number) 
					counter++; 
			}
		}
	}
	return counter;
}

void printNumberCount(int arr[3][3], short row, short col) 
{
	int number = 0;
	cout << "Enter the number you want to check in Matrix: ";
	cin >> number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
		cout << "Enter a valid value: ";
		cin >> number;
	}

	if (!checkNumberExistsInMAtrix(arr, number, row, col))
		cout << "\nThe number doesn't exits in Matrix!\n";
	else
		cout << "\nThe number " << number << " count is: " << numberCountInMatrix(arr, number, row, col); 

}



int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];

	fillArrayWithRandomNumbers(arr, 3, 3);
	cout << "Matrix 1: \n";
	printMatrix(arr, 3, 3);

	printNumberCount(arr, 3, 3);
	cout << endl; 

	return 0;
}