#include <iostream>
#include <cctype>

using namespace std;

string RemovePuntuations(string s1)
{

	//2 methods 
	string s2;

	for (int i = 0; i < s1.length(); i++)
	{
		/*if (ispunct(s1[i]))
			s1.erase(s1.find(s1[i]), 1);*/

		if (!ispunct(s1[i]))
			s2 += s1[i];
	}
	return s2;
}



int main()
{
	string Str = "My name is Abderrezak Redjachta, with email address @ABDOU username: PRO DEV!\n";

	cout << "string BEFORE remove Punctuations: \n";
	cout << Str << endl;

	cout << "\nstring AFTER remove Punctuations: \n";
	cout << RemovePuntuations(Str) << endl << endl;



	return 0;
}