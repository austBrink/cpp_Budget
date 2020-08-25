#include "Checking.h"
#include <string.h>


Checking::Checking() {
	categories = new Categories();
	name = "Checking";
}

Checking::~Checking() {
	categories->clear();
	delete categories;
}

int Checking::createCategory(std::string categoryName) {
	if (categories->getCategory(categoryName)!=NULL) {
		return -1;
	}
	Account* newCategory = new Account(categoryName);
	categories->add(newCategory);
	return 0;
}

Account* Checking::getCategory(std::string categoryName) {
	return categories -> getCategory(categoryName);
}

bool Checking::isEmpty() {
	return categories->isEmpty();
}

int Checking::deposit(double sum, std::string categoryName) {
	if (categories->isEmpty()) {
		return -1;
	}
	Account* depositTo;
	depositTo = categories->getCategory(categoryName);
	if (depositTo == NULL) {
		return -2;
	}
	depositTo->deposit(sum);
	balance = balance + sum;
	return 0;
}

//this is much better than the origonal logic in the python program.... just saying.

int Checking::withdraw(double sum, std::string categoryName) {
	if (categories->isEmpty()) {
		return -1;
	}

	Account* withdrawFrom;
	withdrawFrom = categories->getCategory(categoryName);

	// if no such category exists 
	if (withdrawFrom == NULL) {
		return -2;
	}
	// if we are overdrafting Chekcing as a whole 
	else if (balance < sum) {
		return -3;
	}
	// if we are category overdrafting 
	else if (withdrawFrom->getBalance() < sum) {
		return -4;
	}

	withdrawFrom->withdraw(sum);
	balance = balance - sum;
	return 0;
}

int Checking::removeCategory(std::string categoryName) {
	if(categories->isEmpty()){
		return -1;
	}
	Account* removeThis;
	removeThis = categories->getCategory(categoryName);
	//if the category is not a thing.  
	if (removeThis == NULL) {
		return -2;
	}
	else if (removeThis->getBalance() != 0) {
		return -3;
	}
	removeThis = categories->remove(categoryName);
	delete removeThis;
}

void Checking::show() {
	categories->print();
}


std::string Checking::getName() {
	return name;
}

double Checking::getBalance() {
	return balance;
}








