#include <iostream>
#include <string> 
#include <cctype>


using namespace std;

string readString()
{
    string S1;
    cout << "\nPlease enter String: \n";
    getline(cin, S1);
    return S1;
}

bool IsVowel(char letter)
{
    char c1 = tolower(letter);

    return ((c1 == 'a') || (c1 == 'e') || (c1 == 'i') || (c1 == 'o') || (c1 == 'u'));
}

void printVowels(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i])) 
            cout << S1[i] << "   "; 
    }
    cout << endl;
}



int main()
{
    string S1 = readString();
    printVowels(S1); 
    return 0;
}