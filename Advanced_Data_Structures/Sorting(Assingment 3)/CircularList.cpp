
#include "Interfaces03.h"
#include "CircularList.h"



static int circularsize=0;

void CircularList :: addHead(int num)
{
	

	SingleNode03 *head = new SingleNode03();
	head->setValue(num );
	if (Tail == NULL)
	{
		head->setNext(Tail);
		Tail = head;
		circularsize++;
		
	}
	else
	{
		head->setNext(Head);
		circularsize++;
	}
	Head = head;
	Tail->setNext(Head);
	
}

void CircularList::setTail(ISingleNode03 * tail)
{

	Tail = tail;

}

ISingleNode03 * CircularList :: getTail()

{
	return Tail;
}

int CircularList :: size()
{
	return circularsize;
}



