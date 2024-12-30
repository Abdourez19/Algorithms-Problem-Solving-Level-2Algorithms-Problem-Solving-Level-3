#include <iostream>
#include <cctype>


using namespace std;

char readCharacter()
{
    char C1 ;
    cout << "Please enter character to convert: \n";
    cin >> C1;
    return C1;
}

//char invertCharacterCase(char C1)
//{
//    short characterDec = (short)C1;
//
//    if (characterDec >= 65 && characterDec <= 90)
//        return tolower(C1);
//
//    if (characterDec >= 97 && characterDec <= 122)
//        return toupper(C1);
//
//
//}

char invertCharacterCase(char C1)
{
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

int main()
{
    char C1 = readCharacter();
    C1 = invertCharacterCase(C1);

    cout << "\ncharater after conversion: \n";
    cout << C1 << endl;

    return 0;
}

