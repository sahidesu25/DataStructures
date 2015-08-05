#include "Factory04.h"
#include "Interfaces04.h"
#include "AvlTree.h"
#include "AvlNode.h"
#include "BTree.h"
#include "BTreeNode.h"

Factory04::Factory04()
{
}

Factory04::~Factory04()
{
}
 
void * Factory04::create(std::string name)
{
  if(name == "IAVLTree"){
    return new AvlTree();
  } else if(name == "IPoint"){
    return NULL;
  } else if(name == "IRTree"){
    return NULL;
  } else if(name == "IBTree"){
    return new BTree();
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory04();  
}

}
