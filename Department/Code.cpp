#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

void modify(int created);
void adminPassword();
void adminUserName();
void adminFirstName();
void adminLastName();
void adminCellPhone();
void adminAddress();
void cashierPassword();
void cashierUserName();
void cashierFirstName();
void cashierLastName();
void cashierCellPhone();
void cashierAddress();
void addItem(int & totalItems , string *& ptrOfEnd);
void copyArray1D(string* newArray, string* oldArray, int size);
string * regrowByFactor(string *oldArray, int size);
void removeItem(int & totalItems, int & newAdded1);
void editItem(int totalItems);
void productSummary(int totalItems, int newItem, string * ptrOfEnd);
void productDetailedSummary(int totalItems);
void menu(int totalItems);
void createBill(int totalThings, string *& ptrOfend, int & billsNumber);
void updateQuantity(int totalItems, int itemNum, int quantity);
void billReport(int totalItems, int itemNum, int quantityOfItems, int unique, string * ptrOfEnds);
void shortItem(int totalItems);
void cashier(int & totalCustomers, int &  cashierCreated, int & totalItem, string *& ptrEndingDate);
void modifyCashierOnly(int created);

int main()
{
	int cashierCreated = 0, totalCustomers = 3;
	string fileName;
	ifstream fin;
	fin.open("total.txt");
	if (!fin)
	{
		cout << "Not found" << endl << endl;
		exit(0);
	}
	else
	{
		fin >> cashierCreated;
	}
	fin.close();

	int  totalItem = 10;
	ifstream fin1;
	fin1.open("totalItem.txt");
	if (!fin1)
	{
		cout << "Not found" << endl << endl;
		exit(0);
	}
	else
	{
		fin1 >> totalItem;
	}
	fin1.close();

	ifstream fin2;
	fin2.open("totalCustomer.txt");
	if (!fin2)
	{
		cout << "Not found" << endl << endl;
		exit(0);
	}
	else
	{
		fin2 >> totalCustomers;
	}
	fin2.close();

	int optionAdmin = 1, cellPhone, optionMode, signOut = -11, newAdded = 0;
	string firstName, lastName, userName, addressOfCashier, passwordOfCashier, passwordOfAdmin, userNameAdmin, passwordOfAdmin1, userNameAdmin1;
	cout << "                                                  _____________________________________________________" << endl;
	cout << "                                                 |           Welcome to  Departmental Store            |" << endl;
	cout << "                                                 |_____________________________________________________|" << endl;
	string * ptrEndingDate = new string[totalItem + 100];
	for (int s = 0; s < totalItem + 100; s++)
	{
		ptrEndingDate[s] = "abc";
	}
	while (signOut == -11 || optionAdmin == 1)
	{
		cout << "Select a mode :" << endl
			<< "1 => Admin Mode." << endl
			<< "2 => Cashier Mode." << endl
			<< "3 => Exit (Terminate)." << endl
			<< "(Type 1 , 2 or 3 only.) : ";
		cin >> optionMode;
		while (optionMode != 1 && optionMode != 2 && optionMode != 3)
		{
			cout << "Invalid Option !" << endl;
			cout << "Select a mode :" << endl
				<< "1 => Admin Mode." << endl
				<< "2 => Cashier Mode." << endl
				<< "3 => Exit (Terminate)." << endl
				<< "(Type 1 , 2 or 3 only.) : ";
			cin >> optionMode;
		}
		if (optionMode == 1)
		{
			ifstream fin;
			fin.open("admin.txt");

			if (!fin)
			{
				cout << "Error!!! File is not found." << endl;
				exit(0);
			}
			else
			{
				cout << "Enter Username : ";
				cin.ignore();
				getline(cin, userNameAdmin1);
				cout << "Enter Password : ";
				getline(cin, passwordOfAdmin1);
				getline(fin, userNameAdmin);
				getline(fin, passwordOfAdmin);
				fin.close();
				ofstream fout;
				fout.open("admin.txt");
				fout << userNameAdmin << endl;
				fout << passwordOfAdmin << endl;
				fout.close();
				if (userNameAdmin == userNameAdmin1)
				{
					if (passwordOfAdmin == passwordOfAdmin1)
					{
						cout << " Do you want to :" << endl
							<< "1 => \"Sign out.\"" << endl
							<< "2 => \"Create cashier profile for registering.\"" << endl
							<< "3 => \"Modify admin and cashier.\"" << endl
							<< "4 => \"Exit (Terminate).\"" << endl
							<< "5 => \"Add item.\"" << endl
							<< "6 => \"Remove item.\"" << endl
							<< "7 => \"Edit item.\"" << endl
							<< "8 => \"Product Summary.\"" << endl
							<< "9 => \"Product detailed summary.\"" << endl
							<< "10 => \"Bill report.\"" << endl
							<< "11 => \"Short item.\"" << endl
							<< "Enter a digit in between 1 to 11 :";
						cin >> optionAdmin;
						while (optionAdmin > 11 || optionAdmin < 1)
						{
							cout << "Invalid Option !" << endl;
							cout << " Do you want to :" << endl
								<< "1 => \"Sign out.\"" << endl
								<< "2 => \"Create cashier profile for registering.\"" << endl
								<< "3 => \"Modify admin and cashier.\"" << endl
								<< "4 => \"Exit (Terminate).\"" << endl
								<< "5 => \"Add item.\"" << endl
								<< "6 => \"Remove item.\"" << endl
								<< "7 => \"Edit item.\"" << endl
								<< "8 => \"Product Summary.\"" << endl
								<< "9 => \"Product detailed summary.\"" << endl
								<< "10 => \"Bill report.\"" << endl
								<< "11 => \"Short item.\"" << endl
								<< "Enter a digit in between 1 to 11 :";
							cin >> optionAdmin;
						}
						if (optionAdmin == 1)
						{
							continue;
						}
						else if (optionAdmin == 2)
						{
							int cash;
							cash = cashierCreated;
							cout << "Enter User Name : ";
							cin.ignore();
							getline(cin, userName);
							ofstream fout;
							fout.open(userName);
							if (!fout)
							{
								cout << "Error!!! File is not opened." << endl;
								exit(0);
							}
							else
							{
								fout << "Cashier Detail :" << endl;
								cout << "Enter First Name :";
								getline(cin, firstName);
								fout << firstName << endl;
								cout << "Enter last Name :";
								getline(cin, lastName);
								fout << lastName << endl;
								fout << userName << endl;
								cout << "Enter Cell Phone Number :";
								cin >> cellPhone;
								fout << cellPhone << endl;
								cout << "Enter Address :";
								cin.ignore();
								getline(cin, addressOfCashier);
								fout << addressOfCashier << endl;
								cout << "Enter Password :";
								getline(cin, passwordOfCashier);
								fout << passwordOfCashier << endl;

								cout << "Cashier is successfully registered." << endl;


								cashierCreated++;
							}
							fout.close();
							if (cash == cashierCreated - 1)
							{
								ofstream fout;
								fout.open("total.txt");
								if (!fout)
								{
									cout << "Error!!! File is not opened.(Cashier size)" << endl;
									exit(0);
								}
								else
								{
									fout << cashierCreated;
									cout << "Now you have total " << cashierCreated << " Cashiers" << endl << endl;
								}
							}
							continue;
						}
						else if (optionAdmin == 3)
						{
							modify(cashierCreated);
							continue;
						}
						else if (optionAdmin == 4)
						{
							cout << endl;
							exit(0);
						}
						else if (optionAdmin == 5)
						{
							newAdded++;
							addItem(totalItem, ptrEndingDate);
							cout << endl;
							continue;
						}
						else if (optionAdmin == 6)
						{
							removeItem(totalItem, newAdded);
							totalItem--;
							ofstream fout;
							fout.open("totalItem.txt");
							if (!fout)
							{
								cout << "Error!!! File is not opened.(Cashier size)" << endl;
								exit(0);
							}
							else
							{
								fout << totalItem;
								cout << "Now you have total " << totalItem << " Items" << endl << endl;
							}
							fout.close();
							cout << endl;
							continue;
						}
						else if (optionAdmin == 7)
						{
							editItem(totalItem);
							cout << endl;
							continue;
						}
						else if (optionAdmin == 8)
						{
							productSummary(totalItem, newAdded, ptrEndingDate);
							cout << endl;
							continue;
						}
						else if (optionAdmin == 9)
						{
							productDetailedSummary(totalItem);
							cout << endl;
							continue;
						}
						else if (optionAdmin == 10)
						{
							int ** ptrOfMenuReader = new int*[totalCustomers];
							for (int k = 0; k <= totalCustomers; k++)
							{
								ptrOfMenuReader[k] = new int[3];
							}
							ifstream fin;
							fin.open("bills.txt");

							if (!fin)
							{
								cout << "File not found. " << endl << endl;
							}
							else
							{

								for (int i = 0; i <= totalCustomers; i++)
								{

									for (int j = 0; j < 3; j++)
									{
										fin >> ptrOfMenuReader[i][j];
									}

								}
							}
							fin.close();
							int unqiueid;
							cout << "Enter customer ID : ";
							cin >> unqiueid;
							while (unqiueid < 0 || unqiueid > totalCustomers)
							{
								cout << "No such id found !" << endl;
								cout << "Enter customer ID : ";
								cin >> unqiueid;
							}

							billReport(totalItem, ptrOfMenuReader[unqiueid][1], ptrOfMenuReader[unqiueid][2], unqiueid, ptrEndingDate);

							cout << endl;
							continue;
						}
						else if (optionAdmin == 11)
						{
							shortItem(totalItem);
							cout << endl;
							continue;
						}

					}
					else
					{
						cout << "Password Incorrect." << endl << endl;
						continue;
					}
				}
				else
				{
					if (passwordOfAdmin == passwordOfAdmin1)
					{
						cout << "Username Incorrect." << endl << endl;
						continue;
					}
					else
					{
						cout << "Username and Password both are Incorrect." << endl << endl;
						continue;
					}
				}

			}
		}
		else if (optionMode == 2)
		{
			if (cashierCreated == 0)
			{
				cout << "Cashier is not registered." << endl << endl;
				continue;
			}
			else
			{
				cashier(totalCustomers, cashierCreated, totalItem, ptrEndingDate);
				continue;
			}

		}
		else
		{
			cout << endl;
			exit(0);
		}

	}
	delete[] ptrEndingDate;
	ptrEndingDate = nullptr;
	return 0;
}

