
#include "SingleNode03.h"


int SingleNode03::getValue()
{
	return Value;

}
void SingleNode03 :: setValue(int value)
{
	Value = value;

}
ISingleNode03 * SingleNode03 :: getNext()
{
	return Next;

}

void SingleNode03 :: setNext(ISingleNode03 * next)
{
	Next = (SingleNode03*)next;

}