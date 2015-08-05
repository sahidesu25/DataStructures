#pragma once
#include "PriorityQueue.h"
#include "iostream"
#include "Interfaces02.h"
#include "VectorKeyValue1.h"
#include "KeyValue.h"
#include "VectorString1.h"

#define INTERFACES_KEYVALUE
using namespace std;




KeyValue1 * PriorityQueue::getHead()
	{
		return(p);
	}
KeyValue1 * PriorityQueue::getTail()
	{
		return(tail);
	}
void PriorityQueue::setHead(KeyValue1 * key_value)
{
	//p = key_value;
	p->setPrev(key_value);
	key_value->setNext(p);
	p = key_value;

}
void PriorityQueue::setTail(KeyValue1 *key_value)
{
	//tail = key_value;
	tail->setNext(key_value);
	key_value->setPrev(tail);
	tail = key_value;
}


void PriorityQueue::enqueue(IKeyValue * key_value)
{
	//si++;
	KeyValue1 *temp, *current;
	temp = new KeyValue1();
	temp->setKey(key_value->getKey());
	temp->setValue(key_value->getValue());

	if (p == NULL)
	{
		p = tail = temp;
		si++;
		return;
	}
	
	
	else if (key_value->getKey() < p->getKey())
	{
		setHead((KeyValue1*)key_value);
		si++;
		return;
	}
	else if (key_value->getKey() == p->getKey())
	{
		p->setValue(key_value->getValue());
		return;
	}
	else if (key_value->getKey() > tail->getKey())
	{
		
		setTail((KeyValue1*)key_value);
		si++;
	}
	else if (key_value->getKey() == tail->getKey())
	{
		tail->setValue(key_value->getValue());
		return;
	}
	else
	{

		current = p;

		while (key_value->getKey() > current->getKey())
			current = (KeyValue1 *)current->getNext();

		if (key_value->getKey() == current->getKey())

			current->setValue(key_value->getValue());
		else
		{
			si++;
		current = (KeyValue1 *)current->getPrev();
		
			temp->setNext(current->getNext());
			current->getNext()->setPrev(temp);

			current->setNext(temp);
		
		temp->setPrev(current);
	}
}
}

void PriorityQueue::merge(IPriorityQueue * input_queue)
{

}
IVectorKeyValue * PriorityQueue::returnSorted()
{
	VectorKeyValue1 *q;
	q = new VectorKeyValue1();
	KeyValue1 *ke = new KeyValue1();
	KeyValue1 *h;
	ke = p;
	while (ke != NULL)
	{
		for (int i = 0; i < ke->getvalues()->size();i++)
		{
			h = new KeyValue1();
			h->setKey(ke->getKey());
		
			h->setValue(ke->getvalues()->get(i));
		    q->push_back(h);
		}
		ke = ke->getNext();
	}
	return q;
}
int PriorityQueue::lowestKey()
{ 

	return getHead()->getKey();



	//int lk = ;

	//for (int i = 1; i <= this->size(); i++)
	//{
		//if (this->q->get(i)->getKey() < lk)
		//{
			//lk = this->q->get(i)->getKey();
		//}
	//}
	//return lk;
}


string PriorityQueue::lowestValue()
{
	return getHead()->getValue();
}
IVectorString * PriorityQueue::lowestValues()
{
	return getHead()->getvalues();
	
}
void PriorityQueue::dequeue()
{
	p = p->getNext();
	
	
	if (getHead() != NULL)
	{
		p->setPrev(NULL);
	}
	si--;
}
size_t PriorityQueue::size()
{
	return si;
}


