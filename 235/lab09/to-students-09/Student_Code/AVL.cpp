#include "AVL.h"
#include <iostream>

// ----------------------------------------------------------------------------
// public ---------------------------------------------------------------------
// ----------------------------------------------------------------------------

AVL::AVL() {
	root = NULL;
}

AVL::~AVL() {
	clear();
}

NodeInterface* AVL::getRootNode() {
	return root;
}

bool AVL::add(int data) {
	if (recursiveFind(root, data)) {
		cout << data << " not added, already exists." << endl;
		return false;
	}
	root = recursiveAdd(root, data);
	cout << data << " added successfully." << endl;
	return true;
}

bool AVL::remove(int data) {
	if (root == NULL) {
		cout << data << " tree is empty, remove failed." << endl;
		return false;
	} else if (!recursiveFind(root, data)) {
		cout << data << " not in tree, remove failed."<< endl;
		return false;
	} else {
		root = recursiveRemove(root, data);
		if (!recursiveFind(root, data)) {
			cout << data << " removed successfully." << endl;
			return true;
		} else {
			cout << data << " not removed successfully." << endl;
			return false;
		}
	}
}

void AVL::find(int data) {
	if (recursiveFind(root, data)) {
		cout << data << " found in tree." << endl;
	} else {
		cout << data << " not found in tree." << endl;
	}
}

void AVL::preOrderPrint() {
	recursivePreOrderPrint(root);
	cout << "\n";
}

// ----------------------------------------------------------------------------
// private --------------------------------------------------------------------
// ----------------------------------------------------------------------------

Node* AVL::recursiveAdd(Node* parent, int data) {
	if (parent == NULL) {
		parent = new Node(data);
	} else if (data < parent->data) {
		parent->left_child = recursiveAdd(parent->left_child, data);
	} else {
		parent->right_child = recursiveAdd(parent->right_child, data);
	}
	setHeight(parent);
	int balance = getBalance(parent);
	if (balance == -2) {
		// right imbalance
		if (data > parent->right_child->data) {
			// right right imbalance (or ambiguous)
			return rotateLeft(parent);
		} else {
			// right left imbalance
			parent->right_child = rotateRight(parent->right_child);
			return rotateLeft(parent);
		}
	} else if (balance == 2) {
		// left imbalance
		if (data < parent->left_child->data) {
			// left left imbalance (or ambiguous)
			return rotateRight(parent);
		} else {
			// left right imbalance
			parent->left_child = rotateLeft(parent->left_child);
			return rotateRight(parent);
		}
	}
	return parent;
}

Node* AVL::recursiveRemove(Node* parent, int data) {
	if (data < parent->data) {
		parent->left_child = recursiveRemove(parent->left_child, data);
	} else if (data > parent->data) {
		parent->right_child = recursiveRemove(parent->right_child, data);
	} else {
		if (parent->left_child != NULL) {
			// case 1: has left child
			parent->left_child = replaceIOP(parent->left_child, parent);
		} else {
			// case 2: no left child
			Node* temp = parent;
			parent = parent->right_child;
			delete temp;
		}
	}
	if (parent == NULL) {
		return parent;
	}
	setHeight(parent);
	int balance = getBalance(parent);
	// right imbalance
	if (balance == -2) {
		// right right imbalance (or ambiguous)
		if (getBalance(parent->right_child) <= 0) {
			parent = rotateLeft(parent);
		// right left imbalance
		} else {
			parent->right_child = rotateRight(parent->right_child);
			parent = rotateLeft(parent);
		}
	}
	// left imbalance
	if (balance == 2) {
		// left left imbalance (or ambiguous)
		if (getBalance(parent->left_child) >= 0) {
			parent = rotateRight(parent);
		// left right imbalance 
		} else {
			parent->left_child = rotateLeft(parent->left_child);
			parent = rotateRight(parent);
		}
	}
	return parent;
}

Node* AVL::rotateRight(Node* node) {
	// // save nodes
	// Node* child = node->left_child;
	// Node* child_subtree = child->right_child;
	// // rotate
	// child->right_child = node;
	// node->left_child = child_subtree;
	// // update heights
	
	Node* child = node->left_child;
	node->left_child = child->right_child;
	child->right_child = node;
	setHeight(node);
	setHeight(child);
	return child;
}

Node* AVL::rotateLeft(Node* node) {
	// // save nodes
	// Node* child = node->right_child;
	// Node* child_subtree = child->left_child;
	// // rotate
	// child->left_child = node;
	// node->right_child = child_subtree;
	// // update heights

	Node* child = node->right_child;
	node->right_child = child->left_child;
	child->left_child = node;
	setHeight(node);
	setHeight(child);
	return child;
}

Node* AVL::replaceIOP(Node* current, Node* parent) {
	if (current->right_child != NULL) {
		current->right_child = replaceIOP(current->right_child, parent);
		return current;
	}
	Node* temp = current->left_child;
	parent->data = current->data;
	delete current;
	return temp;
}

int AVL::getBalance(Node* node) {
	if (node == NULL) {
		return 0;
	} else {
		return getHeight(node->left_child) - getHeight(node->right_child);
	}
}

int AVL::getHeight(Node* node) {
	if (node == NULL) {
		return -1;
	} else {
		return node->height;
	}
}

int AVL::getMax(int first, int second) {
	return (first > second) ? first : second;
}

void AVL::setHeight(Node* node) {
	node->height = getMax(getHeight(node->left_child),
		getHeight(node->right_child)) + 1;
}

bool AVL::recursiveFind(Node* parent, int data) {
	if (parent == NULL) {
		return false;
	} else if (data == parent->data) {
		return true;
	} else if (data < parent->data) {
		return recursiveFind(parent->left_child, data);
	} else {
		return recursiveFind(parent->right_child, data);
	}
}

void AVL::recursivePreOrderPrint(Node* root) {
	if (root != NULL) {
		cout << "Node: " << root->data << ", height: "
			<< (root->height) << "\n";
		recursivePreOrderPrint(root->left_child);
		recursivePreOrderPrint(root->right_child);
	}
}

void AVL::clear() {
	while (root != NULL) {
		root = recursiveRemove(root, root->data);
	}
}