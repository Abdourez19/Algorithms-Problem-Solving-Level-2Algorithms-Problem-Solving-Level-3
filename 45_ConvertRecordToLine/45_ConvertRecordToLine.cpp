#include <iostream>
#include <string>
#include <cctype>

using namespace std;


struct stClientBankInfos 
{
	string AccountNumber;
	string PIN;
	string FullName ;
	string PhoneNumber;
	double Balance ; 
}; 

stClientBankInfos readClient()
{
	stClientBankInfos client;

	cout << "Enter Account Number: ";
	getline(cin, client.AccountNumber);

	cout << "Enter PIN code      : ";
	getline(cin, client.PIN);

	cout << "Enter Your FullName : ";
	getline(cin, client.FullName);

	cout << "Enter Phone Number  : ";
	getline(cin, client.PhoneNumber);

	cout << "Enter Balance       : ";
	cin >> client.Balance;

	return client;
}

string ConvertRecordsToLine(stClientBankInfos clientInfos , string delimit = "#//#")
{
	string LineClientRecord = "";

	LineClientRecord += clientInfos.AccountNumber + delimit;
	LineClientRecord += clientInfos.PIN+ delimit;
	LineClientRecord += clientInfos.FullName + delimit;
	LineClientRecord += clientInfos.PhoneNumber + delimit;
	LineClientRecord += to_string(clientInfos.Balance);

	return LineClientRecord;
}



int main()
{
	stClientBankInfos abdou;

	abdou = readClient();

	cout << "\n\nClient Record for saving is: \n";
	cout << ConvertRecordsToLine(abdou); 

	return 0;
}