#include <iostream>
#include <stack>
using namespace std;

class RPN
{
private:
	const char *expression;
	stack<char> result;
public:
	void set_expression(const char* arr)
	{
		this->expression = arr;
	}

	const char* get_expression()
	{
		return expression;
	}

	void evaluate() {
		int i = 0;
		while (expression[i] != '\0') {


			if (expression[i] >= '0' && expression[i] <= '9') {
				result.push(expression[i]);
			}

			else {
				char operation = expression[i];
				if (operation == '+') {
					int right = result.top() - '0';
					result.pop();
					int left = result.top() - '0';
					result.pop();
					int temp = left + right;
					result.push(temp + '0');
				}
				else if (operation == '-') {
					int right = result.top() - '0';
					result.pop();
					int left = result.top() - '0';
					result.pop();
					int temp = left - right;
					result.push(temp + '0');
				}
				else if (operation == '*') {
					int right = result.top() - '0';
					result.pop();
					int left = result.top() - '0';
					result.pop();
					int temp = left * right;
					result.push(temp + '0');
				}
				else if (operation == '/') {
					double right = result.top() - '0';
					result.pop();
					double left = result.top() - '0';
					result.pop();
					double temp = left / right;
					result.push(temp );
				}
			}
			i++;
		}

	}
	char get_top() {
		return result.top();
	}
};

int main()
{
	RPN a;
	a.set_expression("12+345/-*");
	a.evaluate();
	cout << a.get_top() << endl;
}
