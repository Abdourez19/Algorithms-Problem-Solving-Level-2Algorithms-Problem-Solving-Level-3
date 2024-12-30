
#include <iostream>
#include <cstdlib>
#include <iomanip>


using namespace std;


int Randomnumber(int from, int to)
{
    int number;
    number = rand() % (to - from + 1) + from;
    return number;
}

void fillArrayWithRandomNumbers(int arr[3][3], short row, short col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = Randomnumber(1, 10);
        }
    }
}

void PrintArray(int arr[3][3], short row, short col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %0*d    ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

int sumOfMatrixElements(int arr[3][3], short rows, short cols)
{
    short sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];
    }
    return sum;
}

bool areMatricesEqual(int arr1[3][3], int arr2[3][3], short row, short col)
{
    return sumOfMatrixElements(arr1, row, col) == sumOfMatrixElements(arr2, row, col); 
}

void printResultOfEquality(int arr1[3][3], int arr2[3][3], short row, short col)
{
    if (areMatricesEqual(arr1, arr2, row, col))
        cout << "YES, Matrices are EQUAL!\n";
    else 
        cout << "NO, Matrices are NOT EQUAL!\n";
}

int main()
{

    srand((unsigned)time(NULL));

    int arr1[3][3] ,arr2[3][3]; 

    fillArrayWithRandomNumbers(arr1, 3, 3); 
    cout << "\nMatrix 1: \n";
    PrintArray(arr1, 3, 3); 

    fillArrayWithRandomNumbers(arr2, 3, 3); 
    cout << "\nMatrix 2: \n"; 
    PrintArray(arr2, 3, 3); 

    cout << endl;
    printResultOfEquality(arr1, arr2, 3, 3); 

    return 0;
}

