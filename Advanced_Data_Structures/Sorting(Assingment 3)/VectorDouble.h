#pragma once
#include "Interfaces03.h"
class VectorDouble : public IVectorDoubleSort
{
public:
	
	VectorDouble();
	 ~VectorDouble();
	void sort(std::vector<double>& vector);
	void heapify(double r[], int size, int inde);
	void buildheap(double *arr, int n);
	void heapsort(double *j, int n);
};
