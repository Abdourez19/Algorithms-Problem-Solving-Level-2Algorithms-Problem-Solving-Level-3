#include <iostream>
#include <string>
#include <cctype>


using namespace std;

enum whatToCount { smallLetter = 1, capitalLetters = 2, allLetters =3, punctuation =4 , spaces = 5 };

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

short CapitalLetterCount(string S1)
{
    short CapCount = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            CapCount++;
    }
    return CapCount;
}

short SmallLetterCount(string S1)
{
    short SmalCount = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            SmalCount++;
    }
    return SmalCount;
}


int main()
{

    string S1 = readString();
    cout << "\nString Length is: " << S1.length() << endl;

    cout << "\nCapital letter count : " << CapitalLetterCount(S1) <<endl;
    cout << "\nSmall letter count : " << SmallLetterCount(S1)<< endl;

    cout << "**************************************************\n";

    cout << "\nString Length is     : " << stringDetails(S1, whatToCount::allLetters);
    cout << "\nCapital letter count : " << stringDetails(S1, whatToCount::capitalLetters);
    cout << "\nSmall letter count   : " << stringDetails(S1, whatToCount::smallLetter);
    cout << "\nPunctuation  count   : " << stringDetails(S1, whatToCount::punctuation);
    cout << "\nSpaces count         : " << stringDetails(S1, whatToCount::spaces);
    cout << endl;

    return 0;
}

