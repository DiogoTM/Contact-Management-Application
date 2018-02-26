#include <iostream>
#include <string>
using namespace std;


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


static void loadContact(Contact[], const int);
static void loadContact(Contact *, Contact *);

static void displayContact(Contact[], const int);
static void displayContact(Contact *, Contact*);

static void displaySingleContact(Contact[], int);



static void searchContact(Contact[], const int, int);
static void searchContact(Contact *, int);

static void searchContact(Contact[], const int, string);
static void searchContact(Contact[], string);


