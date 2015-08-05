
#pragma once
#include "Interfaces01.h"


class SingleNode : public ISingleNode
{
	int value;
	SingleNode *next;
public:
	SingleNode(){}
	~SingleNode(){}
	 void setValue(int value);
	 int getValue();
	 ISingleNode * getNext();
	 void setNext(ISingleNode * next);
};