void modify(int created)
{
	int optionModify = 0, back1 = 1;
	while (back1 == 1)
	{
		cout << "Select an option :" << endl
			<< "1 => \"Change Password for admin and cashier profile.\"" << endl
			<< "2 => \"Change User Name for admin and cashier profile.\"" << endl
			<< "3 => \"Change first name for admin and cashier profile.\"" << endl
			<< "4 => \"Change last name for admin and cashier profile.\"" << endl
			<< "5 => \"Change Cell phone number for admin and cashier profile.\"" << endl
			<< "6 => \"Change address for admin and cashier profile.\"" << endl
			<< "7 => \"Sign Out(Admin).\"" << endl;	
		cin >> optionModify;
		while (optionModify > 7 || optionModify < 1)
		{
			cout << "Invalid Option!" << endl;
			cout << "Select an option :" << endl
				<< "1 => \"Change Password for admin and cashier profile.\"" << endl
				<< "2 => \"Change User Name for admin and cashier profile.\"" << endl
				<< "3 => \"Change first name for admin and cashier profile.\"" << endl
				<< "4 => \"Change last name for admin and cashier profile.\"" << endl
				<< "5 => \"Change Cell phone number for admin and cashier profile.\"" << endl
				<< "6 => \"Change address for admin and cashier profile.\"" << endl
				<< "7 => \"Sign Out(Admin).\"" << endl;
			cin >> optionModify;
		}
		if (optionModify == 1)
		{
			int optionPassword;
			cout << "You want to change password of : " << endl;
			cout << "1 => Admin." << endl;
			cout << "2 => Cashier." << endl;
			cout << "3 => Back." << endl;
			cin >> optionPassword;
			while (optionPassword != 1 && optionPassword != 2 && optionPassword != 3)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change password of : " << endl;
				cout << "1 => Admin." << endl;
				cout << "2 => Cashier." << endl;
				cout << "3 => Back." << endl;
				cin >> optionPassword;
			}
			if (optionPassword == 1)
			{
				adminPassword();
				cout << endl;
				continue;
			}
			else if (optionPassword == 2)
			{
				if (created != 0)
				{
					cashierPassword();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionPassword == 3)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 2)
		{
			int optionUserName;
			cout << "You want to change User Name of : " << endl;
			cout << "1 => Admin." << endl;
			cout << "2 => Cashier." << endl;
			cout << "3 => Back." << endl;
			cin >> optionUserName;
			while (optionUserName != 1 && optionUserName != 2 && optionUserName != 3)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change User Name of : " << endl;
				cout << "1 => Admin." << endl;
				cout << "2 => Cashier." << endl;
				cout << "3 => Back." << endl;
				cin >> optionUserName;
			}
			if (optionUserName == 1)
			{
				adminUserName();
				cout << endl;
				continue;
			}
			else if (optionUserName == 2)
			{
				if (created != 0)
				{
					cashierUserName();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionUserName == 3)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 3)
		{
			int optionFirstName;
			cout << "You want to change First Name of : " << endl;
			cout << "1 => Admin." << endl;
			cout << "2 => Cashier." << endl;
			cout << "3 => Back." << endl;
			cin >> optionFirstName;
			while (optionFirstName != 1 && optionFirstName != 2 && optionFirstName != 3)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change First Name of : " << endl;
				cout << "1 => Admin." << endl;
				cout << "2 => Cashier." << endl;
				cout << "3 => Back." << endl;
				cin >> optionFirstName;
			}
			if (optionFirstName == 1)
			{
				
				adminFirstName();
				cout << endl;
				continue;
			}
			else if (optionFirstName == 2)
			{
				if (created != 0)
				{
					cashierFirstName();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionFirstName == 3)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 4)
		{
			int optionLastName;
			cout << "You want to change Last Name of : " << endl;
			cout << "1 => Admin." << endl;
			cout << "2 => Cashier." << endl;
			cout << "3 => Back." << endl;
			cin >> optionLastName;
			while (optionLastName != 1 && optionLastName != 2 && optionLastName != 3)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change Last Name of : " << endl;
				cout << "1 => Admin." << endl;
				cout << "2 => Cashier." << endl;
				cout << "3 => Back." << endl;
				cin >> optionLastName;
			}
			if (optionLastName == 1)
			{
				adminLastName();
				cout << endl;
				continue;
			}
			else if(optionLastName == 2)
			{
				if (created != 0)
				{
					cashierLastName();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionLastName == 3)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 5)
		{
			int optionCellPhone;
			cout << "You want to change Cell phone number of : " << endl;
			cout << "1 => Admin." << endl;
			cout << "2 => Cashier." << endl;
			cout << "3 => Back." << endl;
			cin >> optionCellPhone;
			while (optionCellPhone != 1 && optionCellPhone != 2 && optionCellPhone != 3)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change Cell phone number of : " << endl;
				cout << "1 => Admin." << endl;
				cout << "2 => Cashier." << endl;
				cout << "3 => Back." << endl;
				cin >> optionCellPhone;
			}
			if (optionCellPhone == 1)
			{
				adminCellPhone();
				cout << endl;
				continue;
			}
			else if (optionCellPhone == 2)
			{
				if (created != 0)
				{
					cashierCellPhone();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionCellPhone == 3)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 6)
		{
			int optionAddress;
			cout << "You want to change address of : " << endl;
			cout << "1 => Admin." << endl;
			cout << "2 => Cashier." << endl;
			cout << "3 => Back." << endl;
			cin >> optionAddress;
			while (optionAddress != 1 && optionAddress != 2 && optionAddress != 3)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change First Name of : " << endl;
				cout << "1 => Admin." << endl;
				cout << "2 => Cashier." << endl;
				cout << "3 => Back." << endl;
				cin >> optionAddress;
			}
			if (optionAddress == 1)
			{
				adminAddress();
				cout << endl;
				continue;
			}
			else if(optionAddress == 2)
			{
				if (created != 0)
				{
					cashierAddress();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionAddress == 3)
			{

				cout << endl;
				continue;
			}
			cout << endl;
			continue;
		}
		else if (optionModify == 7)
		{
			cout << endl;
			break;
		}
	}
	
}

