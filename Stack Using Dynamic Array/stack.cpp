#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	int capacity;
	int top;
	T* arr;
public:
	Stack() {
		this->capacity = 10;
		this->top = -1;
		arr = new T[this->capacity];
	}

	Stack(int capacity) {
		this->capacity = capacity;
		this->top = -1;
		arr = new T[this->capacity];
	}

	void push(int x) {
		if (top < capacity) {
			top++;
			arr[top] = x;
		}
		else cout << "Stack is full!" << endl;
	}

	void pop() {
		if (top == -1) {
			cout << "There is no element to pop!" << endl;
			return;
		}
		this->top--;
	}

	void print()
	{
		cout << "Stack: ";
		for (int i = 0; i < this->top + 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int get_top() {
		return arr[top];
	}

	bool is_empty() {
		if (top == -1) {
			return true;
		}
		return false;
	}
};

int main()
{
	Stack<int> a;
	a.push(2);
	a.push(2);
	a.push(2);
	a.print();
}
