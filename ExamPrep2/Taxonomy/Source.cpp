#include "Header.h"

int main()
{
	Taxonomy t;
	t.addEntity({ "Animalia", "Chordata", "Mammalia", "Primates", "Hominidae", "Homo", "Homo Sapiens" })
	 .addEntity({ "Animalia", "Chordata", "Mammalia", "Grizachi", "Mishka", "Polska Mishka" });

	vector<string> path;
	t.print();
}