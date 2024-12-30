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

short countWords(string s1)
{
    string delimit = " ";
    string ExtractedWord = "";
    short delimitPosition = 0;
    short counter = 0 ;
     
    while ((delimitPosition = s1.find(delimit)) != string::npos)  
    {
        ExtractedWord = s1.substr(0, delimitPosition);

        if (ExtractedWord.empty() == false)
            counter++;
        s1.erase(0, delimitPosition + delimit.length());
    }

    if (s1 != "")
        counter++;

    return counter;
}



int main()
{
    string S1 = readString();

    cout << "the Number of string's Word is: " << countWords(S1) <<endl;

    return 0;
}