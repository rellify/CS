#ifndef BST_H_
#define BST_H_

#pragma once

#include "BSTInterface.h"

class BST : public BSTInterface {
public:
	Node* root;

	BST();
	~BST();
	NodeInterface * getRootNode();
	bool add(int data);
	bool remove(int data);
	bool remove(int data);
};

#endif