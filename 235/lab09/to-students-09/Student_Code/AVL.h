#ifndef AVL_H_
#define AVL_H_

#include "AVLInterface.h"
#include "Node.h"

class AVL : public AVLInterface {
public:
	AVL();
	~AVL();
	// functions
	NodeInterface* getRootNode();
	bool add(int data);
	bool remove(int data);
	void find(int data);
	void preOrderPrint();
private:
	// functions
	Node* recursiveAdd(Node* parent, int data);
	Node* recursiveRemove(Node* parent, int data);
	Node* rotateRight(Node* node);
	Node* rotateLeft(Node* node);
	Node* replaceIOP(Node* current, Node* parent);
	int getBalance(Node* node);
	int getHeight(Node* node);
	int getMax(int first, int second);
	void setHeight(Node* node);
	bool recursiveFind(Node* parent, int data);
	void recursivePreOrderPrint(Node* root);
	void clear();
	// data members
	Node* root;
};

#endif // AVL_H_