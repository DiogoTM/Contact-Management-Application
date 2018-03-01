#include "Header.h"

//Template to search 

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
	cout << "\t=============================================" << endl;
	Contact * array_contacts = new	Contact[max];
	Contact *pf, *pl;
	pf = &array_contacts[0];
	pl = &array_contacts[max - 1];
	system("pause");
	system("cls");

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
			cout << "\n2. Search by First Name and Last Name.";
			cin >> sel_search;

			switch (sel_search)
			{			
			case 1:				
				cout << "Please insert the contact information to search: " << endl;
				cin >> search_int;
				searchContact(pf, pl, search_int);
				break;
			case 2:
				cout << "Please insert the contact information to search: " << endl;
				cin >> search_name;				
				searchContact(pf, pl, search_name);
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
				sortContactsContNum(pf,pl);
				break;
			case 2:
				sortContactsCompany(pf,pl);
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