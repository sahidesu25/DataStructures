#include "DoubleNode.h"
#include "Interfaces01.h"
 

void DoubleNode::setValue(int value)
{
	this->value = value;
}

int DoubleNode::getValue()
{
	return(this->value);
}


IDoubleNode * DoubleNode::getNext()
{
	return(this->next);
}

IDoubleNode * DoubleNode::getPrev()
{
	return(this->prev);
}

void DoubleNode::setNext(IDoubleNode * next)
{
	this->next = (DoubleNode*)next;
}
void DoubleNode::setPrev(IDoubleNode * prev)
{
	this->prev = (DoubleNode*)prev;
}



