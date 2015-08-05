#pragma once 
#include "Interfaces01.h"
#include "DoubleNode.h"

class DoubleList : public IDoubleList
{
	DoubleNode *head;
	DoubleNode *tail;
public:

	DoubleList() {}
	~DoubleList() {}
	 IDoubleNode * getHead();
	 IDoubleNode * getTail();
	 void setHead(IDoubleNode * head);
	 void setTail(IDoubleNode * tail);
	 void addSorted(int value);
	 void orderSort2() ;
	 void orderSort3();
	 void sequenceOrderSort();
	 void reverse() ;
};
