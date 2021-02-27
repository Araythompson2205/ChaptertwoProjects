// Participants: Gabriela Lopez, Andrew Thompson, and Lincoln Nguyen
// Date: 02-23-21
// Description: LinkedList of Employees Implementation

#include "List.h"
#include <iostream>
#include <cstdlib>
#include "employee.h"
using namespace std;

list::list() : head(NULL), tail(NULL)
{
	size = 0;
}

listNode* list::getHead()
{
	return head;
}
bool list::empty() const
{
	return (head == NULL);
}
list::list(const list& obj)
{
	head = new listNode;
	head->obj = obj.head->obj;
	head->next = obj.head->next;
}
void list::addItem(Employee& newObj) 
{	
	if (head == NULL) 
	{
		size = 1;
		head = new listNode;
		head->obj = newObj;
		head->next = NULL;
		
	}
	else 
	{
		listNode *temp = new listNode;
		temp->obj = newObj;
		temp->next = NULL;
		
		listNode *tempPtr = head;

		while (tempPtr->next != NULL)
			tempPtr = tempPtr->next;

		temp->next = tempPtr->next;
		tempPtr->next = temp;
		size++;
	}
}


void list::deleteLast() {


	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}
	listNode* temp = head;
	while (temp->next && temp->next->next != NULL) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}
void list::addEmployee()
{
	string firstName, lastName, startDate;
	Employee newEmployee;
	size++;
	newEmployee.setId(size);
	cout << "\n Enter the last name: ";
	cin >> lastName;
	cout << "\n Enter the first name: ";
	cin >> firstName;
	startDate = inputDate("\nEnter the Starting date: ");
	newEmployee.setFirstName(firstName);
	newEmployee.setLastName(lastName);
	newEmployee.setStartDate(startDate);
	addItem(newEmployee);

}
ostream& operator <<(ostream& outs, list& obj) {
	listNode* temp = obj.head;
	while (temp != NULL) {
		cout << temp->obj.getStatus() << '\n';
		cout << temp->obj.getLastName() <<", "<<temp->obj.getFirstName()<< '\n';
		cout << temp->obj.getId() << '\n';
		cout << temp->obj.getStartDate() << '\n';
		cout << temp->obj.getEndDate() << '\n';
			
		temp = temp->next;
	}

	return outs;
}
string inputDate(string prompt)			//validates date in form dd/mm/yy
{
	char input[9];
	string toReturn="";
	do
	{
		cout << prompt;
		cin >> input;
		if (strlen(input) < 8 || strlen(input) > 8)
		{
			cout << "Error: date must be in mm/dd/yy format\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (strlen(input) == 8)
		{
			char m[3], d[3], y[3];
			int mm, dd, yy;
			int i, n;
			for (i = 0; i < 2; i++)
				m[i] = input[i];
			for (i = 3, n = 0; i < 5; i++, n++)
				d[n] = input[i];
			for (i = 6, n = 0; i < 8; i++, n++)
				y[n] = input[i];
			mm = atoi(m);
			dd = atoi(d);
			yy = atoi(y);
			if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 ||
				mm == 8 || mm == 10 || mm == 12) && (dd > 31 || dd < 1))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && (dd > 30 || dd < 1))
			{
				cout << "Error: Date \n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm == 2) && (yy % 4 == 0) && (dd > 29 || dd < 1))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm == 2) && (yy % 4 != 0) && (dd > 28 || dd < 1))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm < 1) || (mm > 12))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else
			{
				for (i = 0; i < 8; i++)
					toReturn = toReturn + input[i];
				break;
			}
		}
		
	} while (true);
	return toReturn;
}
