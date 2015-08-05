# pragma once 
#include "Interfaces04.h"
class AvlNode :public IAVLTreeNode
{
private:
	IAVLTreeNode *left=NULL;
	IAVLTreeNode *right=NULL;
	int key;
	
public:
	AvlNode(){}
	~AvlNode() { }
	void setLeft(IAVLTreeNode * left);
	void setRight(IAVLTreeNode * right);
	void setKey(int key);
	IAVLTreeNode * getLeft();
	IAVLTreeNode * getRight();
	int getKey();
	int height(AvlNode * node);
	int h;
};