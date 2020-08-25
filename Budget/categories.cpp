
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

	// traverse list. Break as soon as we drop out. OR when we find the node with the right name. 
	while ((temp != NULL) && name != temp->getName()) {
		prev = temp;
		temp = temp->next;
	}

	// what if not found. CASE 2
	if (temp == NULL) {
		return NULL;
	}
	// now need to see if we are at the head. 
	else if (temp == root) {
		//either points to the next thingy. OR goes ahead and sets it to null because we gutted the list if only head existed. 
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

