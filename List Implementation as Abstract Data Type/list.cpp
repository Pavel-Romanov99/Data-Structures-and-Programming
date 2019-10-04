#include <iostream>
using namespace std;

class List {
private:
	int capacity;
	int end;
	int* arr;
public:
	List() {
		this->capacity = 100;
		this->end = -1;
		arr = new int[capacity];
	}

	List(int capacity) {
		this->capacity = capacity;
		this->end = -1;
		arr = new int[this->capacity];
	}

	//add element at the end of the list
	void add_element(int x) {
		if (this->end < this->capacity) {
			arr[++end] = x;
		}
		else cout << "List is full!" << endl; //for now
	}

	//add an element at position and shift the other elements to the right
	void add_element_at(int x, int position) {
		if (this->end < this->capacity) {
			end++;
			for (int i = end + 1; i > position; i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[position] = x;
		}
	}

	//remove element at the end of the list
	void remove() {
		end--;
	}

	//remove an element at position and shift the other elements to the left
	void remove(int position) {
		for (int i = position; i < end + 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		end--;
	}

	//return size of the list
	int get_size() {
		return end + 1;
	}

	//set an element by position
	void set(int x, int position) {
		arr[position] = x;
	}

	void print() {
		for (int i = 0; i < end + 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	List a;
	a.add_element(1);
	a.add_element(3);
	a.add_element(4);
	a.add_element(5);
	a.print();
	a.add_element_at(2, 2);
	a.print();
	a.add_element_at(7, 3);
	a.print();
	a.remove(3);
	a.print();
	a.remove(3);
	a.print();
	cout << a.get_size() << endl;
	a.set(69, 2);
	a.print();
	a.remove(2);
	a.print();
}
