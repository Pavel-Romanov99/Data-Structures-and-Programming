#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;


class Point
{
private:
	int x;
	int y;
	bool visited;
	int distance = 0;

public:
	Point(int x, int y, bool visited) {
		this->x = x;
		this->y = y;
		this->visited = visited;
	}

	Point() {
		this->x = 0;
		this->y = 0;
		this->visited = 0;
	}

	friend ostream& operator<<(ostream& s, Point& other) {
		cout  << "(" <<  other.getX() << "," << other.getY() << ")";
		return s;
	}

	bool getVisited();
	void setVisited(bool visited);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	bool operator==(Point& other);
	void setDistance(int dist);
	int getDistance();
};

void Point::setDistance(int dist) {
	this->distance = dist;
}

int Point::getDistance() {
	return distance;
}

bool Point::operator==(Point& other) {
	if (this->x == other.getX() && this->y == other.getY()) {
		return true;
	}
	return false;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

bool Point::getVisited() {
	return visited;
}

void Point::setVisited(bool visited) {
	this->visited = visited;
}