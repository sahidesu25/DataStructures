#include "BTree.h"
#include "BTreeNode.h"
static std::vector<int > traverselist;

void BTree::traverse()
{
	
}
void BTree::insert(int key, int num_keys)
{
	  
	
	if (root == NULL)
	{
		
		root = new BTreeNode(3, true);
		root->setKey(0, key);
		root->setKeySize(1);
		
	}
	else 
	{
		
		if (root->getKeySize() == 2 * t - 1)
		{
			
			BTreeNode *s = new BTreeNode(t, false);
            s->setChild(0, root);
			BTreeNode *z = new BTreeNode(root->t, root->isLeaf());
			z->setKeySize(t - 1);
			int counter=0;
			while (counter < t - 1)
			{
				z->setKey(counter, root->getKey(counter + t));
				counter++;
			}
			if (root->isLeaf() == false)
			{
				int counter = 0;
				
				while (counter < t)
				{
					z->setChild(counter, root->getChild(counter + t));
					counter++;
				}
			}
            
			root->setKeySize(t - 1);
            for (int j = s->getKeySize(); j >= 0 + 1; j--)
				s->setChild(j + 1, s->getChild(j));
			s->setChild(1 , z);
           for (int j = s->getKeySize() - 1; j >= 0; j--)
				   s->setKey(j + 1, s->getKey(j));
			s->setKey(0, root->getKey(t - 1));
			s->setKeySize(s->getKeySize() + 1);
		    int i = 0;
			if (s->getKey(0) < key)
				i++;
			((BTreeNode*)s->getChild(i))->_insert(key);
			root = s;
		}
		else  
			root->_insert(key);
	}
}

int BTree::kthMin(int kt)
{
	int k;
	
	if (root != NULL) root->traverseNode();
	int a = root->getsorted(kt);
	return (a);
	
}
void BTree::remove(int key, int num_keys)
{
	

	
	root->remove(key);

	
	if (root->getKeySize() == 0)
	{
		BTreeNode *tmp = root;
		if (root->isLeaf())
			root = NULL;
		else
			root = (BTreeNode*)root->getChild(0);

		
		delete tmp;
	}
}

IBTreeNode * BTree::getRoot()
{
	return (this->root);
}