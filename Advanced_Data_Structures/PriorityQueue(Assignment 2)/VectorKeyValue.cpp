#include "Interfaces02.h"
#include "KeyValue.h"
#include "VectorKeyValue.h"
#include<cstring>




/*VectorKeyValue::VectorKeyValue( int capacity)
{
	//const int a = 10;
	this->vsize = 0;
	this->capacity=capacity;
	this->buffer[this->capacity];

}*/
VectorKeyValue::VectorKeyValue(int capacity, const VectorKeyValue&v)
{
	this->capacity = capacity;
	this->vsize = v.vsize;
	this->buffer[this->capacity];
	for (int i = 0; i < v.vsize; i++)
	{

		this->buffer[i].setKey(v.buffer[i].getKey());
		this->buffer[i].setValue(v.buffer[i].getValue());

	}
}






void VectorKeyValue::push_back(IKeyValue * item)
{
	if (this->vsize == this->capacity)
	{
		VectorKeyValue::expand(this->capacity + VECTORSIZE);
	}
	//this->buffer[this->vsize] = (KeyValue*)item;
		
		
		this->buffer[this->vsize].setKey(item->getKey());
		this->buffer[this->vsize].setValue(item->getValue());
		 
		this->vsize++;
		

		
		
	 
}
void VectorKeyValue::pop_back()
{
	//delete &(this->buffer[this->vsize]);
	this->vsize=this->vsize-1;

	KeyValue *temp = new KeyValue[this->vsize];
	for (int i = 0; i < this->vsize; i++)
	{
		temp[i].setKey(this->buffer[i].getKey());
		temp[i].setValue(this->buffer[i].getValue());
		temp[i].setValues(this->buffer[i].getvalues());

	}
	delete[] buffer;
	buffer = temp;

}
IKeyValue * VectorKeyValue::get(int index)
{
	KeyValue *temp;
	temp = &(this->buffer[index]);
	temp->getKey();
	temp->getValue();
	temp->getvalues();
	return(temp);

	
	/*KeyValue *temp= new KeyValue();
	temp->setKey(this->buffer[index].getKey());
	temp->setValues(this->buffer[index].getvalues());
	return temp;*/
	//return(&(this->buffer[index]));
}
void VectorKeyValue::set(int index, IKeyValue * item)
{
	this->buffer[index].setKey(item->getKey());
	this->buffer[index].setValue(item->getValue());
	

}
void VectorKeyValue::setValues(int index, KeyValue *k)
{
	this->buffer[index].setKey(k->getKey());
	//VectorString *temp;
	//temp = k->getvalues();
	this->buffer[index].setValue(k->getValue());
	this->buffer[index].setValues(k->getvalues());

	
}
size_t VectorKeyValue::size()
{
	return(this->vsize);
}
void VectorKeyValue::expand(int n)
{
	if (n > this->capacity)
	{
		this->capacity = n;
		KeyValue *temp;
		temp = new KeyValue[this->capacity];
		for (int i = 0; i < this->vsize; i++)
		{
			temp[i].setKey(this->buffer[i].getKey());
			temp[i].setValue(this->buffer[i].getValue());
			
		}
		delete[] buffer;
		buffer = temp;
		

	}
}


	  
	



