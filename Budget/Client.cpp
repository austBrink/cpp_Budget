#include<iostream>
#include"Account.h"
#include"Categories.h"


void savingsTest();
void categoriesTest();
void clearTest();
void ptrTest();
void test_getCategory();

// this is a test 

int main(void) {
	//savingsTest();
	//categoriesTest();
	//clearTest();
	//ptrTest();
	test_getCategory();
	return 0;
}

void savingsTest() {

	//test the account object... 

	Account* Savings = new Account("Savings");

	double savBal = Savings->getBalance();
	std::cout << savBal << std::endl;
	std::string name = Savings->getName();
	std::cout << name << std::endl;

	//DEPOSIT 
	Savings->deposit(96.5);
	savBal = Savings->getBalance();
	std::cout << savBal << std::endl;
	//WITHDRAW 
	//case 1. 
	int retVal = Savings->withdraw(0.5);
	if (retVal == 0) {
		std::cout << "it withdrew" << std::endl;
		std::cout << Savings->getBalance() << std::endl;
	}
	//case2. 
	retVal = Savings->withdraw(100);
	if (retVal != 0) {
		std::cout << "yo. attempted overdraft we had a problem" << std::endl;
	}
	std::cout << Savings->getBalance() << std::endl;

	/*************************************************************
	See if this dummy knows how to use the skeleton of a linked list. 
	*************************************************************/

	// savings is in the middle of our little linked list we are going to make. 

	Account* Savings_0 = new Account("0");
	Savings_0->deposit(100);
	Account* Savings_2 = new Account("2");
	Savings_2->deposit(200);

	
	Savings_0->next = Savings;
	Savings->prev = Savings_0;

	std::cout << "first item in the list balance" << std::endl;
	std::cout << (Savings->prev)->getBalance() << std::endl;
	std::cout << (Savings_0->next)->getName() << std::endl;

	Savings->next = Savings_2;
	Savings_2->prev = Savings;

	std::cout << "second item in the list balance" << std::endl;
	std::cout << (Savings->next)->getBalance() << std::endl; // 200 
	std::cout << (Savings_2->prev)->getName() << std::endl; // Savings 


	// link test. 
	Account* temp = NULL;
	temp = Savings_0; 
	std::cout << "commencing iteration" << std::endl;
	while (temp != NULL) {
		std::cout << temp->getName() << std::endl;
		temp = temp->next;
	}
	
}



void categoriesTest() {

	Account* a0 = new Account("a0");
	Account* a1 = new Account("a1");
	Account* a2 = new Account("a2"); 
	Account* a3 = new Account("a3");
	Account* a4 = new Account("a4");

	Categories* myList = new Categories();
	
	myList->add(a0);
	myList->add(a1);
	myList->add(a2);
	myList->add(a3);
	myList->add(a4);
	myList->print();

	delete a0;
	delete a1;
	delete a2;
	delete a3;
	delete a4;
	myList->print();


	//CASE ONE TEST... 
	std::cout << "\n CASE ONE: remove in middle \n ";
	Account* junk = myList->remove("a0");
	delete junk;
	myList->print();

	//CASE TWO TEST... 
	std::cout << "\n CASE TWO: remove in middle \n ";
	Account* junk1 = myList->remove("a3");
	delete junk1;
	myList->print();


	//CASE THREE TEST... 
	std::cout << "\n CASE THREE: remove at tail \n ";
	Account* junk2 = myList->remove("a4");
	delete junk2;
	myList->print();

	// CASE FOUR 
	std::cout << "\n CASE FOUR: empty list \n ";
	Categories *emptyList = new Categories();
	Account* junk3 = emptyList->remove("a4");
	if (junk3 == NULL) {
		std::cout << "\ncaught it";
	}
}

void clearTest() {

	Account* a0 = new Account("a0");
	Account* a1 = new Account("a1");
	Account* a2 = new Account("a2");
	Account* a3 = new Account("a3");
	Account* a4 = new Account("a4");

	Categories* myList = new Categories();

	myList->add(a0);
	myList->add(a1);
	myList->add(a2);
	myList->add(a3);
	myList->add(a4);
	myList->print();

	myList->clear();
	int retVal = myList->print();
	std::cout << "\n" << retVal;
	
	
	

}

void ptrTest() {

	int val = 60;

	int* val1ptr = &val;
	int* val2ptr = val1ptr;

	*val2ptr = 5;

	std::cout << "val: " << val << std::endl;
	std::cout << "val1ptr: " << *val1ptr << std::endl;
	std::cout << "val2ptr: " << *val2ptr << std::endl;

}

void test_getCategory() {
	Account* newAccount = new Account("new1");
	newAccount->deposit(40);
	Categories *myCats = new Categories();
	myCats->add(newAccount);
	myCats->print();
	Account *re = myCats->getCategory("new1");
	re->deposit(100);
	myCats->print();
}



