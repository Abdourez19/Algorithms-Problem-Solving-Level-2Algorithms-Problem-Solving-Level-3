#include <iostream>
#include <string>
#include <vector>

using namespace std;

string joinString(vector <string> vString, string delimit)
{

	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + delimit;
	}
	return S1.substr(0, S1.length() - delimit.length());
}

string joinString(string arr[], int length,string delimit )
{
	string joinedString = "";

	for (int i = 0; i < length; i++)
	{
		joinedString = joinedString + arr[i] + delimit;
	}
	return joinedString.substr(0, joinedString.length() - delimit.length());
}



int main()
{

	vector <string> vNames = { "abdou", "rezouk" , "safa" , "noLove" };

	string arrNames[] = { "abdou", "rezouk" , "safa" , "noLove" };

	cout << "\nVector after join: \n\n";
	cout << joinString(vNames, ", ") << endl;

	cout << "\nArray after join: \n\n";
	cout << joinString(arrNames, 4, ", ") << endl;


	return 0;
}