# pragma once
#include "Interfaces02.h"
#include<iostream>
#include <string>
#include "VectorKeyString.h"
class KeyValue : public IKeyValue
{
	int key;
	std::string val;
	VectorString *value;
public:

	KeyValue(){
		this->value = new VectorString(10);
		this->key = 0;
	}
	
	~KeyValue() {}
	void setKey(int key);
    void setValue(std::string value);
    int getKey();
	std::string getValue();
	VectorString* getvalues();
	void setValues(VectorString *strings);
};