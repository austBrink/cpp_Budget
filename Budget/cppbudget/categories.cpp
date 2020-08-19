
//----------------------------------------------------------------------
// File: Account.cpp
// Purpose: cpp file for defining object specs in a generalized account type to be used in a double linked list structure. 
// Author: Austin Migchelbrink
// github creds: userName = austbrink , email = austbrink@gmail.com
//----------------------------------------------------------------------

#include "categories.h"
#include"iostream"


Categories::Categories() {
}

Categories::~Categories() {
}

void Categories:: add(Account *a){
	Account* temp, * prev;
	temp = root;
	if (root == NULL) {
		root = a;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = a;
		a->prev = temp;
	}
}

Account * Categories::remove(std::string name) {
	
	Account* prev, * temp;
	temp = root;
	prev = NULL;

	while ((temp != NULL) && name != temp->getName()) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		return NULL;
	}

	else if (prev==NULL) {
		root = root->next;
		return temp;
	}
	else {
		prev->next = temp->next;
		return temp;
	}

	return NULL;
}

int Categories :: print() {

	Account* temp;
	temp = root;

	if (root == NULL) {
		return -1;
	}

	while (temp != NULL) {
		std::cout << temp->getName() << ",";
		temp = temp->next;
	}
}