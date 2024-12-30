#include <iostream>
#include <string>
#include <vector>

using namespace std;

string readString()
{
	string s1; 
	cout << "Please enter a string: \n";
	getline(cin, s1);

	return s1;
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

string trimRight(string s1)
{
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        if (s1[i] != ' ')
        {
            return s1.substr(0, i + 1);
        }
    }
    return "";
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

//string reverseString(string s1)
//{ 
//    string newStr = "";
//    vector <string> vReversed = split(s1, " ");
//
//    for (int i = 0; i < vReversed.size() / 2 ; i++)
//    {
//        string tempStr = vReversed[i];
//        vReversed[i] = vReversed[vReversed.size() - 1 - i];
//        vReversed[vReversed.size() - 1 - i] = tempStr; 
//    }
//
//    return joinString(vReversed, ",");
//}

string reverseString(string s1)
{
    string myStr = "";
    vector <string> vStr = split(s1, " ");

    vector <string>::iterator itr = vStr.end();

    while (itr != vStr.begin())
    {
        itr--;
        myStr = myStr + *itr + " ";
    }
    //return myStr.substr(0, myStr.length() - 1);
    return trimRight(myStr); 
}



int main()
{

	string S1 = readString();

    cout << "\nString after reversing words: \n";
    cout << reverseString(S1) << endl;


	return 0;
}