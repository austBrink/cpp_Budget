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

int Checking::removeCategory(std::string categoryName) {
	if (categories->isEmpty()) {
		return -1;
	}
	else if (categories->getCategory(categoryName)==NULL) {
		return -2;
	}
	categories->remove("categoryName");
	return 0;
}

Account* Checking::getCategory(std::string categoryName) {
	return categories -> getCategory(categoryName);
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


std::string Checking::getName() {
	return name;
}








