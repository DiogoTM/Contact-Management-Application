#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	

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

void loadContact(vector <Contact>&);
void displayContacts(vector <Contact>);
void searchContact(string, vector <Contact>);
void searchContact(int, vector <Contact>);
bool sortByNumber(const Contact &, const Contact &);
bool sortByName(const Contact &, const Contact &);
bool exit_app();
ostream & operator <<(ostream &, Contact &);
istream & operator >> (istream &, Contact &);





