
//----------------------------------------------------------------------
// File: Account.cpp
// Purpose: cpp file for linking Account objects. Needed as a structure to keep "categories" in a Checking Account object. 
// Author: Austin Migchelbrink
// github creds: userName = austbrink , email = austbrink@gmail.com
//----------------------------------------------------------------------

#include "categories.h"
#include"iostream"

Categories::Categories() {
	root = NULL;
}

Categories::~Categories() {
}


void Categories:: add(Account *a){

	Account* temp;
	temp = root;

	Account* newNode = new Account(a->getName());
	newNode->next = NULL;
	newNode->deposit(a->getBalance());

	if (root == NULL) {
		root = newNode;
	}

	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}

}

Account * Categories::remove(std::string name) {
	
	Account* prev, * temp;
	temp = root;
	prev = NULL;

	if (root == NULL) {
		return NULL;
	}

	while ((temp != NULL) && name != temp->getName()) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		return NULL;
	}

	else if (prev==NULL) {
		(temp->next)->prev = prev;
		root = root->next;
		return temp;
	}
	else {
		
		prev->next = temp->next;
		return temp;
	}

	// nail down what the logic is behind a default return of NULL.

	return NULL;
}

int Categories :: print() {

	Account* temp;
	temp = root;

	if (root == NULL) {
		return -1;
	}

	while (temp != NULL) {
		std::cout << temp->getName() << ":" << temp->getBalance() << std::endl;
		temp = temp->next;
	}
}

void Categories::clear() {
	Account* temp;
	temp = root;
	if (root != NULL) {
		while (root != NULL) {
			temp = root;
			root = root->next;
			delete temp;
		}
	}
}

bool Categories::isEmpty() {
	if (root!=NULL) {
		return false;
	}
	return true;
}


Account* Categories::getCategory(std::string name) {
	if (isEmpty()) {
		return NULL;
	}
	Account* temp = root;

	while (temp != NULL && name != temp->getName()) {
		temp=temp->next;
	}
	if (temp == NULL) {
		return NULL;
	}
	else {
		return temp;
	}
}

