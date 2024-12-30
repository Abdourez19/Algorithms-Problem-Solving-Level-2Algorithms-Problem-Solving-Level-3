
#include <iostream>

using namespace std;



bool isMatrixIdentity(int arr[3][3], short row, short col) 
{

    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            if (i == j && arr[i][j] != 1)
            {
                return false;
            }
                
            else if (i != j && arr[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void PrintArray(int arr[3][3], short row, short col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
}







int main()
{
    int arr[3][3] = { {1,0,0 }, {0, 1, 0}, {0,0,1} };

    cout << "matrix 1: \n";
    PrintArray(arr, 3, 3);

    if (isMatrixIdentity(arr, 3, 3))
        cout << "YES, the matrix is IDENTITY!\n";
    else 
        cout << "NO, the matrix is NOT IDENTITY!\n";


    return 0;
}
