#include "Header.h"

static void loadContact(Contact array_contacts[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		array_contacts[i].contNum = i + 1;
		cout << "Please insert the contact information:";
		cout << "/nFirst Name: ";
		cin.ignore;
		getline(cin, array_contacts[i].fname);
		cout << "/nLast Name: ";
		cin.ignore;
		getline(cin, array_contacts[i].lname);
		cout << "/nCompany Name: ";
		cin.ignore;
		getline(cin, array_contacts[i].company);
		cout << "/nPhone Number: ";
		cin >> array_contacts[i].phNum;
		cout << "/nFax Number: ";
		cin >> array_contacts[i].faxNum;
		cout << "/nMeeting Date: " << "/nDay: ";
		cin >> array_contacts[i].meetDate.day;
		cout << "/nMonth: ";
		cin >> array_contacts[i].meetDate.month;
		cout << "/nYear: ";
		cin >> array_contacts[i].meetDate.year;
	}
}

static void loadContact(Contact * ptr_first, Contact * ptr_last)
{
	for (Contact *ptr = ptr_first; ptr <= ptr_last; ptr++)
	{
		ptr->contNum = (ptr - ptr_first) + 1;
		cout << "Please insert the contact information:";
		cout << "/nFirst Name: ";
		cin.ignore;
		getline(cin, ptr->fname);
		cout << "/nLast Name: ";
		cin.ignore;
		getline(cin, ptr->lname);
		cout << "/nCompany Name: ";
		cin.ignore;
		getline(cin, ptr->company);
		cout << "/nPhone Number: ";
		cin >> ptr->phNum;
		cout << "/nFax Number: ";
		cin >> ptr->faxNum;
		cout << "/nMeeting Date: " << "/nDay: ";
		cin >> ptr->meetDate.day;
		cout << "/nMonth: ";
		cin >> ptr->meetDate.month;
		cout << "/nYear: ";
		cin >> ptr->meetDate.year;
	}
}

static void displayContact(Contact array_contacts[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "/nContact information: ";
		cout << "/nFirst Name: " << array_contacts[i].fname;
		cout << "/nLast Name: " << array_contacts[i].lname;
		cout << "/nCompany Name: " << array_contacts[i].company;
		cout << "/nPhone Number: " << array_contacts[i].phNum;
		cout << "/nFax Number: " << array_contacts[i].faxNum;
		cout << "/nMeeting Date: " << array_contacts[i].meetDate.day << "/" <<
			array_contacts[i].meetDate.month << "/" << array_contacts[i].meetDate.year;
	}
}

static void displayContact(Contact array_contacts[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "/nContact information: ";
		cout << "/nFirst Name: " << array_contacts[i].fname;
		cout << "/nLast Name: " << array_contacts[i].lname;
		cout << "/nCompany Name: " << array_contacts[i].company;
		cout << "/nPhone Number: " << array_contacts[i].phNum;
		cout << "/nFax Number: " << array_contacts[i].faxNum;
		cout << "/nMeeting Date: " << array_contacts[i].meetDate.day << "/" <<
			array_contacts[i].meetDate.month << "/" << array_contacts[i].meetDate.year;
	}
}

static void displaySingleContact(Contact array_contacts[], int i)
{
	cout << "/nContact information: ";
	cout << "/nFirst Name: " << array_contacts[i].fname;
	cout << "/nLast Name: " << array_contacts[i].lname;
	cout << "/nCompany Name: " << array_contacts[i].company;
	cout << "/nPhone Number: " << array_contacts[i].phNum;
	cout << "/nFax Number: " << array_contacts[i].faxNum;
	cout << "/nMeeting Date: " << array_contacts[i].meetDate.day << "/" <<
		array_contacts[i].meetDate.month << "/" << array_contacts[i].meetDate.year;
}

static void searchContact(Contact array_contacts[], const int size, int searchNum)
{
	for (int i = 0; i < size; i++)
	{
		if (array_contacts[i].contNum == searchNum)
		{
			cout << "Contact found: ";
			displaySingleContact(array_contacts, i);
		}
	}
}
static void searchContact(Contact array_contacts[], const int size, int searchNum)
{
	bool found;
	for (int i = 0; i < size; i++)
	{
		if (array_contacts[i].contNum == searchNum)
		{
			cout << "Contact found: ";
			found = true;
			displaySingleContact(array_contacts, i);
		}
	}
	if (!found)
	{
		cout << "Contact not found!";
	}
}

static void searchContact(Contact array_contacts[], const int size, string searchName)
{
	bool found;
	for (int i = 0; i < size; i++)
	{
		if ((array_contacts[i].fname == searchName) || ((array_contacts[i].lname == searchName)))
		{
			cout << "Contact found: ";
			found = true;
			displaySingleContact(array_contacts, i);
		}
	}
	if (!found)
	{
		cout << "Contact not found!";
	}