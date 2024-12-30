#include <iostream>

using namespace std;


void fillArrayWithOrderedNumbers(int arr[3][3], int row, int col)
{
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			++counter;
			arr[i][j] = counter;
		}
	}
}

void printMatrix(int arr[3][3], int row, int col)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << "     ";
		cout << endl;
	}
}

void fillTransposeMAtrix(int arr[3][3], int transArr[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			transArr[i][j] = arr[j][i]; 
	}
}





int main()
{

	int arr[3][3];
	int transposedArr[3][3];

	cout << "The following is 3x3 ordered matrix: \n";
	fillArrayWithOrderedNumbers(arr, 3, 3);
	printMatrix(arr, 3, 3);

	cout << "The following is 3x3 transposed matrix: \n";

	fillTransposeMAtrix(arr, transposedArr, 3, 3);
	printMatrix(transposedArr, 3, 3);

	return 0;;
}