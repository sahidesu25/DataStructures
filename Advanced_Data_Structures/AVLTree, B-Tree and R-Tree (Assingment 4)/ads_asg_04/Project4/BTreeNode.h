
#pragma once
#include "Interfaces04.h"

class BTreeNode : public IBTreeNode
{
public:
	int *keys;
	
	BTreeNode **Child ;
	int n;
	bool leaf;
	

	int t;
	BTreeNode()
	{
		
	}
	BTreeNode(int mindegree, bool _leaf)
	{
		this->t = mindegree;
		this->leaf = _leaf;
		keys = new int[2 * t - 1];
		Child = new BTreeNode *[2 * t];
		n = 0;
	}
	
	~BTreeNode() {}
	int getKey(int index);
	void setKey(int index, int key);
	int getKeySize();
	void setKeySize(int size);
	int getChildSize();
	void setChildSize(int size);
	IBTreeNode * getChild(int index);
	void setChild(int index, IBTreeNode * child);
	bool isLeaf();
	void _insert(int k);
	void traverseNode();
    int  getsorted(int k);
    void remove(int k);


};