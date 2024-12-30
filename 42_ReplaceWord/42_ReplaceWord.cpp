#include <iostream>
#include <string>

using namespace std;

string readString(string message)
{
    string s1;
    cout << message ;
    getline(cin, s1);

    return s1;
}

string replaceWord(string s1)
{
    string wordToChange = readString("\nEnter the word you want to change in string: \n");
    
    string changeTo = "";

    if (s1.find(wordToChange) == string::npos)  
    {
        while (s1.find(wordToChange) == string::npos) 
        {
            wordToChange = readString("\nSorry the string doesn't match, enter other! \n"); 
        }
    }

    changeTo = readString("\nEnter the replacement word: \n");

    while (s1.find(wordToChange) != string::npos) 
    {
        s1.replace(s1.find(wordToChange), wordToChange.length(), changeTo);
    } 

    return s1;
}



int main()
{

    string S1 = readString("Please enter a string: \n");

    string s1AfterReplacement = replaceWord(S1); 

    cout << "\nOriginal string: \n";
    cout << S1 << endl;

    cout << "\nString after replacing word: \n";
    cout <<s1AfterReplacement<< endl; 


    return 0;
}