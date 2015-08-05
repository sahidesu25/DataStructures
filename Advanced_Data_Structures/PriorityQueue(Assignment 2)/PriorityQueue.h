#include"Interfaces02.h"
#include "KeyValue01.h"
#include "VectorKeyValue1.h"
#include "VectorString1.h"

class PriorityQueue : public IPriorityQueue
{
	int si;
	KeyValue1 *p = NULL;
	KeyValue1 *tail = NULL;
public:
	PriorityQueue()
{
		si = 0;
}
	~PriorityQueue()
	{
	}

	KeyValue1 * getHead();
	KeyValue1 * getTail();
	void setHead(KeyValue1 * key_value);
	
	void setTail(KeyValue1 *key_value);
	
	void enqueue(IKeyValue * key_value);
	
     void merge(IPriorityQueue * input_queue);
	 IVectorKeyValue * returnSorted();
	 int lowestKey();
	 IVectorString * lowestValues();
      void dequeue();
	 size_t size();
	 string lowestValue();
	
};