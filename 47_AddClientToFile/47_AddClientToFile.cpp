#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

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


stClientBankInfos readClient()
{
	stClientBankInfos client;

	cout << "Enter Account Number: ";
	getline(cin>> ws, client.AccountNumber);

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

string ConvertRecordsToLine(stClientBankInfos clientInfos, string delimit = "#//#")
{
	string LineClientRecord = "";

	LineClientRecord += clientInfos.AccountNumber + delimit;
	LineClientRecord += clientInfos.PIN + delimit;
	LineClientRecord += clientInfos.FullName + delimit;
	LineClientRecord += clientInfos.PhoneNumber + delimit;
	LineClientRecord += to_string(clientInfos.Balance);

	return LineClientRecord;
}

void addClientToFile(string fileName, string Client)
{
	fstream ClientFile;
	ClientFile.open(fileName, ios::out | ios::app);

	if (ClientFile.is_open())
	{
		ClientFile << Client << endl;
		ClientFile.close();
	}
}

void addNewClient()
{
	stClientBankInfos sClient;
	sClient = readClient();
	addClientToFile(fileName, ConvertRecordsToLine(sClient)); 
}

void FillFileWithClientsData() 
{
	char addMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding new Client: \n\n";

		addNewClient(); 

		cout << "Client added successfuly, Do you want to add more? [Y/N]: ";
		cin >> addMore;
		
	} while (toupper(addMore) == 'Y'); 

}




int main()
{
	FillFileWithClientsData();

	return 0;
}