#include "Header.h"

//Template to search 
template<class T>
T sortContact(Contact * pf, Contact * pl, T search)
{
	bool found;
	for (Contact *ptr = pf; ptr <= pl; ptr++)
	{
		if (*ptr->contNum == search)
		{
			cout << "Contact found: ";
			found = true;
		}
	}
	if (!found)
	{
		cout << "Contact not found!";
	}
}


int main()

{
	int sel_menu;
	int max;
	int search_int;
	string search_name;
	bool exit = false;
	cout << "\tWelcome to the Contact Management Application";
	cout << "\n\t=============================================";
	cout << "\nBefore we start, how many contacts do you need?" << endl ;
	cin >> max;
	cout << "\t=============================================";
	Contact * array_contacts = new	Contact[max];
	Contact *pf, *pl;
	pf = &array_contacts[0];
	pl = &array_contacts[max - 1];

	cout << "\n\tThank you, now please make your choice:" << endl;

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
			loadContact(pf, pl);
			break;
		case 2:
			displayContacts(pf, pl);
			break;
		case 3:
			int sel_search;
			cout << "\nPlease, select the type of search to be performed: " << endl;
			cout << "\n1. Search by Contact Number.";
			cout << "\n2. Search by First Name.";
			cout << "\n3. Search by Last Name." << endl;
			cin >> sel_search;
			switch (sel_search)
			{
			case 1:				
				cout << "Please insert the contact information to search: " << endl;
				cin >> search_int;
				break;
			case 2:
				cout << "Please insert the contact information to search: " << endl;
				cin >> search_name;				
				break;
			case 3:
				cout << "Please insert the contact information to search: " << endl;
				cin >> search_name;				
				break;
			default:
				cout << "\nPlease make your choice.";
				break;
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
				break;
			case 2:
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
	} while (!exit);
}