
#include "Interfaces03.h"
#include "SingleNode03.h"



class CircularList : public ICircularList
{
	public:
		int Number;
		

		ISingleNode03 * Tail=NULL;
		ISingleNode03 * Head = NULL;

	CircularList() {}
	~CircularList() {}
	 void addHead(int number);
	
	 ISingleNode03 * getTail();
	void setTail(ISingleNode03 * tail);
	 
	int size();
		


};

