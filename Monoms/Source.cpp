#include "Monome.h"
#include "List.h"

int main()
{
	//monomes
	Monom a(3, 1);
	Monom b(2, 1);

	//polinome 1
	Polinome list1;
	list1.add(a);
	list1.add(b);

	//polinome 2
	Polinome list2;
	list2.add(a);
	list2.add(b);

	Polinome result = list1 * list2;
	result.print();
	cout << endl;
	cout << result.calculatePoint(2) << endl;
}
