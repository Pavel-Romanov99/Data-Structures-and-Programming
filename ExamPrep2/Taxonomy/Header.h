#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct node {
	string data;
	vector<node*> children;

	//constructor
	node(std::string name) : data(name) { }

	node* findChild(string name) {

		//iterator to traverse the children of the node
		for (auto it = children.begin(); it != children.end(); ++it)
		{
			//if we find it we return the adress of the found node
			if ((*it)->data == name) {
				return (*it);
			}
		}
		//if we don't find it we return false
		return nullptr;
	}

	bool isLeaf() const {
		return children.empty();
	}
};

class Taxonomy {
private:
	node* root = NULL;
public:

	//default constructor
	Taxonomy() {
		root = new node("Animalia");
	}

	~Taxonomy() {
		delete root;
	}

	//deleting a node
	void deleteNode(node* root) {
		vector<node*> children = root->children;
		delete root;
		for (auto child : children) {
			deleteNode(child);
		}
	}

	Taxonomy& addEntity(vector<string> path) {
		//if the tree is empty or the root is not Animalia
		if (root == NULL || path[0] != root->data) {
			cout << "Cannot add element to the tree" << endl;
			return *this;
		}
		node* currentLevel = root;

		//we traverse the path
		for (auto itr = path.begin() + 1; itr != path.end(); ++itr)
		{
			node* next = currentLevel->findChild(*itr);
			//if we don't find the element we add it to the children of currentLevel
			if (next == nullptr) {
				next = new node(*itr);
				currentLevel->children.push_back(next);
			}
			currentLevel = next;
		}
		return *this;
	}

	void print(node* root, vector<string>& path) const {
		if (root->isLeaf()) {
			for (auto category : path) {
				cout << category << "->";
			}
			cout << root->data;
			return;
		}

		//if root is not a child 
		path.push_back(root->data);
		for (node* child : root->children)
		{
			print(child, path);
		}
		path.pop_back();
	}

	void print() const{
		vector<string> path;
		print(root, path);
	}

};