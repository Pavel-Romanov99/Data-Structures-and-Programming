
#include "shortestPath.h"

int main()
{
	//input WORKING
	
	int furniture, paint;

	int paintX, paintY;
	int counter = 1;
	ifstream file("input.txt");
	int num1, num2;
	int line = 1;
	int startX, startY;
	string inputs;
	int y = 0;

	while (file >> num1 >> num2) {
		if (counter == 1) {
			room_length = num1;
			room_width = num2;
		}
		break;
	}

	bool** maze1 = new bool* [room_length];
	maze1 = getMaze(maze1, room_length, room_width);


	int** sol = new int* [room_length];
	sol = getSol(sol, room_length, room_width);

	counter = 2;
	while (file >> num1 >> num2)
	{
	     if (counter == 2) {
			TomX = num1;
			TomY = num2;
		}

		else if (counter == 3) {
			JerryX = num1;
			JerryY = num2;
		}

		else if (counter == 4) {
			furniture = num1;
			paint = num2;
		}

		else if (counter == 5) {

			while (!file.eof())
			{
				if (line == 1)
				{
					startX = num1;
					startY = num2;
				}

				else
				{
					vector<char> vector;
					file >> inputs;
					for (int i = 0; i < inputs.length(); i++)
					{
						vector.push_back(inputs[i]);
						if (vector[i] == '.') {
							maze1[startX + y][startY + i] = 0;
						}

						else if (vector[i] == '1')
						{
							maze1[startX + y][startY + i] = 1;
						}

						else if (vector[i] == '=') {

							furniture--;
							line = 0;
							y = -1;
							break;
						}
					}
					y++;
				}
				line++;
				if (furniture == 0) {
					break;
				}
			}

		}

		else if (counter == 6) {
			file >> num1 >> num2;
			paintX = num1;
			paintY = num2;
		}

		counter++;
	}

	for (int i = 0; i < room_length; i++)
	{
		for (int j = 0; j < room_width; j++)
		{
			std::cout << maze1[i][j] << " ";
		}
		std::cout << endl;
	}

	cout << paintX << " " << paintY << endl;

	Room room(room_length, room_width);

	for (int i = 0; i < room_length; i++)
	{
		for (int j = 0; j < room_width; j++)
		{
			room.arr[i][j].setVisited(maze1[i][j]);
			room.arr[i][j].setX(i);
			room.arr[i][j].setY(j);
		}
	}

	Point Tom(TomX, TomY, 0);
	Point Jerry(JerryX, JerryY, 0);

	if (maze1[TomX][TomY] == 1 || maze1[JerryX][JerryY] == 1) {
		cout << "Invalid Locations for Tom or Jerry" << endl;
	}
	else {
		std::cout << "Shortest Path from Tom to Jerry is: " << room.shortestPath(Tom, Jerry) << endl;
		shortestPath(Tom, Jerry, maze1, sol);
		std::cout << endl;
	}


}