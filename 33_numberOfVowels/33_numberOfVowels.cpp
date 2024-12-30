#include <iostream>
#include <string> 
#include <cctype>


using namespace std;

string readString()
{
    string S1;
    cout << "\nPlease enter String: \n";
    getline (cin, S1); 
    return S1;
}  

bool IsVowel(char letter)
{
    char c1 = tolower(letter);

    return ((c1 == 'a') || (c1 == 'e') || (c1 == 'i') || (c1 == 'o') || (c1 == 'u'));
}

short countVowels(string St1)
{
    short counter = 0;
    for (int i = 0; i < St1.length(); i++)
    {
        if (IsVowel(St1[i]))
            counter++;
    }
    return counter;
}

int main()
{
    string S1 = readString(); 

    cout << "\nNumber of Vowels is : " << countVowels(S1); 

    return 0;
}