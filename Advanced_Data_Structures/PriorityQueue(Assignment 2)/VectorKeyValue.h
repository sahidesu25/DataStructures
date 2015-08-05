#pragma once
#include "Interfaces02.h"
#include "KeyValue.h"
#include<string>
#include<cstring>
const int VECTORSIZE =20;
class VectorKeyValue : public IVectorKeyValue
{
	int vsize;
	int capacity;
	KeyValue *buffer;
	int index;


public:
	VectorKeyValue()
		
	{
		
		capacity = VECTORSIZE;
		buffer = new KeyValue[capacity]();
		vsize = 0;
		index = 0;
		
	}
   
   VectorKeyValue(int n)
	   
	   
   {

	  
	   capacity = n;
	   buffer= new KeyValue[capacity];
	   vsize = 0;
	   index = 0;

		 
   }
	   
   VectorKeyValue(int,const VectorKeyValue&);
   ~VectorKeyValue() {
	   delete[]buffer;
   }
   void push_back(IKeyValue * item);
 void pop_back();
 IKeyValue * get(int index) ;
void set(int index, IKeyValue * item);
size_t size();
void expand(int n);
void setValues(int n, KeyValue *k);
};
