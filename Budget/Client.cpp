#include<iostream>
#include"Account.h"
#include"Categories.h"
#include"Checking.h"
#include<string>


void savingsTest();
void categoriesTest();
void clearTest();
void ptrTest();
void test_getCategory();
void testChecking();
void tests();
void menuPrint();
void menuSwitch(std::string& userChoice, Checking *myChecking, Account *Savings); 
void mkcat(Checking* myChecking);
void in(Checking* myChecking, Account *Savings);
void out(Checking* myChecking);
void rmcat(Checking *myChecking);
void trans(Checking* myChecking, Account *Savings);

#define HEADER "\n\t\t~~BUDGET~~\n"


int main(void) {
	
	Checking *myChecking = new Checking();
	Account* Savings = new Account("Savings");

	std::cout << HEADER << std::endl;
	menuPrint();
	std::string userChoice = "";
	while (userChoice != "q") {
		std::cout << "-->> ";
		std::cin >> userChoice;
		menuSwitch(userChoice,myChecking,Savings);
	}
	bool debug = false;
	if (debug) {
		tests();
	}
	
	return 0;
}

void menuSwitch(std::string& userChoice, Checking *myChecking, Account *Savings) {
	double sum = 0.0;
	std::string categoryName = "";
	int retVal;
	if (userChoice == "show") {
		myChecking->show();
		std::cout << "Savings:" << Savings->getBalance()<<std::endl;
	}
	else if (userChoice == "in") {
		in(myChecking, Savings);
	}
	else if (userChoice == "out") {
		out(myChecking);
	}
	else if (userChoice == "trans") {
		trans(myChecking,Savings);
	}
	else if (userChoice == "mkcat") {
		mkcat(myChecking);
	}
	else if (userChoice == "rmcat") {
		rmcat(myChecking);
	}
	else if (userChoice == "opt") {
		std::cout << "options print" << std::endl;
	}
	else if (userChoice == "q") {
		std::cout << "leaving" << std::endl;
	}
	else {
		std::cout << "enter a valid command" << std::endl;
	}
}

void mkcat(Checking *myChecking) {
	int retVal;
	std::string categoryName;
	std::cout << "enter new category name -->> ";
	std::cin >> categoryName;
	retVal = myChecking->createCategory(categoryName);
	if (retVal == -1) {
		std::cout << "error: " << categoryName << " already exists\n";
	}
	else if (retVal == 0) {
		std::cout << "success: " << categoryName << " added as new category\n";
	}
}

void in(Checking* myChecking, Account *Savings) {
	double sum;
	std::string categoryName;
	int retVal;
	std::cout << "enter an amount -->> ";
	std::cin >> sum;
	std::cout << "enter a destination category -->> ";
	std::cin >> categoryName;
	if (categoryName == "Savings") {
		Savings->deposit(sum);
		std::cout << "success: $" << sum << " has been deposited to Savings account\n";
	}
	else {
		retVal = myChecking->deposit(sum, categoryName);
		if (retVal == -1) {
			std::cout << "error: no categories to deposit to\n";
		}
		else if (retVal == -2) {
			std::cout << "error: " << categoryName << " is not a valid category \n";
		}
		else {
			std::cout << "success: $" << sum << " has been deposited to " << categoryName << " account\n";
		}
	}
	
}

void out(Checking* myChecking) {
	double sum;
	std::string categoryName;
	int retVal;
	std::cout << "enter an amount -->> ";
	std::cin >> sum;
	std::cout << "enter a destination category -->> ";
	std::cin >> categoryName;
	retVal = myChecking->withdraw(sum, categoryName);
	if (retVal == -1) {
		std::cout << "error: no categories to withdraw from \n";
	}
	else if (retVal == -2) {
		std::cout << "error: " << categoryName << " is not a valid category \n";
	}
	else if (retVal == -3) {
		std::cout << "error: attempted to overdraft checking account \n";
	}
	else if (retVal == -4) {
		std::cout << "error: attempted to overdraft " << categoryName << "\n";
	}
	else if (retVal == 0) {
		std::cout << "success: $" << sum << " withdrawn from " << categoryName << "\n";
	}
}

