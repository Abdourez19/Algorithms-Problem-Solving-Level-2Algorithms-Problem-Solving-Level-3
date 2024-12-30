

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

int SumOfColElements(int arr[3][3], short row, short colNumber)
{
    int ColSum = 0;
    
    for (int i = 0; i < row ; i++)     
        ColSum += arr[i][colNumber];
    
    return ColSum;
}

void printColSum(int arr[3][3], short row, short col)
{

    cout << "\nThe following is the SUM of each Row Elements of the matrix: \n";
    for (int i = 0; i < col; i++)

        cout << " Col " << i + 1 << " Sum = " << SumOfColElements(arr, row, i) << endl;
}




int main()
{

    srand((unsigned)time(NULL));

    int arr[3][3];
    int ODimentionArray[3];

    fillArrayWithRandomNumbers(arr, 3, 3);
    cout << "The following is 3x3 Random matrix (random numbers from 1 to 100): \n";
    PrintArray(arr, 3, 3);

    /*cout << "\nPress any key to see the sum of each row! \n";
    system("pause>0");  */     //This is used to pause the execution, when the user clicks on any key it continues execution.

    cout << endl;
    printColSum(arr, 3, 3);

    return 0;
}
