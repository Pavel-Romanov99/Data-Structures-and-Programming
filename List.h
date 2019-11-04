#pragma once
#include "Monome.h";

struct node {
	node* next;
	Monom monom;
};

class Polinome {
public:
	node* head = NULL;
public:
	void add(Monom& a);
	void print();
	double calculatePoint(double x);
	double polinomeSum( Polinome& b, double x);
	double polinomeProduct( Polinome& b, double x);

	Polinome operator+(Polinome& other) {
		Polinome result;
		node* temp1 = this->head;

		while (temp1 != NULL) {
			node* temp2 = other.head;
			while (temp2 != NULL)
			{
				if (temp1->monom.coefficient == temp2->monom.coefficient) {
					Monom temp;
					temp.coefficient = temp1->monom.coefficient;
					temp.power = temp1->monom.power + temp2->monom.power;
					result.add(temp);
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
		return result;
	}

	Polinome operator*(Polinome &other) {
		Polinome result;
		node* temp1 = this->head;

		while (temp1 != NULL) {
			node* temp2 = other.head;
			while (temp2 != NULL)
			{
					Monom temp;
					temp.coefficient = temp1->monom.coefficient * temp2->monom.coefficient;
					temp.power = temp1->monom.power + temp2->monom.power;
					result.add(temp);
					temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
		return result;
	}
};

void Polinome::add(Monom& a) {

	node* temp = new node();
	temp->next = head;
	temp->monom = a;
	head = temp;
}

void Polinome::print() {
	node* temp = head;
	
	while (temp != NULL)
	{
		temp->monom.print_monom();
		temp = temp->next;
	}
}

double Polinome::calculatePoint(double x) {
	int sum = 0;
	node *temp = head;

	while (temp != NULL) {
		sum += temp->monom.calculate(x);
		temp = temp->next;
	}
	return sum;
}

double Polinome::polinomeSum(Polinome& b, double x) {
	return this->calculatePoint(x) + b.calculatePoint(x);
}

double Polinome::polinomeProduct(Polinome& b, double x) {
	return this->calculatePoint(x) * b.calculatePoint(x);
}
