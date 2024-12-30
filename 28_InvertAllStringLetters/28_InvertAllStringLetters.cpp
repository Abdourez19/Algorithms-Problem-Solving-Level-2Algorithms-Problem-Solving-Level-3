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

char invertCharacterCase(char C1)
{
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

string invertAllLettersCaseOfString(string S1)
{
    string ConS = S1;

    for (int i = 0; i < ConS.length(); i++)
    {
        ConS[i] = invertCharacterCase(ConS[i]);
    }
    return ConS;
}



int main()
{
    string S1 = readString();
    cout << "\n\nString after Inverting All: \n";
    cout << invertAllLettersCaseOfString(S1) << endl << endl;
    system("pause");

    return 0;
}
