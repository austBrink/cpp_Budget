#ifndef CHECKING 
#define CHECKING 
#include <string>
#include "categories.h"
#include "Account.h"
class Checking {

private:
	Categories* categories;
	double balance;
	std::string name; 

public:
	Checking();
	~Checking();
	int createCategory(std::string categoryName);
	int removeCategory(std::string categoryName);
	Account* getCategory(std::string categoryName);
	int deposit(double sum, std::string categoryName);
	int withdraw(double sum, std::string categoryName);
	double getBalance();
	double getName();
	
};


#endif 