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

string LowerFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    string ConS = S1;

    for (int i = 0; i < ConS.length(); i++)
    {
        if (ConS[i] != ' ' && isFirstLetter)
        {
            ConS[i] = tolower(ConS[i]);
        }
        isFirstLetter = ConS[i] == ' ' ? true : false;
    }


    return ConS;
}

void printConvertedString()
{
    string S1 = LowerFirstLetterOfEachWord(readString());
    cout << "\nString after conversion \n\n";
    cout << S1 << endl;
}


int main()
{
    printConvertedString();

    return 0;
}
