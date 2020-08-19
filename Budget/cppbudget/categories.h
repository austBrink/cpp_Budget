#ifndef CATEGORIES 
#define CATEGORIES 
#include"Account.h"
class Categories {

private:
	Account* root;
public:
	Categories();
	~Categories();
	void add(Account* a);
	Account *remove(std::string name);
	int print();
};

#endif