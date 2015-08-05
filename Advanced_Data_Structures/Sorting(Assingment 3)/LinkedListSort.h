
#pragma once
#include "Interfaces03.h"


class LinkedListSort : public ILinkedListSort
{
public:
	LinkedListNode * head = NULL;
	LinkedListSort() { }
	~LinkedListSort() { }
	LinkedListNode * sort(LinkedListNode * list);
   

};