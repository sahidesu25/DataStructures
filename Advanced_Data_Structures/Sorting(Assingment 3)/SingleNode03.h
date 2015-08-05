
#include "Interfaces03.h"


class SingleNode03 : public ISingleNode03
{
	public:
		int Value;
		ISingleNode03 * Next = NULL;
	
	SingleNode03() {};
	~SingleNode03() {};


	int getValue();
	void setValue(int value);
	ISingleNode03 * getNext();
	void setNext(ISingleNode03 * next);


};


