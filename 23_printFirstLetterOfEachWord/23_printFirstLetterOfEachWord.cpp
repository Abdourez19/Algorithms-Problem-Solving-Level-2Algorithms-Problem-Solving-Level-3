
#include <iostream>
#include <string>

using namespace std;

string readString()
{
    string s1;
    cout << "Please enter a string: \n";
    getline(cin, s1);

    return s1;
}

void printFirstLetterOfEachWord( string S1)
{
    bool isFirstLetter = true;

    cout << "first letter of each word is:\n";

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter )
        {
            cout << S1[i] << endl;
        }

        isFirstLetter = S1[i] == ' ' ? true : false; 
    }

}

int main()
{

    printFirstLetterOfEachWord(readString());

    return 0;
}
