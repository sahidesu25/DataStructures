#include "Interfaces04.h"
#include "AvlNode.h"
void AvlNode::setLeft(IAVLTreeNode * left)
{
	this->left = left;
}

void AvlNode::setRight(IAVLTreeNode * right)
{
	this->right = right;
}

void AvlNode::setKey(int key)
{
	this->key = key;
}

IAVLTreeNode * AvlNode::getLeft()
{
	return this->left;
}

IAVLTreeNode * AvlNode::getRight()
{
	return this->right;
}

int AvlNode::getKey()
{
	return this->key;

}