void adminPassword()
{
	string passwordOfAdmin1, userNameAdmin, passwordOfAdmin, passwordOfAdminNew;
	ifstream fin;
	fin.open("admin.txt");

	if (!fin)
	{
		cout << "Error!!! File is not found." << endl;
		exit(0);
	}
	else
	{
		cout << "Enter old Password : ";
		cin.ignore();
		getline(cin, passwordOfAdmin1);
		getline(fin, userNameAdmin);
		getline(fin, passwordOfAdmin);
		fin.close();
		if (passwordOfAdmin1 == passwordOfAdmin)
		{
			cout << "Enter New Password : ";
			getline(cin, passwordOfAdminNew);
			ofstream fout;
			fout.open("admin.txt");
			fout << userNameAdmin << endl;
			fout << passwordOfAdminNew << endl;
			fout.close();
			cout << "Successfully changed !" << endl;
		}
		else
		{
			cout << "Old Password Incorrect! " << endl;
			ofstream fout;
			fout.open("admin.txt");
			fout << userNameAdmin << endl;
			fout << passwordOfAdmin << endl;
			fout.close();
		}
	}
}

void cashierPassword()
{
	string detail, firstName, lastName, userName, addressOfCashier, passwordOfCashier, passwordOfCashierOld, passwordOfCashierNew;
	int cellPhone;
	cout << "Enter User Name : ";
	cin.ignore();
	getline(cin, userName);
	ifstream fin;
	fin.open(userName);
	if (!fin)
	{
		cout << "Error ! File is not found." << endl << endl;
	}
	else
	{
		getline(fin, detail);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, userName);
		fin >> cellPhone;
		fin.ignore();
		getline(fin, addressOfCashier);
		getline(fin, passwordOfCashier);
		fin.close();

		cout << "Enter Old Password : ";
		getline(cin, passwordOfCashierOld);

		if (passwordOfCashier == passwordOfCashierOld)
		{
			cout << "Enter New Password : ";
			getline(cin, passwordOfCashierNew);
			ofstream fout;
			fout.open(userName);
			fout << detail << endl;
			fout << firstName << endl;
			fout << lastName << endl;
			fout << userName << endl;
			fout << cellPhone << endl;
			fout << addressOfCashier << endl;
			fout << passwordOfCashierNew << endl;
			fout.close();

			cout << "Cashier password is successfully changed." << endl;
		}
		else
		{
			cout << "Old Password Incorrect!" << endl;
			ofstream fout;
			fout.open(userName);
			fout << detail << endl;
			fout << firstName << endl;
			fout << lastName << endl;
			fout << userName << endl;
			fout << cellPhone << endl;
			fout << addressOfCashier << endl;
			fout << passwordOfCashier << endl;
			fout.close();
		}
	}
	

}

void adminUserName()
{
	string userNameOfAdmin1, userNameAdmin, passwordOfAdmin, userNameOfAdminNew;
	ifstream fin;
	fin.open("admin.txt");

	if (!fin)
	{
		cout << "Error!!! File is not found." << endl;
		exit(0);
	}
	else
	{
		cout << "Enter old User name : ";
		cin.ignore();
		getline(cin, userNameOfAdmin1);
		getline(fin, userNameAdmin);
		getline(fin, passwordOfAdmin);
		fin.close();
		if (userNameOfAdmin1 == userNameAdmin)
		{
			cout << "Enter New User name : ";
			getline(cin, userNameOfAdminNew);
			ofstream fout;
			fout.open("admin.txt");
			fout << userNameOfAdminNew << endl;
			fout << passwordOfAdmin << endl;
			fout.close();
			cout << "Successfully changed !" << endl;
		}
		else
		{
			cout << "Old user Name Incorrect! " << endl;
			ofstream fout;
			fout.open("admin.txt");
			fout << userNameAdmin << endl;
			fout << passwordOfAdmin << endl;
			fout.close();
		}
	}
}

