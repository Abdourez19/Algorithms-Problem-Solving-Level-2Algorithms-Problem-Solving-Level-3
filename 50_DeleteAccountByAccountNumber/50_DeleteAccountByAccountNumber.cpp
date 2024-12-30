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

//1 - Method using Vector Iterator

//vector <string> split(string s1, string delimit)
//{
//	vector <string> vClient;
//	short DelimitPosition = 0;
//	string theWord = "";
//
//	while ((DelimitPosition = s1.find(delimit)) != string::npos)
//	{
//		theWord = s1.substr(0, DelimitPosition);
//
//		if (theWord != "")
//			vClient.push_back(theWord);
//		s1.erase(0, DelimitPosition + delimit.length());
//	}
//
//	if (s1 != "")
//		vClient.push_back(s1);
//
//	return vClient;
//}
//
//stClients convertLineDataToStructRecord(string s1, string delimit)
//{
//	stClients stClient;
//
//	vector <string> vClient = split(s1, delimit);
//
//	stClient.AccountNumber = vClient[0];
//	stClient.PIN = vClient[1];
//	stClient.FullName = vClient[2];
//	stClient.PhoneNumber = vClient[3];
//	stClient.Balance = stod(vClient[4]);
//
//	return stClient;
//}
//
//vector <stClients> loadDataFromFile(string fileName)
//{
//	fstream MyFile;
//
//	vector <stClients> vClient;
//
//	MyFile.open(fileName, ios::in);
//
//	if (MyFile.is_open())
//	{
//		string line;
//
//		while (getline(MyFile, line))
//		{
//			vClient.push_back(convertLineDataToStructRecord(line, delimit));
//		}
//
//		MyFile.close();
//		return vClient;
//	}
//
//}
//
//bool findClientByAccountNumber(stClients& Client, string accountNumber)
//{
//	vector <stClients> vClients = loadDataFromFile(fileName);
//
//	for (stClients& Cl : vClients)
//	{
//		if (Cl.AccountNumber == accountNumber)
//		{
//			Client = Cl;
//			return true;
//		}
//	}
//	return false;
//}
//
//void printClientByAcountNumber(stClients sClient, string accountNumber)
//{
//	if (sClient.AccountNumber == accountNumber)
//	{
//		cout << "\nThe Following is the clients details: \n\n";
//		cout << "Account Number : " << sClient.AccountNumber << endl;
//		cout << "PIN            : " << sClient.PIN << endl;
//		cout << "Client Name    : " << sClient.FullName << endl;
//		cout << "Phone Number   : " << sClient.PhoneNumber << endl;
//		cout << "Balance        : " << sClient.Balance << endl;
//	}
//	else
//		cout << "\nNo account Found with this Account Number! \n\n";
//}
//
//string ConvertRecordToLine(stClients clientInfos, string delimit)
//{
//	string LineClientRecord = "";
//
//	LineClientRecord += clientInfos.AccountNumber + delimit;
//	LineClientRecord += clientInfos.PIN + delimit;
//	LineClientRecord += clientInfos.FullName + delimit;
//	LineClientRecord += clientInfos.PhoneNumber + delimit;
//	LineClientRecord += to_string(clientInfos.Balance);
//
//	return LineClientRecord;
//}
//
//vector <stClients> deleteFromVector(string accountNumber) 
//{
//	vector <stClients> vClients = loadDataFromFile(fileName);
//
//	vector <stClients> ::iterator itr;
//
//	for (itr = vClients.begin(); itr != vClients.end(); itr++) 
//	{ 
//		if (itr->AccountNumber == accountNumber)
//		{
//			vClients.erase(itr);
//			break;
//		}
//			
//	}
//
//	return vClients;
//}
//
//void saveClientDatatoFile(string accountNumberToDel) 
//{
//	vector <stClients> sClients = deleteFromVector(accountNumberToDel); 
//
//	fstream client; 
//	 
//	client.open(fileName, ios::out); 
//
//	if (client.is_open()) 
//	{
//		for (stClients& cl : sClients)
//		{
//			client << ConvertRecordToLine(cl, delimit) << '\n';
//		}
//		client.close();
//	}
//}
//
//void DeleteClientByitsAccountNumber(stClients sClient)
//{
//	char deleteClient = 'Y';
//
//	string accountNumber;
//
//	do
//	{
//		system("cls");
//		cout << "Enter Account Number : ";
//		cin >> accountNumber;
//			
//		if (findClientByAccountNumber(sClient, accountNumber))
//		{
//			printClientByAcountNumber(sClient, accountNumber); 
//
//			cout << "\nAre you sure you want to delete this client? [Y/N]: ";
//			cin >> deleteClient;
//
//			if (toupper(deleteClient) == 'Y')
//			{
//				deleteFromVector(accountNumber); 
//				saveClientDatatoFile(accountNumber);
//
//				cout << "\nClient Deleted Successfully, Do you want to Delete more? [Y/N]: ";
//				cin >> deleteClient; 
//			}
//		}
//		else
//		{
//			printClientByAcountNumber(sClient, accountNumber); 
//			cout << "\nDo you want to try again? [Y/N]: ";
//			cin >> deleteClient;
//		}
//	} while (toupper(deleteClient)==  'Y');
//}


//2 - method using our custom functions

string readAccountNumber()
{
	string accountNumber;
	cout << "please enter Account Number: ";
	getline(cin, accountNumber);
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

void markClientToDeleteByAccountNumber(vector <stClients>& vClients , string accountNumber)
{
	for (stClients& cl : vClients)
	{
		if (cl.AccountNumber == accountNumber)
		{
			cl.markedToDelete = true; 
		}
	}
}

void saveClientDatatoFile(vector <stClients> vClients, string accountNumber) 
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

bool  deleteClientByAccountNumber(vector <stClients>& vClients, string accountAnumber)
{
	stClients Client;
	char answer = 'n';

	if (findClientByAccountNumber(vClients, accountAnumber, Client))
	{
		printClientByAcountNumber(Client);

		cout << "Do you want to delete this Client? [y/n]: ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{

			markClientToDeleteByAccountNumber(vClients, accountAnumber);
			saveClientDatatoFile(vClients, accountAnumber);

			//refresh the vector to get new data
			vClients = loadDataFromFile(fileName);

			cout << "\nClient deleted Successfully! \n";
			return true;
		}
	}
	else
	{
		cout << "\nAccount Number! '" << accountAnumber<< "' Not Found!\n\n";
		return false;
	}
		
}



int main()
{
	vector <stClients> vClients = loadDataFromFile(fileName);

	string accountAnumber = readAccountNumber();


	deleteClientByAccountNumber(vClients, accountAnumber);

	return 0;
}









		