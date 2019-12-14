#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

struct node {
	char data;
	node* left;
	node* right;

	bool isLeaf() {
		if (this->left == NULL && this->right == NULL) {
			return true;
		}
		return false;
	}
};

node* getNode(char data) {
	node* temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

class Math {
public:
	node* root;
	Math(char data);
	void Print(node* root, int indent);
	int Evaluate(node* root);
};

Math::Math(char data) {
	root = getNode(data);
}

void Math::Print(node* root, int indent) {

	if (root != nullptr) {
		Print(root->right, indent + 4);
		cout << setw(indent);
		cout << root->data << endl;
		Print(root->left, indent + 4);
	}
}

int Math::Evaluate(node* root) {
	if (root == NULL) return 0;
	if (!root->isLeaf()) {
		switch (root->data) {
		case '+': return Evaluate(root->left) + Evaluate(root->right);
		case '-': return Evaluate(root->left) - Evaluate(root->right);
		case '*': return Evaluate(root->left) * Evaluate(root->right);
		case '/': return Evaluate(root->left) / Evaluate(root->right);
		}
	}
	else {
		return root->data - '0';
	}
}