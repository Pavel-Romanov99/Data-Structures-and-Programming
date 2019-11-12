#pragma once
#include "Node.h"

class LinkedList {
private:
	node *head = NULL;
public:
	void addBeginning(int x);
	void addAt(int x, int position);
	void addEnd(int x);
	void print();
	void removeBiginning();
	void removeEnd();
	void removeAt(int position);
	int length();
	void sorting()
	{
		node * temphead = head;
		int temproll;
		int counter = 0;
		while (temphead)
		{
			temphead = temphead->next;
			counter++;
		}
		temphead = head;

		for (int j = 0; j < counter; j++)
		{
			while (temphead->next)  //iterate through list until next is null
			{
				if (temphead->data > temphead->next->data)
				{
					temproll = temphead->data;
					temphead->data = temphead->next->data;
					temphead->next->data = temproll;

					temphead = temphead->next;//increment node
				}
				else
					temphead = temphead->next;//increment node
			}
			temphead = head;//reset temphead
		}
	}
};

void LinkedList::addBeginning(int x) {
	//we create a new node
	node *temp = new node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

void LinkedList::print() {
	node *temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void LinkedList::addAt(int x, int position) {
	node *temp = head;

	node *inserted = new node();
	inserted->data = x;
	inserted->next = NULL;

	if (position == 1) {
		inserted->next = head;
		head = inserted;
		return;
	}

	//pointer to n-1-th node
	for (int i = 0; i < position - 2; i++)
	{
		temp = temp->next;
	}

	inserted->next = temp->next; //we set the new node to point to n-th - 1
	temp->next = inserted;
}

void LinkedList::addEnd(int x) {

	node *inserted = new node();
	inserted->next = NULL;
	inserted->data = x;

	node *temp = head;

	//pointer to the last element of the list
	while (temp->next != NULL) {
		temp = temp->next;
	}

	//we direct the last element to the new last element
	temp->next = inserted;
}

void LinkedList::removeBiginning() {
	node *temp = head;
	head = temp->next;
	delete temp;
}

int LinkedList::length() {
	node *temp = head;
	int counter = 1;

	while (temp->next != NULL) {
		counter++;
		temp = temp->next;
	}
	return counter;
}

void LinkedList::removeEnd() {

	node *temp = head;

	for (int i = 0; i < this->length() - 2; i++)
	{
		temp = temp->next;
	}

	node *temp2 = temp->next;
	temp->next = NULL;
	delete temp2;
}

void LinkedList::removeAt(int position) {
	node* temp = head;

	//pointer to the n-th - 1 element of the list
	for (int i = 0; i < position - 2; i++)
	{
		temp = temp->next;
	}

	node *temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
}
