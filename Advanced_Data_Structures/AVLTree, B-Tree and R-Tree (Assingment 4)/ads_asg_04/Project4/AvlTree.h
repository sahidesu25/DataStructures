
#pragma once 
#include "Interfaces04.h"
#include "AvlNode.h"




class AvlTree: public IAVLTree {

public:
	AvlTree() { }
   ~AvlTree() { }
	 void insert(int key) ;
	 void remove(int key) ;
     int kthMin(int k) ;
	 IAVLTreeNode * getRoot();

	AvlNode *root = NULL;
};