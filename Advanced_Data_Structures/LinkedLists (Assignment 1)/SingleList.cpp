#include "SingleList.h"
#include "Interfaces01.h"

ISingleNode *  SingleList::getHead()
{
	return(head);
}

void SingleList::setHead(ISingleNode * head){
	this->head = (SingleNode *)head;
}

void SingleList::addHead(int value)
{
	SingleNode *N = new SingleNode();
	N->setValue(value);
	N->setNext(head);
	setHead(N);
}

void SingleList::orderSort2()
{
	SingleNode *current, *next, *temp,*previous;
	if ((this->SingleList::getHead() == NULL) || (this->SingleList::getHead()->getNext() == NULL))
	{
		return;
	}
	current = (SingleNode*) SingleList::getHead();
	next = (SingleNode*)current->SingleNode::getNext();
	temp = (SingleNode*)next->SingleNode::getNext();
	head = (SingleNode*)current->SingleNode::getNext();

	while (true)
	{
		
		temp = (SingleNode*)next->getNext();
		next->setNext(current);
		previous = current;
		current->setNext(temp);
		if (((current->getNext()) != NULL) && (((current->getNext())->getNext()) != NULL))
		{
			current = (SingleNode*)current->getNext();
			next = (SingleNode*)current->getNext();
			previous->setNext(next);

		}
		else
		{
			break;
		}



	}


}




void SingleList::orderSort3(){


	SingleNode *current, *next, *temp, *previous,*backup;
	if ((this->SingleList::getHead() == NULL) || (this->getHead()->getNext() == NULL) || (this->getHead()->getNext()->getNext() == NULL))
	{
		return;
	}
	current = (SingleNode*)SingleList::getHead();
	next = (SingleNode*)current->SingleNode::getNext()->getNext();
	temp = (SingleNode*)next->SingleNode::getNext();
	head = (SingleNode*)current->SingleNode::getNext()->getNext();

	while (true)
	{

		temp = (SingleNode*)next->getNext();
		next->setNext(current->getNext());
		backup = (SingleNode*)current->getNext();
		backup->setNext(current);
		previous = current;
		current->setNext(temp);
		if (((current->getNext()) != NULL) && (((current->getNext())->getNext()) != NULL) && (((current->getNext())->getNext())->getNext() != NULL))
		{
			current = (SingleNode*)current->getNext();
			next = (SingleNode*)current->getNext()->getNext();
			previous->setNext(next);

		}
		else
		{
			if (((current->getNext()) != NULL) && (((current->getNext())->getNext()) != NULL))
			{
				previous = current;
				current =(SingleNode*) current->getNext();
				next = (SingleNode*)current->getNext();
				next->setNext(current);
				previous->setNext(next);
				current->setNext(NULL);
				break;
			}
			else
			{
				break;
			}
			
		}
	}
}

void SingleList::reverse()
{
	SingleNode *current, *next = NULL, *temp;
	if ((this->SingleList::getHead() == NULL) || (this->SingleList::getHead()->getNext() == NULL))
	{
		return;
	}
	current = (SingleNode*)SingleList::getHead();
	while ((current->getNext()) != NULL)
	{
		next = (SingleNode*)current->getNext();
		current->setNext(next->getNext());
		next->setNext(head);
		head = next;

	}
}

	


	
	

void SingleList::sequenceOrderSort()
	{
	int k = 1;
	SingleNode *current, *temp=NULL, *next=NULL, *backup;
	if ((this->SingleList::getHead() == NULL) || (this->SingleList::getHead()->getNext() == NULL))
	{
		return;
	}
	current = (SingleNode*)SingleList::getHead();
	backup = current;
	while (current != NULL)
	{
		int i = 0;
		while ((i < k) && (current->getNext() != NULL))
		{
			next = (SingleNode*)current->getNext();
			current->setNext(next->getNext());
			if (k == 1)
			{
				next->setNext(head);
				head = next;
				backup = current;
			}
			else
			{
				next->setNext(temp);
				temp = next;
			}
			++i;
		}
		if (k != 1)
		{
			backup->setNext(next);
		}
		temp = (SingleNode*)current->getNext();
		backup = current;
		current = temp;
		k++;
		}
	}


	




