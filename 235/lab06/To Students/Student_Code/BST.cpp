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
		parent->left_child = recursiveAdd(parent->left_child, data);
	} else {
		parent->right_child = recursiveAdd(parent->right_child, data);
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
		return find(parent->left_child, data);
	} else {
		return find(parent->right_child, data);
	}
}

/**
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool BST::remove(int data) {
	if (root == NULL) {
		//
		std::cout << data << " not removed, tree is empty." << "\n";
		//
		return false;
	} else if (!find(data)) {
		//
		std::cout << data << " not in tree, remove failed."<< "\n";
		//
		return false;
	} else {
		root = recursiveRemove(root, data);
		//
		std::cout << data << " removed successfully." << "\n";
		//
		return true;
	}
}

Node* BST::recursiveRemove(Node* parent, int data) {
	if (data < parent->data) {
		parent = recursiveRemove(parent->left_child, data);
	} else if (data > parent->data) {
		parent = recursiveRemove(parent->right_child, data);
	} else {
		if (parent->left_child == NULL && parent->right_child == NULL) {
			// Case 1: Node to be deleted is a leaf node
			delete parent;
			parent = NULL;
		} else if (parent->left_child) {
			// Case 2: Node to be deleted has only a left child
			Node* temp = parent;
			parent = parent->left_child;
			delete temp;
		}
	}
	return parent;
}

/**
 * Removes all nodes from the tree, resulting in an empty tree
 */
void BST::clear() {
	return;
}