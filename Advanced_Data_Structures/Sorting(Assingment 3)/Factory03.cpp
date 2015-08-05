#include "Factory03.h"
#include "LinkedListSort.h"
#include "CircularList.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "RadixSort.h"
#include "VectorDouble.h"
#include "LinkedListSort.h"
#include "KthMin.h"
#include "DoubleNode.h"
#include "DoubleList.h"
Factory03::Factory03()
{
}

Factory03::~Factory03()
{
}
 
void * Factory03::create(std::string name)
{
  if(name == "IVectorDoubleSort1"){
    return new VectorDouble();
  } else if(name == "IVectorDoubleSort2"){
    return new VectorDouble();
  } else if(name == "ISmoothSort"){
    return NULL;
  } else if(name == "IRunningMedian"){
    return NULL;
  }
  else if (name == "IRecordsSearch"){
	  return NULL;

  }
  else if (name == "ILinkedListSort"){
	  return new LinkedListSort();
 
  } else if(name == "IHeapSort"){
    return new HeapSort();
  } else if(name == "ISingleNode03"){
    return NULL;
  } else if(name == "ICircularList"){
	  return new CircularList();
  } else if(name == "IMergeSort"){
    return new MergeSort();
  } else if(name == "IRadixSort"){
	  return new RadixSort();
  }
  else if (name == "IDoubleList03"){
	  return new DoubleList();
  }

  
  else if(name == "IKthMin"){
    return new KthMin();
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory03();  
}

}
