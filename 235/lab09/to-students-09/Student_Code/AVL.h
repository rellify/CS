#ifndef AVL_H_
#define AVL_H_

#include "AVLInterface.h"
#include "BST.h"
#include "Node.h"

class AVL : public AVLInterface {
public:
	AVL();
	~AVL();
	// methods
	NodeInterface* getRootNode();
	bool add(int data);
	bool remove(int data);
	void print();
	void find(int data);
private:
	// methods
	Node* recursiveAdd(Node* parent, int data);
	Node* recursiveRemove(Node* parent, int data);
	Node* rotateRight(Node* node);
	Node* rotateLeft(Node* node);
	Node* replaceIOP(Node* current, Node* parent);
	int getBalance(Node* node);
	int getHeight(Node* node);
	int getMax(int first, int second);
	void recursivePrint(Node* node);
	bool find(Node* parent, int data);
	void clear();
	// data members
	Node* root;
};

#endif // AVL_H_