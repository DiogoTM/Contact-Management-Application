#include "Header.h"


//Overloading operators to display the object of type Contact

ostream & operator <<(ostream & out_stream, Contact &a_contact)
{
	out_stream << "\n=================================";
	out_stream << "\nContact information: ";
	out_stream << "\n=================================";

	out_stream << "\nFirst Name: " << a_contact.fname;
	out_stream << "\nLast Name: " << a_contact.lname;
	out_stream << "\nCompany Name: " << a_contact.company;
	out_stream << "\nPhone Number: " << a_contact.phNum;
	out_stream << "\nFax Number: " << a_contact.faxNum;
	out_stream << "\nMeeting Date: " << a_contact.meetDate.day << "/" <<
		a_contact.meetDate.month << "/" << a_contact.meetDate.year << endl;
	return out_stream;
}

istream & operator >> (istream & in_stream, Contact &a_contact)
{
	cout << "\nPlease insert the contact information:";
	cout << "\nFirst Name: ";
	in_stream.ignore();
	getline(in_stream, a_contact.fname);
	cout << "\nLast Name: ";
	in_stream.ignore();
	getline(in_stream, a_contact.lname);
	cout << "\nCompany Name: ";
	in_stream.ignore();
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
void loadContact(Contact * pf, Contact * pl)
{
	for (Contact *ptr = pf; ptr <= pl; ptr++)
	{
		ptr->contNum = pl - pf + 1;
		cin >> *ptr;
	}

}

void displayContacts(Contact * pf, Contact * pl)
{
	for (Contact *ptr = pf; ptr <= pl; ptr++)
	{
		cout<< *ptr;
	}
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