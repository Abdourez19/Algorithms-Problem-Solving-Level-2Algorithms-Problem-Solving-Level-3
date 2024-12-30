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

stClientBankInfos convertLineDataToStruct(string s1, string delimit )
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

void printingDataTemplate(stClientBankInfos sClient)
{
	cout << "|" << setw(15)<< left  << sClient.AccountNumber 
		 << "|" << setw(6) << left  << sClient.PIN 
		 << "|" << setw(25)<< left  << sClient.FullName
		 << "|" << setw(15)<< left  << sClient.PhoneNumber 
		 << "|" << setw(12)<< left  << sClient.Balance << endl;
}

void printClientUsingTemplateFunction(string fileName, string delimit)
{
	fstream ClientFile;


	ClientFile.open(fileName, ios::in);

	if (ClientFile.is_open())
	{
		string line;
		while (getline(ClientFile, line))
		{
			printingDataTemplate( convertLineDataToStruct(line, delimit));
		}
		ClientFile.close();
	}
}

short getClientsNumber (string fileName, string delimit)
{  
	fstream ClientFile;
	short counter = 0;

	ClientFile.open(fileName, ios::in);

	if (ClientFile.is_open())
	{
		string line;
		while (getline(ClientFile, line))
		{
			counter++;
		}
		ClientFile.close();
	}
	return counter;
}

void printTableHeader(string fileName, string delimit)
{

	cout << setw(35) << "Client List (" << getClientsNumber(fileName, delimit) << ") Client(s)\n";
	cout << setw(70) << "_______________________________________________________________________________\n";
	cout << "|" << left << setw(15) << "Account Number" 
		 << "|" << left << setw(6) << "PIN"
		 << "|" << left << setw(25) << "Client Name"
		 << "|" << left << setw(15) << "Phone Number"
		 << "|" << left << setw(12) << "Balance" << endl;
	cout << setw(70) << "_______________________________________________________________________________\n";

}

void getAllData()
{
	printTableHeader(fileName, delimit); 
	printClientUsingTemplateFunction(fileName, delimit); 
	cout << setw(70) << "\n_______________________________________________________________________________\n";

}


int main()
{
	getAllData();

	return 0;
}