#include"Interfaces02.h"
#include"LinkListNode.h"

void DoubleNode::setValue(std::string value)
{
	this->value = value;
}

int DoubleNode::getKey()
{
	return(this->key);
}
std::string DoubleNode::getValue()

{
	return(this->value);
}
//DoubleNode * DoubleNode::getPrev()
//{
//	return(this->prev);
//}
DoubleNode * DoubleNode::getNext()
{
	return (this->next);
}
//void DoubleNode::setPrev(DoubleNode * prev)
//{
//	this->prev = prev;
// }
void DoubleNode::setNext(DoubleNode * next)
{
	this->next = next;
}
void DoubleNode::setKey(int key)
{
	this->key = key;
}
