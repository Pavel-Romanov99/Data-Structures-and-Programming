#include "Header.h"

int main()
{
	BinaryTree a(10);
	a.insertNode(a.root, 5);
	a.insertNode(a.root, 20);
	a.insertNode(a.root, 15);
	a.insertNode(a.root, 25);

	cout << endl;
	a.Print(a.root, 0);

	cout << endl;
	
	a.getAt(a.root, 5);
}