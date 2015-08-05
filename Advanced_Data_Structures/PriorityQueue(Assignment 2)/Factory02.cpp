#include "Factory02.h"
#include "Interfaces02.h"
#include "KeyValue.h"
#include "LinkListNode.h"
#include "VectorQueue.h"
#include "linkedQueue.h"
#include "priorityqueue.h"
#include "KeyValue01.h"

Factory02::Factory02()
{
}

Factory02::~Factory02()
{
}
 
void * Factory02::create(std::string name)
{
  if(name == "IKeyValue1"){
	  return new KeyValue1();
  } else if(name == "IKeyValue2"){
	  return new KeyValue();
  } else if(name == "IKeyValue3"){
	  return new DoubleNode();
  } else if(name == "IKeyValue4"){
    return new DoubleNode();
  } else if(name == "IPriorityQueue1"){
    return new PriorityQueue();
  } else if(name == "IPriorityQueue2"){
    return new Heap();
  } else if(name == "IPriorityQueue3"){
    return new LinkedQueue();
  } else if(name == "IPriorityQueue4"){
    return new LinkedQueue();
  } else {
    return new KeyValue();
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory02();  
}

}
