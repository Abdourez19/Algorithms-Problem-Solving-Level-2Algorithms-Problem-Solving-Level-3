#include <iostream>
#include <string> 
#include <cctype>

using namespace std;


string readString()
{
    string S1;
    cout << "\nPlease enter String: \n";
    getline(cin, S1);
    return S1;
}  
  
//string trimLeft(string s1) 
//{
//    bool isSpace = true;
//    do
//    {
//        if (s1[0] != ' ')
//            return s1;
//
//        else  
//        {
//            s1.erase(0, 1); 
//            isSpace = true; 
//        }
//    } while (isSpace == true);
//
//    return s1;
//}
//
//string trimRight(string s1)  
//{
//    bool isSpace = true;
//    do
//    {
//        if (s1[s1.length()-1] != ' ')
//            return s1;
//
//        else if (s1[s1.length() - 1] == ' ') 
//        {
//            s1.erase(s1.length() - 1, 1); 
//            isSpace = true;
//        }
//    } while (isSpace == true);
//
//    return s1;
//}
//
//string Trim(string S1)
//{
//    return trimLeft(trimRight(S1));
//}



string trimLeftForLoop(string s1)
{
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ')
        {
            return s1.substr(i, s1.length() - i); 
        }
    }
    return "";
}

string trimRightForLoop(string s1)
{
    for (int i = s1.length()-1 ; i >=0 ; i--)
    {
        if (s1[i] != ' ')
        {
            return s1.substr(0, i+1);
        }
    }
    return "";
}

string Trim(string S1)
{
    return trimLeftForLoop(trimRightForLoop(S1));
}



int main()
{
    string S1 = readString();

    cout << "Trim LEFT  :" << trimLeftForLoop(S1) <<endl <<endl;

    cout << "Trim Right :" << trimRightForLoop(S1)  << endl << endl;

    cout << "Trim       :" << Trim(S1) << endl << endl; 


    return 0;
}