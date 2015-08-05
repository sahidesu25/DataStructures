#pragma once
#include "Interfaces03.h"
class HeapSort : public IHeapSort
{
	public : 
	HeapSort();
	virtual ~HeapSort();
	void sort(std::vector<int>& vector) ;
	void heapify(int r[], int size, int inde);
	void buildheap(int *arr, int n);
	void heapsort(int *j, int n);
};
