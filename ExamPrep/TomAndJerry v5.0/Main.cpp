
#include "Room.h"

//const int WIDTH = 5;
//const int HEIGHT = 5;
//
//void check(int x, int y, int dest_x, int dest_y,
//	int(&maze)[HEIGHT][WIDTH], std::string& path) 
//{
//	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || !maze[y][x]) {
//		return;
//	}
//	int len = path.size();
//	path += (char)('0' + x);
//	path += ',';
//	path += (char)('0' + y);
//
//	if (x == dest_x && y == dest_y && path.length() == 7*6 + 3) {
//		std::cout << path << "\n";
//	}
//	else {
//		path += " -> ";
//		maze[y][x] = 0;
//		check(x + 0, y - 1, dest_x, dest_y, maze, path);
//		check(x + 0, y + 1, dest_x, dest_y, maze, path);
//		check(x - 1, y + 0, dest_x, dest_y, maze, path);
//		check(x + 1, y + 0, dest_x, dest_y, maze, path);
//		maze[y][x] = 1;
//	}
//	path.resize(len);
//}

int main()
{
	Room a;
	RunProgram();
}