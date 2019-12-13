#include "TopView.h"

int main()
{
	BinaryTree a(9);
	a.insertNode(a.root, 11);
	a.insertNode(a.root, 5);
	a.insertNode(a.root, 6);
	a.insertNode(a.root, 7);
	a.insertNode(a.root, 8);
	cout << a.getHeight(a.root);
}