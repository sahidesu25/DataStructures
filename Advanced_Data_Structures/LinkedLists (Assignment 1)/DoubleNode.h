#pragma once
#include "Interfaces01.h"


class DoubleNode : public IDoubleNode
{
	int value;
	DoubleNode *next;
	DoubleNode *prev;
public:
	DoubleNode() {}
    ~DoubleNode() {}
	 void setValue(int value);
	int getValue();
 IDoubleNode * getPrev();
 IDoubleNode * getNext() ;
 void setPrev(IDoubleNode * prev);
 void setNext(IDoubleNode * next);
};

