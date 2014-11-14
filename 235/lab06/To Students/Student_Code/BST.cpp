#include "BST.h"

BST::BST() {
	root = NULL;
}

BST::~BST() {
	clear();
}

NodeInterface* BST::getRootNode() {
	return root;
}

bool BST::add(int data) {
	if (find(root, data)) {
		std::cout << data << " not added, already exists." << "\n";
		return false;
	}
	root = recursiveAdd(root, data);
	std::cout << data << " added successfully." << "\n";
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
	} else if (data == parent->data) {
		return true;
	} else if (data < parent->data) {
		return find(parent->left_child, data);
	} else {
		return find(parent->right_child, data);
	}
}

bool BST::remove(int data) {
	if (root == NULL) {
		std::cout << data << " tree is empty, remove failed." << "\n";
		return false;
	} else if (!find(root, data)) {
		std::cout << data << " not in tree, remove failed."<< "\n";
		return false;
	} else {
		root = recursiveRemove(root, data);
		std::cout << data << " removed successfully." << "\n";
		return true;
	}
}

Node* BST::recursiveRemove(Node* parent, int data) {
	if (data < parent->data) {
		parent->left_child = recursiveRemove(parent->left_child, data);
	} else if (data > parent->data) {
		parent->right_child = recursiveRemove(parent->right_child, data);
	} else {
		if (parent->left_child == NULL && parent->right_child == NULL) {
			// Case 1: leaf node
			delete parent;
			parent = NULL;
		} else if (parent->left_child == NULL) {
			// Case 2: node lacks a left child (no predecessor)
			Node* temp = parent;
			parent = parent->right_child;
			delete temp;
		} else if (getMax(parent->left_child)->right_child == NULL) {
			// Case 3: predecessor to node has no right child
			Node* predecessor = getMax(parent->left_child);
			parent->data = predecessor->data;
			delete predecessor;
		} else if (getMax(parent->left_child)->right_child != NULL) {
			// Case 4: predecessor to node has right child
			Node* predecessor = getMax(parent->left_child);
			Node* predecessor_left = predecessor->left_child;
			parent->data = predecessor->data;
			predecessor->data = predecessor_left->data;
			delete predecessor_left;
		}
	}
	return parent;
}

Node* BST::getMax(Node* parent) {
	Node* go = parent;
	while (go->right_child != NULL) {
		go = go->right_child;
	}
	return go;
}

void BST::clear() {
	while (root != NULL) {
		root = recursiveRemove(root, root->data);
	}
}