#pragma once
#include "Point.h"
#define N 5

vector<Point> path;
Point Tom(0, 0, 0);
Point Jerry(3, 3, 0);

bool maze[N][N] = {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
};

int sol[N][N];   

bool isValidPlace(int x, int y) { 
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0)
		return true;
	return false;
}

bool solveMaze(int x, int y) {

	if (x == Jerry.getX() && y == Jerry.getY()) {       //when (x,y) is the bottom right room
		sol[x][y] = 1;
		return true;
	}

	if (isValidPlace(x, y) == true) {     //check whether (x,y) is valid or not
		sol[x][y] = 1; //set 0, when it is valid place
		if (solveMaze(x + 1, y) == true)       //find path by moving right direction
			return true;
		if (solveMaze(x, y + 1) == true)         //when x direction is blocked, go for bottom direction
			return true;
		sol[x][y] = 0;         //if both are closed, there is no path
		return false;
	}
	return false;
}

bool shortestPath(Point Tom, Point Jerry) {

	if (solveMaze(Tom.getX(), Tom.getY()) == false) {
		cout << "There is no path";
		return false;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
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
