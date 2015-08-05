#pragma once
#include"Interfaces02.h"
#include<string>

class DoubleNode:public IKeyValue
{
	int key;
	std::string value;
	DoubleNode *next=NULL;
	//DoubleNode *prev;
public:
	DoubleNode() {
	
	}
	~DoubleNode() {}
	void setKey(int key);
	
	void setValue(std::string value);
	int getKey();
	std::string getValue();
	//DoubleNode * getPrev();
	DoubleNode * getNext();
	//void setPrev(DoubleNode * prev);
	void setNext(DoubleNode * next);

};

