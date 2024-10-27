#include <iostream>
#include <string>
#include <cctype>


using namespace std;

char readChar()
{
    char C1;
    cout << "\nPlease enter character: \n";
    cin >> C1;
    return C1;
}

bool IsVowel(char letter)
{
    char c1 = tolower(letter);

    return ((c1 == 'a') || (c1 == 'e') || (c1 == 'i') || (c1 == 'o') || (c1 == 'u'));
}

int main()
{
    char letter = readChar();

    if (IsVowel(letter))
        printf("YES: Letter \'%c\' is Vowel! \n", letter);
    else 
        printf("No: Letter \'%c\' is Not a Vowel! \n", letter);


    return 0;
}