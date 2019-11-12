#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class MatchingBrackets
{
private:
	stack<char> brackets;
public:
	string expression;
	bool closed = true;

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
					closed = false;
					break;
				}
				brackets.pop();
			}
			else if (expression[i] == ']') {
				if (expression[i] != brackets.top()) {
					closed = false;
					break;
				}
				brackets.pop();
			}
			else if (expression[i] == '}') {
				if (expression[i] != brackets.top()) {
					closed = false;
					break;
				}
				brackets.pop();
			}
		}

		if (!brackets.empty()) {
			closed = false;
		}

		return closed;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<MatchingBrackets> vector;

	for (int i = 0; i < n; i++)
	{
		MatchingBrackets b;
		string expression;
		cin >> expression;
		b.expression = expression;
		vector.push_back(b);
	}

	for (int i = 0; i < n; i++)
	{ 
		if (vector[i].evaluate()) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}
