#pragma once
#include <iostream>
using namespace std;

struct Monom
{
	int power;
	double coefficient;

	Monom() {
		this->power = 0;
		this->coefficient = 0;
	}

	Monom(int coef, int pow) {
		this->power = pow;
		this->coefficient = coef;
	}

	int get_power() {
		return this->power;
	}

	double get_coef() {
		return this->coefficient;
	}

	double calculate(double x) {
		return coefficient * (pow(x, power));
	}

	void print_monom() {
		cout <<  power << "* x^" << coefficient << " + ";
	}
};
