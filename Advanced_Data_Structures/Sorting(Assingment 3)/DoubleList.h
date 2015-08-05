#pragma once
#include "DoubleNode.h"
#include "Interfaces03.h"
class DoubleList:public IDoubleList03
{
	DoubleNode *head=NULL;
	DoubleNode *tail = NULL;
	int LinkSize;
public:
	DoubleList(){

	}
	~DoubleList()
	{

	}
	 IDoubleNode03 * getHead() ;
	 IDoubleNode03 * getTail() ;
     void setHead(IDoubleNode03 * head) ;
	 void setTail(IDoubleNode03 * tail) ;
	void addBack(int value) ;
	 int size() ;
};