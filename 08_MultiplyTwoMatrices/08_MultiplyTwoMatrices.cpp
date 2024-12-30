
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

void fillMultyplyingMatrice(int arr1[3][3], int arr2[3][3], int multArr[3][3], short row, short col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            multArr[i][j] = arr1[i][j] * arr2[i][j];
    }
}


int main()
{ 

    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3][3] , MultArray [3][3]; 
        
    fillArrayWithRandomNumbers(arr1, 3, 3);
    fillArrayWithRandomNumbers(arr2, 3, 3); 

    cout << "Matrix 1: \n";
    PrintArray(arr1, 3, 3);

    cout << endl;

    cout << "Matrix 2: \n";
    PrintArray(arr2, 3, 3); 

    cout << endl;

    fillMultyplyingMatrice(arr1, arr2, MultArray, 3, 3);
    cout << "Result: \n";
    PrintArray(MultArray, 3, 3);    

   return 0;
}

