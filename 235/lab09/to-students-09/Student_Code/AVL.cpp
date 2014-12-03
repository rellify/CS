#include "AVL.h"
#include <iostream>

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
	if (find(root, data)) {
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
	} else if (!find(root, data)) {
		cout << data << " not in tree, remove failed."<< endl;
		return false;
	} else {
		root = recursiveRemove(root, data);
		if (!find(root, data)) {
			cout << data << " removed successfully." << endl;
			return true;
		} else {
			cout << data << " not removed successfully." << endl;
			return false;
		}
	}
}

void AVL::print() {
	recursivePrint(root);
}

void AVL::find(int data) {
	if (find(root, data)) {
		cout << data << " found in tree." << endl;
	} else {
		cout << data << " not found in tree." << endl;
	}
}

// private

Node* AVL::recursiveAdd(Node* parent, int data) {
	if (parent == NULL) {
		parent = new Node(data);
	} else if (data < parent->data) {
		parent->left_child = recursiveAdd(parent->left_child, data);
	} else {
		parent->right_child = recursiveAdd(parent->right_child, data);
	}
	parent->height = getMax(getHeight(parent->left_child),
		getHeight(parent->right_child)) + 1;
	int balance = getBalance(parent); 
	// case 1: left left imbalance
	if (balance > 1 && data < parent->left_child->data) {
		parent = rotateRight(parent);
	}
	// case 2: right right imbalance
	if (balance < -1 && data > parent->right_child->data) {
		parent = rotateLeft(parent);
	}
	// case 3: left right imbalance
	if (balance > 1 && data > parent->left_child->data) {
		parent->left_child = rotateLeft(parent->left_child);
		parent = rotateRight(parent);
	}
	// case 4: right left imbalance
	if (balance < -1 && data < parent->right_child->data) {
		parent->right_child = rotateRight(parent->right_child);
		parent = rotateLeft(parent);
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
	return parent;
}

Node* AVL::rotateRight(Node* node) {
	Node* child = node->left_child;
	Node* child_subtree = child->right_child;
	child->right_child = node;
	node->left_child = child_subtree;
	node->height = getMax(getHeight(node->left_child),
		getHeight(node->right_child)) + 1;
	child->height = getMax(getHeight(child->left_child),
		getHeight(child->right_child)) + 1;
	return child;
}

Node* AVL::rotateLeft(Node* node) {
	Node* child = node->right_child;
	Node* child_subtree = child->left_child;
	child->left_child = node;
	node->right_child = child_subtree;
	node->height = getMax(getHeight(node->left_child),
		getHeight(node->right_child)) + 1;
	child->height = getMax(getHeight(child->left_child),
		getHeight(child->right_child)) + 1;
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
		int stuff = getHeight(node->left_child) - getHeight(node->right_child);
		cout << "Node: " << node->data << " , height: " << stuff << "\n";
		return stuff;
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
	if (first > second) {
		return first;
	} else {
		return second;
	}
}

void AVL::recursivePrint(Node* node) {
	if (node != NULL) {
		if (node->left_child != NULL) {
			recursivePrint(node->left_child);
		}
		cout << "Node: " << node->data << ", height: " << node->height << "\n";
		if (node->right_child != NULL) {
			recursivePrint(node->right_child);
		}
	} else {
		cout << "Tree is empty\n";
	}
}

bool AVL::find(Node* parent, int data) {
	if (parent == NULL) {
		return false;
	} else if (data == parent->data) {
		return true;
	} else if (data < parent->data) {
		return find(parent->left_child, data);
	} else {
		return find(parent->right_child, data);
	}
}

void AVL::clear() {
	while (root != NULL) {
		root = recursiveRemove(root, root->data);
	}
}