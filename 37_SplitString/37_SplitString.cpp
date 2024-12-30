#include <iostream>
#include <string> 
#include <cctype>
#include <vector>


using namespace std;

string readString() 
{
    string S1;
    cout << "\nPlease enter String: \n";
    getline(cin, S1);
    return S1;
}

vector <string> splitString(string s1, string delimit)
{
    vector <string> vSplit ;
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

void printSplitedString(vector <string> vSplit)
{
    for (string& token : vSplit)
        cout << token << endl;
}


int main()
{
    string S1 = readString();

    vector <string> vSplit = splitString(S1, " ");

    cout << "Tokens = " << vSplit.size() << endl;

    printSplitedString(vSplit);

    return 0;
}