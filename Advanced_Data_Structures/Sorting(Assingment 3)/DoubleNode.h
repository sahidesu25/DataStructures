#pragma once
#include"Interfaces03.h"
#include<string>

class DoubleNode :public IDoubleNode03
{
public: int value;
	
	
	DoubleNode *next=NULL;
	DoubleNode *prev = NULL;
	

	DoubleNode() {
	
	}
	~DoubleNode() {}
	
	 void setValue(int value);
	 int getValue();
    IDoubleNode03 * getPrev() ;
	 IDoubleNode03 * getNext() ;
	 void setPrev(IDoubleNode03 * prev) ;
 void setNext(IDoubleNode03 * next);

};

