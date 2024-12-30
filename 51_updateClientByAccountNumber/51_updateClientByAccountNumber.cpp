#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


struct stClients
{
	string AccountNumber;
	string PIN;
	string FullName;
	string PhoneNumber;
	double Balance;
	bool markedToDelete = false;
};

const string fileName = "ClientBanksData.txt";
const string delimit = "#//#";



string readString(string message)
{
	string accountNumber;
	cout <<message ;
	getline(cin>> ws, accountNumber);
	return accountNumber;
}

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

stClients convertLineDataToStructRecord(string s1, string delimit)
{
	stClients stClient;

	vector <string> vClient = split(s1, delimit);

	stClient.AccountNumber = vClient[0];
	stClient.PIN = vClient[1];
	stClient.FullName = vClient[2];
	stClient.PhoneNumber = vClient[3];
	stClient.Balance = stod(vClient[4]);

	return stClient;
}

vector <stClients> loadDataFromFile(string fileName)
{
	fstream MyFile;

	vector <stClients> vClient;

	MyFile.open(fileName, ios::in);

	if (MyFile.is_open())
	{
		string line;

		while (getline(MyFile, line))
		{
			vClient.push_back(convertLineDataToStructRecord(line, delimit));
		}

		MyFile.close();
		return vClient;
	}

}



bool findClientByAccountNumber(vector <stClients> vClients, string accountNumber, stClients& sClient)
{
	for (stClients& Cl : vClients)
	{
		if (Cl.AccountNumber == accountNumber)
		{
			sClient = Cl;
			return true;
		}
	}
	return false;
}

void printClientByAcountNumber(stClients sClient)
{
	cout << "\nThe Following is the clients details: \n\n";
	cout << "Account Number : " << sClient.AccountNumber << endl;
	cout << "PIN            : " << sClient.PIN << endl;
	cout << "Client Name    : " << sClient.FullName << endl;
	cout << "Phone Number   : " << sClient.PhoneNumber << endl;
	cout << "Balance        : " << sClient.Balance << endl;
}

string ConvertRecordToLine(stClients clientInfos, string delimit)
{
	string LineClientRecord = "";

	LineClientRecord += clientInfos.AccountNumber + delimit;
	LineClientRecord += clientInfos.PIN + delimit;
	LineClientRecord += clientInfos.FullName + delimit;
	LineClientRecord += clientInfos.PhoneNumber + delimit;
	LineClientRecord += to_string(clientInfos.Balance);

	return LineClientRecord;
}

void markClientToDeleteByAccountNumber(vector <stClients>& vClients, string accountNumber)
{
	for (stClients& cl : vClients)
	{
		if (cl.AccountNumber == accountNumber)
		{
			cl.markedToDelete = true;
		}
	}
}

void saveClientDatatoFile(vector <stClients> vClients)
{

	fstream client;

	client.open(fileName, ios::out);

	if (client.is_open())
	{
		for (stClients& cl : vClients)
		{
			if (cl.markedToDelete == false)
				client << ConvertRecordToLine(cl, delimit) << "\n";
		}
		client.close();
	}
}

stClients updateClient(string accountNumber) 
{
	stClients cl;

	cl.AccountNumber = accountNumber;
	cl.PIN = readString("Enter Your New Pin Code : ");
	cl.FullName = readString("Enter Your Name         : ");
	cl.PhoneNumber = readString("Enter Your Phone Number : ");
	cout << "Set the Balance: ";
	cin >> cl.Balance; 

	return cl;
}

bool  updateClientByAccountNumber(vector <stClients>& vClients, string accountAnumber)
{
	stClients Client;

	char answer = 'n';

	if (findClientByAccountNumber(vClients, accountAnumber, Client))
	{

		printClientByAcountNumber(Client);

		cout << "Do you want to Update this Client? [y/n]: ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			for (stClients& cl : vClients)
			{
				if (cl.AccountNumber == accountAnumber)
				{
					cl = updateClient(accountAnumber); 
					break;
				}
			}

			saveClientDatatoFile(vClients);

			cout << "\nClient Updated Successfully! \n";
			return true;
		}
	}
	else
	{
		cout << "\nAccount Number! '" << accountAnumber << "' Not Found!\n\n";
		return false;
	}

}

int main()
{
	vector <stClients> vClients = loadDataFromFile(fileName);

	string accountAnumber = readString("please enter Account Number: ");

	updateClientByAccountNumber(vClients, accountAnumber);

	return 0;
}









