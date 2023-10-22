#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "userInp.h"

void UserData::dataWithoutDeposits(Investment a_userInvestment) {
	//assign user inputs to variables
	double initialInvestment = a_userInvestment.getStartingInvestment();
	int years = a_userInvestment.getNumYears();

	// variables for 'display' screen
	int screenWidth = 80;
	string balanceMsg = "Balance and Interest Without Additional Monthly Deposits";
	int centerScreen = balanceMsg.length() / 2;
	int halfWidth = screenWidth / 2;
	int sizeToCenter = halfWidth + centerScreen;

	cout << endl;

	//header
	cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
	cout << setfill('=') << setw(80) << '=' << endl;
	cout << setfill(' ') << left << setw(26) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;

	//add initial amount to the total

	a_userInvestment.setTotalWithoutDeposits(initialInvestment);
	double interestYTD = 0;

	unsigned int yearCount, monthCount;

	// loop to get interest for each year user provided
	for (yearCount = 1; yearCount <= years; yearCount++) {
		for (monthCount = 1; monthCount <= 12; monthCount++) {
			interestYTD += a_userInvestment.InterestWithoutDeposits();
		}
		a_userInvestment.setTotalWithoutDeposits(interestYTD);	// adds total interest from the year to main total
		cout << setfill(' ') << left << setw(30) << yearCount;
		cout << "$" << fixed << setprecision(2) << interestYTD;
		cout << right << setw(35) << "$" << fixed << setprecision(2) << a_userInvestment.getTotalWithoutDeposits() << endl;

		interestYTD = 0; // reset if user wants to enter another data set
	}
}

void UserData::dataWithDeposits(Investment a_userInvestment) {
	/*
	Second display but
	with deposits
	*/

	// initializing local vars with the user data
	double initialInvestment = a_userInvestment.getStartingInvestment();
	double monthlyDeposit = a_userInvestment.getMonthlyDeposit();
	int years = a_userInvestment.getNumYears();

	string balanceMsg = "Balance and Interest With Additional Monthly Deposits";
	int screenWidth = 80;

	
	int centerScreen = balanceMsg.length() / 2;
	int half = screenWidth / 2;
	int Center = half + centerScreen;

	cout << endl;
	
	/*
	Display format for data
	From user Input
	*/
	
	cout << setfill(' ') << setw(Center) << balanceMsg << setfill(' ') << setw(Center) << endl;
	cout << setfill('=') << setw(80) << '=' << endl;
	cout << setfill(' ') << left << setw(26) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;

	//put initial amount to total
	a_userInvestment.setTotalWithDeposits(initialInvestment);

	// reset YTD if user decides to enter another data set
	double interestYTD = 0;

	unsigned int yearCount, monthCount;

	//same as above but adding monthly deposits to total
	for (yearCount = 1; yearCount <= years; yearCount++) { // uses users amount of years invested as the amount of times to loop for data
		for (monthCount = 1; monthCount <= 12; monthCount++) { // increases month count to display data for each month
			a_userInvestment.setTotalWithDeposits(monthlyDeposit); //sets the monthly deposits
			double interest = a_userInvestment.InterestWithDeposits();//get interest rate
			a_userInvestment.setTotalWithDeposits(interest); //add interest to total
			interestYTD += interest; // assigns YTD to display
		}
		
		cout << setfill(' ') << left << setw(30) << yearCount;
		cout << "$" << fixed << setw(39) << setprecision(2) << interestYTD;
		cout << left << "$" << fixed << setprecision(2) << a_userInvestment.getTotalWithDeposits() << endl;

		interestYTD = 0; // reset YTD if user wants to enter a new data set
	}
}