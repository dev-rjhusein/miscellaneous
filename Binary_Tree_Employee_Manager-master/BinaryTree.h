#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

template <class T>
class BinaryTree {
private:
	struct TreeNode {
		T value;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *root; //Points to the root node (the base, the start, the head)

	/* Functions */
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(T, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;

public:
	//Constructor
	BinaryTree() {
		root = nullptr;
	}

	//Destructor
	~BinaryTree() {
		destroySubTree(root);
	}

	//Binary Tree operations
	void insertNode(T);
	bool searchNode(T);
	void remove(T);

	void displayInOrder() const {
		displayInOrder(root);
	}

	void displayPreOrder() const {
		displayPreOrder(root);
	}

	void displayPostOrder() const {
		displayPostOrder(root);
	}

	// Main function needs root pointer access
	TreeNode* getRoot() {
		return root;
	}

	int totalNodeCounter(TreeNode *);		//returns total number of nodes in tree
	int leafNodeCounter(TreeNode *);		//return number of leaves in tree
	int treeHeightCounter(TreeNode *);		//returns number of "levels" in tree
};


/*****************************************************
********* Define the Binary Tree Members *************
*****************************************************/
template <class T>
void BinaryTree<T>::insertNode(T data) {
	TreeNode *newNode = nullptr; //New node pointer

	newNode = new TreeNode; 
	newNode->value = data; // Store num in "value" of the new node
	newNode->left = nullptr;
	newNode->right = nullptr; // the leaves of the new node are null

	//Insert the node
	insert(root, newNode);
}

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode) {	
	if (nodePtr == nullptr) {	
		nodePtr = newNode;		
	}
	else if (newNode->value < (nodePtr->value)) {		//if the new variable is less than the currently viewed variable
		insert(nodePtr->left, newNode);			// then insert it to the left
	}
	else {
		insert(nodePtr->right, newNode);		// otherwise, insert it to the right.
	}	
}

/* Traverse and Display tree content inorder*/
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

/* find if a value exists in the tree (returns T/F) */
template <class T>
bool BinaryTree<T>::searchNode(T data) {
	TreeNode *nodePtr = root; //create a pointer that points at the beginning of the tree

	while (nodePtr) {	// While the beginning exists (tree exists)
		if (nodePtr->value == data) {	//If its the value being searched for, return true;
			cout << nodePtr->value;
			return true;
		}
		else if (data < nodePtr->value) {		//if the value being searched for is less than the value being looked at
			nodePtr = nodePtr->left;		//search the left side of the branch
		}
		else {
			nodePtr = nodePtr->right;		// otherwise search the right side.
		}
	}
	cout << "Data not found.";
	return false;	//is there is not tree, or the end was reached without finding the value, return false
}

/* removes a node via deleteNode function*/
template <class T>
void BinaryTree<T>::remove(T data) {	//assists deleteNode in getting args

	deleteNode(data, root); 
}

/* Deletes a node specified by node's content */
template <class T>
void BinaryTree<T>::deleteNode(T data, TreeNode *&nodePtr) {	//params are the variable wished to be deleted, and pointer to beginning
	
	if (searchNode(data)) {

		if (data < nodePtr->value) {			//If the variable is less than the value pointed to
			deleteNode(data, nodePtr->left);	//then try deleting the one to the left
		}
		else if (data > nodePtr->value) {		//If the variable is more than the value pointer to
			deleteNode(data, nodePtr->right);	//then try deleting the one to the right
		}
		else {
			makeDeletion(nodePtr);			//otherwise, delete the current node pointed to
			cout << "\"" << data << "\" deleted successfully!\n";
		}
	}
	else {
		cout << "\"" << data << "\" doesn't exist in this tree!\n";
	}
}

/* deletes a node */
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr) {

	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr) {
		cout << "Cannot delete an empty node!\n";
	}
	else if (nodePtr->right == nullptr) {	//if only left node exists
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr) {	//if only right node exists
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else {	//if the node has two children
		tempNodePtr = nodePtr->right;

		while (tempNodePtr = nodePtr->left) {
			tempNodePtr = tempNodePtr->left;
		}
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;

		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

/* used by destructor to delete every node in a tree */
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr) {
	if (nodePtr) {	//if tree exists
		if (nodePtr->left) {	//if left half exists
			destroySubTree(nodePtr->left);
		}
		if (nodePtr->right) {	//if right half exists
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;	//Delete the node currently pointed to
	}
}

// Count the nodes in a tree
template <class T>
int BinaryTree<T>::totalNodeCounter(TreeNode *nodePtr) {
	if (nodePtr == nullptr) {	
		return 0;
	}
	else {
		return totalNodeCounter(nodePtr->left) + totalNodeCounter(nodePtr->right) + 1;
	}
}

// Count the leaf nodes in a tree
template <class T>
int BinaryTree<T>::leafNodeCounter(TreeNode *nodePtr) {
	if (nodePtr == nullptr) {
		return 0;
	}
	if (nodePtr->left == nullptr && nodePtr->right == nullptr) {	//both left and right being null means you're on the leaf
		return 1;
	}
	else {
		return leafNodeCounter(nodePtr->right) + leafNodeCounter(nodePtr->left);
	}
}

//Count the number of "levels" in a tree
template<class T>
int BinaryTree<T>::treeHeightCounter(TreeNode *nodePtr) {

	if (nodePtr == nullptr) {	//if tree or current node isn't empty
		return 0;
	}
	int leftCount = treeHeightCounter(nodePtr->left);	//count the left subtree
	int rightCount = treeHeightCounter(nodePtr->right);	//count the right subtree

	//return the highest count 
	if (leftCount > rightCount) {
		return 1 + leftCount;
	}
	else {
		return 1 + rightCount;
	}
}



#endif