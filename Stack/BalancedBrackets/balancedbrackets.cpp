#include <iostream>
#include <string>
#include <stack>
using namespace std;

class MatchingBrackets
{
private:
	stack<char> brackets;
public:
	string expression;
	bool evaluate()
	{
		for (int i = 0; i < expression.length(); i++)
		{
			if (expression[i] == '(') {
				brackets.push(')');
			}
			else if (expression[i] == '[') {
				brackets.push(']');
			}
			else if (expression[i] == '{') {
				brackets.push('}');
			}
			else if (expression[i] == ')') {
				if (expression[i] != brackets.top()) {
					return false;
				}
				brackets.pop();
			}
			else if (expression[i] == ']') {
				if (expression[i] != brackets.top()) {
					return false;
				}
				brackets.pop();
			}
			else if (expression[i] == '}') {
				if (expression[i] != brackets.top()) {
					return false;
				}
				brackets.pop();
			}
		}
		return true;
	}
};

int main()
{
	MatchingBrackets a;
	a.expression = "{[()]}";
	cout << a.evaluate() << endl;
}
