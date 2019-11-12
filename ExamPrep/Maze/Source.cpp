#include "Point.h"
#include "Maze.h"

int main()
{
	Maze b;
	Point start(0, 0, 0);
	Point end(4, 4, 0);

	bool input[5][5] = {
		{0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 0, 0},
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			b.matrix[i][j].set_visited(input[i][j]);
		}
	}

	b.BFS(start);
	cout << b.validPath(start, end) << endl;
}