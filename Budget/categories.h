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
	void clear();
	int print();
	bool isEmpty();
	Account* getCategory(std::string name);
};

#endif 