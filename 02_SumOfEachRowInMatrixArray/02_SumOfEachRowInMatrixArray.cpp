#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>


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
            arr[i][j] = Randomnumber(1, 100);
        }
    }
}

void PrintArray(int arr[3][3], short row, short col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

int SumOfRowElements(int arr[3][3], short rowNumber, short col)
{
    int RowSum = 0;
    for (int j = 0; j < col; j++)
        RowSum += arr[rowNumber][j];

    return RowSum;
}

void printRowSum(int arr[3][3], short row ,short col)
{
    for (int i = 0; i < row; i++)
        cout <<" Row " << i + 1 << " Sum = " << SumOfRowElements(arr, i, col) << endl; 
}




int main()
{

    srand((unsigned)time(NULL));

    int arr[3][3];
    fillArrayWithRandomNumbers(arr, 3, 3);
    cout << "The following is 3x3 Random matrix (random numbers from 1 to 100): \n";
    PrintArray(arr, 3, 3);

    cout << "\nPress any key to continue! \n";
    system("pause>0");       //This is used to pause the execution, when the user clicks on any key it continues execution.

    cout << endl;
    cout << "The following is the SUM of each Row Elements of the matrix: \n";
    printRowSum(arr, 3,3);

    return 0;
}
