#pragma once
#include "Interfaces02.h"
#include "VectorKeyValue1.h"
#include "KeyValue01.h"
#include "iostream"


#define INTERFACES_KEYVALUE
using namespace std;
void VectorKeyValue1::push_back(IKeyValue * item)
{

	if ((sizee == capacity) || (sizee > capacity))
	{
		capacity = 2 * capacity;
		KeyValue1 **arr1 = new KeyValue1*[capacity];
		KeyValue1 ** n = arr;
		for (int i = 0; i < (this->sizee); i++)
		{
			
			arr1[i] = n[i];

		}
		delete[] arr;
		arr = arr1;
		arr[sizee] = (KeyValue1*)item;
		sizee++;
	}
	else if (sizee < capacity)
	{
		arr[sizee] = (KeyValue1*)item;
		sizee++;
	}

}
void VectorKeyValue1::pop_back()
{
	//DELETE THE NODE EXPLICITLY!!!
	(sizee--);
}
IKeyValue * VectorKeyValue1::get(int index)
{
	
	return (arr[index]);
}
void VectorKeyValue1:: set(int index, IKeyValue * item)
{
	
	
	arr[index] = (KeyValue1 *)item;

}
size_t VectorKeyValue1::size()
{
	return(sizee);
}