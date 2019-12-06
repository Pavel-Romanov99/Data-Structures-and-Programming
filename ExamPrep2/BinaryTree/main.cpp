#include "Header.h"

int main()
{
	BinaryTree<int> a(5);
	a.insertNode(a.root,1);
	a.insertNode(a.root,6);
	a.insertNode(a.root, 8);
	a.insertNode(a.root, 9);
	cout << endl;
	cout << a.height(a.root) << endl;
}
