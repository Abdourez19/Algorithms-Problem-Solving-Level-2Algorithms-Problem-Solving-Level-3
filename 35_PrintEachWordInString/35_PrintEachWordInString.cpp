#include <iostream>
#include <string> 
#include <cctype>
using namespace std;


using namespace std;

string readString()
{
    string S1;
    cout << "\nPlease enter String: \n";
    getline(cin, S1);
    return S1;
}

void printWordsOfString(string s1)
{
    string delimit = " ";
    string ExtractedWord = "";
    short delimitPosition = 0;

    cout << "\nstring's words are: \n\n";

    while ((delimitPosition = s1.find(delimit)) != string::npos)
    {
        ExtractedWord = s1.substr(0, delimitPosition);

        if (ExtractedWord.empty() == false)
            cout << ExtractedWord << endl;

        s1.erase(0, delimitPosition + delimit.length());
    }
    if (s1 != "")
        cout << s1 << endl <<endl;
}



int main()
{
    string S1 = readString();

    printWordsOfString(S1);

    return 0;
}