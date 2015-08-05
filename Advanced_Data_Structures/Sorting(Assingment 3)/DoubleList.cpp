#include "Interfaces03.h"
#include "DoubleList.h"
#include "DoubleNode.h"

IDoubleNode03 * DoubleList::getHead()
{
	return(this->head);
}
IDoubleNode03 *DoubleList:: getTail()
{
	return(this->tail);
}
void DoubleList::setHead(IDoubleNode03 * head)
{
	this->head = (DoubleNode*)head;
}
void DoubleList::setTail(IDoubleNode03 * tail)
{
	this->tail = (DoubleNode*)tail;
}
void DoubleList:: addBack(int value)
{
	if (this->head == NULL) 
	{
		DoubleNode *n = new DoubleNode();
		n->setValue(value);
		n->setNext(NULL);
		n->setPrev(NULL);
		setHead(n);
		setTail(n);
		LinkSize++;
	}
	else
	{
		DoubleNode *n = new DoubleNode();
		n->setValue(value);
		tail->setNext(n);
		n->setPrev(tail);
		n->setNext(NULL);
		setTail(n);
		LinkSize++;
		
	}
}
int DoubleList::size()
{
	return(this->LinkSize);
}