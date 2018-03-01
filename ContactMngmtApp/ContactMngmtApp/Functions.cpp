
#include "Header.h"


//Overloading operator << to display the object of type Contact

ostream & operator <<(ostream & out_stream, Contact &a_contact)
{
	out_stream << "\n=================================";
	out_stream << "\nContact information: ";
	out_stream << "\n=================================";

	out_stream << "\nContact Number: " << a_contact.contNum;
	out_stream << "\nFirst Name: " << a_contact.fname;
	out_stream << "\nLast Name: " << a_contact.lname;
	out_stream << "\nCompany Name: " << a_contact.company;
	out_stream << "\nPhone Number: " << a_contact.phNum;
	out_stream << "\nFax Number: " << a_contact.faxNum;
	out_stream << "\nMeeting Date: " << a_contact.meetDate.day << "/" <<
		a_contact.meetDate.month << "/" << a_contact.meetDate.year << endl;
	return out_stream;
}
//Overloading operator >> to input data to the object of type Contact
istream & operator >> (istream & in_stream, Contact &a_contact)
{
	cout << "\nPlease insert the contact information:";
	cout << "\nFirst Name: ";
	in_stream.ignore();
	getline(in_stream, a_contact.fname);
	cout << "\nLast Name: ";
	//in_stream.ignore();
	getline(in_stream, a_contact.lname);
	cout << "\nCompany Name: ";
	//in_stream.ignore();
	getline(in_stream, a_contact.company);
	cout << "\nPhone Number: ";
	in_stream >> a_contact.phNum;
	cout << "\nFax Number: ";
	in_stream >> a_contact.faxNum;
	cout << "\nMeeting Date: " << "\nDay: ";
	in_stream >> a_contact.meetDate.day;
	cout << "\nMonth: ";
	in_stream >> a_contact.meetDate.month;
	cout << "\nYear: ";
	in_stream >> a_contact.meetDate.year;
	return in_stream;
}

//Functions
//Function do load/add contacts
void loadContact(Contact * pf, Contact * pl)
{
	for (Contact *ptr = pf; ptr <= pl; ptr++)
	{
		ptr->contNum = ptr-pf+1;
		cin >> *ptr;
	}

}

//Function to display all contacts
void displayContacts(Contact * pf, Contact * pl)
{
	for (Contact *ptr = pf; ptr <= pl; ptr++)
	{
		cout<< *ptr;
	}
}

//Function to search contacts by int (Contact number)
void searchContact(Contact * pf, Contact * pl, int search)
{
	bool found = false;
	for (Contact *ptr = pf; ptr <= pl; ptr++)
	{
		if (ptr->contNum == search)
		{
			cout << "Contact found: ";
			found = true;
			cout << *ptr;
			break;
		}
		found = false;
	}
	if (!found)
	{
		cout << "Contact not found!";
	}
}
//Overloaded function to search contact by string (first name and last name)
void searchContact(Contact * pf, Contact * pl, string search)
{
	bool found = false;
	for (Contact *ptr = pf; ptr <= pl; ptr++)
	{
		if (ptr->fname == search || ptr->lname == search || (ptr->fname + " " + ptr->lname) == search)
		{
			cout << "Contact found: ";
			found = true;
			cout << *ptr;
			break;
		}
		found = false;
	}
	if (!found)
	{
		cout << "Contact not found!";
	}
}

//Function to sort contacts by contact number.
void sortContactsContNum(Contact *pf, Contact *pl)
{
	for (Contact *i = pf; i <= pl; i++)
	{
		for (Contact *j = i+1; j <= pl; j++)
		{
			if (i->contNum > j->contNum)
			{
				Contact temp = *i;
				*i = *j;
				*j = temp;
			}
		}	
	}
	cout << "Contacts sorted succesfully!" << endl;
}

//Function to sort contacts by company name
void sortContactsCompany(Contact *pf, Contact *pl)
{
	for (Contact *i = pf; i <= pl; i++)
	{
		for (Contact *j = i + 1; j <= pl; j++)
		{
			if (i->company > j->company)
			{
				Contact temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
	cout << "Contacts sorted succesfully!" << endl;

}

bool exit_app()
{
	char exit;
	cout << "\n\nAre you sure you want to EXIT the program (Y/N)? ";
	cin >> exit;
	if (toupper(exit) == 'Y')
	{
		return true;
	}
	else if (toupper(exit) == 'N')
	{
		return false;
	}
	else
	{
		cout << "\n\nPlease enter a valid choice.";
		return exit_app();
	}
}