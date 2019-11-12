#pragma once
#include "Point.h"
#include <queue>
#include <vector>


class Maze {
private:
	queue<Point> queue;
public:
	Point matrix[5][5];

	Maze()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				Point a(i, j, 0);
				matrix[i][j] = a;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void BFS(Point start)
	{
		queue.push(start);
		start.set_visited(true);


		while (!queue.empty()) {

			start = queue.front();
			cout << start << " ";
			queue.pop();

			vector<Point> adj;
			adj.push_back(matrix[start.get_X() + 1][start.get_Y()]);
			adj.push_back(matrix[start.get_X()][start.get_Y() + 1]);

			for (int i = 0; i < adj.size(); i++)
			{
				if (!adj[i].get_visited()) {

					adj[i].set_visited(true);
					queue.push(adj[i]);
				}
			}
		}
		cout << endl;
	}

	bool validPath(Point start, Point end)
	{

		queue.push(start);
		start.set_visited(true);


		while (!queue.empty()) {

			start = queue.front();
			if (start.get_X() == end.get_X() && start.get_Y() == end.get_Y()) {
				return true;
			}

			queue.pop();

			vector<Point> adj;
			adj.push_back(matrix[start.get_X() + 1][start.get_Y()]);
			adj.push_back(matrix[start.get_X()][start.get_Y() + 1]);

			for (int i = 0; i < adj.size(); i++)
			{
				if (!adj[i].get_visited()) {
					adj[i].set_visited(true);
					queue.push(adj[i]);
				}
			}
		}
		return false;
	}
};
