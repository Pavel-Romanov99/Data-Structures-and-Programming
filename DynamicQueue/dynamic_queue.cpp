#include <iostream>
using namespace std;

class Queue1
{
private:
	int *arr;
	int front;
	int rear;
	int capacity;
public:

	Queue1()
	{
		this->capacity = 3;
		this->front = -1;
		this->rear = -1;
		arr = new int[capacity];
	}
	void Enqueue(int x)
	{
		if (rear < capacity - 1)
		{
			this->front = 0;
			arr[++rear] = x;
		}
		else {
			int new_capacity = 2 * capacity;
			int *arr_new = new int[new_capacity];

			memcpy(arr_new, arr, capacity * sizeof(int));
			capacity = new_capacity;
			delete[] arr;
			arr = arr_new;
		}
	}

	bool Empty()
	{
		if (front == -1 && rear == -1) {
			return true;
		}
		return false;
	}

	void Dequeue()
	{
		if (!Empty())
		{
			rear--;
		}
		else cout << "Queue is empty" << endl;
	}


	void Print()
	{
		for (int i = 0; i <= this->rear; i++)
		{
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}

	int getFront() {
		if (!Empty())
			return arr[front];

		else return -1;
	}
};

int main()
{
	Queue1 a;
	a.Enqueue(2);
	a.Enqueue(2);
	a.Enqueue(2);
	a.Enqueue(2);
	a.Enqueue(2);
	a.Enqueue(2);
	a.Enqueue(2);
	a.Print();
}
