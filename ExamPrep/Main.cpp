#include "Point.h"
#include "Room.h"

int main()
{
	Room c(5, 5);
	
	bool input[5][5] = {
		{0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0},
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			c.arr[i][j].setVisited(input[i][j]);
			c.arr[i][j].setX(i);
			c.arr[i][j].setY(j);
		}
	}

	Point Tom(0, 0, 0);
	Point Jerry(3, 3, 0);

	c.Print();
	cout << c.shortestPath(Tom, Jerry) << endl;

}