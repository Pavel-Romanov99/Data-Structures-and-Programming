#include "Point.h"
#include "Room.h"
#include "shortestPath.h"

int main()
{
	//input WORKING
	//int room_length, room_width;
	//int JerryX, JerryY;
	//int TomX, TomY;
	//int furniture, paint;

	//bool maze[5][5] = {
	//	{0, 0, 0, 0, 1},
	//	{1, 0, 1, 0, 1},
	//	{1, 0, 1, 0, 1},
	//	{1, 0, 1, 0, 1},
	//	{1, 0, 1, 0, 0},
	//};

	//int counter = 1;
	//ifstream file("input.txt");
	//int num1, num2;
	//while (file >> num1 >> num2)
	//{
	//	if (counter == 1) {
	//		room_length = num1;
	//		room_width = num2;
	//	}

	//	else if (counter == 2) {
	//		TomX = num1;
	//		TomY = num2;
	//	}

	//	else if (counter == 3) {
	//		JerryX = num1;
	//		JerryY = num2;
	//	}

	//	else if (counter == 4) {
	//		furniture = num1;
	//		paint = num2;
	//	}
	//	counter++;
	//}

	//Room room(room_length, room_width);

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		room.arr[i][j].setVisited(maze[i][j]);
	//		room.arr[i][j].setX(i);
	//		room.arr[i][j].setY(j);
	//	}
	//}

	//Point Tom(TomX, TomY, 0);
	//Point Jerry(JerryX, JerryY, 0);

	//cout << "Shortest Path from Tom to Jerry is: " << room.shortestPath(Tom, Jerry) << endl;
	//shortestPath(Tom, Jerry);
	//cout << endl;

	//======================================================
	//TESTING FURNITURE - WORKING
	//NEED TO COMBINE THE UPPER CODE WITH THIS ONE

	//int arr[3][3] = {
	//	{0,0,0},
	//	{0,0,0},
	//	{0,0,0},
	//};

	//int line = 1;
	//fstream files("test.txt");
	//int startX, startY;
	//string inputs;
	//int y = 0;
	//int n1, n2;

	//while (!files.eof())
	//{
	//	if (line == 1)
	//	{
	//		files >> n1 >> n2;
	//		startX = n1;
	//		startY = n2;
	//	}
	//	else 
	//	{
	//		vector<char> vector;
	//		files >> inputs;
	//		for (int i = 0; i < inputs.length(); i++)
	//		{
	//			vector.push_back(inputs[i]);
	//			if (vector[i] == '.') {
	//				arr[startX + y][startY + i] = 0;
	//			}

	//			else if (vector[i] == '1')
	//			{
	//				arr[startX + y][startY + i] = 1;
	//			}

	//			else if (vector[i] == '=') {

	//				line = 0;
	//				y = -1;
	//				break;
	//			}
	//		}
	//		y++;
	//	}
	//	line++;
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int  j = 0; j < 3; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}


//=====================================================

	//input WORKING
	int room_length, room_width;
	int JerryX, JerryY;
	int TomX, TomY;
	int furniture, paint;

	int paintX, paintY;
	int counter = 1;
	ifstream file("input.txt");
	int num1, num2;
	int line = 1;
	int startX, startY;
	string inputs;
	int y = 0;

	while (file >> num1 >> num2)
	{
		if (counter == 1) {
			room_length = num1;
			room_width = num2;
		}

		else if (counter == 2) {
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

			while(!file.eof())
			{
				if (line == 1)
				{
					file >> num1 >> num2;
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
							maze[startX + y][startY + i] = 0;
						}

						else if (vector[i] == '1')
						{
							maze[startX + y][startY + i] = 1;
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

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	cout << paintX << " " << paintY << endl;

	Room room(room_length, room_width);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			room.arr[i][j].setVisited(maze[i][j]);
			room.arr[i][j].setX(i);
			room.arr[i][j].setY(j);
		}
	}

	Point Tom(TomX, TomY, 0);
	Point Jerry(JerryX, JerryY, 0);

	cout << "Shortest Path from Tom to Jerry is: " << room.shortestPath(Tom, Jerry) << endl;
	shortestPath(Tom, Jerry);
	cout << endl;
}
