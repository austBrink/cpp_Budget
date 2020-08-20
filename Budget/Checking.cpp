#include "Checking.h"
#include <string.h>


Checking::Checking() {
	Categories* categories = new Categories();
	name = "Checking";
}

Checking::~Checking() {
	categories->clear();
	delete categories;
}

int Checking::createCategory(std::string categoryName) {
	if (categories->isEmpty()) {
		return -1;
	}
	else if (categories->getCategory(categoryName)!=NULL) {
		return -2;
	}
	Account* newCategory = new Account(categoryName);
	return 0;
}







