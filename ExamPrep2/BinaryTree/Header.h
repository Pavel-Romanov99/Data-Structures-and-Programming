#pragma once
#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <vector>
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
	bool sameTrees(node<T>* tree1, node<T>* tree2);
	bool findElement(node<T>* root, T data);
	node<T>* deleteElement(node<T>* root, T data);
	node<T>* findMin(node<T>* root);
	void numbers(BinaryTree<T> a);
	bool checkFull(node<T>* root);
	bool checkBalanced(node<T>* root);
	bool sameStructure(node<T>* tree1, node<T>* tree2);
	void createByPreorder(vector<int> preorder);
	int numberElements(node<T>* root);
	void leaves(node<T>* root);
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

	preOrder(root->left);
	preOrder(root->right);
	cout << root->data << " ";

}

template<typename T>
void BinaryTree<T>::postOrder(node<T>* root) {
	if (root == NULL) return;
	postOrder(root->right);
	cout << root->data << " ";
	postOrder(root->left);

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

//Check whether two trees are the same
template<typename T>
bool BinaryTree<T>::sameTrees(node<T>* tree1, node<T>* tree2) {
	
	if (tree1 == nullptr && tree2 == nullptr) return true; //if both are empty
	if (tree1 != NULL && tree2 != NULL) {
		return tree1->data == tree2->data && sameTrees(tree1->left, tree2->left) &&
			sameTrees(tree1->right, tree2->right);
	}
	return 0; //if one is empty the other is not
}

//check if an element is in the tree
template<typename T>
bool BinaryTree<T>::findElement(node<T>* root, T data) {
	if (root == NULL) return false;
	return data == root->data || findElement(root->left, data)
		|| findElement(root->right, data);
 }

//delete an element from the tree
template <typename T>
node<T>* BinaryTree<T>::findMin(node<T>* root) {
	node<T>* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

template <typename T>
node<T>* BinaryTree<T>::deleteElement(node<T>* root, T data) {
	if (root == NULL) return root; // if tree is empty
	//these two lines fix the tree
	else if (data < root->data) root->left = deleteElement(root->left, data);
	else if (data > root->data) root->right = deleteElement(root->right, data);
	else {
		//we have found the element
		if (root->left == NULL && root->right == NULL) //case 1: no children
		{
			delete root;
			root = NULL;
		}

		//case 2: Only one child
		else if (root->left == NULL) {
			node<T>* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			node<T>* temp = root;
			root = root->left;
			delete temp;
		}

		//case 3: There are two children
		else {
			node<T>* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteElement(root->right, temp->data);
		}
	}
	return root;
}

//exercise on binary tree
template<typename T>
void BinaryTree<T>::numbers(BinaryTree<T> a) {
	int n;
	cout << "How many numbers do you want to insert? ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		a.insertNode(a.root, num);
	}
	a.inOrder(a.root);
	int c;
	cout << "How many numbers do you want to delete? ";
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int num;
		cin >> num;
		a.deleteElement(a.root, num);
	}
	a.inOrder(a.root);
}

//check if a tree is full
template <typename T>
bool BinaryTree<T>::checkFull(node<T>* root) {
	if (root == NULL) return true;
	else if (root->left == NULL && root->right == NULL) return true;
	return root->left != NULL && root->right != NULL &&
		checkFull(root->left) && checkFull(root->right);
}

//check if a tree is balanced
template<typename T>
bool BinaryTree<T>::checkBalanced(node<T>* root) {
	if (root == NULL) return false;
	if (root->left != nullptr && root->right != nullptr) {
		if (height(root->left) == height(root->right) ||
			height(root->left) + 1 == height(root->right) ||
			height(root->left) == height(root->right) + 1)
			return true;
	}
	return false;
}

//check if two trees have the same structure
template<typename T>
bool BinaryTree<T>::sameStructure(node<T>* tree1, node<T>* tree2) {
	if (tree1 == NULL && tree2 == NULL) return true;
	return (tree1 != NULL && tree2 != NULL) && sameStructure(tree1->left, tree2->left)
		&& sameStructure(tree1->right, tree2->right);
}

//build a tree via a string in a preorder format
template<typename T>
void BinaryTree<T>::createByPreorder(vector<int> preorder) {
	int rootData = preorder[preorder.size() - 1];
	BinaryTree a(rootData);
	for (int i = 0; i < preorder.size() - 1; i++)
	{
		a.insertNode(a.root, preorder[i]);
	}
	a.inOrder(a.root);
}

//get number of elements in a tree
template<typename T>
int BinaryTree<T>::numberElements(node<T>* root) {
	if (root == NULL) return 0;
	return (root != NULL) + numberElements(root->left) + 
		numberElements(root->right);
}

//prints the leaves in a tree
template<typename T>
void BinaryTree<T>::leaves(node<T>* root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) {
		cout << root->data << " ";
	}
	leaves(root->left);
	leaves(root->right);
}
