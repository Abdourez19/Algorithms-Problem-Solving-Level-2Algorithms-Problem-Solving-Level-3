#include <iostream>

using namespace std;


void fillArrayWithOrderedNumbers(int arr[3][3], int row , int col)
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

void printOrderedMatrix(int arr[3][3], int row, int col)
{
	cout << "The following is 3x3 ordered matrix: \n";

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << "     ";
		cout << endl;
	}
}


int main()
{

	int arr[3][3];

	fillArrayWithOrderedNumbers(arr, 3, 3);
	printOrderedMatrix(arr, 3, 3);


	return 0;;
}