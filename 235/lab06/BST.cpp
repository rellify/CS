#include "BST.h"

BST::BST() {
	root = NULL;
}
BST::~BST() {
	clear();
}

/**
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface* BST::getRootNode() {
	return root;
}

/**
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool BST::add(int data) {
	if (find(root, data)) {
		//
		std::cout << data << " not added, already exists." << "\n";
		//
		return false;
	}
	root = recursiveAdd(root, data);
	//
	std::cout << data << " added successfully." << "\n";
	//
	return true;
}

Node* BST::recursiveAdd(Node* parent, int data) {
	if (parent == NULL) {
		Node* newNode = new Node(data);
		parent = newNode;
	} else if (data < parent->data) {
		parent->leftChild = recursiveAdd(parent->leftChild, data);
	} else {
		parent->rightChild = recursiveAdd(parent->rightChild, data);
	}
	return parent;
}

bool BST::find(int data) {
	return find(root, data);
}

bool BST::find(Node* parent, int data) {
	if (parent == NULL) {
		return false;
	} else if (parent->data == data) {
		return true;
	} else if (data < parent->data) {
		return find(parent->leftChild, data);
	} else {
		return find(parent->rightChild, data);
	}
}

/**
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool BST::remove(int data) {
	return true;
}

/**
 * Removes all nodes from the tree, resulting in an empty tree
 */
void BST::clear() {
	return;
}