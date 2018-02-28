#include <iostream>
#include <string>
using namespace std;

//Necessary Structures
struct Address
{
	int strNum;
	string strName, city, province, pCode, country;
};

struct Date
{
	int day, month, year;
};

struct Contact
{
	int contNum;
	string fname, lname, company;
	long int phNum, faxNum;
	Date meetDate;
};

//Function prototypes

void loadContact(Contact *, Contact *);
void displayContacts(Contact *, Contact*);
void searchContact(Contact *, Contact*, int);
bool exit_app();




