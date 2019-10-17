  #include <iostream>
#include <string>
#include <stack>
using namespace std;

class SYA
{
private:

	stack<char> operations;
public:
	stack<char> result;
	string expression;

	void set(string arr) {
		this->expression = arr;
	}

	string get() {
		return expression;
	}

	void print_result()
	{
		while (!result.empty()) {
			cout << result.top();
			result.pop();
		}
	}

	void print(stack<char> result)
	{
		if (result.empty())
		{
			return;
		}

		char top = result.top();
		result.pop();
		print(result);

		cout << top;
	}

	void transform() {
		for (int  i = 0; i < expression.length(); i++)
		{
			if (expression[i] >= '0' && expression[i] <= '9') {
				result.push(expression[i]);
			}
			else if (expression[i] == '(') {

				operations.push(expression[i]);
			}
			else if (expression[i] == '+') {

				//we push the higher priority or equal priority operations
				while (operations.top() != '(') {
					result.push(operations.top());
					operations.pop();
				}
				operations.push(expression[i]);
			}
			else if (expression[i] == '-') {

				//we push the higher priority or equal priority operations				
				while (operations.top() != '(') {
					result.push(operations.top());
					operations.pop();
				}
				operations.push(expression[i]);
			}
			else if (expression[i] == '*') {
				operations.push(expression[i]);
			}
			else if (expression[i] == '/') {
				operations.push(expression[i]);
			}
			else if (expression[i] == ')') {
				while (operations.top() != '(') {
					result.push(operations.top());
					operations.pop();
				}
				operations.pop();
			}
		}
		while (!operations.empty()) {
			result.push(operations.top());
			operations.pop();
		}
	}
};

int main()
{
	SYA a;
	a.set("(1+2)*(3/4-5)");
	a.transform();
	a.print(a.result);
}
