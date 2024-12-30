#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


struct stClientBankInfos
{
	string AccountNumber;
	string PIN;
	string FullName;
	string PhoneNumber;
	double Balance;
};

const string fileName = "ClientBanksData.txt";
const string delimit = "#//#";


vector <string> split(string s1, string delimit)
{
	vector <string> vClient;
	short DelimitPosition = 0;
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

stClientBankInfos convertLineDataToStruct(string s1, string delimit)
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

vector <stClientBankInfos> loadDataFromFile(string fileName)
{
	fstream MyFile;

	vector <stClientBankInfos> vClient;

	MyFile.open(fileName, ios::in);

	if (MyFile.is_open())
	{
		string line;

		while (getline(MyFile, line))
		{
			vClient.push_back(convertLineDataToStruct(line, delimit)); 
		}

		MyFile.close();
		return vClient;
	}

}

bool isClientExists(stClientBankInfos& Client, string accountNumber)
{
	vector <stClientBankInfos> vClients = loadDataFromFile(fileName);

	for (stClientBankInfos& Cl : vClients)
	{
		if (Cl.AccountNumber == accountNumber)
		{
			Client = Cl;
			return true;
		}
			
	}
	return false;
}

void printClientByAcountNumber (stClientBankInfos sClient , string accountNumber)
{
	if (sClient.AccountNumber == accountNumber)
	{
		cout << "\nThe Following is the clients details: \n\n";
		cout << "Account Number : " << sClient.AccountNumber << endl; 
		cout << "PIN            : " << sClient.PIN << endl; 
		cout << "Client Name    : " << sClient.FullName << endl; 
		cout << "Phone Number   : " << sClient.PhoneNumber << endl; 
		cout << "Balance        : " << sClient.Balance << endl; 
	}
	else
		cout << "\nNo account Found with this Account Number! \n\n";
}


int main()
{
	stClientBankInfos sClient ;

	string accountNumber;
	cout << "Enter Account Number: ";
	cin >> accountNumber;

	isClientExists(sClient, accountNumber);

	printClientByAcountNumber(sClient, accountNumber );

	return 0;
}