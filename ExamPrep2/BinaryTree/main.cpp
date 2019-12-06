#include "Header.h"

int main()
{
	BinaryTree<int> a(5);
	a.insertNode(a.root, 1);
	a.insertNode(a.root, 6);
	a.insertNode(a.root, 8);
	a.insertNode(a.root, 9);
	a.inOrder(a.root);
	cout << endl;
	
	cout << a.accumulate(a.root, product, 1) << endl;
	cout << a.accumulate(a.root, addition, 0) << endl;
}
