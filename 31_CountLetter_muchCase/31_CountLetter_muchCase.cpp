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

char readChar()
{
    char C1;
    cout << "\nPlease enter character: \n";
    cin >> C1;
    return C1;
}

char invertCharacterCase(char C1)
{
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

short countLetter(string S1, char letter, bool matchcase = true)
{
    short counter = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (matchcase)
        {
            if (S1[i] == letter)
                counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(letter))
                counter++;
        } 
    }
    return counter;
}

//short notMatchLetterCaseCount(string S1, char C1) 
//{
//
//    short counter =0;
//    for (int i = 0; i < S1.length(); i++)
//    {
//        if (S1[i] == toupper(C1) || S1[i] == tolower(C1)) 
//            counter++;
//    }
//    return counter; 
//}


int main()
{
    string S1 = readString();
    char C1 = readChar();

    //send (true or false) as 3rd argument for the function countLetter() - true - for match case - false -  for unmatchcase

    cout << "\nLetter \'" << C1 << "\' count : " << countLetter(S1, C1) << endl;   
    cout << "\nLetter \'" << C1 << "\' or \'" << invertCharacterCase(C1) << "\' count is : ";  
    cout << countLetter(S1, C1, false) << endl;

    return 0;
}


