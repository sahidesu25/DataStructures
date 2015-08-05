#include "SingleNode.h"

#include "Interfaces01.h"


void SingleNode::setValue(int value)
{
	this->value = value;
}

int SingleNode::getValue()
{
	return(this->value);
}
 
ISingleNode * SingleNode::getNext()
{
	return(this->next);
}

void SingleNode::setNext(ISingleNode * next)
{
	this->next = (SingleNode*)next;
}
