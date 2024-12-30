
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

string UpperFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    string ConS = S1;

    for (int i = 0; i < ConS.length(); i++)
    {
        if (ConS[i] != ' ' && isFirstLetter)
        {
            ConS[i] = toupper(ConS[i]);
        }
        isFirstLetter = ConS[i] == ' ' ? true : false; 
    }

    
    return ConS;
}

void printConvertedString()
{
    string S1 = UpperFirstLetterOfEachWord( readString() ); 
    cout << "\nString after concerting \n\n";
    cout << S1 << endl;
}


int main()
{
    printConvertedString();  

    return 0;
}