void adminCellPhone()
{
	string cellPhoneOfAdmin, firstNameAdmin, addressOfAdmin, lastNameOfAdmin;

	ifstream fin;
	fin.open("adminData.txt");
	if (!fin)
	{
		cout << "Error!!! File is not found." << endl;
		exit(0);
	}
	else
	{
		getline(fin, firstNameAdmin);
		getline(fin, lastNameOfAdmin);
		getline(fin, cellPhoneOfAdmin);
		getline(fin, addressOfAdmin);
	}
	fin.close();
	cout << "Enter the new cell phone number  : ";
	cin.ignore();
	getline(cin, cellPhoneOfAdmin);

	ofstream fout;
	fout.open("adminData.txt");
	if (!fout)
	{
		cout << "Error!!! File is not opened." << endl;
		exit(0);
	}
	else
	{
		fout << firstNameAdmin << endl;
		fout << lastNameOfAdmin << endl;
		fout << cellPhoneOfAdmin << endl;
		fout << addressOfAdmin << endl;
		cout << "Successfully changed !" << endl;
	}
	fout.close();
}
void adminFirstName()
{
	string cellPhoneOfAdmin, firstNameAdmin, addressOfAdmin, lastNameOfAdmin;

	ifstream fin;
	fin.open("adminData.txt");
	if (!fin)
	{
		cout << "Error!!! File is not found." << endl;
		exit(0);
	}
	else
	{
		getline(fin, firstNameAdmin);
		getline(fin, lastNameOfAdmin);
		getline(fin, cellPhoneOfAdmin);
		getline(fin, addressOfAdmin);
	}
	fin.close();
	cout << "Enter the new First Name : ";
	cin.ignore();
	getline(cin, firstNameAdmin);

	ofstream fout;
	fout.open("adminData.txt");
	if (!fout)
	{
		cout << "Error!!! File is not opened." << endl;
		exit(0);
	}
	else
	{
		fout << firstNameAdmin << endl;
		fout << lastNameOfAdmin << endl;
		fout << cellPhoneOfAdmin << endl;
		fout << addressOfAdmin << endl;
		cout << "Successfully changed !" << endl;
	}
	fout.close();
}
void adminLastName()
{
	string cellPhoneOfAdmin, firstNameAdmin, addressOfAdmin, lastNameOfAdmin;

	ifstream fin;
	fin.open("adminData.txt");
	if (!fin)
	{
		cout << "Error!!! File is not found." << endl;
		exit(0);
	}
	else
	{
		getline(fin, firstNameAdmin);
		getline(fin, lastNameOfAdmin);
		getline(fin, cellPhoneOfAdmin);
		getline(fin, addressOfAdmin);
	}
	fin.close();
	cout << "Enter the new last Name : ";
	cin.ignore();
	getline(cin, lastNameOfAdmin);

	ofstream fout;
	fout.open("adminData.txt");
	if (!fout)
	{
		cout << "Error!!! File is not opened." << endl;
		exit(0);
	}
	else
	{
		fout << firstNameAdmin << endl;
		fout << lastNameOfAdmin << endl;
		fout << cellPhoneOfAdmin << endl;
		fout << addressOfAdmin << endl;
		cout << "Successfully changed !" << endl;
	}
	fout.close();
}
void adminAddress()
{
	string cellPhoneOfAdmin, firstNameAdmin, addressOfAdmin, lastNameOfAdmin;

	ifstream fin;
	fin.open("adminData.txt");
	if (!fin)
	{
		cout << "Error!!! File is not found." << endl;
		exit(0);
	}
	else
	{
		getline(fin, firstNameAdmin);
		getline(fin, lastNameOfAdmin);
		getline(fin, cellPhoneOfAdmin);
		getline(fin, addressOfAdmin);
	}
	fin.close();
	cout << "Enter the new address of admin : ";
	cin.ignore();
	getline(cin, addressOfAdmin);

	ofstream fout;
	fout.open("adminData.txt");
	if (!fout)
	{
		cout << "Error!!! File is not opened." << endl;
		exit(0);
	}
	else
	{
		fout << firstNameAdmin << endl;
		fout << lastNameOfAdmin << endl;
		fout << cellPhoneOfAdmin << endl;
		fout << addressOfAdmin << endl;
		cout << "Successfully changed !" << endl;
	}
	fout.close();
}


void cashierUserName()
{
	string detail, firstName, lastName, userName, addressOfCashier, passwordOfCashier, userNameOld, userNameNew;
	int cellPhone;
	cout << "Enter old User Name : ";
	cin.ignore();
	getline(cin, userNameOld);
	ifstream fin;
	fin.open(userNameOld);
	if (!fin)
	{
		cout << "Error ! Wrong user name." << endl << endl;
	}
	else
	{
		getline(fin, detail);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, userName);
		fin >> cellPhone;
		fin.ignore();
		getline(fin, addressOfCashier);
		getline(fin, passwordOfCashier);
		fin.close();
		if (userName == userNameOld)
		{
			cout << "Enter New User Name : : ";
			getline(cin, userNameNew);
			ofstream fout;
			fout.open(userNameNew);
			fout << detail << endl;
			fout << firstName << endl;
			fout << lastName << endl;
			fout << userNameNew << endl;
			fout << cellPhone << endl;
			fout << addressOfCashier << endl;
			fout << passwordOfCashier << endl;
			fout.close();

			cout << "Cashier User name is successfully changed." << endl;
		}
		else
		{
			cout << "Old User Name Incorrect!" << endl;
			ofstream fout;
			fout.open(userName);
			fout << detail << endl;
			fout << firstName << endl;
			fout << lastName << endl;
			fout << userName << endl;
			fout << cellPhone << endl;
			fout << addressOfCashier << endl;
			fout << passwordOfCashier << endl;
			fout.close();
		}
	}

}

void cashierFirstName()
{
	string detail, firstName, lastName, userName, addressOfCashier, passwordOfCashier;
	int cellPhone;
	cout << "Enter User Name : ";
	cin.ignore();
	getline(cin, userName);
	ifstream fin;
	fin.open(userName);
	if (!fin)
	{
		cout << "Error ! File is not found." << endl << endl;
	}
	else
	{
		getline(fin, detail);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, userName);
		fin >> cellPhone;
		fin.ignore();
		getline(fin, addressOfCashier);
		getline(fin, passwordOfCashier);
		fin.close();
		cout << "Enter New First name : ";
		getline(cin, firstName);
		ofstream fout;
		fout.open(userName);
		fout << detail << endl;
		fout << firstName << endl;
		fout << lastName << endl;
		fout << userName << endl;
		fout << cellPhone << endl;
		fout << addressOfCashier << endl;
		fout << passwordOfCashier<< endl;
		fout.close();

		cout << "Cashier first name is successfully changed." << endl;

		
	}


}

