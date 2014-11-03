#ifndef NODE_H_
#define NODE_H_

#pragma once

#include "NodeInterface.h"

using namespace std;		

class Node : public NodeInterface {
public:
	int data;
	NodeInterface * leftChild;
	NodeInterface * rightChild;

	Node(int value);
	~Node();
	int getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();
};

#endif