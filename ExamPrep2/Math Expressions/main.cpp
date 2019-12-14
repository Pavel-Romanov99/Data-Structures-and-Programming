
#include "Header.h"

int main()
{
	Math a('+');
	a.root->left = getNode('-');
	a.root->left->left = getNode('3');
	a.root->left->right = getNode('/');
	a.root->left->right->left = getNode('8');
	a.root->left->right->right = getNode('2');
	a.root->right = getNode('5');
	a.Print(a.root, 0);
	cout << "Result = " << a.Evaluate(a.root) << endl;
}