void cashierLastName()
{
	string detail, firstName, lastName, userName, addressOfCashier, passwordOfCashier;
	int cellPhone;
	cout << "Enter User Name : ";
	cin.ignore();
	getline(cin, userName);
	ifstream fin;
	fin.open(userName);
	if (!fin)
	{
		cout << "Error ! File is not found." << endl << endl;
	}
	else
	{
		getline(fin, detail);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, userName);
		fin >> cellPhone;
		fin.ignore();
		getline(fin, addressOfCashier);
		getline(fin, passwordOfCashier);
		fin.close();
		cout << "Enter New last Name : ";
		getline(cin, lastName);
		ofstream fout;
		fout.open(userName);
		fout << detail << endl;
		fout << firstName << endl;
		fout << lastName << endl;
		fout << userName << endl;
		fout << cellPhone << endl;
		fout << addressOfCashier << endl;
		fout << passwordOfCashier << endl;
		fout.close();

		cout << "Cashier last name is successfully changed." << endl;


	}


}

void cashierCellPhone()
{
	string detail, firstName, lastName, userName, addressOfCashier, passwordOfCashier;
	int cellPhone;
	cout << "Enter User Name : ";
	cin.ignore();
	getline(cin, userName);
	ifstream fin;
	fin.open(userName);
	if (!fin)
	{
		cout << "Error ! File is not found." << endl << endl;
	}
	else
	{
		getline(fin, detail);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, userName);
		fin >> cellPhone;
		fin.ignore();
		getline(fin, addressOfCashier);
		getline(fin, passwordOfCashier);
		fin.close();
		cout << "Enter New Cell phone Number : ";
		cin >> cellPhone;
		ofstream fout;
		fout.open(userName);
		fout << detail << endl;
		fout << firstName << endl;
		fout << lastName << endl;
		fout << userName << endl;
		fout << cellPhone << endl;
		fout << addressOfCashier << endl;
		fout << passwordOfCashier << endl;
		fout.close();

		cout << "Cashier Cell phone Number is successfully changed." << endl;


	}

}

void cashierAddress()
{
	string detail, firstName, lastName, userName, addressOfCashier, passwordOfCashier;
	int cellPhone;
	cout << "Enter User Name : ";
	cin.ignore();
	getline(cin, userName);
	ifstream fin;
	fin.open(userName);
	if (!fin)
	{
		cout << "Error ! File is not found." << endl << endl;
	}
	else
	{
		getline(fin, detail);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, userName);
		fin >> cellPhone;
		fin.ignore();
		getline(fin, addressOfCashier);
		getline(fin, passwordOfCashier);
		fin.close();
		cout << "Enter New adress : ";
		getline(cin, addressOfCashier);
		ofstream fout;
		fout.open(userName);
		fout << detail << endl;
		fout << firstName << endl;
		fout << lastName << endl;
		fout << userName << endl;
		fout << cellPhone << endl;
		fout << addressOfCashier << endl;
		fout << passwordOfCashier << endl;
		fout.close();

		cout << "Cashier address is successfully changed." << endl;


	}


}

