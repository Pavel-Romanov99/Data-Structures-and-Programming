#include <iostream>
using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int capacity;
	int* arr;
public:
	Queue() {
		this->front = 0;
		this->rear = 0;
		this->capacity = 10;
		arr = new int[capacity];
	}

	void Insert(int x) {
		if (rear < capacity) {
			arr[++rear] = x;
		}
		else cout << "Queue is full!" << endl;
	}

	void Remove() {
		if (!isEmpty()) {
			for (int i = front; i < rear; i++)
			{
				arr[i] = arr[i + 1];
			}
			rear--;
		}
		else cout << "Queue is empty" << endl;
	}

	int getFront() {
		if (!isEmpty())
			return arr[front + 1];

		else return -1;
	}

	bool isEmpty() {
		if (rear == 0) {
			return true;
		}
		return false;
	}

	void Print() {
		for (int i = 1; i < rear + 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() 
{
	Queue a;
	cout << a.isEmpty() << endl;
	a.Remove();
	a.Print();
}
