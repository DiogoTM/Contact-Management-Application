#include "Header.h"

/*
Contact Management Application

Author: Diogo Machado
Submitted to teacher Houria Houmel (420-P45-AS DATA STRUCTURE: C++)
Date: XX/04/2018
Version 2.0

Create a vector of contacts and implement the necessary functions to:
1- add a contact
2- display all contacts
3- remove a contact from the vector
4- search for a contact: use 2 kinds of keys (one should be int value and the other should be string value)
5- sort contacts: use 2 kinds of keys (one should be int value and the other should be string value)


*/


int main()

{
	int sel_menu;
	int max;
	int search_int;
	string search_name;
	bool exit = false;

	vector<Contact> contact_vect;
	Contact a_contact;

	cout << "\tWelcome to the Contact Management Application";
	cout << "\n\t=============================================";
	cout << "\n\tPlease make your choice:" << endl;
	do
	{
		cout << "\nMain Menu:" << endl;
		cout << "\n1. Create a contact.";
		cout << "\n2. Display all the contacts.";
		cout << "\n3. Search for a contact.";
		cout << "\n4. Sort the contacts.";
		cout << "\n5. Exit the application." << endl;
		cin >> sel_menu;

		switch (sel_menu)
		{			
		case 1:			
			loadContact(contact_vect);
			break;
		case 2:
			displayContacts(contact_vect);		
			break;
		case 3:
			int sel_search;
			cout << "\nPlease, select the type of search to be performed: " << endl;
			cout << "\n1. Search by Contact Number.";
			cout << "\n2. Search by First Name and Last Name.";
			cin >> sel_search;

			switch (sel_search)
			{			
			case 1:				
				cout << "Please insert the contact information to search: " << endl;
				cin >> search_int;
				searchContact(search_int, contact_vect);
				break;
			case 2:
				cout << "Please insert the contact information to search: " << endl;
				cin >> search_name;				
				searchContact(search_name, contact_vect);
				break;
			default:
				cout << "\nPlease make your choice.";
				break;
				system("pause");
				system("cls");
			}		

			break;
		case 4:
			int sel_sort;
			cout << "\nPlease, select the type of sort to be performed: " << endl;
			cout << "\n1. Sort by Contact Number.";
			cout << "\n2. Sort by Company Name." << endl;
			cin >> sel_sort;
			switch (sel_sort)
			{
			case 1:
				sort(contact_vect.begin(), contact_vect.end(), sortByNumber);
				break;
			case 2:
				sort(contact_vect.begin(), contact_vect.end(), sortByName);
				break;
			default:
				cout << "\nPlease make your choice.";
				break;
			}			
			break;
		case 5:
			exit = exit_app();
			if (exit == true)
			{
				return 0;
			}
		}		
		system("pause");
		system("cls");
	} while (!exit);
}