#include "Interfaces02.h"
#include "KeyValue01.h"

#pragma once
#define INTERFACES_KEYVALUE
using namespace std;
class VectorKeyValue1 : public IVectorKeyValue
{
	int capacity;
	int sizee;
	KeyValue1 **arr;
public:
	VectorKeyValue1()
	{
		capacity = 10;
		sizee = 0;
		arr = new KeyValue1 *[capacity];
	}
	~VectorKeyValue1()
	{
		delete arr;
	}
	void push_back(IKeyValue * item);
	 void pop_back();
	IKeyValue * get(int index);
	 void set(int index, IKeyValue * item);
	 size_t size();
};

