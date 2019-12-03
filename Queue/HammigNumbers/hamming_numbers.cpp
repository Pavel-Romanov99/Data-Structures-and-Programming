#include <iostream>
#include <queue>
#include <cmath>
using namespace std;



int main()
{
	queue<int> q2;
	queue<int> q3;
	queue<int> q5;

	int n;
	cin >> n;


	cout << "1";
	q2.push(2);
	q3.push(3);
	q5.push(5);

	for (int i = 0; i < n; i++)
	{
		int temp = min(q2.front(), min(q3.front(), q5.front()));
		q2.push(temp * 2);
		q3.push(temp * 3);
		q5.push(temp * 5);

		if ((q2.front() < q3.front() && q2.front() < q5.front()) || 
			(q2.front() == q3.front() && q2.front() < q5.front()) ||
			(q2.front() == q5.front() && q2.front() < q3.front()) ||
			(q2.front() == q3.front() && q2.front() == q5.front())
			) {
			if (q2.front() == q3.front()) {
				q2.pop();
				q3.pop();
			}
			else if (q2.front() == q5.front()) {
				q2.pop();
				q5.pop();
			}
			else if (q2.front() == q3.front() && q2.front() == q5.front())
			{
				q2.pop();
				q3.pop();
				q5.pop();
			}
			else {
				q2.pop();
			}
		}
		else if ((q3.front() < q2.front() && q3.front() < q5.front()) ||
			(q3.front() == q2.front() && q3.front() < q5.front()) ||
			(q3.front() == q5.front() && q3.front() < q2.front()) ||
			(q3.front() == q2.front() && q3.front() == q5.front())
			) {
			if (q3.front() == q2.front()) {
				q2.pop();
				q3.pop();
			}
			else if (q3.front() == q5.front()) {
				q3.pop();
				q5.pop();
			}
			else if (q2.front() == q3.front() && q2.front() == q5.front())
			{
				q2.pop();
				q3.pop();
				q5.pop();
			}
			else {
				q3.pop();
			}
		}
		else if ((q5.front() < q3.front() && q5.front() < q2.front()) ||
			(q5.front() == q2.front() && q5.front() < q3.front()) ||
			(q5.front() == q3.front() && q5.front() < q2.front()) ||
			(q5.front() == q3.front() && q5.front() == q2.front())
			) {
			if (q5.front() == q3.front()) {
				q5.pop();
				q3.pop();
			}
			else if (q2.front() == q5.front()) {
				q2.pop();
				q5.pop();
			}
			else if (q2.front() == q3.front() && q2.front() == q5.front())
			{
				q2.pop();
				q3.pop();
				q5.pop();
			}
			else {
				q5.pop();
			}
		}
		cout << temp << " ";

	}
}
