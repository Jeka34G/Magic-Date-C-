// magicDate.cpp 
// Implementation of the magic date assignment

#include <iostream>
#include <iomanip> // setprecision	
#include <string> 
using namespace std;


// CONSTANT global enums
enum promptWord { DAY, MONTH, YEAR };
enum months {
	DUM, JANUARY, FEBRUARY, MARCH, APRIL,
	MAY, JUNE, JULY, AUGUST, SEPTEMBER,
	OCTOBER, NOVEMBER, DECEMBER
}; // DUM is a "dummy" value for clarity since the JANUARY is 1, not 0

// CONSTANT global variables
const int daysInFullMonths = 31;
const int daysInShortMonths = 30;
const int maxDaysInFebruary = 29;

// Function Prototypes
void programGreeting();
void displayPrompt(int);
void displayPrompt(int, int);
int getVal(int);
bool validateDay(int, int);
string determineMonth(int);
void visualizeDate(int, int, int); // also includes magic date calculation
void autoTitle(string); // the auto-title maker 

int main() {
	programGreeting();

	autoTitle("Magic Dates");

	int usersMonth, usersDay, usersYear;

	usersMonth = getVal(MONTH);
	displayPrompt(DAY, usersMonth);
	usersDay = getVal(DAY);
	displayPrompt(YEAR);
	usersYear = getVal(YEAR);

	visualizeDate(usersMonth, usersDay, usersYear); 

	return 0;
}

void programGreeting() {
	cout << "Welcome to my third extra credit assignment!\n";
	cout << "The program is launching...\n";
	cout << endl; // newline
}
void displayPrompt(int choice) {
	switch (choice) {
	case DAY: cout << "Enter the day of the month: ";
		break;
	case MONTH: cout << "Enter the month 1-12: ";
		break;
	case YEAR: cout << "Enter the year: ";
		break;
	}
}
void displayPrompt(int choice, int month) {
	switch (month) {
	case JANUARY:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case MARCH:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case MAY:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case JULY:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case AUGUST:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case OCTOBER:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case DECEMBER:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case APRIL:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case JUNE:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case SEPTEMBER:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case NOVEMBER:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	case FEBRUARY:
		cout << "Your month is " << determineMonth(month) << endl;
		break;
	}
	switch (month) {
	case JANUARY:
	case MARCH:
	case MAY:
	case JULY:
	case AUGUST:
	case OCTOBER:
	case DECEMBER: cout << "Enter 1-" << daysInFullMonths << ": ";
		break;
	case APRIL:
	case JUNE:
	case SEPTEMBER:
	case NOVEMBER:
		cout << "Enter 1-" << daysInShortMonths << ": ";
		break;
	case FEBRUARY:
		cout << "Enter 1-" << maxDaysInFebruary << ": ";
		break;
	}
}
int getVal(int choice) {
	static int usersMonth;
	static int usersDay; 
	int usersYear;

	switch (choice) {
	case MONTH:
		displayPrompt(MONTH);
		cin >> usersMonth; 
		cout << endl;
		while (!(usersMonth >= 1 && usersMonth <= 12)) {
			cout << "Invalid input: " << usersMonth << endl;
			displayPrompt(MONTH);
			cin >> usersMonth;
			cout << endl;
		}
		return usersMonth;
		break; 

	case DAY:
		cin >> usersDay;
		while (validateDay(usersDay, usersMonth) == false) {
			cout << endl;
			cout << "Invalid input: " << usersDay << endl;
			displayPrompt(DAY, usersMonth);
			cin >> usersDay;
		}
		return usersDay;
		break; 
	case YEAR:
		cin >> usersYear;
		{
			if (usersMonth == FEBRUARY && usersDay == 29)
			{
				while ((usersYear % 4 && usersYear % 100 != 0) || (usersYear % 400 == 0))
				{
					cout << endl;
					cout << "You entered day " << usersDay << " of the " << determineMonth(usersMonth) << endl;
					cout << "Please enter a valid leap year: ";
					cin >> usersYear;
				}
			}
		}
		return usersYear;

	}
	return -1; // Error return value
}
bool validateDay(int usersDay, int usersMonth) {
	switch (usersMonth) {
	case JANUARY:
	case MARCH:
	case MAY:
	case JULY:
	case AUGUST:
	case OCTOBER:
	case DECEMBER:
		if (usersDay > 0 && usersDay <= daysInFullMonths)
			return true;
		else
			return false;
		break;
	case FEBRUARY:
		if (usersDay > 0 && usersDay <= maxDaysInFebruary)
			return true;
		else
			return false;
		break;
	case APRIL:
	case JUNE:
	case SEPTEMBER:
	case NOVEMBER:
		if (usersDay > 0 && usersDay <= daysInShortMonths)
			return true;
		else
			return false;
		break;
	}
	return false;
}

string determineMonth(int month) {
	switch (month) {
	case JANUARY: return "January";
	case FEBRUARY: return "February";
	case MARCH: return "March";
	case APRIL: return "April";
	case MAY: return "May";
	case JUNE: return "June";
	case JULY: return "July";
	case AUGUST: return "August";
	case SEPTEMBER: return "September";
	case OCTOBER: return "October";
	case NOVEMBER: return "November";
	case DECEMBER: return "December";
	default: return "Invalid Month";
	}
}

void visualizeDate(int usersMonth, int usersDay, int  usersYear)
{
	cout << endl;
	cout << usersMonth << "/" << usersDay << "/" << usersYear % 100 << endl;
	if (usersDay * usersMonth == usersYear % 100)
		cout << "MAGIC DATE!" << endl;
	else
		cout << "Not a magic date(" << endl;

}
void autoTitle(string title) {
	int titleLength = title.length();
	string underscores = string(titleLength, '=');

	cout << title << endl;
	cout << underscores << endl;
}
