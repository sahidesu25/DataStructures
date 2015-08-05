#pragma once
#include "Interfaces02.h"
#include "VectorKeyValue.h"
#include "KeyValue.h"
#include "VectorString1.h"


#define INTERFACES_KEYVALUE
using namespace std;

void VectorString1::push_back(std::string item)
{

	if ((siz == cap) || (siz > cap))
	{
		cap = 2 * cap;
		string *ars1 = new string[cap];
		string *nw = ars;
		for (int i = 0; i < (siz); i++)
		{
			ars1[i] = (nw[i]);

		}
		delete[] ars;
		ars = ars1;
		ars[siz] = item;
		siz++;
	}
	else if (siz < cap)
	{
		ars[siz] = item;
		siz++;
	}
}
void VectorString1:: pop_back()
{
	(siz--);
}
string VectorString1:: get(int index)
{
	return (ars[index]);
}
void VectorString1:: set(int index, std::string item)
{
	ars[index] = item;
	(this->siz)++;
	//EXCEPTION
	//(this->ars->size)++;
	//size and duplicate keys
	//(this->siz)++;
}

size_t VectorString1:: size()
{
	return (siz);
}