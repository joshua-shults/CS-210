#pragma once
/*
Variable with an underscore is for 
the class, without is for user
data!!!
IMPORTANT: make sure variables match 
their type or data will be wrong
*/


// InvestmentData class
class Investment {
public: // public classes, getters and setters for class Investment
	void setStartingInvestment(double _startingInvestment);
	double getStartingInvestment() {
		return startingInvestment; }
	void setMonthlyDeposit(double _monthlyDeposit);
	double getMonthlyDeposit() {
		return monthlyDeposit; }
	void setAnnualInterest(double _annualInterest);
	double getAnnualInterest() {
		return annualInterest; }
	void setNumYears(int _years);
	int getNumYears() {
		return numYears; }
	void setTotalWithDeposits(double _amount);
	void setTotalWithoutDeposits(double _amount);
	// define these class functions elsewhere, too long for readability
	double getTotalWithDeposits();
	double getTotalWithoutDeposits();
	double InterestWithDeposits();
	double InterestWithoutDeposits();


private: // private classes for Investment class
	//initialize all variables to zero to avoid program confusion through multiple reused variables
	double startingInvestment = 0.0;
	double monthlyDeposit = 0.0;
	double annualInterest = 0.0;
	int numYears = 0;
	double totalWithDeposits = 0.0;
	double totalWithoutDeposits = 0.0;

};
