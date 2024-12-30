#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

enum enMatchCaseStatus { MatchCase = 1, DontMatchCase = 2 };

string readString(string message)
{
    string s1;
    cout << message;
    getline(cin, s1);

    return s1;
}

string LowerAllLettersOfString(string S1)
{
    string ConS = S1;

    for (int i = 0; i < ConS.length(); i++)
    {
        ConS[i] = tolower(ConS[i]);
    }
    return ConS;
}

vector <string> split(string s1, string delimit)
{
    vector <string> vSplit;
    short spacePos = 0;
    string theWord = "";

    while ((spacePos = s1.find(delimit)) != string::npos)
    {
        theWord = s1.substr(0, spacePos);

        if (theWord != "")
        {
            vSplit.push_back(theWord);
        }

        s1.erase(0, spacePos + delimit.length());
    }
    if (s1 != "")
        vSplit.push_back(s1);

    return vSplit;
}

string joinString(vector <string> vString, string delimit)
{

    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + delimit;
    }
    return S1.substr(0, S1.length() - delimit.length());
}

string ReplaceUsStringUsingSplit(string s1, string stringToReplace, string changeTo, bool matchCase = true)
{
    vector <string> vStr = split(s1, " ");

   
        for (string& s : vStr) 
        {
            if (matchCase)
            {
                if (s == stringToReplace)
                    s = changeTo;
            }
            else
            {
                if (LowerAllLettersOfString(s) == LowerAllLettersOfString(stringToReplace))  
                    s = changeTo; 
            }
        }
    
    return joinString(vStr, " ");
}
 

//using enum method 

//string replaceWordsDontMatchCase(string S1, string wordToChange, string changeTo) 
//{
//
//    string S1Clone = LowerAllLettersOfString(S1);
//    wordToChange = LowerAllLettersOfString(wordToChange); 
//
//    short wordToChangePos = 0;
//
//    while ((wordToChangePos = S1Clone.find(wordToChange)) != string::npos)
//    {
//        S1Clone.erase(wordToChangePos, wordToChange.length());
//        S1.erase(wordToChangePos, wordToChange.length());
//
//        S1Clone.insert(wordToChangePos, changeTo);
//        S1.insert(wordToChangePos, changeTo);
//    }
//
//    return ("Replacement with not match case: \n" + S1); 
//} 
//
//string replaceWordsMatchCase(string S1, string wordToChange, string changeTo)
//{
//    short wordToChangePos = 0;
//
//    while ((wordToChangePos = S1.find(wordToChange)) != string::npos) 
//    {
//        S1.erase(wordToChangePos, wordToChange.length());
//        S1.insert(wordToChangePos, changeTo);
//    }
//
//    return ("Replacement with match case: \n" + S1);
//}
//
//string ReplaceDependsCaseStatus(string S1, string wordToChange, string changeTo, enMatchCaseStatus match = enMatchCaseStatus::MatchCase)
//{
//    if (match == enMatchCaseStatus::DontMatchCase)
//        return replaceWordsDontMatchCase(S1, wordToChange, changeTo);
//
//    else 
//        return replaceWordsMatchCase(S1, wordToChange, changeTo); 
//    
//}



int main()
{

    string s1 = readString("enter a string: \n");
    string wordToChange = readString("Enter the word you to change: \n"); 
    string changeTo  = readString("Enter the Replacement word: \n"); 

    cout << "Replace with 'Case match': \n";
    cout << ReplaceUsStringUsingSplit(s1, wordToChange, changeTo) << endl << endl;

    cout << "Replace with 'Don't Case match': \n";
    cout << ReplaceUsStringUsingSplit(s1, wordToChange, changeTo, false) << endl << endl;  

    return 0;
}