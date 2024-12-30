
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int readNumber()
{
    int number; 
    cout << "please enter the length of the Fibonacci: ";
    cin >> number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << "please anter a valid NUMBER: ";
        cin >> number;
    }
    return number;
}

void makeAndPrintFibonacci(short length)
{
    int prev1 = 1, prev2 = 0, FebNumber =0;


    cout << "1   ";

    for (int i = 2; i <= length; i++)
    {
        FebNumber = prev1 + prev2;
        cout << FebNumber << "   ";
        prev2 = prev1;
        prev1 = FebNumber;
    }
    cout << endl; 
}


//using vector
//void makeFibonacci(vector <int>& vFibonacci)
//{
//    int length = readNumber(); 
//    int prev1 = 0;
//    int prev2 = 0; 
//
//    if (length == 1)
//        vFibonacci.push_back(prev1+1);
//    else if (length == 2)
//    {
//        vFibonacci.push_back(prev1 + 1); 
//        vFibonacci.push_back(prev2 + 1);
//    }
//        
//    else
//    {
//        prev1 = 1; 
//        prev2 = 1;
//        vFibonacci.push_back(prev1);
//        vFibonacci.push_back(prev2);
//
//        for (int i = 2; i < length; i++)
//        {
//            vFibonacci.push_back(vFibonacci[i-1] + vFibonacci[i - 2]);
//        }
//    }
//    
//}
//
//void printVFibonacci(vector <int> vFibonacci)
//{
//    cout << "\nThe Fibonacci series is: \n\n";
//
//    for (int& element : vFibonacci)
//    {
//        cout << element << "    ";
//    }
//    cout << endl;
//}


int main()
{
    //using vector
    /*vector <int> vFibonacci;
    makeFibonacci(vFibonacci);
    printVFibonacci(vFibonacci);*/


    makeAndPrintFibonacci(10);


    return 0;
}
