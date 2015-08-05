#pragma once
#include "Interfaces02.h"
#include "VectorString1.h"

#define INTERFACES_KEYVALUE
using namespace std;
class KeyValue1 : public IKeyValue
{
	int key;
	//string value;
	IVectorString *v;
	KeyValue1 *next = NULL;
	KeyValue1 *prev = NULL;
	
public:
	KeyValue1()
	{
		v = new VectorString1( );
		this->key = 0;
	}

	~KeyValue1(){
		delete v;
	}
	void setKey(int key);
	void setValue(std::string value);
	int getKey();
	std::string getValue();
	VectorString1 * getvalues();
	void setValues(VectorString1 *st);
	KeyValue1 * getPrev();
	KeyValue1 * getNext();
	void setPrev(KeyValue1 * prev);
	void setNext(KeyValue1 * next);
};