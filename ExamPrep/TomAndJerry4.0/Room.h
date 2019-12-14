#pragma once
#include "Point.h"

class Room
{
private:
	int width;
	int length;

public:
	Point** arr;

	Room() {
		this->width = 0;
		this->length = 0;
		arr = new Point * [length];
	}

	Room(int l, int w) {

		this->width = w;
		this->length = l;

		//initialize the room 
		arr = new Point * [l];
		for (int i = 0; i < l; ++i)
			arr[i] = new Point[w];

	}

	~Room()
	{
		for (int i = 0; i < length; ++i) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	int shortestPath(Point start, Point Jerry);
	void Print();
	void BFS(Point start);
	bool isValid(int row, int col);
};

bool Room::isValid(int row, int col) {

	return (row >= 0) && (row < length) &&
		(col >= 0) && (col < width);
}

void Room::Print()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//works
void Room::BFS(Point start)
{
	queue<Point> queue;
	queue.push(start);
	start.setVisited(true);

	while (!queue.empty()) {

		start = queue.front();
		cout << start << " ";
		queue.pop();

		vector<Point> adj;
		if (isValid(start.getX() + 1, start.getY())) {
			adj.push_back(arr[start.getX() + 1][start.getY()]);
		}

		if (isValid(start.getX(), start.getY() + 1)) {
			adj.push_back(arr[start.getX()][start.getY() + 1]);
		}


		for (int i = 0; i < adj.size(); i++)
		{
			if (!adj[i].getVisited()) {

				adj[i].setVisited(true);
				queue.push(adj[i]);
			}
		}
	}
	cout << endl;
}

//works
int Room::shortestPath(Point start, Point Jerry)
{
	int counter = 0;
	queue<Point> queue;
	queue.push(start);
	start.setVisited(true);

	while (!queue.empty()) {

		start = queue.front();
		counter = start.getDistance();

		if (start.getX() == Jerry.getX() && start.getY() == Jerry.getY()) {
			return counter + 1;
		}

		queue.pop();

		vector<Point> adj;

		//right
		if (isValid(start.getX() + 1, start.getY())) {
			adj.push_back(arr[start.getX() + 1][start.getY()]);
		}

		//down
		if (isValid(start.getX(), start.getY() + 1)) {
			adj.push_back(arr[start.getX()][start.getY() + 1]);
		}

		//left
		if (isValid(start.getX() - 1, start.getY())) {
			adj.push_back(arr[start.getX() - 1][start.getY()]);
		}

		//up
		if (isValid(start.getX(), start.getY() - 1)) {
			adj.push_back(arr[start.getX()][start.getY() - 1]);
		}

		for (int i = 0; i < adj.size(); i++)
		{
			if (!adj[i].getVisited()) {

				adj[i].setVisited(true);
				adj[i].setDistance(start.getDistance() + 1);
				queue.push(adj[i]);
			}
		}

	}
	return -1; // if can't be reached 
}
