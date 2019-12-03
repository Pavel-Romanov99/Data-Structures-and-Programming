#include <iostream>
#include <stack>
#include <string>
using namespace std;

class RPN
{
private:
	string expression;
	stack<string> result;
public:
	void set_expression(string exp) {
		this->expression = exp;
	}

	string get_expression()
	{
		return this->expression;
	}

	string get_num(char a) {
		switch (a) {
		case '0': return "0";
		case '1': return "1";
		case '2': return "2";
		case '3': return "3";
		case '4': return "4";
		case '5': return "5";
		case '6': return "6";
		case '7': return "7";
		case '8': return "8";
		case '9': return "9";
		}
	}

	void evaluate() {

		for (int i = 0; i < expression.length(); i++)
		{
			if (expression[i] >= '0' && expression[i] <= '9') {
				result.push(get_num(expression[i]));
			}

			else {
				char operation = expression[i];
				if (operation == '+') {
					double right = stod(result.top());
					result.pop();
					double left = stod(result.top());
					result.pop();
					double temp = left + right;
					result.push(to_string(temp));
				}
				else if (operation == '-') {
					double right = stod(result.top());
					result.pop();
					double left = stod(result.top());
					result.pop();
					double temp = left - right;
					result.push(to_string(temp));
				}
				else if (operation == '*') {
					double right = stod(result.top());
					result.pop();
					double left = stod(result.top());
					result.pop();
					double temp = left * right;
					result.push(to_string(temp));
				}
				else if (operation == '/') {
					double right = stod(result.top());
					result.pop();
					double left = stod(result.top());
					result.pop();
					double temp = left / right;
					result.push(to_string(temp));
				}
			}
		}
	}
	string get_top() {
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
