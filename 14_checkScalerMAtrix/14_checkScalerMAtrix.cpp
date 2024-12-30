
#include <iostream>

using namespace std;



bool isMatrixIScalar(int arr[3][3], short row, short col)
{
    short FirstElement = arr[0][0];

    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j && arr[i][j] != FirstElement)
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
    int arr[3][3] = { {5,0,0 }, {0, 5, 0}, {0,0,5} };

    cout << "matrix 1: \n";
    PrintArray(arr, 3, 3);

    if (isMatrixIScalar(arr, 3, 3))
        cout << "YES, the matrix is Scalar!\n";
    else
        cout << "NO, the matrix is NOT Scalar!\n";


    return 0;
}
