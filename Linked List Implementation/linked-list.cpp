#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
//global variable that is the pointer to the first node of the list
node* head;

void Insert_at_beginning(int x) {
	//we create a new node
	node* temp = new node();
	temp->data = x;
	// we set the new node to point to where the head points
	temp->next = head;
	//we set the head to point to the new node
	head = temp;
}

 void Insert_at_end(int x) {
	node* temp = new node();
	node* temp1 = head;
	while (temp1->next != NULL) {
		temp1 = temp1->next;
	}

	temp1->next = temp;
	temp->data = x;
	temp->next = NULL;
}

 void Insert_at(int x, int position) {
	 //we create a new node
	 node* temp1 = new node();
	 temp1->data = x;
	 temp1->next = NULL;

	 //if we insert at first position (works even if the list is empty)
	 if (position == 1) {
		 temp1->next = head;
		 head = temp1;
		 return;
	 }

	 node* temp2 = head;
	 //we do the for to position - 2 so that we get temp2 to point to position - 1 element of the list
	 for (int i = 0; i < position - 2; i++)
	 {
		 temp2 = temp2->next;
	 }
	 // we set the new node at n-th position to point to the next element
	 temp1->next = temp2->next;
	 //we set the previous element to point to the new nodes
	 temp2->next = temp1;
 }

 void remove_at(int n) {
	 node* temp1 = head;

	 if (n == 1) {
		 head = temp1->next; // head now points to the second node
		 delete temp1;
		 return;
	 }

	 for (int i = 0; i < n-2; i++)
	 {
		 temp1 = temp1->next; //point to n-1 node
	 }
	 node* temp2 = temp1->next; //n-th node
	 temp1->next = temp2->next; //n+1 node
	 delete temp2;
 }

void Print() {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	head = NULL; //empty list
	Insert_at_beginning(6);
	Insert_at_beginning(8);
	Insert_at_end(69);
	Insert_at_end(2);
	Insert_at_end(3);
	Insert_at_beginning(1);

	Print();
	Insert_at(300, 2);
	Print();
	remove_at(2);
	Print();
	remove_at(2);
	Print();
}
