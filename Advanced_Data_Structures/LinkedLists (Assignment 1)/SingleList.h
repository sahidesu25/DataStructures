#pragma once 
#include "Interfaces01.h"
#include "SingleNode.h"

class SingleList : public ISingleList
{
	SingleNode *head;
public:
	SingleList() {}
	~SingleList() {};
	 ISingleNode * getHead();
	 void setHead(ISingleNode * head);
	 void addHead(int value);
	 void orderSort2();
	 void orderSort3();
	 void sequenceOrderSort();
	 void reverse();

};