#include <iostream>
#include <cstdlib>
#include <iomanip>


using namespace std;


int Randomnumber(int from , int to)
{
    int number;
    number = rand() % (to - from + 1) + from;
    return number;
}

void fillArrayWithRandomNumbers(int arr[3][3], short row, short col)
{
    for (int i = 0;  i< row; i++)
    {
        for (int j = 0; j <col ; j++)
        {
            arr[i][j] = Randomnumber(1, 100);
        }
    }
}

void PrintArray(int arr[3][3], short row, short col)
{

    for (int i = 0;  i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            cout << setw(3) << arr[i][j] << "     " ;
        }
        cout << endl; 
    }
}

int main()
{

    srand((unsigned)time(NULL));


    int arr[3][3];
    fillArrayWithRandomNumbers(arr,3,3);
    cout << "The following is 3x3 Random matrix (random numbers from 1 to 100): \n";

    PrintArray(arr,3,3);

    return 0;
}
