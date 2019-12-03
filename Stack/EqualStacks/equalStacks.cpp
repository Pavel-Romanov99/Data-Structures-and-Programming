#include <iostream>
#include <stack>
using namespace std;

class EqualStacks
{
private:
	stack<int> stack1;
	stack<int> stack2;
	stack<int> stack3;
	int sum1 = 0, sum2 = 0, sum3 = 0;
public:
	void add1(int x) {
		stack1.push(x);
		sum1 += x;
	}
	void add2(int x) {
		stack2.push(x);
		sum2 += x;
	}
	void add3(int x) {
		stack3.push(x);
		sum3 += x;
	}
	int get_sum1() {
		return sum1;
	}
	int get_sum2() {
		return sum2;
	}
	int get_sum3() {
		return sum3;
	}

	void evaluate() {
		while (sum1 != sum2 || sum1 != sum3 || sum2 != sum3) {
			if (sum1 < sum2 && sum1 < sum3) {
				sum2 -= stack2.top();
				stack2.pop();

				sum3 -= stack3.top();
				stack3.pop();
			}
			else if (sum2 < sum1 && sum2 < sum3) {
				sum1 -= stack1.top();
				stack1.pop();

				sum3 -= stack3.top();
				stack3.pop();
			}
			else if (sum3 < sum2 && sum3 < sum1) {
				sum2 -= stack2.top();
				stack2.pop();

				sum1 -= stack1.top();
				stack1.pop();
			}
			else if (sum1 < sum2 && sum1 == sum3) {
				sum2 -= stack2.top();
				stack2.pop();
			}
			else if (sum1 < sum3 && sum1 == sum2) {
				sum3 -= stack3.top();
				stack3.pop();
			}
			else if (sum2 < sum1 && sum2 == sum3) {
				sum1 -= stack1.top();
				stack1.pop();
			}
			else if (sum2 < sum3 && sum2 == sum1) {
				sum3 -= stack3.top();
				stack3.pop();
			}
			else if (sum3 < sum2 && sum3 == sum1) {
				sum2 -= stack2.top();
				stack2.pop();
			}
			else if (sum3 < sum1 && sum3 == sum2) {
				sum1 -= stack1.top();
				stack1.pop();
			}
		}
	}
};

int main()
{
	EqualStacks a;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	for (int i = 0; i < n1; i++)
	{
		int num;
		cin >> num;
		a.add1(num);
	}
	for (int i = 0; i < n2; i++)
	{
		int num;
		cin >> num;
		a.add2(num);
	}
	for (int i = 0; i < n3; i++)
	{
		int num;
		cin >> num;
		a.add3(num);
	}
	a.evaluate();
	cout << a.get_sum1() << " " << a.get_sum2() << " " << a.get_sum3() << endl;
}
