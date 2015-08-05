#include "AvlTree.h"

AvlNode * leftRotate(AvlNode *node);
AvlNode * rightRotate(AvlNode *node);
int max(int a, int b);
int height(AvlNode *node);
AvlNode  * newNode(int key);
AvlNode *_insert(AvlNode* node, int key);
AvlNode * minValueNode(AvlNode* node);
int getBalance(AvlNode *N);
AvlNode* deleteNode(AvlNode* root, int key);
std::vector<int> kth;
AvlNode * checkUnbal(char bal, AvlNode *node);

char mode;
void inOrder(AvlNode *root)
{
	if (root == NULL)
	{
		return;
	}
	else

	{
		inOrder((AvlNode*)root->getLeft());
		kth.push_back(root->getKey());
		inOrder((AvlNode*)root->getRight());
	}
}
int height(AvlNode *node)
{
	if (node == NULL)
		return 0;
	return node->h;
}
AvlNode  * newNode(int key)
{
	AvlNode *node = new AvlNode();
	node->setKey(key);
	node->setLeft( NULL);
	node->setRight ( NULL);
	node->h = 1; 
	return(node);
}

void AvlTree::insert(int key)
{
	root=_insert(root, key);

}



void AvlTree::remove(int key)
{
	root = deleteNode(root, key);


}


AvlNode* deleteNode( AvlNode* root, int key)
{
	

	if (root == NULL)
		return root;

	
	if (key < root->getKey())
		root->setLeft ( deleteNode((AvlNode*)root->getLeft(), key));

	
	else if (key > root->getKey())
		root->setRight ( deleteNode((AvlNode*)root->getRight(), key));

	
	else
	{
		
		if ((root->getLeft() == NULL) || (root->getRight() == NULL))
		{
			AvlNode *temp;
			if (root->getLeft())
			{
				temp = (AvlNode*)root->getLeft();
			}
			else
			{
				temp = (AvlNode*)root->getRight();
			}
			 
			
			if (temp!= NULL)
			{
				*root = *temp;

				free(temp);
			}
			else
			{
				root = NULL;
			}
				
		}
		else
		{
			AvlNode *current = ((AvlNode*)root->getRight());
			while (current->getLeft() != NULL)
				current = (AvlNode*)current->getLeft();
			root->setKey ( current ->getKey());
			root->setRight ( deleteNode((AvlNode*)root->getRight(), current ->getKey()));
		}
	}

	
	if (root == NULL)
		return root;

	
	root->h = max(height((AvlNode*)root->getLeft()), height((AvlNode*)root->getRight()))+1;

	
	int balance = getBalance(root);
	root = checkUnbal(balance, root);
	

	return root;
}


int AvlTree::kthMin(int k)
{
	
	inOrder(root);
	int a = kth.at(k);
	kth.clear();
	return(a);
	
}
IAVLTreeNode *AvlTree::getRoot()
{
	return (this->root);
}
 AvlNode *leftRotate(AvlNode *node)
{
	 AvlNode *y  = (AvlNode*)node->getRight();
	AvlNode *T2 =(AvlNode*) y->getLeft();

	
	y->setLeft( node);
	node->setRight ( T2);

	
	node->h= max(height((AvlNode*)node->getLeft()), height((AvlNode*)node->getRight())) + 1;
	y->h = max(height((AvlNode*)y->getLeft()), height((AvlNode*)y->getRight())) + 1;

	
	return y;
}

 AvlNode *rightRotate( AvlNode *y)
 {
	  AvlNode *x = (AvlNode*)y->getLeft();
	  AvlNode *T2 = (AvlNode*)x->getRight();

	 
	 x->setRight(y);
	 y->setLeft(T2);

	 
	 y->h = max(height(((AvlNode*)y->getLeft())), height(((AvlNode*)y->getRight()))) + 1;
     x->h = max(height((AvlNode*)x->getLeft()), height((AvlNode*)x->getRight())) + 1;

	
	 return x;
 }
 int max(int a, int b)
 {
	 if (a > b)
	 {
		 return(a);
	 }
	 else
	 {
		 return(b);
	 }
 }
 int getBalance(AvlNode *N)
 {
	
	 if (N == NULL)
		 return 0;
	 int a=height((AvlNode*)N->getLeft()) - height((AvlNode*)N->getRight());
	 return a;
 }
  AvlNode* _insert( AvlNode* node, int key)
 {
	
	 if (node == NULL)
		 return(newNode(key));

	 if (key < node->getKey())
		 node->setLeft(_insert((AvlNode*)node->getLeft(), key));
	 else
		 node->setRight (_insert((AvlNode*)node->getRight(), key));

	
	 node->h = max(height((AvlNode*)node->getLeft()), height((AvlNode*)node->getRight())) + 1;

	
	 int  balance = getBalance(node);
	 node = checkUnbal(balance, node);

	 
	 return node;
 }

  AvlNode * checkUnbal(char balance, AvlNode * Node)
  {
	  if (balance>1  && getBalance((AvlNode*)Node->getLeft()) >= 0)
		  return rightRotate(Node);

	  
	  if (balance>1 && getBalance((AvlNode*)Node->getLeft()) < 0)
	  {
		  Node->setLeft(leftRotate((AvlNode*)Node->getLeft()));
		  return rightRotate(Node);
	  }

	 
	  if (balance <-1&& getBalance((AvlNode*)Node->getRight()) <= 0)
		  return leftRotate(Node);

	 
	  if (balance<-1 && getBalance((AvlNode*)Node->getRight()) > 0)
	  {
		  Node->setRight(rightRotate((AvlNode*)Node->getRight()));
		  return leftRotate(Node);
	  }
	  return Node;
  }
  