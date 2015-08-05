
#include "Interfaces03.h"




class MergeSort : public IMergeSort
{
	public :
		MergeSort() {};
	~MergeSort() {};
	void mergeSort(ICircularList * input);
	
};

