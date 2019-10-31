#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TextEditor
{
private:
	queue<char> phrase;
	queue<char> undo;
public:
	void append(string s);
	void del();
	void print(int position);
	void undo1();
	void PrintFull();

};

void TextEditor::append(string s)
{
	undo = phrase;
	for (int i = 0; i < s.length(); i++)
	{
		phrase.push(s[i]);
	}
}

void TextEditor::del() {
	undo = phrase;
	if (!phrase.empty()) {
		phrase.pop();
	}
}

void TextEditor::PrintFull() {
	while (!phrase.empty())
	{
		cout << phrase.front() << " ";
		phrase.pop();
	}
	cout << endl;
}

void TextEditor::undo1() {
	phrase = undo;
}

void TextEditor::print(int position)
{
	for (int i = 0; i < position; i++)
	{
		phrase.pop();
	}
	cout << phrase.front() << endl;

	undo1();
}

int main()
{
	TextEditor a;
	a.append("pavelelcoh");
	a.append("Messi");
	a.undo1();
	a.print(3);
	a.PrintFull();
}
