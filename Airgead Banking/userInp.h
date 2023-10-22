#pragma once
#include "Invest.h"
//create class for user's inputs
class UserData {

public:
	//functions defined elsewhere for easier readability
	void dataWithoutDeposits(Investment _userInvestment); //both of these functions will inherit from Investment superclass
	void dataWithDeposits(Investment _userInvestment);


	UserData() = default; // default constructor
};