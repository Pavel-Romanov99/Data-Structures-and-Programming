#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

class FileExplorer {
private:
	string currentPath;
	fstream currentFile;
	stack<string> previous;
	stack<string> next;
public:
	void open(string fileName) {

		if (currentFile.is_open())
		{
			currentFile.close();
			previous.push(currentPath);
		}
		currentFile.open(fileName);
		currentPath = fileName;
		more();
	}

	void more() {

		std::string line;
		int linesRead = 0;

		//we read 10 lines from the file
		for (; linesRead < 10 && getline(currentFile, line); linesRead++)
		{
			cout << line << std::endl;
		}

		//if we reach the end of the file
		if (currentFile.eof())
		{
			cout << "EOF Reached" << std::endl;
		}
	}

	void back() {
		next.push(currentPath);
		currentPath = previous.top();
		previous.pop();
		open(currentPath);
		more();
	}

	void forward() {

		previous.push(currentPath);
		currentPath = next.top();
		next.pop();
		open(currentPath);
		more();
	}
};

int main()
{
	FileExplorer a;
	a.open("file.txt");
	a.open("second.txt");
	a.back();
	a.forward();
}
