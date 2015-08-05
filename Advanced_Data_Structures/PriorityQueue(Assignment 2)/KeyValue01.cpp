#pragma once
#include "Interfaces02.h"
#include "KeyValue01.h"
#include "VectorString1.h"
#include "VectorKeyValue1.h"

#define INTERFACES_KEYVALUE
using namespace std;

	void KeyValue1::setKey(int key)
	{
		this->key = key;
	}
	
	void KeyValue1:: setValue(std::string value) 
	{
		//this->v->set(arr->siz, value);
		//this->value = value;
		//this->v[v->siz]->
		//this->v = value;
		//this->s
	this->v->set(v->size(),value);
//		v->push_back(value);
	}
	
	int KeyValue1:: getKey()
	{
		return (this->key);

	}	
	string KeyValue1:: getValue()
	{

		return(v->get(0));
	//	for (int i = 0; i <= this->v->size(); i++)
			//return(this->value);
		//{
		//	(this->v->get(i));
		//}
		
		//return(v->value);
	}

	VectorString1 * KeyValue1::getvalues()
	{

		return((VectorString1 *)v);
	}

	void KeyValue1::setValues(VectorString1 *st)
	{
		for (int i = 0; i < st->size(); i++)
		{
			this->v->set(i, st->get(i));
		}
      //for (int i = 0;i<)
		//this->v->set(v->siz, st->get()
	}

	KeyValue1 * KeyValue1::getPrev()
	{
		return(this->prev);
	}
	KeyValue1 * KeyValue1::getNext()
	{
		return(this->next);
	}
	void KeyValue1::setPrev(KeyValue1 * prev)
	{
		this->prev = (KeyValue1 *)prev;                                                                                
	}
	void KeyValue1::setNext(KeyValue1 * next)
	{
		this->next = (KeyValue1 *)next;
	}