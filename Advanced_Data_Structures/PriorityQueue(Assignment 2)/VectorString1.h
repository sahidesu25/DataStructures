#pragma once
#include "Interfaces02.h"

#define INTERFACES_KEYVALUE
using namespace std;
class VectorString1 : public IVectorString
{
	public:
	int cap;
	int siz;
	string *ars = NULL;
	VectorString1()
	{
		cap = 10;
		siz = 0;
		ars = new string[cap];
	}
	~VectorString1()
	{
		delete ars;
	}
	void push_back(std::string item);
	void pop_back();
	string get(int index);
	void set(int index, std::string item);
	size_t size();
};
