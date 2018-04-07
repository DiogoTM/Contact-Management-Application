
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

//Function to add Contacts
void loadContact(vector <Contact>&contact_vector)
{
	Contact a_contact;
	bool continue_insert = true;
	while (continue_insert)
	{
		cin >> a_contact;
		a_contact.contNum = contact_vector.size() + 1;
		contact_vector.push_back(a_contact);
		char option;
		cout << "\nDo you want to continue inserting contacts? (Y or N)" << endl;
		cin >> option;

		if (toupper(option) == 'Y')
		{
			continue_insert = true;
		}
		else if (toupper(option) == 'N')
		{
			continue_insert = false;
		}
		else
		{
			cout << "\nPlease enter a valid option, Y or N." << endl;
			cin >> option;
		}
	}

}

//Function to delete a contact
void deleteContact(vector <Contact>& contact_vector)
{
	int contact_num;
	cout << "\nPlease enter the contact number to be deleted: " << endl;
	cin >> contact_num;
	vector<Contact>::iterator it;
	it = find_if(contact_vector.begin(), contact_vector.end(), IsEqual(contact_num));
	if ( it != contact_vector.end())
	{
		contact_vector.erase(it);
		cout << "\nContact removed succesfully!" << endl;		
	}
	else
	{
		cout << "\nContact not found!" << endl;
	}

}

//Function to display all contacts
void displayContacts(vector <Contact> contact_vector)
{
	for (int i = 0; i < contact_vector.size(); i++)
	{
		cout << contact_vector.at(i) << endl;
	}
}

//Function to search contacts by int (Contact number)
void searchContact(int search, vector <Contact> contact_vector)
{
	bool found = false;
	contact_vector;
	for (int i = 0; i < contact_vector.size(); i++)
	{
		if (contact_vector[i].contNum == search)
		{
			cout << "Contact found: ";
			found = true;
			cout<< contact_vector[i];
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
void searchContact(string search, vector <Contact> contact_vector)
{
	bool found = false;
	for (int i = 0; i < contact_vector.size(); i++)
	{
		if (contact_vector[i].fname == search || contact_vector[i].lname == search)
		{
			cout << "Contact found: ";
			found = true;
			cout << contact_vector[i];
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

bool sortByNumber(const Contact & cont1, const Contact & cont2)
{
	return cont1.contNum < cont2.contNum;
}
bool sortByName(const Contact & cont1, const Contact & cont2)
{
	return cont1.fname < cont2.fname;
}
//Function to sort contacts by company name

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