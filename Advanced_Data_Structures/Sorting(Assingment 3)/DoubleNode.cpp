
#include"DoubleNode.h"



IDoubleNode03 * DoubleNode::getPrev()
{
	return(this->prev);
}
IDoubleNode03 * DoubleNode::getNext()
{
	return (this->next);
}
void DoubleNode:: setValue(int value)
{
	this->value = value;
}
int DoubleNode::getValue()
{
	return(this->value);
}
void DoubleNode::setPrev(IDoubleNode03 * prev)
{
	this->prev = (DoubleNode*)prev;
}

void DoubleNode::setNext(IDoubleNode03 * next)
{
	this->next = (DoubleNode*)next;
}

