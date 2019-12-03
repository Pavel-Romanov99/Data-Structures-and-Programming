#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class Stack {
private:
	node* top = NULL;
public:
	void push(int x);
	void pop();
	bool isEmpty();
	int peek();
	void print();
};


void Stack::pop() {
	node* popper = top;
	top = popper->next;
	delete popper;
}

void Stack::push(int x) {
	node* temp = new node();
	temp->data = x;
	temp->next = top;
	top = temp;
}

void Stack::print() {

		node* temp = top;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
}

bool Stack::isEmpty() {
	if (top == NULL) {
		return true;
	}
	return false;
}

int Stack::peek() {
	return top->data;
}

int main()
{
	Stack a;
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	a.print();
	cout << "is it empty " << a.isEmpty() << endl;
	cout << "Top = " << a.peek() << endl;
	a.pop();
	a.print();
}