void rmcat(Checking* myChecking) {
	std::string categoryName;
	int retVal;
	std::cout << "enter the name of category to remove -->> ";
	std::cin >> categoryName;
	retVal = myChecking->removeCategory(categoryName);
	if (retVal == -1) {
		std::cout << "error: no categories to remove\n";
	}
	else if (retVal == -2) {
		std::cout << "error: " << categoryName << " is not a valid category \n";
	}
	else if (retVal == -3) {
		std::cout << "error: " << categoryName << " must have balance $0.00 to remove \n";
	}
	else if (retVal == 0) {
		std::cout << "success: " << categoryName << " removed \n";
	}
	
}

void trans(Checking* myChecking, Account *Savings) {
	std::string withdrawFrom;
	std::string depositTo;
	int retVal;
	double sum; 
	std::string userChoice;
	Account* temp;

	std::cout << "enter a valid choice:\n";
	std::cout << "A) checking to savings\n";
	std::cout << "B) savings to checking\n";
	std::cout << "C) category to category\n";
	std::cin >> userChoice;

	if (userChoice == "A") {
		std::cout << "withdraw from -->> ";
		std::cin >> withdrawFrom;
		std::cout << "amount -->> ";
		std::cin >> sum;
		retVal = myChecking->withdraw(sum, withdrawFrom);
		if (retVal == -1) {
			std::cout << "error: no categories to transfer from\n";
		}
		else if (retVal == -2) {
			std::cout << "error: " << withdrawFrom << " is not a valid category \n";
		}
		else if (retVal ==- 3) {
			std::cout << "error: attempted to overdraft checking account \n";
		}
		else if (retVal == -4) {
			std::cout << "error: attempted to overdraft " << withdrawFrom << "\n";
		}
		else if (retVal == 0) {
			Savings->deposit(sum);
			std::cout << "success: $" << sum << " transfered from " << withdrawFrom << " to Savings \n";
		}
	}
	else if (userChoice == "B") {
		std::cout << "to category -->> ";
		std::cin >> depositTo;
		std::cout << "amount -->> ";
		std::cin >> sum;
		// See if the select category is valid or is its empty. need to add ckecing->categories();
		temp = myChecking->getCategory(depositTo);
		if (myChecking->isEmpty()) {
			std::cout << "error: no categories to transfer from\n";
		}
		//need to make sure that the categories was non empty, but the category was not found. 
		else if (!myChecking->isEmpty() && temp == NULL) {
			std::cout << "error: " << depositTo << " is not a valid category \n";
		}
		else if (temp != NULL) {
			retVal = Savings->withdraw(sum);
			if (retVal == -1) {
				std::cout << "error: attempted savings overdraft\n";
			}
			else if(retVal == 0) {
				myChecking->deposit(sum, depositTo);
				std::cout << "success: $" << sum << " transfered from Savings, to " << depositTo << "\n";
			}
		}
	}
	else if (userChoice == "C") {
		std::cout << "to category -->> ";
		std::cin >> depositTo;
		std::cout << "from category -->> ";
		std::cin >> withdrawFrom;
		std::cout << "amount -->> ";
		std::cin >> sum;

		temp = myChecking->getCategory(depositTo);
		if (myChecking->isEmpty()) {
			std::cout << "error: no categories to transfer from\n";
		} else if(!myChecking->isEmpty() && temp == NULL) {
			std::cout << "error: " << depositTo << " is not a valid category \n";
		}
		else if (temp != NULL) {
			// now check to see if location is valid. 
			temp = myChecking->getCategory(withdrawFrom);
			if (myChecking->isEmpty()) {
				std::cout << "error: no categories to transfer from\n";
			}
			else if (!myChecking->isEmpty() && temp == NULL) {
				std::cout << "error: " << withdrawFrom << " is not a valid category \n";
			}
			else if (temp != NULL) {
				myChecking->withdraw(sum, withdrawFrom);
				myChecking->deposit(sum, depositTo);
				std::cout << "success: $" << sum << " transfered from " << withdrawFrom << " to " << depositTo << "\n";
			}
		}
	}
}


