#include"Interfaces02.h"
#include "VectorKeyString.h"
#include<string>
void VectorString::push_back(std::string item)
{
	if (this->_size == this->_capacity)
	{
		VectorString::expand(2 * this->_capacity);

	}

	this->duplicates[this->_size] = item;
	this->_size++;
}
void VectorString::pop_back()
{
	this->_size = this->_size - 1;

}
std::string VectorString::get(int index)
{
	return this->duplicates[index];
}
void VectorString::set(int index, std::string item)
{
	this->duplicates[index] = item;
	//this->_size++;

}
size_t VectorString::size()
{
	return this->_size;
}
void VectorString::expand(int n){
	if (n > this->_capacity)
	{
		this->_capacity = n;
		std::string *temp = duplicates;
		std::string *tempstr = new std::string[this->_capacity];
		//memcpy(tempstr, duplicates, this->_capacity);
		for (int i = 0; i < this->_size; i++)
		{
			tempstr[i] = temp[i];

			
		}
		delete this->duplicates;
		duplicates = tempstr;

	}
}
void VectorString::resize(int size)
{
	this->_size = size;
}
