# pragma once
#include "Interfaces02.h"
#include<string>

class VectorString : public IVectorString
{
	int _size;
	int _capacity;
	std::string * duplicates;

public:

	VectorString() {}
	VectorString(int n)
	{
		this->_size = 0;
		this->_capacity = n;
		this->duplicates = new std::string[n];

	}
	~VectorString() {}
	 void push_back(std::string item) ;
	 void pop_back() ;
	 std::string get(int index) ;
	 void set(int index, std::string item) ;
	 size_t size();
	 void expand(int i);
	 void resize(int i);
	 void set_array_size(int);
};
