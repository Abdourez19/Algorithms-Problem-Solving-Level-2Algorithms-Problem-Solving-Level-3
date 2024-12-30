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


int main()
{

	vector <string> vNames = { "abdou", "rezouk" , "safa" , "noLove" };

	cout << "Vector after join: \n\n" ;
	cout << joinString(vNames, ",,") << endl;

	return 0;
}