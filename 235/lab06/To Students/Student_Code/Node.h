#ifndef NODE_H_
#define NODE_H_

#include "NodeInterface.h"

using namespace std;		

class Node : public NodeInterface {
public:
	Node(int value);
	~Node();

	int data;
	Node* leftChild;
	Node* rightChild;

	int getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();
};

#endif