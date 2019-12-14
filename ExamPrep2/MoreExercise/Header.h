#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	int index;
};

node* getNewNode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

class BinaryTree
{
public:
	node* root = NULL;
	BinaryTree(int data) {
		root = getNewNode(data);
	}
	node* insertNode(node* root, int data) {
		if (root == NULL) root = getNewNode(data);
		else if (data <= root->data) {
			root->left = insertNode(root->left, data);
		}
		else if (data > root->data) {
			root->right = insertNode(root->right, data);
		}
		return root;
	}
	void inOrder(node* root) {
		if (root == NULL) return;
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}

	//=============
	//Exercises
	int numberElements(node* root);
	int countEvens(node* root);
	int predicate(bool (*p)(int), node* root);
	int getHeight(node* root);
	int countLeaves(node* root);
	int MaxLeaf(node* root);
	void Print(node* root, int indent);
	void SerializeTree(node* root);
	void allLeaves(node* root);
	bool hasPath(node* root, vector<int>& vector, int data);
	void trace(node* root, int data); 
	void index(node* root);
	void getAt(node* root, int index);
};

//1.Number of elements
int BinaryTree::numberElements(node* root) {
	if (root == nullptr) return 0;
	return 1 + numberElements(root->left) + numberElements(root->right);
}

 //2.Number of even elements
int evens = 0;
int BinaryTree::countEvens(node* root) {
	if (root == NULL) return 0;
	else if (root->data % 2 == 0) evens++;
	countEvens(root->left);
	countEvens(root->right);
	return evens;
}

 //3.Number of nodes that return true to predicate p
int result = 0;
int BinaryTree::predicate(bool(*p)(int), node* root) {
	if (root == nullptr) return 0;
	if (p(root->data)) result++;
	predicate(p, root->left);
	predicate(p, root->right);
	return result;
}

bool odd(int x) {
	if (x % 2 == 1) return 1;
	return 0;
}

 //4.Height of a tree
int max1(int a, int b) {
	if (a > b) return a;
	return b;
}

int BinaryTree::getHeight(node* root) {
	if (root == nullptr) return 0;
	return 1 + max1(getHeight(root->left), getHeight(root->right));
}

 //5.Count leaves
int BinaryTree::countLeaves(node* root) {
	if (root == nullptr) return 0;
	return (root->left != NULL && root->right != NULL) + countLeaves(root->left) + countLeaves(root->right);
}

 //6.Biggest Leaf
int maxLeaf = 0;
int BinaryTree::MaxLeaf(node* root) {
	node* current = root;
	while (current->right != nullptr) {
		current = current->right;
	}
	return current->data;
}

 //7.Pretty print
void BinaryTree::Print(node* root, int indent) {
	if (root != nullptr) {
		Print(root->right, indent + 4);
		cout << setw(indent);
		cout << root->data << endl;
		Print(root->left, indent + 4);
	}
}

 //8.Serialize Tree
void BinaryTree::SerializeTree(node* root) {
	if (root == NULL) return;
	cout << " ( ";
	cout << root->data;
	if (root->left == NULL || root->right == NULL) {
		cout << " () ";
	}
	SerializeTree(root->right);
	SerializeTree(root->left);
	cout <<  " ) ";
}

 //9.Return all the leaves of a tree
void BinaryTree::allLeaves(node* root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) {
		cout << root->data << " ";
	}
	allLeaves(root->left);
	allLeaves(root->right);
}


 //10.Return the path to an element
bool BinaryTree::hasPath(node* root, vector<int>& vector, int data) {
	if (root == NULL) return false; //if tree is empty
	vector.push_back(root->data); //push the root data to a vector
	if (root->data == data) return true; //if the root = data return true

	//if data is in either the left or right subtree
	if (hasPath(root->left, vector, data) || hasPath(root->right, vector, data)) return true; 
	
	//if data in not in the left or right subtree of the current node
	vector.pop_back();
	return false;
}

void BinaryTree::trace(node* root, int data) {

	vector<int> path;
	if (hasPath(root, path, data)) {
		for (int i = 0; i < path.size() - 1 ; i++)
		{
			cout << path[i] << "->";
		}
		cout << path[path.size() - 1];
	}
	else cout << "There is no element: " << data << endl;
}


 //11.Get a node via index
vector<int> container;
void BinaryTree::index(node* root) {
	if (root == NULL) return;

	if(root != NULL)
	container.push_back(root->data);

	index(root->left);
	index(root->right);

}

void BinaryTree::getAt(node* root, int index) {
	if (root != NULL)
	{
		this->index(root);
		if (index < container.size())
			cout << container[index] << endl;
		else cout << "Index out of range" << endl;
	}
}