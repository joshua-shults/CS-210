#include <iostream>
using namespace std;

#include "Invest.h" // include Invest header
/*
This section includes function definitions
For the Investment Class
*/

//make sure variables are correct, underscore for interacting with class, no underscore for user data!!!
void Investment::setStartingInvestment(double _startingInvestment) { //setter for _startingInvestment
	this->startingInvestment = _startingInvestment;
}
void Investment::setMonthlyDeposit(double _monthlyDeposit) { //setter for _monthlyDeposits
	this->monthlyDeposit = _monthlyDeposit;
}
void Investment::setAnnualInterest(double _annualInterest) { //setter for _annualInterest
	this->annualInterest = _annualInterest;
}
void Investment::setNumYears(int _numYears) { //setter for _numYears
	this->numYears = _numYears;
}
double Investment::InterestWithoutDeposits() { // calculates interest without deposits
	return ((this->totalWithoutDeposits) * ((this->annualInterest / 100) / 12));
}
double Investment::InterestWithDeposits() { // calculates interest with deposits
	return ((this->totalWithDeposits) * ((this->annualInterest / 100) / 12));
}
void Investment::setTotalWithoutDeposits(double t_amount) { //set total without deposits
	this->totalWithoutDeposits += t_amount;
}
double Investment::getTotalWithoutDeposits() { //get total without deposits
	return this->totalWithoutDeposits;
}
void Investment::setTotalWithDeposits(double t_amount) { //set total with deposits
	this->totalWithDeposits += t_amount;
}
double Investment::getTotalWithDeposits() { //get total with deposits
	return this->totalWithDeposits;
}

