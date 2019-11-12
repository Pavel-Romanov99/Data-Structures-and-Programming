#include "LinkedList.h"

int main()
{
	LinkedList lst;
	lst.addBeginning(1);
	lst.addBeginning(1);
	lst.addBeginning(1);
	lst.print();
	lst.addAt(5, 2);
	lst.print();
	lst.addEnd(7);
	lst.print();
	lst.removeBiginning();
	lst.removeBiginning();
	lst.print();
	cout << lst.length() << endl;
	lst.addBeginning(4);
	lst.addBeginning(5);
	lst.addBeginning(6);
	lst.print();
	lst.removeAt(2);
	lst.print();
	lst.removeAt(1);
	lst.print();
}