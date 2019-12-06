#pragma once
#include <iostream>
#include <queue>
#include <string>
using namespace std;

template <typename T>
struct node
{
	T data;
	node* left;
	node* right;
	bool visited = 0;
	int distance = 1;
};

template <typename T>
node<T>* getNewNode(T data) {
	node<T>* temp = new node<T>();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

template <typename T>
class BinaryTree
{
public:
	node<T>* root = NULL;
	BinaryTree(T data);
	node<T>* insertNode(node<T>* root, T data);

	void inOrder(node<T>* root);
	void preOrder(node<T>* root);
	void postOrder(node<T>* root);
	void BFS(node<T>* node);
	void refreshVisited(node<T>* root);
	int height(node<T>* node);
};

template <typename T>
BinaryTree<T>::BinaryTree<T>(T data) {
	root = getNewNode(data);
}

template<typename T>
node<T>* BinaryTree<T>::insertNode(node<T>* root, T data) {

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

template<typename T>
void BinaryTree<T>::inOrder(node<T>* root) {
	if (root == NULL)return;
	cout << root->data << " ";
	inOrder(root->left);
	inOrder(root->right);
}

template<typename T>
void BinaryTree<T>::preOrder(node<T>* root) {
	if (root == NULL) return;
	preOrder(root->left);
	cout << root->data << " ";
	preOrder(root->right);
}

template<typename T>
void BinaryTree<T>::postOrder(node<T>* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

template<typename T>
void BinaryTree<T>::BFS(node<T>* root) {

	if (root == NULL) {
		cout << "Empty tree" << endl;
	}

	queue<node<T>*> queue;
	queue.push(root);
	root->visited = 1;

	while (!queue.empty()) {
		node<T>* current = queue.front();
		cout << current->data << " ";
		queue.pop();

		if (current->left != NULL) {
			current->left->visited = 1;
			current->left->distance = current->distance + 1;
			queue.push(current->left);
		}
		if (current->right != NULL) {
			current->right->visited = 1;
			current->right->distance = current->distance + 1;
			queue.push(current->right);
		}
	}
	cout << endl;
}

template <typename T>
void BinaryTree<T>::refreshVisited(node<T>* root) {
	if (root == NULL) return;
	root->visited = 0;
	refreshVisited(root->left);
	refreshVisited(root->right);
}

template<typename T>
int BinaryTree<T>::height(node<T>* root) {

	if (root == NULL) {
		return -1;
	}

	int distance = root->distance;
	queue<node<T>*> queue;
	queue.push(root);
	root->visited = 1;

	while (!queue.empty()) {
		node<T>* current = queue.front();
		queue.pop();

		if (current->left != NULL) {
			current->left->visited = 1;
			current->left->distance = current->distance + 1;
			queue.push(current->left);
		}
		if (current->right != NULL) {
			current->right->visited = 1;
			current->right->distance = current->distance + 1;
			queue.push(current->right);
		}
		distance = current->distance;
	}
	return distance;
}