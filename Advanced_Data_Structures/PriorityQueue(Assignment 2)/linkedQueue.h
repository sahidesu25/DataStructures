#pragma once
#include"Interfaces02.h"
#include"LinkListNode.h"
#include "VectorKeyString.h"
class LinkedQueue :public IPriorityQueue
{
	DoubleNode *head = NULL;
	DoubleNode *tail=NULL;
	DoubleNode *min;
	size_t qsize;

public:
	LinkedQueue()
	{
		
	}
	~LinkedQueue()
	{

	}
	
	void enqueue(IKeyValue * key_value);
	void merge(IPriorityQueue * input_queue);
	IVectorKeyValue * returnSorted();
	int lowestKey();
	IVectorString * lowestValues();
	void dequeue();
	size_t size();
	void setHead(DoubleNode * head);
	DoubleNode * getHead();
	void setTail(DoubleNode * tail);
	DoubleNode * getTail();
	DoubleNode *getMin();
	void setMin(DoubleNode *min);
	DoubleNode * SortedMerge(DoubleNode *a, DoubleNode *b);

	
};