
//----------------------------------------------------------------------
// File: Account.h
// Purpose: Header file for outlining object specs for a generalized account type to be used in a double linked list structure. 
// Author: Austin Migchelbrink
// github creds: userName = austbrink , email = austbrink@gmail.com
// Notes: See .cpp for comments 
//----------------------------------------------------------------------
// test 

#ifndef ACCOUNT 
#define ACCOUNT
#include <string>

class Account {
protected:
	std::string name;
	double balance;
public:	
	Account* next, *prev;
	Account(std::string);
	~Account();
	void deposit(double sum);
	int withdraw(double sum);
	double getBalance();
	std::string getName();
};

#endif 