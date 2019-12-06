#pragma once
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
	BinaryTree();
	BinaryTree(T data);
	node<T>* insertNode(node<T>* root, T data);
	void inOrder(node<T>* root);
	void preOrder(node<T>* root);
	void postOrder(node<T>* root);
	void BFS(node<T>* node);
	void refreshVisited(node<T>* root);
	int height(node<T>* node);
	int minElement(node<T>* node);
	int maxElement(node<T>* node);
	int sumElements(node<T>* node);
	//===================================
	// new functions
	void swapTree(node<T>* tree1, node<T>* tree2);
	node<T>* swapInsert(node<T>* root,T data);
	void addToNodes(node<T>* root, T data);
	void map1(node<T>* root, T(*f) (T));
	int accumulate(node<T>* root, T(*f) (T, T, T), int value);
};

template<typename T>
int BinaryTree<T>::sumElements(node<T>* root) {

	if (root == NULL) return 0;
	return (root->data + sumElements(root->left) + sumElements(root->right));
}

template<typename T>
int BinaryTree<T>::minElement(node<T>* root) {
	if (root == nullptr) return -1;
	node<T>* current = root;
	while (current->left != nullptr) {
		current = current->left;
	}
	return current->data;
}

template<typename T>
int BinaryTree<T>::maxElement(node<T>* root) {
	if (root == nullptr) return -1;
	node<T>* current = root;
	while (current->right != nullptr) {
		current = current->right;
	}
	return current->data;
}

template <typename T>
BinaryTree<T>::BinaryTree() {
	this->root = NULL;
}

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

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

template<typename T>
void BinaryTree<T>::preOrder(node<T>* root) {
	if (root == NULL) return;

	cout << root->data << " ";
	preOrder(root->left);
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

//===================================
//Swap trees
template<typename T>
node<T>* BinaryTree<T>::swapInsert(node<T>* root, T data) {
	if (root == NULL) {
		root = getNewNode(data);
	}
	else if (data >= root->data) {
		root->left = swapInsert(root->left, data);
	}
	else if (data < root->data) {
		root->right = swapInsert(root->right, data);
	}
	return root;
}

template<typename T>
void BinaryTree<T>::swapTree(node<T>* tree1, node<T>* tree2) {
	if (tree1 == NULL)return;

	swapTree(tree1->left, tree2);
	tree2 = swapInsert(tree2, tree1->data);
	swapTree(tree1->right, tree2);
}

//add a number to all nodes
template<typename T>
void BinaryTree<T>::addToNodes(node<T>* root, T data) {
	if (root == NULL) {
		return;
	}
	root->data += data;
	addToNodes(root->left, data);
	addToNodes(root->right, data);
}

//map function to all nodes
int addFive(int x) {
	return x + 5;
}

template<typename T>
void BinaryTree<T>::map1(node<T>* root, T(*f)(T)) {
	if (root == NULL) {
		return;
	}
	root->data = f(root->data);
	map1(root->left, f);
	map1(root->right, f);
}

//Accumulate function
int addition(int x, int y, int z) { return x + y + z; }
int product(int x, int y, int z) { return x * y * z; }

template <typename T>
int BinaryTree<T>::accumulate(node<T>* root, T(*op)(T, T, T), int value) {
	if (root == nullptr) return value;
	return (op(root->data, accumulate(root->right, op, value),
						   accumulate(root->left, op, value)));
}
