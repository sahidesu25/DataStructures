#include "HeapSort.h"
#include "iostream"
//#include "vector.h"
using namespace std;




void HeapSort::buildheap(int *arr, int limit_size)
{
	for (int k = limit_size; k >= 0; k--)
	{
		heapify(arr, limit_size, k);
	}
}
void HeapSort::heapify(int arr[], int size, int inde)
{
	int index = inde;
	int left;
	int temp;
	int right;
	int max;
	while (true)
	{
		
		right = 2 * index + 2;
		left = 2 * index + 1;
		if (left >= size)
			return;
		else if (right >= size)
		{
			max = left;
		}
		else if ( arr[right]<arr[left])
		{
			max = left;
		}
		else if (arr[right] > arr[left])
			max = right;
		if (arr[max] > arr[index])
		{
			
			temp = arr[max];
			arr[max] = arr[index];
			arr[index] = temp;
			index = max;
			
		}
		else
			return;
	}
}


void HeapSort::heapsort(int *arr, int n)
{
	int heapsize = n;
	for (int last = n-1 ; last > 0; last--)
	{
		int temp = arr[last];
		arr[last] = arr[0];
		arr[0] = temp;
		heapsize = heapsize - 1;
		heapify(arr, heapsize, 0);

	}
}


HeapSort::HeapSort()
{

}
HeapSort::~HeapSort()
{
}

void HeapSort::sort(std::vector<int>& vector)
{
	
int *vecarray = new int[499999];
	for (int i = 0; i < vector.size(); i++)
	{
	
		vecarray[i] = vector[i];
	}
	
	buildheap(vecarray, vector.size());
	heapsort(vecarray, vector.size());
	for (int i = 0; i < vector.size(); i++)
	{
		vector[i] = vecarray[i];
		
	}
	


}