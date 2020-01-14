#pragma once
#include "Point.h"

void check(int TomX, int TomY, int JerryX, int JerryY,
	bool** &maze, std::string& path, int &level, int &width, int &height)
{
	if (TomX < 0 || TomY < 0 || TomX >= width || TomY >= height || !maze[TomY][TomX]) {
		return;
	}

	int len = path.size();
	path += (char)('0' + TomX);
	path += ',';
	path += (char)('0' + TomY);

	if (TomX == JerryX && TomY == JerryY && path.length() == 7 * level + 3) {
		std::cout << path << "\n";
	}
	else {
		path += " -> ";
		maze[TomY][TomX] = 0;
		check(TomX + 0, TomY - 1, JerryX, JerryY, maze, path, level, width, height);
		check(TomX + 0, TomY + 1, JerryX, JerryY, maze, path, level, width, height);
		check(TomX - 1, TomY + 0, JerryX, JerryY, maze, path, level, width, height);
		check(TomX + 1, TomY + 0, JerryX, JerryY, maze, path, level, width, height);
		maze[TomY][TomX] = 1;
	}
	path.resize(len);
}

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
	bool isValid(int row, int col);
};

//if a point is in the room 
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
int Room::shortestPath(Point start, Point Jerry)
{
	int counter = 0;
	queue<Point> queue;
	queue.push(start);
	start.setVisited(true);

	while (!queue.empty()) {

		start = queue.front();
		counter = start.getDistance();

		//if we have reached Jerry return the distance
		if (start.getX() == Jerry.getX() && start.getY() == Jerry.getY()) {
			return counter + 1;
		}

		queue.pop();

		vector<Point> adj;

		//right
		if (isValid(start.getX() + 1, start.getY()) && arr[start.getX() + 1][start.getY()].getVisited() == false) {
			adj.push_back(arr[start.getX() + 1][start.getY()]);
			arr[start.getX() + 1][start.getY()].setVisited(true);
			arr[start.getX() + 1][start.getY()].setDistance(start.getDistance() + 1);

		}

		//down
		if (isValid(start.getX(), start.getY() + 1) && arr[start.getX()][start.getY()+1].getVisited() == false) {
			adj.push_back(arr[start.getX()][start.getY() + 1]);
			arr[start.getX()][start.getY() + 1].setVisited(true);
			arr[start.getX()][start.getY() + 1].setDistance(start.getDistance() + 1);

		}

		//left
		if (isValid(start.getX() - 1, start.getY()) && arr[start.getX() - 1][start.getY()].getVisited() == false) {
			adj.push_back(arr[start.getX() - 1][start.getY()]);
			arr[start.getX() - 1][start.getY()].setVisited(true);
			arr[start.getX() - 1][start.getY()].setDistance(start.getDistance() + 1);
		}

		//up
		if (isValid(start.getX(), start.getY() - 1) && arr[start.getX()][start.getY() - 1].getVisited() == false) {
			adj.push_back(arr[start.getX()][start.getY() - 1]);
			arr[start.getX()][start.getY() - 1].setVisited(true);
			arr[start.getX()][start.getY() - 1].setDistance(start.getDistance() + 1);
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

void RunProgram()
{
	//input WORKING
	int furniture, paint, paintX, paintY, num1, num2, startX, startY, TomX, TomY, JerryX, JerryY, length, width;
	int counter = 1;
	int y = 0;
	int line = 1;
	string inputs;
	ifstream file("input.txt");
	vector<Point> painted_spots;

	//legth and width of the room
	while (file >> num1 >> num2) {
		if (counter == 1) {
			length = num1;
			width = num2;
		}
		break;
	}

	//create a maze
	bool** maze1 = new bool* [length];
	maze1 = getMaze(maze1, length, width);

	counter = 2;
	while (file >> num1 >> num2)
	{
		//read Tom coordinates
		if (counter == 2) {
			TomX = num1;
			TomY = num2;
		}
		//read Jerry coordinates
		else if (counter == 3) {
			JerryX = num1;
			JerryY = num2;
		}
		//read number of furniture and paint dropped
		else if (counter == 4) {
			furniture = num1;
			paint = num2;
		}

		//read furniture location and put it in the array
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
		//read paint dropped coordinates
		else if (counter == 6) {
			while (paint > 0) {

				paintX = num1;
				paintY = num2;
				file >> num1 >> num2;
				Point a(paintX, paintY, 0);
				painted_spots.push_back(a);
				paint--;
			}
		}
		counter++;
	}

	//display the maze
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << maze1[i][j] << " ";
		}
		std::cout << endl;
	}

	//cout << paintX << " " << paintY << endl;
	Room room(length, width);

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			room.arr[i][j].setVisited(maze1[i][j]);
			room.arr[i][j].setX(i);
			room.arr[i][j].setY(j);
		}
	}

	Point Tom(TomX, TomY, 0);
	Point Jerry(JerryX, JerryY, 0);
	int level;

	if (room.arr[TomX][TomY].getVisited() == 1 || room.arr[JerryX][JerryY].getVisited() == 1) {
		cout << "Invalid Locations for Tom or Jerry" << endl;
		return;
	}
	else {
		level = room.shortestPath(Tom, Jerry);
		std::cout << "Shortest Path from Tom to Jerry is: " << level << endl;
		std::cout << endl;
	}
	
	//maze for the shortest paths
	level--; // for the path size
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (maze1[i][j] == 1) maze1[i][j] = 0;
			else maze1[i][j] = 1;
		}
	}

	string path;
	cout << "The shortest paths from Tom to Jerry are: "<< endl;
	check(TomX,  TomY,  JerryX,  JerryY, maze1, path,  level, width, length);
	cout << endl;

	cout << "Painted spots are: " << endl;
	for (int i = 0; i < painted_spots.size(); i++)
	{
		cout << painted_spots[i] << " ";
	}
}

