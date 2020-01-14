#pragma once
#include "Point.h"
#include "Room.h"

vector<Point> path;
int room_length, room_width;
int JerryX, JerryY;
int TomX, TomY;

Point Tom1(TomX, TomY, 0);
Point Jerry1(JerryX, JerryY, 0);

bool** getMaze(bool** maze, int length, int width)
{
	for (int i = 0; i < length; ++i) {
		maze[i] = new bool[width];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			maze[i][j] = 0;
		}
	}

	return maze;
}

int** getSol(int**& sol, int length, int width) {
	for (int i = 0; i < length; ++i) {
		sol[i] = new int[width];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			sol[i][j] = 0;
		}
	}
	return sol;
}


bool isValidPlace(int x, int y, bool**& maze, int**& sol) {

	if (x >= 0 && x < room_length && y >= 0 && y < room_width && maze[x][y] == 0)
		return true;
	return false;
}

bool solveMaze(int x, int y, bool**& maze, Point T, Point J, int** sol) {

	if (x == J.getX() && y == J.getY()) {       //when (x,y) is the bottom right room
		sol[x][y] = 1;
		return true;
	}

	if (isValidPlace(x, y, maze, sol) == true) {     //check whether (x,y) is valid or not
		sol[x][y] = 1; //set 0, when it is valid place
		if (solveMaze(x + 1, y, maze, T, J, sol) == true) //find path moving to the right
			return true;
		if (solveMaze(x, y + 1, maze, T, J, sol) == true) //find path moving down
			return true;
		sol[x][y] = 0;         //if both are closed, there is no path
		return false;
	}
	return false;
}

bool shortestPath(Point& T, Point& J, bool**& maze, int** sol) {

	if (solveMaze(T.getX(), T.getY(), maze, T, J, sol) == false) {
		cout << "There is no path";
		return false;
	}

	for (int i = 0; i < room_length; i++)
	{
		for (int j = 0; j < room_width; j++)
		{
			if (sol[i][j] == 1)
			{
				Point temp(i, j, 0);
				path.push_back(temp);
			}
		}
	}

	for (int i = 0; i < path.size() - 1; i++)
	{
		cout << path[i] << " -> ";
	}
	cout << path[path.size() - 1];

	return true;
}