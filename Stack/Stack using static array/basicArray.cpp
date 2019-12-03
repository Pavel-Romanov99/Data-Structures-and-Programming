#include <iostream>
using namespace std;

const int MAX = 10;

class BasicStack {
private:
	int top = -1;
	int arr[MAX];
public:
	void push(int x);
	void pop();
	int peek();
	bool isEmpty();
	void Print();
};

void BasicStack::push(int x) {
	if (top >= MAX - 1) {
		cout << "Stack is full!" << endl;
	}

	else {
		arr[++top] = x;
	}
}

void BasicStack::pop() {
	if (top == -1) {
		cout << "Stack is empty" << endl;
	}

	else top--;
}

bool BasicStack::isEmpty() {
	if (top == -1) {
		return true;
	}
	return false;
}

int BasicStack::peek() {
	if (top > -1) {
		return arr[top];
	}
	else cout << "Stack is empty" << endl;
}

void BasicStack::Print() {
		for (int i = 0; i < top + 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
}
