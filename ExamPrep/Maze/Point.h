#pragma once
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Point {
private:
	int x;
	int y;
	bool visited;
public:
	Point() {
		this->x = 0;
		this->y = 0;
		this->visited = 0;
	}

	Point(int x, int y, bool visited) {
		this->x = x;
		this->y = y;
		this->visited = 0;

	}

	friend ostream& operator<<(ostream& os, const Point& other) {
		cout << "(" << other.x << " , " << other.y << ")";
		return os;
	}
	
	int get_X() {
		return x;
	}

	int get_Y() {
		return y;
	}

	bool get_visited() {
		return visited;
	}

	void set_visited(bool visited) {
		this->visited = visited;
	}
};
