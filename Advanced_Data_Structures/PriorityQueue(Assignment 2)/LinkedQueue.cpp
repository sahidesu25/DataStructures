#include"Interfaces02.h"
#include"LinkListNode.h"
#include"linkedQueue.h"
#include"VectorKeyString.h"
void LinkedQueue::enqueue(IKeyValue * key_value)
{


	DoubleNode *temp1, *temp2;
	if (head == NULL)
	{
		DoubleNode *N = new DoubleNode();
		N->setKey(key_value->getKey());
		N->setValue(key_value->getValue());
		N->setNext(NULL);
	
		setHead(N);
		setTail(N);

		temp1 = (DoubleNode*)LinkedQueue::getHead();
		temp2 = (DoubleNode*)temp1->getNext();


	}
	else

	{
		DoubleNode *N = new DoubleNode();
		N->setKey(key_value->getKey());
		N->setValue(key_value->getValue());
		temp1 = (DoubleNode*)getHead();
		temp2 = (DoubleNode*)temp1->getNext();




		if ((temp2 == NULL) && (temp1->getKey() >N->getKey()))
		{
			
			N->setNext(temp1);
			setHead(N);
			temp1 = N;
			temp2 = (DoubleNode*)temp1->getNext();
			setTail(temp2);


		}
		else if ((temp1->getNext() == NULL) && (temp2 == NULL) && (temp1->getKey() < key_value->getKey()))
		{
			
			temp1->setNext(N);
			N->setNext(NULL);
			temp2 = (DoubleNode*)temp1->getNext();
			setTail(temp2);

		}
		else
		{
			if (temp1->getKey() > N->getKey())
			{
			
				N->setNext(temp1);
				
				setHead(N);
			}
			else
			{
				int found = 0;
				while ((temp2 != NULL) && (found == 0))
				{
					if ((temp1->getKey() < N->getKey()) && (temp2->getKey() > N->getKey()))
					{
						temp1->setNext(N);
						
						N->setNext(temp2);
						
						found = 1;
					}
					else
					{
						temp1 = (DoubleNode*)temp1->getNext();
						temp2 = (DoubleNode*)temp1->getNext();
						if (temp2 != NULL)
							setTail(temp2);
						else
							setTail(temp1);
					}

				}
				if ((temp1->getKey() < N->getKey()) && (found == 0))
				{
					temp1->setNext(N);
					
					N->setNext(NULL);
					setTail(N);
				}
				if (found == 1)
				{
					while (tail->getNext() != NULL)
					{
						tail = (DoubleNode*)tail->getNext();
					}
				}
			}
		}

	}
	this->qsize++;

}
void LinkedQueue::merge(IPriorityQueue * input_queue)
{DoubleNode *res = SortedMerge(this->head, ((LinkedQueue*)input_queue)->getHead());
	setHead(res);
	this->qsize = this->qsize + 10;
}
IVectorKeyValue * LinkedQueue::returnSorted()
{
	return 0;
}
int LinkedQueue::lowestKey()
{
	return(this->head->getKey());
}
IVectorString * LinkedQueue::lowestValues()
{
	std::string lowstring = this->head->getValue();
	VectorString *minvalue = new VectorString(10);

	minvalue->push_back(lowstring);
	
	return(minvalue);
}
void LinkedQueue::dequeue()
{
	DoubleNode *temp1, *temp2;
	temp1 = (DoubleNode*)LinkedQueue::getHead();
	temp2 = temp1->getNext();
	setHead(temp2);
	temp1->setNext(NULL);
	this->qsize--;



}
size_t LinkedQueue::size()
{
	return(this->qsize);
}
void LinkedQueue::setHead(DoubleNode * head)
{
	this->head = head;
}
DoubleNode * LinkedQueue::getHead()
{
	return(this->head);
}
void LinkedQueue::setTail(DoubleNode * tail)
{
	this->tail = tail;
}
DoubleNode * LinkedQueue::getTail()
{
	return(this->tail);
}
void LinkedQueue::setMin(DoubleNode * min)
{
	this->min = min;
}
DoubleNode * LinkedQueue::getMin()
{
	return(this->min);
}
DoubleNode* LinkedQueue::SortedMerge(DoubleNode* a, DoubleNode* b)
{
	DoubleNode* result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->getKey() <= b->getKey())
	{
		result = a;
		result->setNext( SortedMerge(a->getNext(), b));
	}
	else
	{
		result = b;
		result->setNext ( SortedMerge(a, b->getNext()));
	}
	return(result);
}

