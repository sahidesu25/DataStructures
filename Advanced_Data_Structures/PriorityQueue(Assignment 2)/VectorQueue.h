#pragma once
#include"Interfaces02.h"
#include "VectorKeyString.h"
#include "VectorKeyValue.h"
#include "KeyValue.h"

class Heap: public IPriorityQueue
{
	VectorKeyValue *v;
	int lowkey;
	VectorKeyValue *sorted;
	int sortedsize;

	
	int left(int parent);
	int right(int parent);
	int parent(int i);
	void upheapify(int i);
	void downheapify(int i);
public:
	Heap()
	{
		this->v = new VectorKeyValue(20);
		this->sorted = new VectorKeyValue(30);
		//this->lowkey = 2147483647;
		
	}
	~Heap(){}
	 void enqueue(IKeyValue * key_value) ;
	 void merge(IPriorityQueue * input_queue) ;
	 IVectorKeyValue * returnSorted() ;
	 int lowestKey() ;
	 IVectorString * lowestValues() ;
	 void dequeue();
	 size_t size() ;
	 void merging(int, int,int);
	 void mergesort(int, int);
	 void insert(IKeyValue *v);
	 void deletemin();
	 VectorKeyValue* getV();
	 


};