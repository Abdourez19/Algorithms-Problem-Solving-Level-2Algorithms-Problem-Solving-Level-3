
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



int main()
{

    srand((unsigned)time(NULL));

    int arr1[3][3];

    fillArrayWithRandomNumbers(arr1, 3, 3);
    cout << "Matrix 1: \n";
    PrintArray(arr1, 3, 3);

    cout << ("\nSum of Matrix1 is: ") << sumOfMatrixElements(arr1, 3, 3) << endl;

    return 0;
}

