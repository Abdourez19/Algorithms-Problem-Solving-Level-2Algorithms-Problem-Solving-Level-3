#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

string readString()
{
    string s1;
    cout << "Please enter a string: \n";
    getline(cin, s1);
    return s1;
}

string UpperAllLettersOfString(string S1)
{
    string ConS = S1;

    for (int i = 0; i < ConS.length(); i++)
    {
        ConS[i] = toupper(ConS[i]);
    }
    return ConS;
}

string LowerAllLettersOfString(string S1)
{
    string ConS = S1;

    for (int i = 0; i < ConS.length(); i++)
    {
        ConS[i] = tolower(ConS[i]); 
    }
    return ConS;
}




int main()
{
    string S1 = readString();

    cout << "\n\nString after using Upper All: \n";
    cout << UpperAllLettersOfString(S1) <<endl <<endl;

    cout << "String after using Lower All: \n";
    cout << LowerAllLettersOfString(S1) <<endl <<endl;

    system("pause");

    return 0;
}
