#include <iostream>
using namespace std;



struct node
{
	int data;
	node* next;
};

class LinkedQueue
{
private:
	node* front = NULL;
	node* rear = NULL;
public:
	void Enqueue(int x);
	void Dequeue();
	bool isEmpty();
	int getFront();
	void Print();
};

void LinkedQueue::Enqueue(int x) {
	node* temp = new node();
	temp->data = x;
	temp->next = NULL;

	if (isEmpty()) {
		front = temp;
		rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}

void LinkedQueue::Dequeue()
{
	if (!isEmpty()) {
		node* temp = front;
		front = front->next;
		delete temp;
	}
	else cout << "Queue is empty" << endl;
}

int LinkedQueue::getFront() {
	return front->data;
}

bool LinkedQueue::isEmpty() {
	if (front == NULL && rear == NULL)
	{
		return true;
	}
	return false;
}

void LinkedQueue::Print()
{
	node* temp = front;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{

} 
