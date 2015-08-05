#pragma once
#include "Interfaces03.h"
#include "DoubleList.h"
#include "DoubleNode.h"
class KthMin : public IKthMin
{
public:
	KthMin(){}
	~KthMin(){}

	int findKthMin(IDoubleList03 * data, int k);
};