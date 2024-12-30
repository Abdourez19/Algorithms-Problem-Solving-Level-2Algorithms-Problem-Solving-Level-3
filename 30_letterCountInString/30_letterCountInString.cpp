#include <iostream>
#include <string>
#include <cctype>


using namespace std;

enum whatToCount { smallLetter = 1, capitalLetters = 2, allLetters = 3, punctuation = 4, spaces = 5 };

short stringDetails(string S1, whatToCount whatUWantfromString)
{
    if (whatUWantfromString == whatToCount::allLetters)
    {
        return S1.length();
    }
    if (whatUWantfromString == whatToCount::capitalLetters)
    {
        short counter = 0;
        for (int i = 0; i < S1.length(); i++)
            if (isupper(S1[i]))
                counter++;
        return counter;
    }
    if (whatUWantfromString == whatToCount::smallLetter)
    {
        short counter = 0;
        for (int i = 0; i < S1.length(); i++)
            if (islower(S1[i]))
                counter++;
        return counter;
    }
    if (whatUWantfromString == whatToCount::punctuation)
    {
        short counter = 0;
        for (int i = 0; i < S1.length(); i++)
            if (ispunct(S1[i]))
                counter++;
        return counter;
    }
    if (whatUWantfromString == whatToCount::spaces)
    {
        short counter = 0;
        for (int i = 0; i < S1.length(); i++)
            if (S1[i] == ' ')
                counter++;
        return counter;
    }
}

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
    cout << "\nplease enter character: \n";
    cin >> C1;
    return C1;
}

short SpecificLetterCount(string S1 , char C1)
{
    short letterCount = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] == C1)
            letterCount++;
    }
    return letterCount;
}



int main()
{

    string S1 = readString();

    char C1 = readChar();

    cout << "\nLetter \'"<< C1<< "\' count : "<< SpecificLetterCount(S1, C1) << endl; 
    



    return 0;
}

