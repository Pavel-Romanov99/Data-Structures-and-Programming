#include <iostream>
using namespace std;

class DynamicStack
{
private:
	int top;
	int* arr;
	int capacity;
public:
	DynamicStack();
	void push(int x);
	void pop();
	bool isEmpty();
	int peek();
	void print();

	void resize() {
		int newSize = capacity * 2;
		int* newArr = new int[newSize];

		memcpy(newArr, arr, capacity * sizeof(int));
		capacity = newSize;
		delete[] arr;
		arr = newArr;
	}
};

DynamicStack::DynamicStack() {
	this->top = -1;
	this->capacity = 10;
	this->arr = new int[capacity];
}

void DynamicStack::push(int x) {
	if (top < capacity - 1) {
		arr[++top] = x;
	}
	else {
		this->resize();
		arr[++top] = x;
	}
}

void DynamicStack::pop() {
	if (!isEmpty()) {
		top--;
	}
	else cout << "Stack is empty!" << endl;
}

bool DynamicStack::isEmpty() {
	if (top == -1) {
		return true;
	}
	return false;
}

int DynamicStack::peek() {
	if (!isEmpty()) {
		return arr[top];
	}
	else cout << "Stack is empty!";
}

void DynamicStack::print() {
	for (int i = 0; i < top + 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	DynamicStack a;
	for (int i = 0; i < 20; i++)
	{
		a.push(i);
	}
	a.print();
	a.pop();
	a.print();
	cout << a.peek() << endl;
	cout << a.isEmpty() << endl;
}
