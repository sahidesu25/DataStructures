#pragma once
#include "Interfaces04.h"
#include "BTreeNode.h"

class BTree : public IBTree {
public:
	
	

	BTree()
	{
		this->root = NULL;  this->t = 3;
	}
	
	~BTree() {
	}

	void insert(int key, int num_keys);
	void traverse();
	void remove(int key, int num_keys);
	int kthMin(int kt);
	IBTreeNode * getRoot();
	
	
	
	BTreeNode *root;
	int t;

};