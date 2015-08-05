#include "DoubleList.h"
#include"DoubleNode.h"
#include "Interfaces01.h"


IDoubleNode * DoubleList::getHead()
{
	return(head);
}

IDoubleNode * DoubleList::getTail(){
	return(tail);
}
void DoubleList::setHead(IDoubleNode * head)
{
	this->head = (DoubleNode*)head;
}
void DoubleList::setTail(IDoubleNode * tail)
{
	this->tail = (DoubleNode*)tail;
}
void DoubleList::addSorted(int value)
{
	DoubleNode *temp1, *temp2; 
	if (head == NULL)
	{
		DoubleNode *N = new DoubleNode();

		N->setValue(value);
		N->setNext(NULL);
		N->setPrev(NULL);
		setHead(N);
		setTail(N);
		
		temp1 = (DoubleNode*)DoubleList::getHead();
		temp2 = (DoubleNode*)temp1->getNext();


	}
	else 

	{
		DoubleNode *N = new DoubleNode();

		N->setValue(value);
		temp1 = (DoubleNode*)DoubleList::getHead();
		temp2 = (DoubleNode*)temp1->getNext();

		

		
		if ((temp1->getPrev() == NULL) && (temp2==NULL) && (temp1->getValue() >N->getValue() ))
		{
			temp1->setPrev(N);
			N->setNext(temp1);
			setHead(N);
			temp1 = N;
			temp2 = (DoubleNode*)temp1->getNext();
			setTail(temp2);
			

		}
		else if ((temp1->getNext() == NULL) && (temp2==NULL) && (temp1->getValue() < value))
		{
			N->setPrev(temp1);
			temp1->setNext(N);
			N->setNext(NULL);
			temp2 = (DoubleNode*)temp1->getNext();
			setTail(temp2); 

		}
		else
		{
			if (temp1->getValue() > N->getValue())
			{
				temp1->setPrev(N);
				N->setNext(temp1);
				N->setPrev(NULL);
				setHead(N);
			}
			else
			{
				int found = 0;
				while ((temp2!= NULL) && (found == 0))
				{
					if ((temp1->getValue() < N->getValue()) && (temp2->getValue() > N->getValue()))
					{
						temp1->setNext(N);
						N->setPrev(temp1);
						N->setNext(temp2);
						temp2->setPrev(N);
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
				if ((temp1->getValue() < N->getValue()) && (found == 0))
				{
					temp1->setNext(N);
					N->setPrev(temp1);
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
}

void DoubleList::orderSort2()
{
	int i = 0;
	DoubleNode *current, *temp, *next, *backup;
	if ((this->getHead() == NULL) && (this->getHead()->getNext() == NULL))
	{
		return;
	}
	current = (DoubleNode*)DoubleList::getHead();
	next = (DoubleNode*)current->DoubleNode::getNext();
	temp = (DoubleNode*)next->DoubleNode::getNext();
	head = (DoubleNode*)current->DoubleNode::getNext();
	while (true)
	{
		temp = (DoubleNode*)next->getNext();
		next->setNext(current);
		backup = current;
		current->setNext(temp); 
		
		if (current->getNext()!=NULL)
		temp->setPrev(current);
		current->setPrev(next);
		if (i == 0)
		{
			next->setPrev(NULL);
		}

		
		if (((current->getNext()) != NULL) && (((current->getNext())->getNext()) != NULL))
		{
			current = (DoubleNode*)current->getNext();
			next = (DoubleNode*)current->getNext();
			backup->setNext(next);
			next->setPrev(backup);
			
		}
		else
		{
			if (current->getNext() == NULL)
			{
				setTail(current);
			}
			else if (current->getNext()->getNext() != NULL)
			{
				setTail(current->getNext());
	
			}
			break;
		}
		i++;
	}

}


	void DoubleList::orderSort3(){


		DoubleNode *current, *next, *temp, *previous, *backup;
		if ((this->DoubleList::getHead() == NULL) || (this->getHead()->getNext() == NULL) || (this->getHead()->getNext()->getNext() == NULL))
		{
			return;
		}
		current = (DoubleNode*)DoubleList::getHead();
		next = (DoubleNode*)current->DoubleNode::getNext()->getNext();
		temp = (DoubleNode*)next->DoubleNode::getNext();
		head = (DoubleNode*)current->DoubleNode::getNext()->getNext();
		int i = 0;

		while (true)
		{

			temp = (DoubleNode*)next->getNext();
			next->setNext(current->getNext());
			(current->getNext())->setPrev(next);
			backup = (DoubleNode*)current->getNext();
			backup->setNext(current);
			current->setPrev(backup);
			previous = current;
			current->setNext(temp);
			if (temp != NULL)
				temp->setPrev(current);
			else
				current->setNext(NULL); 
			if (i == 0)
			{
				next->setPrev(NULL);
			}
			if (((current->getNext()) != NULL) && (((current->getNext())->getNext()) != NULL) && (((current->getNext())->getNext())->getNext() != NULL))
			{
				current = (DoubleNode*)current->getNext();
				next = (DoubleNode*)current->getNext()->getNext();
				previous->setNext(next);
				next->setPrev(previous);

			}
			else
			{
				
				 if (((current->getNext()) != NULL) && (((current->getNext())->getNext()) != NULL))
				{
					previous = current;
					current = (DoubleNode*)current->getNext();
					next = (DoubleNode*)current->getNext();
					next->setNext(current); 
					previous->setNext(next);
					next->setPrev(previous);
					current->setNext(NULL);
					current->setPrev(next);
					setTail(current);
					break;
				}
				else
				{
					if (current->getNext() != NULL)
					{
						current = (DoubleNode*)current->getNext();
						setTail(current);
						break;
					}
					else
					{

						setTail(current);
						break;
					}
				}

			}
			i++;
		}
	}




	void DoubleList::reverse()
	{
		DoubleNode *current, *next = NULL;
		if ((this->DoubleList::getHead() == NULL) || (this->DoubleList::getHead()->getNext() == NULL))
		{
			return;
		}
		current = (DoubleNode*)DoubleList::getHead();
		DoubleNode *temp = head;
		head = tail;
		tail = temp;
		
		while (current != NULL)
		{
			next = (DoubleNode*)current->getPrev();
			current->setPrev(current->getNext());
			current->setNext(next);
			current = (DoubleNode*)current->getPrev();
			
		}
	}

	


void DoubleList::sequenceOrderSort()
{
	int k = 1;
	DoubleNode *current, *temp = NULL, *next = NULL, *backup;
	if ((this->DoubleList::getHead() == NULL) || (this->DoubleList::getHead()->getNext() == NULL))
	{
		return;
	}
	current = (DoubleNode*)DoubleList::getHead();
	backup = current;
	while (current != NULL)
	{
		int i = 0;
		while ((i < k) && (current->getNext() != NULL))
		{
			next = (DoubleNode*)current->getNext();
			current->setNext(next->getNext());
			if (current->getNext()!=NULL)
			(next->getNext())->setPrev(current);
			if (k == 1)
			{
				next->setNext(head);
				head->setPrev(next);
				next->setPrev(NULL);
				head = next;
				backup = current;
			}
			else
			{
				next->setNext(temp);
				temp->setPrev(next);
				next->setPrev(backup);
				backup->setNext(next);
				temp = next;
			}
			++i;
		}
		//if (k != 1)
		//{
			//backup->setNext(next);
		//}
		if (current->getNext() == NULL)
			setTail(current);
		temp = (DoubleNode*)current->getNext();
		backup = current;
		current = temp;
		k++;
	}
}