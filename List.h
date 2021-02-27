// Participants: Gabriela Lopez, Andrew Thompson, and Lincoln Nguyen
// Date: 02-23-21
// Description: LinkedList of Employees Definition

//EXPLAIN HOW TO USE THIS LINKEDLIST************************************************************************
//HEADER FILE COMMENT

#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include "employee.h"
using namespace std;

	struct listNode {
		Employee obj;
		listNode* next;
	};
	class list {
	private:
		listNode* head, * tail;
		int size;
	public:
		//Precondition:N/A
		//Postcondition:Creates a list
		list();
		//Precondition:A list object
		//Postcondition:Creates a list with the same items as obj
		list(const list& obj);
		/*~list();*/
		//precondition: a  list with at least one node(Please really do not call this on an empty list)
		//postcondition:removes the last node in the list
		void deleteLast();
		//precondition: any list, empty or not.
		//postcondition:adds a node with value of obj at the end of the list
		void addItem(Employee& obj);
		//Precondition: a list containing employee objects
		//postcondition: runs the addEmployee option for the employee program
		void addEmployee();
		//Precondition: a list containing employee objects
		//postcondition: displays all list nodes and thier contents 
		friend ostream& operator <<(ostream& outs, list& obj);
		//Precondition: a list 
		//postcondition: returns true if empty, false if not.
		bool empty() const;
		//Precondition: a list 
		//postcondition: Returns the location of the head of the list
		listNode* getHead();
	};
	//Precondition: the employee program is running and the user has chosen to add a new employee
	//Postconditions: returns an input date as a string, provided it is a valid date AND is in mm/dd/yy format.
	string inputDate(string promt);
#endif 