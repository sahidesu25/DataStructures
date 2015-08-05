#include "BTreeNode.h"
std::vector<int> _sorted;
int BTreeNode::getKey(int index)
{
	return this->keys[index];
}


void BTreeNode::setKey(int index, int key)
{
	this->keys[index] = key;
	if (index<this->n)
		return;
	
}
int BTreeNode::getKeySize()
{
	return this->n;
}
void BTreeNode::setKeySize(int size)
{
	this->n = size;
}
int BTreeNode::getChildSize()
{

	if (!isLeaf())
	{
		return getKeySize() + 1;
	}
	return 0;
}
IBTreeNode * BTreeNode::getChild(int index)
{
	return this->Child[index];
}

void BTreeNode::setChildSize(int size)
{
	for (int i = 0; i <size;i++)
	this->Child[i]=NULL;
}

void BTreeNode::setChild(int index, IBTreeNode * child)
{
	this->Child[index] =(BTreeNode*) child;
}

bool BTreeNode::isLeaf()
{
	return (this->leaf);
}
void BTreeNode::_insert(int k)
{
	
	int i = this->n - 1;

	
	if (this->leaf == true)
	{
		
		while (i >= 0 && this->keys[i] > k)
		{
			this->keys[i + 1] = this->keys[i];
			i--;
		}

		
		this->keys[i + 1] = k;
		this->n = this->n + 1;
	}
	else
	{
		
		while (i >= 0 && this->keys[i] > k)
			i--;

		
		if (this->Child[i + 1]->n == 2 * t - 1)
		{
			
			int index = i + 1;
			BTreeNode *z = new BTreeNode(this->Child[i + 1]->t, this->Child[i+1]->leaf);
			z->n = t - 1;
			if (this->Child[i + 1]->leaf == false)
			{
				for (int j = 0; j < t; j++)
					z->Child[j] = this->Child[i + 1]->Child[j + t];
			}
			
			for (int j = 0; j < t - 1; j++)
				z->keys[j] = this->Child[i+1]->keys[j + t];
            this->Child[i+1]->n = t - 1;
             
			   for (int j = n; j >= index + 1; j--)
				this->Child[j + 1] = this->Child[j];

			
			this->Child[index + 1] = z;

			
			for (int j = n - 1; j >= index; j--)
				this->keys[j + 1] = this->keys[j];

			
			this->keys[index] = this->Child[i+1]->keys[t - 1];

			
			this->n = this->n + 1;
		

			
			if (this->keys[i + 1] < k)
				i++;
		}
		this->Child[i + 1]->_insert(k);
	}
}


 void BTreeNode::traverseNode()
{
	
	int i, flag = 0;
	for (i = 0; i <this-> n; i++)
	{
		
		if (this->leaf == false)
		{
			flag = 1;
			this->Child[i]->traverseNode();
		}
			
		_sorted.push_back(keys[i]);
		
	}

	
	if (flag==1)
		this->Child[i]->traverseNode();
}
int BTreeNode::getsorted(int k)
{
	int temp = _sorted.at(k);
	_sorted.clear();
	return temp;


}


