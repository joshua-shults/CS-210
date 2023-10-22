
/*
Project 2 CS-210
Joshua Shults
9/28/2023
*/


#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;
//include both header files
#include "Invest.h"
#include "userInp.h"

//create main program function that retrieves user data and calls functinos for investment data
void mainProgram() {

	//create objects of Investment and UserData

	Investment userInvestment;
	UserData dataCalculations;

	//declare user variables for starting amount, deposit, and interest rate

	double startingAmount;
	double monthlyDeposit;
	double interest;
	int numYears;

	string option;//variable to continue data retrievement or end program
	bool program = true;//boolean to end loop if error reached

	do { // while program = true;
		/*
		First make initial screen to display to user
		To inform them what data is being asked for
		*/

		/*
		screen width and layout according to Airgead banking
		*/

		cout << setfill('*') << setw(34) << ' ' << endl;
		cout << "********** Data Input ***********" << endl;
		cout << setfill('-') << setw(34) << '-' << endl;

		cout << "Initial Investment Amount: ";
		cin >> startingAmount;
		cout << endl;

		cout << "Monthly Deposit: ";
		cin >> monthlyDeposit;
		cout << endl;

		cout << "Annual Interest: ";
		cin >> interest;
		cout << endl;

		cout << "Number of years: ";
		cin >> numYears;
		cout << endl;


		// use objects with relevant functions to set the data to be used in calculations

		userInvestment.setStartingInvestment(startingAmount);
		userInvestment.setMonthlyDeposit(monthlyDeposit);
		userInvestment.setAnnualInterest(interest);
		userInvestment.setNumYears(numYears);

	/* USE THIS TO VERIFY CORRECT INPUTS USED IN PROPER VARIABLES, COMMENT OUT WHEN PROGRAM IS RUNNING
		cout << setfill('*') << setw(34) << ' ' << endl;
		cout << "********** Data Input ***********" << endl;
		cout << setfill('-') << setw(34) << '-' << endl;
		cout << "Initial Investment Amount: " << setfill(' ') << right << setw(10) << "$" << userInvestment.getStartingInvestment() << endl;
		cout << "Monthly Deposit: " << setfill(' ') << right << setw(20) << "$" << userInvestment.getMonthlyDeposit() << endl;
		cout << "Annual Interest: " << setfill(' ') << right << setw(20) << " " << userInvestment.getAnnualInterest() << "%" << endl;
		cout << "Number of years: " << setfill(' ') << right << setw(20) << " " << userInvestment.getNumYears() << endl;
		
	*/
		cout << endl;
		// waiting for use input
		


		//use try statements to use catch for std::exceptions
		try {
			dataCalculations.dataWithoutDeposits(userInvestment);
		}
		catch (const std::exception& exc) { // catches exceptions
			cout << "error in data without deposits" << endl;
			program = false;
		}
		//try to get data
		try
		{
			dataCalculations.dataWithDeposits(userInvestment);
		}
		catch (const std::exception& exc)
		{
			cout << "error in data with deposits" << endl;
			program = false;
		}

		cout << endl;

		//prompt user to enter another data set
		cout << "Enter another data set? 'y' to continue, 'n' to end" << endl;
		cin >> option;
		if (option == "n" || "N") {
			program = false;
		}
		else {
			continue; // start from top if user entered anything other than 'n' or 'N'
		}



	} while (program == true); // while for do statement, do this while program == true

}

int main() {

	try {
		mainProgram();
	}
	catch (const std::exception& exc) {
		cout << exc.what() << endl;
		cout << "error in beginning" << endl;
	}
}
