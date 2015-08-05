
#include "MergeSort.h"
#include "CircularList.h"




ISingleNode03* merging(ISingleNode03* left, ISingleNode03* right);
void Middleoflist(ISingleNode03** leftRef, ISingleNode03** rightRef, ISingleNode03* lhead);
void Merge_Sort(ISingleNode03** headRef);

void MergeSort :: mergeSort(ICircularList * input)
{

	ISingleNode03 *Tail =  input->getTail();
	ISingleNode03 * Head = Tail->getNext();
	Tail->setNext(NULL);


	int sizeOfCircularList = input->size();

	

	Merge_Sort(&Head);

	ISingleNode03* cur_ptr = Head;
	while (true)
	{
		cur_ptr = cur_ptr->getNext();
		if (cur_ptr->getNext() == NULL)
			break;

	}
	
	Tail = cur_ptr;
	Tail->setNext(Head);
	input->setTail(Tail);
	
	
}







void Merge_Sort(ISingleNode03** headRef)
{
	ISingleNode03* head = *headRef;
	ISingleNode03* left;
	ISingleNode03* right;
	if ((head == NULL) || (head->getNext()== NULL))
	{
		return;
	}
	Middleoflist(&left, &right, head);
	Merge_Sort(&left);
	Merge_Sort(&right);
	*headRef = merging(left, right);
}

ISingleNode03* merging(ISingleNode03* left, ISingleNode03* right)
{
	ISingleNode03 * leftptr = left;
	ISingleNode03 * rightptr = right;

	ISingleNode03* result = NULL;
	if (leftptr == NULL)
		return rightptr;
	else if (rightptr == NULL)
		return leftptr;
	if (leftptr->getValue() <= rightptr->getValue())
	{
		result = leftptr;
		result->setNext(merging(leftptr->getNext(), rightptr));
	}
	else
	{
		result = rightptr;
		result->setNext(merging(leftptr, rightptr->getNext()));
	}
	return result;
}


void Middleoflist(ISingleNode03** leftRef, ISingleNode03** rightRef, ISingleNode03* Headl)
{
	ISingleNode03* fast = NULL ;
	ISingleNode03* slow = NULL;
	ISingleNode03* first = Headl;
	if (first== NULL || first->getNext() == NULL)
	{
		*leftRef = first;
		*rightRef = NULL;
	}
	else
	{
		slow = first;
		fast = slow->getNext();
		while (fast)
		{
			if (fast->getNext() != NULL)
				fast = fast->getNext()->getNext();
			else
				break;
			slow = slow->getNext();
			
		}
		*leftRef = Headl;
		*rightRef = slow->getNext(); 
		slow->setNext(NULL);
	}
}


