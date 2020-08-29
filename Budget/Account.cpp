
//----------------------------------------------------------------------
// File: Account.cpp
// Purpose: cpp file for defining object specs in a generalized account type to be used in a double linked list structure. 
// Author: Austin Migchelbrink
// github creds: userName = austbrink , email = austbrink@gmail.com
//----------------------------------------------------------------------

#include "Account.h"

Account::Account(std::string nameDef) {
	balance = 0.0;
	name = nameDef;
}

Account::~Account() {
}

//takes a double type sum, updates balance by adding sum to it. void because we typically have no issues there.
void Account::deposit(double sum) {
	balance = balance + sum;
}


/*************************************************************
takes adouble sum and attempts to decrement balance to it.
Returns -1 if the withdraw sum is greater than current balance
Otherwise Return 0
*************************************************************/
int Account::withdraw(double sum) {
	if (sum > balance) {
		return -1;
	} 
	balance = balance - sum;
	return 0;
}

double Account::getBalance() {
	return balance;
}

std::string Account::getName() {
	return name;
}

void Account::setBalance(double sum) {
	balance = sum;
}



