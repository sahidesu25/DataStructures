#include "KthMin.h"
#include "DoubleList.h"
#include "DoubleNode.h"


//int KthMin::findKthMin(IDoubleList03 * data, int k){
//	DoubleNode *outer=(DoubleNode*)data->getHead();
//	DoubleNode *backup = (DoubleNode*)outer->getNext();
//	DoubleNode *inner = (DoubleNode*)outer->getNext();
//	DoubleNode *min_ptr = outer;
//	int counter = 0;
//	DoubleNode *backup1=NULL;
//	while (counter <= k)
//	{
//		min_ptr = outer;
//		int min_value = outer->getValue();
//
//		
//		
//		
//
//			while (inner)
//			{
//				if (inner->getValue() < min_value)
//				{
//					min_ptr = inner;
//					min_value = inner->getValue();
//				}
//				inner = (DoubleNode*)inner->getNext();
//
//
//			}
//			if (outer->getValue() != min_ptr->getValue())
//			{
//				
//				
//				if (outer->getPrev() == NULL)
//				{
//					outer->setNext(min_ptr->getNext());
//					min_ptr->getPrev()->setNext(outer);
//					outer->setPrev(min_ptr->getPrev());
//					if (outer->getNext() != NULL)
//						outer->getNext()->setPrev(outer);
//					min_ptr->setNext(backup);
//					min_ptr->setPrev(NULL);
//					backup->setPrev(min_ptr);
//					backup1 = min_ptr;
//					data->setHead(min_ptr);
//
//				}
//					if (min_ptr == backup)
//					{
//					backup1->setNext(min_ptr);
//					min_ptr->setPrev(backup);
//					outer->setNext(min_ptr->getNext());
//					min_ptr->getNext()->setPrev(outer);
//					min_ptr->setNext(outer);
//					outer->setPrev(min_ptr);
//					backup1 = min_ptr;
//					}
//
//					else
//					{
//						outer->setNext(min_ptr->getNext());
//						min_ptr->getPrev()->setNext(outer);
//						outer->setPrev(min_ptr->getPrev());
//						outer->getNext()->setPrev(outer);
//						min_ptr->setNext(backup);
//						min_ptr->setPrev(backup1);
//						backup1->setNext(min_ptr);
//						backup->setPrev(min_ptr);
//						backup1 = min_ptr;
//					}
//				}
//			
//		
//		
//			outer = (DoubleNode*)min_ptr->getNext();
//			if (outer != NULL)
//			{
//				backup = (DoubleNode*)outer->getNext();
//				inner = (DoubleNode*)outer->getNext();
//			}
//		
//		counter++;
//	}
//	return(min_ptr->getValue());
//}


DoubleNode *lastNode(DoubleNode *root);
DoubleNode* partition(DoubleNode *l, DoubleNode *h);
void _quickSort(DoubleNode* l, DoubleNode *h);
void swap(int* a, int* b);
int KthMin::findKthMin(IDoubleList03 * data, int k){
	DoubleNode *current = (DoubleNode*)data->getHead();
	DoubleNode *h = lastNode((DoubleNode*)(data->getHead()));
	int counter=0;
	// Call the recursive QuickSort
	_quickSort(current, h);
	if (k == 0)
	{
		return (data->getHead()->getValue());
	}
	while (counter<=k)
	{
		if (counter == k)
		{
			return (current->getValue());
		}
		else
		{
			current = (DoubleNode*)current->getNext();
			counter++;
		}
	}
	
}

DoubleNode* partition(DoubleNode *l, DoubleNode *h)
{
	// set pivot as h element
	int x = h->getValue();

	// similar to i = l-1 for array implementation
	DoubleNode *i = (DoubleNode*)l->getPrev();

	// Similar to "for (int j = l; j <= h- 1; j++)"
	for (DoubleNode *j = l; j != h; j = (DoubleNode*)j->getNext())
	{
		if (j->getValue() <= x)
		{
			// Similar to i++ for array
			i = (i == NULL) ? l : (DoubleNode*)i->getNext();
			//int a1 = i->getValue();
			//int b1 = j->getValue();
			swap(&i->value,&j->value);
			
		}
	}
	i = (i == NULL) ? l :(DoubleNode*) i->getNext(); // Similar to i++
	//int a = i->getValue();
	//int b = h->getValue();
	swap(&i->value, &h->value);
	return i;
}

void _quickSort(DoubleNode * l, DoubleNode *h)
{
	if (h != NULL && l != h && l != h->getNext())
	{
		DoubleNode *p = partition(l, h);
		_quickSort(l, (DoubleNode*)p->getPrev());
		_quickSort((DoubleNode*)p->getNext(), h);
	}
}


DoubleNode *lastNode(DoubleNode *root)
{
	while (root && root->getNext())
		root = (DoubleNode*)root->getNext();
	return root;
}


void swap(int* a, int* b)
{
	int t = *a;      *a = *b;       *b = t;
}