void menuPrint() {
	std::cout << "ENTER A VALID CHOICE:\n";
	std::cout << "show) show accounts and categories\n";
	std::cout << "in) deposit \n";
	std::cout << "out) withdraw \n";
	std::cout << "trans) transfer \n";
	std::cout << "mkcat) create category \n";
	std::cout << "rmcat) remove category \n";
	std::cout << "opt) options \n";
	std::cout << "q) quit \n";
}


void tests() {
	savingsTest();
	categoriesTest();
	clearTest();
	ptrTest();
	test_getCategory();
	testChecking();
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
	if (myList->getCategory("a0")==NULL) {
		std::cout << ":(" << std::endl;
	}

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

void testChecking() {

	//create a checking account.
	//Checking* myChecking = new Checking();
	//
	//std::cout << myChecking->getName() << "\n";
	//
	//int retVal;
	//
	//retVal = myChecking->removeCategory("dope");
	//std::cout << retVal << std::endl;
	//
	//retVal = myChecking->deposit(50,"catOne");
	//std::cout << retVal << std::endl;
	//
	//std::cout << "ADD FUNCTIONS" << std::endl;
	//retVal = myChecking->createCategory("catOne");
	//std::cout << retVal << std::endl;
	//retVal = myChecking->createCategory("catTwo");
	//std::cout << retVal << std::endl;
	//retVal = myChecking->createCategory("catTwo");
	//std::cout << retVal << std::endl;
	//std::cout << myChecking->getName() << std::endl;
	//
	//std::cout << "REMOVE" << std::endl;
	//retVal = myChecking->removeCategory("dope");
	//std::cout << retVal << std::endl;
	//retVal = myChecking->removeCategory("catTwo");
	//std::cout << retVal << std::endl;
	//
	//std::cout << "GET CAT " << std::endl;
	//
	//Account* temp = myChecking->getCategory/("catOne");
	//std::cout << temp->getName() << std::endl;
	//
	//std::cout << "DEPO" << std::endl;
	//retVal = myChecking->deposit(90, "dope");
	//std::cout << retVal << std::endl;
	//retVal = myChecking->deposit(90, "catTwo");
	//std::cout << retVal << std::endl;
	//
	//// testing the withdraw and remove // 
	//std::cout << "TESTING WITHDRAW" << std::endl;
	//retVal = myChecking->withdraw(90, "catThree");
	//myChecking->deposit(900, "catTwo");
	//myChecking->createCategory("catThree");
	//std::cout << retVal << std::endl;
	//myChecking -> deposit(100, "catThree");
	//retVal = myChecking->withdraw(90, "catThree");
	//std::cout << retVal << std::endl;
	//retVal = myChecking->withdraw(100, "catThree");
	//std::cout << retVal << std::endl;
	//retVal = myChecking->withdraw(1000, "catThree");
	//std::cout << retVal << std::endl;


	Checking* myChecking = new Checking();
	int retVal;
	retVal = myChecking->withdraw(100,"one");
	//should be -1 
	std::cout << retVal << std::endl;
	myChecking->createCategory("one");
	myChecking->deposit(100, "one");
	myChecking->createCategory("two");
	myChecking->deposit(200,"two");

	//should be 0 
	retVal = myChecking->withdraw(50, "one");
	std::cout << retVal << std::endl;
	//should be -2 
	retVal = myChecking->withdraw(100, "goop");
	std::cout << retVal << std::endl;
	//should be -4 
	retVal = myChecking->withdraw(100,"one");
	std::cout << retVal << std::endl;
	//should be -3
	retVal = myChecking->withdraw(900, "one");

	std::cout << retVal << std::endl;

	// IT WORKS 
	


	
	
	
	



	
	

}



