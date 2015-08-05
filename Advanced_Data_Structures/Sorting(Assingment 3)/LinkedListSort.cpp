#include "LinkedListSort.h"



LinkedListNode* merging(LinkedListNode* left, LinkedListNode* right);
void Middleoflist(LinkedListNode** leftRef, LinkedListNode** rightRef, LinkedListNode* lhead);
void Merge_Sort(LinkedListNode** headRef);



LinkedListNode * LinkedListSort::sort(LinkedListNode * list)
{
	LinkedListNode *headRef = list;


	Merge_Sort(&headRef);

	return headRef;
}



void Merge_Sort(LinkedListNode** headRef)
{
	LinkedListNode* head = *headRef;
	LinkedListNode* left;
	LinkedListNode* right;
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}
	Middleoflist(&left, &right, head);
	Merge_Sort(&left);
	Merge_Sort(&right);
	*headRef = merging(left, right);
}


LinkedListNode* merging(LinkedListNode* left, LinkedListNode* right)
{
	LinkedListNode * leftptr = left;
	LinkedListNode * rightptr = right;

	LinkedListNode* result = NULL;
	if (leftptr == NULL)
		return rightptr;
	else if (rightptr == NULL)
		return leftptr;
	if (leftptr->key <= rightptr->key)
	{
		result = leftptr;
		result->next=merging(leftptr->next, rightptr);
	}
	else
	{
		result = rightptr;
		result->next=merging(leftptr, rightptr->next);
	}
	return result;
}




void Middleoflist(LinkedListNode** leftRef, LinkedListNode** rightRef, LinkedListNode* Headl)
{
	LinkedListNode* fast = NULL;
	LinkedListNode* slow = NULL;
	LinkedListNode* first = Headl;
	if (first == NULL || first->next == NULL)
	{
		*leftRef = first;
		*rightRef = NULL;
	}
	else
	{
		slow = first;
		fast = slow->next;
		while (fast)
		{
			if (fast->next != NULL)
				fast = fast->next->next;
			else
				break;
			slow = slow->next;

		}
		*leftRef = Headl;
		*rightRef = slow->next;
		slow->next=NULL;
	}
}