void addItem(int & totalItems, string *& ptrOfEnd)
{
	totalItems = totalItems + 1;
	ofstream fout;
	fout.open("totalItem.txt");
	if (!fout)
	{
		cout << "Error!!! File is not opened.(Cashier size)" << endl;
		exit(0);
	}
	else
	{
		fout << totalItems;
		cout << "Now you have total " << totalItems << " Items" << endl << endl;
	}
	fout.close();
	ptrOfEnd = regrowByFactor(ptrOfEnd, totalItems);

	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{

		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (i == totalItems - 1)
				{
					if (j == 1)
					{
						cin.ignore();
						cout << "Enter Item Name : ";
						getline(cin, ptrOfMenuName[i]);
					}
					else if (j == 0)
					{
						ptrOfMenuReader[i][j] = totalItems - 1;
					}
					else if (j == 3)
					{
						cout << "Enter the price of item :";
						cin >> ptrOfMenuReader[i][j];
					}
					else if (j == 4)
					{
						cout << "Enter the quantity of item : ";
						cin >> ptrOfMenuReader[i][j];
					}
					else if (j == 5)
					{
						cout << "Enter the tax percent : ";
						cin >> ptrOfMenuReader[i][j];
					}
					else if (j == 2)
					{
						cout << "Enter the manufacturing date : ";
						getline(cin, ptrOfMenuDate[i]);
					}

				}
				else if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		ofstream fout;
		fout.open("menu.txt");
		if (!fout)
		{
			cout << "Error ! File is not opened." << endl << endl;
		}
		else
		{
			for (int i = 0; i < totalItems; i++)
			{

				for (int j = 0; j < 6; j++)
				{
					if (j == 1)
					{
						fout << ptrOfMenuName[i] << endl;
					}
					else if (j == 2)
					{
						fout << ptrOfMenuDate[i] << endl;
					}
					else
					{
						fout << ptrOfMenuReader[i][j] << endl;
					}
				}

			}
			fout.close();
		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

string * regrowByFactor(string *oldArray, int size)
{
	string *Narray = new string[size];
	copyArray1D(Narray, oldArray, size -1);
	delete[]oldArray;
	oldArray = nullptr;
	return Narray;
}

void copyArray1D(string* newArray, string* oldArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		newArray[i] = oldArray[i];
	}
}

void removeItem(int & totalItems, int & newAdded1)
{
	int itemNumber;
	string itemName;
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		cout << "Enter Item number : ";
		cin >> itemNumber;
		while (itemNumber < 0 || itemNumber > totalItems)
		{
			cout << "Invalid Item number!" << endl;
			cout << "Enter Item number : ";
			cin >> itemNumber;
		}
		if (totalItems - newAdded1 >= itemNumber)
		{
			newAdded1--;
		}
		cout << "Enter item Name : ";
		cin.ignore();
		getline(cin, itemName);
		while (ptrOfMenuName[itemNumber] != itemName)
		{
			cout << "Invalid Item name!" << endl;
			cout << "Enter item Name : ";
			getline(cin, itemName);
		}
		ofstream fout;
		fout.open("menu.txt");
		if (!fout)
		{
			cout << "Error ! File is not opened." << endl << endl;
		}
		else
		{
			for (int i = 0; i < itemNumber; i++)
			{

				for (int j = 0; j < 6; j++)
				{
					if (j == 1)
					{
						fout << ptrOfMenuName[i] << endl;
					}
					else if (j == 2)
					{
						fout << ptrOfMenuDate[i] << endl;
					}
					else
					{
						fout << ptrOfMenuReader[i][j] << endl;
					}
				}
			}
			cout << "Item Numbers : ";
			cout << ptrOfMenuReader[itemNumber][0] << endl;
			cout << "Item Names   : ";
			cout << ptrOfMenuName[itemNumber] << endl;
			cout << "Start  Dates : ";
			cout << ptrOfMenuDate[itemNumber] << endl;
			cout << "Item Prices  : ";
			cout << ptrOfMenuReader[itemNumber][3] << endl;
			cout << "Item.Quantity: ";
			cout << ptrOfMenuReader[itemNumber][4] << endl;
			cout << "Tax Percents : ";
			cout << ptrOfMenuReader[itemNumber][5] << endl;

			for (int i = itemNumber + 1; i < totalItems; i++)
			{

				for (int j = 0; j < 6; j++)
				{
					if (j == 1)
					{
						fout << ptrOfMenuName[i] << endl;
					}
					else if (j == 2)
					{
						fout << ptrOfMenuDate[i] << endl;
					}
					else if (j == 0)
					{
						fout << ptrOfMenuReader[i][j] - 1 << endl;
					}
					else
					{
						fout << ptrOfMenuReader[i][j] << endl;
					}
				}

			}
			fout.close();
		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void editItem(int totalItems)
{
	int itemNumber, newItemNumber;
	string itemName;
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		cout << "Enter Item number : ";
		cin >> itemNumber;
		while (itemNumber < 0 || itemNumber > totalItems)
		{
			cout << "Invalid Item number!" << endl;
			cout << "Enter Item number : ";
			cin >> itemNumber;
		}
		cout << "Enter item Name : ";
		cin.ignore();
		getline(cin, itemName);
		while (ptrOfMenuName[itemNumber] != itemName)
		{
			cout << "Invalid Item name!" << endl;
			cout << "Enter item Name : ";
			getline(cin, itemName);
		}
		ofstream fout;
		fout.open("menu.txt");
		if (!fout)
		{
			cout << "Error ! File is not opened." << endl << endl;
		}
		else
		{
			cout << "Do you want to edit : " << endl
				<< "1 => Name ." << endl
				<< "2 => Manufacturing Date." << endl
				<< "3 => Price." << endl
				<< "4 => Quantity." << endl
				<< "5 => Tax Percent." << endl;
			cin >> newItemNumber;
			while (newItemNumber > 5 || newItemNumber <= 0)
			{
				cout << "Invalid Option!" << endl;
				cout << "Do you want to edit : " << endl
					<< "1 => Item Name ." << endl
					<< "2 => Manufacturing Date." << endl
					<< "3 => Price." << endl
					<< "4 => Quantity." << endl
					<< "5 => Tax Percent." << endl;
				cin >> newItemNumber;
			}
			if (newItemNumber == 1)
			{
				cout << "You can Re-Enter Item Name : ";
			}
			else if (newItemNumber == 2)
			{
				cout << "You can Re-Enter Manufacturing Date : ";
			}
			else if (newItemNumber == 3)
			{
				cout << "You can Re-Enter Price : ";
			}
			else if (newItemNumber == 4)
			{
				cout << "You can Re-Enter Quantity : ";
			}
			else if (newItemNumber == 5)
			{
				cout << "You can Re-Enter Tax Percent : ";
			}
			for (int i = 0; i < totalItems; i++)
			{
				
				for (int j = 0; j < 6; j++)
				{
					if (j == 1)
					{
						if (itemNumber == i && j == newItemNumber)
						{
							cin.ignore();
							getline(cin, ptrOfMenuName[i]);
						}
						fout << ptrOfMenuName[i] << endl;
					}
					else if (j == 2)
					{
						if (itemNumber == i && j == newItemNumber)
						{
							cin.ignore();
							getline(cin, ptrOfMenuDate[i]);
						}
						fout << ptrOfMenuDate[i] << endl;
					}
					else
					{
						if (itemNumber == i && j == newItemNumber)
						{
							cin >> ptrOfMenuReader[i][j];
						}
						fout << ptrOfMenuReader[i][j] << endl;
					}
				}

			}
			fout.close();
		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void productSummary(int totalItems, int newItem, string * ptrOfEnd)
{
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		cout << " Total New added item is " << newItem << endl;
		for (int i = totalItems - newItem; i < totalItems; i++)
		{
			cout << "Starting Date of " << i << " is " << ptrOfMenuDate[i] << endl;
			if (ptrOfEnd[i] == "abc" || ptrOfMenuReader[i][4] != 0)
			{
				cout << "Item is still available." << endl;
			}
			else
			{
				cout << "Ending Date of " << i << " is " << ptrOfEnd[i] << endl;
			}
		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void productDetailedSummary(int totalItems)
{
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		for (int i = 0; i < 6; i++)
		{
			for (int j = -1; j < totalItems; j++)
			{
				if (j == -1 && i == 0)
				{
					cout << "Item Numbers : ";
				}
				else if (j == - 1 && i == 1)
				{
					cout << "Item Names   : ";
				}
				else if (j == -1 && i == 2)
				{
					cout << "Start  Dates : ";
				}
				else if (j == -1 && i == 3)
				{
					cout << "Item Prices  : ";
				}
				else if (j == -1 && i == 4)
				{
					cout << "Item.Quantity: ";
				}
				else if (j ==-1  && i == 5)
				{
					cout << "Tax Percents : ";
				}
				if (i == 1 && j != -1)
				{
					cout << ptrOfMenuName[j] << "  ";
				}
				else if (i == 2 && j != -1)
				{
					cout << ptrOfMenuDate[j] << "  ";
				}
				else if (j != -1)
				{
					cout << ptrOfMenuReader[j][i] << "  ";
				}
			}
			cout << endl;
		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void menu(int totalItems)
{
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					fin.ignore();
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		for (int i = 0; i < 6; i++)
		{
			for (int j = -1; j < totalItems; j++)
			{
				if (j == -1 && i == 0)
				{
					cout << "Item Numbers : ";
				}
				else if (j == -1 && i == 1)
				{
					cout << "Item Names   : ";
				}
				if (i == 1 && j != -1)
				{
					cout << ptrOfMenuName[j] << "  ";
				}
				else if (j != -1 && i == 0)
				{
					cout << ptrOfMenuReader[j][i] << "  ";
				}
			}
			cout << endl;

		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void createBill(int totalThings, string *& ptrOfend,int & billsNumber)
{
	int ** ptrOfMenuReader = new int*[billsNumber + 2];
	for (int k = 0; k <= billsNumber + 1; k++)
	{
		ptrOfMenuReader[k] = new int[3];
	}

	int uniqueId, quantity, itemNumber;
	uniqueId =billsNumber + 1;
	menu(totalThings);
	cout << "Enter the item Number : ";
	cin >> itemNumber;
	while (itemNumber < 0 || itemNumber > totalThings)
	{
		cout << "Sorry ! No such item exit." << endl;
		cout << "Enter the item Number : ";
		cin >> itemNumber;
	}
	cout << "Enter the Quantity : ";
	cin >> quantity;
	cout << "Enter the date of purchase : ";
	cin.ignore();
	getline(cin, ptrOfend[itemNumber]);

	ifstream fin;
	fin.open("bills.txt");
	if (!fin)
	{
		cout << "File not found. " << endl << endl;
	}
	else
	{
		
		for (int i = 0; i <= billsNumber; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				fin >> ptrOfMenuReader[i][j];
			}

		}
	}
	fin.close();
	billsNumber++;

	ofstream fout1;
	fout1.open("totalCustomer.txt");
	if (!fout1)
	{
		cout << "Error!!! File is not opened.(Cashier size)" << endl;
		exit(0);
	}
	else
	{
		fout1 << billsNumber;
	}
	fout1.close();

	ptrOfMenuReader[billsNumber][0] = billsNumber;
	ptrOfMenuReader[billsNumber][1] = itemNumber;
	ptrOfMenuReader[billsNumber][2] = quantity;

	ofstream fout;
	fout.open("bills.txt");
	if (!fout)
	{
		cout << "File not opened." << endl << endl;
	}
	else
	{
		for (int i = 0; i <= billsNumber; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				fout << ptrOfMenuReader[i][j] << endl;
			}

		}
	}
	fout.close();

	billReport(totalThings, itemNumber, quantity, uniqueId, ptrOfend);

	updateQuantity(totalThings, itemNumber, quantity);

	for (int k = 0; k <= billsNumber; k++)
	{
		delete[]ptrOfMenuReader[k];
	}
	delete[] ptrOfMenuReader;
	ptrOfMenuReader = nullptr;

}

void updateQuantity(int totalItems,int itemNum, int quantity)
{
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		ofstream fout;
		fout.open("menu.txt");
		if (!fout)
		{
			cout << "Error ! File is not opened." << endl << endl;
		}
		else
		{
			
			for (int i = 0; i < totalItems; i++)
			{

				for (int j = 0; j < 6; j++)
				{
					if (j == 1)
					{
						
						fout << ptrOfMenuName[i] << endl;
					}
					else if (j == 2)
					{
						
						fout << ptrOfMenuDate[i] << endl;
					}
					else
					{
						if (i == itemNum && j == 4)
						{
							ptrOfMenuReader[i][j] = ptrOfMenuReader[i][j] - quantity;
						}
						fout << ptrOfMenuReader[i][j] << endl;
					}
				}

			}
			fout.close();
		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void billReport(int totalItems, int itemNum, int quantityOfItems,int unique, string * ptrOfEnds)
{
	double billWithOutTax, taxs, BillWithTax;
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		for (int j = 0; j < 6; j++)
		{
			if (j == 0)
			{
				cout << "Item Numbers : ";
			}
			else if (j == 1)
			{
				cout << "Item Names   : ";
			}
			else if (j == 2)
			{
				cout << "Start  Dates : ";
			}
			else if (j == 3)
			{
				cout << "Item Prices  : ";
			}
			else if (j == 4)
			{
				cout << "Item.Quantity: ";
			}
			else if (j == 5)
			{
				cout << "Tax Percents : ";
			}
			if (j == 1)
			{
				cout << ptrOfMenuName[itemNum] << " ";
			}
			else if (j == 2)
			{
				cout << ptrOfMenuDate[itemNum] << " ";
			}
			else
			{
				if (j != 4)
				{
					cout << ptrOfMenuReader[itemNum][j] << " ";
				}
				else
				{
					cout << quantityOfItems << " ";
				}
			}
			cout << endl;
		}
		billWithOutTax = ptrOfMenuReader[itemNum][3] * quantityOfItems;
		taxs = ( static_cast<double>(ptrOfMenuReader[itemNum][5]) / 100) * billWithOutTax;
		BillWithTax = taxs + billWithOutTax;
		cout << "Customer id : " << unique << endl << endl;
		cout << "Total amount without tax : "<< billWithOutTax << endl;
		cout << "Total tax amount : " << taxs << endl;
		cout << "Total amount with tax : " << BillWithTax << endl;

		if (ptrOfEnds[itemNum] != "abc")
		{
			cout << "Date of purchase : " << ptrOfEnds[itemNum] << endl;
		}
		
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete [] ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void shortItem(int totalItems)
{
	ifstream fin;
	fin.open("menu.txt");
	if (!fin)
	{
		cout << "Error ! File Not found" << endl << endl;
	}
	else
	{
		int ** ptrOfMenuReader = new int*[totalItems];
		string * ptrOfMenuName = new string[totalItems];
		string * ptrOfMenuDate = new string[totalItems];
		for (int k = 0; k < totalItems; k++)
		{
			ptrOfMenuReader[k] = new int[6];
		}

		for (int i = 0; i < totalItems; i++)
		{

			for (int j = 0; j < 6; j++)
			{
				if (j == 1)
				{
					fin.ignore();
					getline(fin, ptrOfMenuName[i]);
				}
				else if (j == 2)
				{
					fin.ignore();
					getline(fin, ptrOfMenuDate[i]);
				}
				else
				{
					fin >> ptrOfMenuReader[i][j];
				}
			}

		}
		fin.close();
		for (int i = 0; i < 6; i++)
		{
			if (ptrOfMenuReader[i][4] == 0)
			{

				cout << "The Item number " << ptrOfMenuReader[i][0] << " and its name is " << ptrOfMenuName[i] << " reached zero quantity in store";
				cout << endl;
			}
			cout << endl;
		}
		delete[] ptrOfMenuDate;
		ptrOfMenuDate = nullptr;
		delete[] ptrOfMenuName;
		ptrOfMenuName = nullptr;
		for (int k = 0; k < totalItems; k++)
		{
			delete[]ptrOfMenuReader[k];
		}
		delete[] ptrOfMenuReader;
		ptrOfMenuReader = nullptr;
	}
}

void cashier(int & totalCustomers, int &  cashierCreated, int & totalItem, string *& ptrEndingDate)
{
	cin.ignore();
	string userName1, passWord;
	string detail, firstName, lastName, userName, addressOfCashier, passwordOfCashier;
	int cellPhone, optionCashier;
	cout << "Enter Username : ";
	getline(cin, userName1);
	ifstream fin;
	fin.open(userName1);

	if (!fin)
	{
		cout << "Error!!! User name not match." << endl;
	}
	else
	{
		cout << "Enter Password : ";
		getline(cin, passWord);

		getline(fin, detail);
		getline(fin, firstName);
		getline(fin, lastName);
		getline(fin, userName);
		fin >> cellPhone;
		fin.ignore();
		getline(fin, addressOfCashier);
		getline(fin, passwordOfCashier);
		fin.close();
		const int a = 0;
		if (passwordOfCashier == passWord)
		{
			while (a == 0)
			{
				cout << " Do you want to :" << endl
					<< "1 => \"Sign out.\"" << endl
					<< "2 => \"Modify cashier profile.\"" << endl
					<< "3 => \"Exit (Terminate).\"" << endl
					<< "4 => \"Create Bill.\"" << endl
					<< "5 => \"Bill report.\"" << endl
					<< "6 => \"Short item.\"" << endl
					<< "Enter a digit in between 1 to 6 :";
				cin >> optionCashier;
				while (optionCashier > 6 || optionCashier < 1)
				{
					cout << "Invalid Option !" << endl;
					cout << " Do you want to :" << endl
						<< "1 => \"Sign out.\"" << endl
						<< "2 => \"Modify cashier profile.\"" << endl
						<< "3 => \"Exit (Terminate).\"" << endl
						<< "4 => \"Create Bill.\"" << endl
						<< "5 => \"Bill report.\"" << endl
						<< "6 => \"Short item.\"" << endl
						<< "Enter a digit in between 1 to 6 :";
					cin >> optionCashier;
				}
				if (optionCashier == 1)
				{
					break;
				}
				else if (optionCashier == 2)
				{
				    modifyCashierOnly(cashierCreated);
					continue;
				}
				else if (optionCashier == 3)
				{
					cout << endl;
					exit(0);
				}
				else if (optionCashier == 4)
				{
					createBill(totalItem, ptrEndingDate, totalCustomers);
					cout << endl;
					continue;
				}
				else if (optionCashier == 5)
				{
					int ** ptrOfMenuReader = new int*[totalCustomers];
					for (int k = 0; k <= totalCustomers; k++)
					{
						ptrOfMenuReader[k] = new int[3];
					}
					ifstream fin;
					fin.open("bills.txt");

					if (!fin)
					{
						cout << "File not found. " << endl << endl;
					}
					else
					{

						for (int i = 0; i <= totalCustomers; i++)
						{

							for (int j = 0; j < 3; j++)
							{
								fin >> ptrOfMenuReader[i][j];
							}

						}
					}
					fin.close();
					int unqiueid;
					cout << "Enter customer ID : ";
					cin >> unqiueid;
					while (unqiueid < 0 || unqiueid > totalCustomers)
					{
						cout << "No such id found !" << endl;
						cout << "Enter customer ID : ";
						cin >> unqiueid;
					}

					billReport(totalItem, ptrOfMenuReader[unqiueid][1], ptrOfMenuReader[unqiueid][2], unqiueid, ptrEndingDate);

					cout << endl;
					continue;
				}
				else if (optionCashier == 6)
				{
					shortItem(totalItem);
					cout << endl;
					continue;
				}
			}
		}
		else
		{
			cout << "Incorrect Password ! " << endl << endl;
		}
	}
}

void modifyCashierOnly(int created)
{
	int optionModify = 0, back1 = 1;
	while (back1 == 1)
	{
		cout << "Select an option :" << endl
			<< "1 => \"Change Password of cashier profile.\"" << endl
			<< "2 => \"Change User Name of cashier profile.\"" << endl
			<< "3 => \"Change first name of cashier profile.\"" << endl
			<< "4 => \"Change last name of cashier profile.\"" << endl
			<< "5 => \"Change Cell phone number of cashier profile.\"" << endl
			<< "6 => \"Change address of cashier profile.\"" << endl
			<< "7 => \"Back.\"" << endl;
		cin >> optionModify;
		while (optionModify > 7 || optionModify < 1)
		{
			cout << "Invalid Option!" << endl;
			cout << "Select an option :" << endl
				<< "1 => \"Change Password of cashier profile.\"" << endl
				<< "2 => \"Change User Name of cashier profile.\"" << endl
				<< "3 => \"Change first name of cashier profile.\"" << endl
				<< "4 => \"Change last name of cashier profile.\"" << endl
				<< "5 => \"Change Cell phone number of cashier profile.\"" << endl
				<< "6 => \"Change address of cashier profile.\"" << endl
				<< "7 => \"Back.\"" << endl;
			cin >> optionModify;
		}
		if (optionModify == 1)
		{
			int optionPassword;
			cout << "You want to change password of : " << endl;
			cout << "1 => Cashier." << endl;
			cout << "2 => Back." << endl;
			cin >> optionPassword;
			while (optionPassword != 1 && optionPassword != 2)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change password of : " << endl;
				cout << "1 => Cashier." << endl;
				cout << "2 => Back." << endl;
				cin >> optionPassword;
			}
			if (optionPassword == 1)
			{
				if (created != 0)
				{
					cashierPassword();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionPassword == 2)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 2)
		{
			int optionUserName;
			cout << "You want to change User Name of : " << endl;
			cout << "1 => Cashier." << endl;
			cout << "2 => Back." << endl;
			cin >> optionUserName;
			while (optionUserName != 1 && optionUserName != 2)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change User Name of : " << endl;
				cout << "1 => Cashier." << endl;
				cout << "2 => Back." << endl;
				cin >> optionUserName;
			}
			if (optionUserName == 1)
			{
				if (created != 0)
				{
					cashierUserName();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionUserName == 2)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 3)
		{
			int optionFirstName;
			cout << "You want to change First Name of : " << endl;
			cout << "1 => Cashier." << endl;
			cout << "2 => Back." << endl;
			cin >> optionFirstName;
			while (optionFirstName != 1 && optionFirstName != 2)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change First Name of : " << endl;
				cout << "1 => Cashier." << endl;
				cout << "2 => Back." << endl;
				cin >> optionFirstName;
			}
			if (optionFirstName == 1)
			{
				if (created != 0)
				{
					cashierFirstName();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionFirstName == 2)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 4)
		{
			int optionLastName;
			cout << "You want to change Last Name of : " << endl;
			cout << "1 => Cashier." << endl;
			cout << "2 => Back." << endl;
			cin >> optionLastName;
			while (optionLastName != 1 && optionLastName != 2)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change Last Name of : " << endl;
				cout << "1 => Cashier." << endl;
				cout << "2 => Back." << endl;
				cin >> optionLastName;
			}
			if (optionLastName == 1)
			{
				if (created != 0)
				{
					cashierLastName();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionLastName == 2)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 5)
		{
			int optionCellPhone;
			cout << "You want to change Cell phone number of : " << endl;
			cout << "1 => Cashier." << endl;
			cout << "2 => Back." << endl;
			cin >> optionCellPhone;
			while (optionCellPhone != 1 && optionCellPhone != 2)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change Cell phone number of : " << endl;
				cout << "1 => Cashier." << endl;
				cout << "2 => Back." << endl;
				cin >> optionCellPhone;
			}
			if (optionCellPhone == 1)
			{
				if (created != 0)
				{
					cashierCellPhone();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionCellPhone == 2)
			{

				cout << endl;
				continue;
			}
		}
		else if (optionModify == 6)
		{
			int optionAddress;
			cout << "You want to change First Name of : " << endl;
			cout << "1 => Cashier." << endl;
			cout << "2 => Back." << endl;
			cin >> optionAddress;
			while (optionAddress != 1 && optionAddress != 2)
			{
				cout << "Invalid Option." << endl;
				cout << "You want to change First Name of : " << endl;
				cout << "1 => Cashier." << endl;
				cout << "2 => Back." << endl;
				cin >> optionAddress;
			}
			if (optionAddress == 1)
			{
				if (created != 0)
				{
					cashierAddress();
				}
				else
				{
					cout << "Cashier is not registered." << endl;
				}
				cout << endl;
				continue;
			}
			else if (optionAddress == 2)
			{

				cout << endl;
				continue;
			}
			cout << endl;
			continue;
		}
		else if (optionModify == 7)
		{
			cout << endl;
			break;
		}
	}

}

