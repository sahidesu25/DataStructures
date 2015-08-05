#include "Interfaces02.h"
#include "KeyValue.h"
/*int lowestkey = int.maxvalue;
void enqueue(IkeyValue *k)
{
	if (lowestkey < k.keylowestkey)
	{
		lowestkey = k.key;
	}
	
}
void getlowestkey()
{
	return(lowestkey);
}
*/
void KeyValue::setKey(int key)
{
	this->key = key;
}

void KeyValue::setValue(std::string value)
{
	this->val = value;
	(this->value)->push_back(value);
}
int KeyValue::getKey()
{
	return(this->key);
}
std::string KeyValue::getValue()
{
	return(this->val);
	/*int i = this->value->size();
	
	return this->value->get(i);*/
}
VectorString* KeyValue::getvalues()
{
	return (this->value);
}
void KeyValue::setValues(VectorString *strings){
	for (int i = 0; i < strings->size(); i++)
	{
		
		this->value->set(i,strings->get(i));
		if (i == (strings->size() - 1))
		{
			this->value->resize(strings->size());
		}
		
	}
} 
