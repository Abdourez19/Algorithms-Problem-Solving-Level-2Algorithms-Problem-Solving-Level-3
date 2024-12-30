#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;


struct stClientBankInfos
{
	string AccountNumber;
	string PIN;
	string FullName;
	string PhoneNumber;
	double Balance;
};

vector <string> split(string s1, string delimit)
{
	vector <string> vClient;
	short DelimitPosition = 0 ;
	string theWord = "";

	while ((DelimitPosition = s1.find(delimit)) != string::npos)
	{
		theWord = s1.substr(0, DelimitPosition);

		if (theWord != "")
			vClient.push_back(theWord);
		s1.erase(0, DelimitPosition + delimit.length());
	}

	if (s1 != "")
		vClient.push_back(s1);

	return vClient;
}

stClientBankInfos convertLineDataToStruct( string s1 , string delimit = "#//#")
{
	stClientBankInfos stClient;  

	vector <string> vClient = split(s1, delimit);   

	stClient.AccountNumber = vClient[0]; 
	stClient.PIN = vClient[1];
	stClient.FullName = vClient[2];
	stClient.PhoneNumber = vClient[3];
	stClient.Balance = stod(vClient[4]);

	return stClient;
}

void printRecord(stClientBankInfos stClient)
{
	cout << "The following is the extracted client records: \n\n";
	cout << "Account Number    :" << stClient.AccountNumber << endl;
	cout << "Account PIN       :" << stClient.PIN << endl;
	cout << "Cient Name        :" << stClient.FullName << endl;
	cout << "Phone Number      :" << stClient.PhoneNumber << endl;
	cout << "Account Balance   :" << stClient.Balance << endl << endl;
}



int main()
{
	string lineData = "AA325xx#//#3652#//#Redjachta Abderrezak#//#0369598#//#896513.000000 ";

	cout << lineData << endl << endl;

	stClientBankInfos stClient = convertLineDataToStruct(lineData);

	printRecord(stClient);

	cout << endl;

	return 0;
}