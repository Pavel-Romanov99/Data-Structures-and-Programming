#pragma once
#include <iostream>
#include <map>
#include <queue>
#include <iterator>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	int key;
	bool visited = 0;
};

node* getNewNode(int data){
	node* temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

class BinaryTree {
public:
	node* root;
	BinaryTree() {
		this->root = NULL;
		this->root->key = 0;
	}

	BinaryTree(int data) {
		root = getNewNode(data);
	}

	node* insertNode(node* root, int data) {
		if (root == NULL) {
			root = getNewNode(data);
		}
		else if (data <= root->data) {
			root->left = insertNode(root->left, data);
		}
		else if (data > root->data) {
			root->right = insertNode(root->right, data);
		}
		return root;
	}

	void InOrder(node* root) {
		if (root == NULL) return;
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}

	void Levels(node* root) {
		if (root == NULL) return;

		if (root->left != NULL)
		{
			root->left->key = -1 + root->key;
		}
		if (root->right != NULL)
		{
			root->right->key = root->key + 1;
		}

		cout << "(" << root->data << " " << root->key << ") ";
		Levels(root->left);
		Levels(root->right);
	}

	void TopView(node* root) {
		queue<node*> queue;
		map<int, int> map1;

		queue.push(root);

		while (!queue.empty()) {
			node* current = queue.front();
			queue.pop();

			if (map1.find(current->key) == map1.end()) { //cannot find the elem
				map1.insert(std::pair<int, int> (current->key, current->data));
			}

			if (current->left != NULL) {	
				queue.push(current->left);
			}
			if (current->right != NULL) {
				queue.push(current->right);
			}
		}

		map<int, int>::iterator itr;
		for (itr = map1.begin(); itr != map1.end(); ++itr) {
			cout << itr->second << " ";
		}
	}

	int getHeight(node* root) {
		if (root == NULL) return 0;
		return 1 + max(getHeight(root->left), getHeight(root->right));
	}

};