void BTreeNode::remove(int k)
{
	
	int idx = 0;
	while (idx<n && keys[idx] < k)
		++idx;
	if (idx < n && keys[idx] == k)
	{
		if (leaf)
		{
			for (int i = idx + 1; i<n; ++i)
				keys[i - 1] = keys[i];
			n = n - 1;
		}
			
		else
		{
			
			int k = keys[idx];

			if (Child[idx]->n >= t)
			{
				int pred;
				BTreeNode *cur = Child[idx];
				while (!cur->leaf)
					cur = cur->Child[cur->n];
				pred = cur->keys[cur->n - 1];

				keys[idx] = pred;
				Child[idx]->remove(pred);
			}


			else if (Child[idx + 1]->n >= t)
			{
				int succ;
				BTreeNode *cur = Child[idx + 1];
				while (!cur->leaf)
					cur = cur->Child[0];
				succ = cur->keys[0];
				keys[idx] = succ;
				Child[idx + 1]->remove(succ);
			}


			else
			{

				BTreeNode *child = Child[idx];
				BTreeNode *sibling = Child[idx + 1];
				child->keys[t - 1] = keys[idx];
				for (int i = 0; i<sibling->n; ++i)
					child->keys[i + t] = sibling->keys[i];
				if (!child->leaf)
				{
					for (int i = 0; i <= sibling->n; ++i)
						child->Child[i + t] = sibling->Child[i];
				}
				for (int i = idx + 1; i<n; ++i)
					keys[i - 1] = keys[i];

				for (int i = idx + 2; i <= n; ++i)
					Child[i - 1] = Child[i];


				child->n += sibling->n + 1;
				n--;


				delete(sibling);
				Child[idx]->remove(k);
			}

			

		}
			
	}
	else
	{

		if (leaf)
			return;
		int last_index=0;
		if (idx == n)
		{
			last_index = 1;
		}
		
		
          if (Child[idx]->n < t)
			
			if (idx != 0 && Child[idx - 1]->n >= t)
			{
			
			BTreeNode *child = Child[idx];
			BTreeNode *sibling = Child[idx - 1];

			
			for (int i = child->n - 1; i >= 0; --i)
				child->keys[i + 1] = child->keys[i];

			
			if (!child->leaf)
			{
				for (int i = child->n; i >= 0; --i)
					child->Child[i + 1] = child->Child[i];
			}

		
			child->keys[0] = keys[idx - 1];

			
			if (!leaf)
				child->Child[0] = sibling->Child[sibling->n];

			
			keys[idx - 1] = sibling->keys[sibling->n - 1];

			child->n= child->n+ 1;
			sibling->n =sibling->n- 1;

			}
				

		
			else if (idx != n && Child[idx + 1]->n >= t)
			{
				BTreeNode *child = Child[idx];
				BTreeNode *sibling = Child[idx + 1];

				
				child->keys[(child->n)] = keys[idx];

				
				if (!(child->leaf))
					child->Child[(child->n) + 1] = sibling->Child[0];

				
				keys[idx] = sibling->keys[0];

				
				for (int i = 1; i<sibling->n; ++i)
					sibling->keys[i - 1] = sibling->keys[i];

				
				if (!sibling->leaf)
				{
					for (int i = 1; i <= sibling->n; ++i)
						sibling->Child[i - 1] = sibling->Child[i];
				}

				
				child->n += 1;
				sibling->n =sibling->n-1 ;

			}
				

		
			else
			{
				if (idx != n)
				{
					BTreeNode *child = Child[idx];
					BTreeNode *sibling = Child[idx + 1];

					
					child->keys[t - 1] = keys[idx];

					
					for (int i = 0; i<sibling->n; ++i)
						child->keys[i + t] = sibling->keys[i];

					
					if (!child->leaf)
					{
						for (int i = 0; i <= sibling->n; ++i)
							child->Child[i + t] = sibling->Child[i];
					}

					
					for (int i = idx + 1; i<n; ++i)
						keys[i - 1] = keys[i];

					
					for (int i = idx + 2; i <= n; ++i)
						Child[i - 1] = Child[i];

					
					child->n =child->n+ sibling->n + 1;
					n--;

					
					delete(sibling);
				}
					

				
				else
				{
					BTreeNode *child = Child[idx-1];
					BTreeNode *sibling = Child[idx ];
					child->keys[t - 1] = keys[idx-1];
                	for (int i = 0; i<sibling->n; ++i)
						child->keys[i + t] = sibling->keys[i];
					if (!child->leaf)
					{
						for (int i = 0; i <= sibling->n; ++i)
							child->Child[i + t] = sibling->Child[i];
					}
					for (int i = idx; i<n; ++i)
						keys[i - 1] = keys[i];
                    for (int i = idx + 1; i <= n; ++i)
						Child[i - 1] = Child[i];
					child->n += sibling->n + 1;
					n--;
					delete(sibling);
				}
					
			}
		
		if (last_index==1 && idx > n)
			Child[idx - 1]->remove(k);
		else
			Child[idx]->remove(k);
	}
	
}








