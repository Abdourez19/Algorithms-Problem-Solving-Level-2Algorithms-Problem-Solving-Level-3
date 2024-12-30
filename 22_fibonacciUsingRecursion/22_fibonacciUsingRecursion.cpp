
#include <iostream>

using namespace std;

void fiboancciNumber(short number ,short prev1, short prev2)
{
    if (number > 0)
    {
        int fibNumber = 0;

        fibNumber = prev1 + prev2;
        cout << fibNumber << "   ";

        prev2 = prev1;
        prev1 = fibNumber; 

        fiboancciNumber(number - 1, prev1, prev2); 
    }
    
}



int main()
{

    fiboancciNumber(10, 0, 1);

    return 0;
}


