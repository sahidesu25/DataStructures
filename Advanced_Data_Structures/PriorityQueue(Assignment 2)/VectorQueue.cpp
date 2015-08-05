#include"Interfaces02.h"
#include"KeyValue.h"
#include"VectorKeyString.h"
#include"VectorKeyValue.h"
#include"VectorQueue.h"
#include"VectorKeyString.h"

void Heap::enqueue(IKeyValue * key_value)
{
	this->sorted->push_back(key_value);
	this->sortedsize++;
	int flag = 0;
	//KeyValue *k = new KeyValue();
	//k->setKey(key_value->getKey());
	//k->setValue(key_value->getValue());
	for (int i = 0; i < this->size(); i++)
	{
		if (this->v->get(i)->getKey() == key_value->getKey())
		{
			this->v->get(i)->setValue(key_value->getValue());
			flag = 1;
			break;
		}
		
	}
	if (flag == 0)
	{
		insert(key_value);
	}
}
void Heap::insert(IKeyValue *key)
{
	this->v->push_back(key);
	upheapify(this->size() - 1);
}
int Heap::parent(int child)
{
	int p = (child - 1) / 2;
	if (child == 0)
	{
		return -1;
	}
	else
		return p;
}
int Heap::right(int parent)
{
	int r = 2 * parent + 2;
	if (r < this->size())
	{
		return r;
	}
	else
	{
		return - 1;
	}
}

int Heap::left(int parent)
{
	int l = 2 * parent + 1;
	if (l < this->size())
		return l;
	else
		return -1;


}
void Heap::upheapify(int index)
{
	if (index > 0 && parent(index) >= 0 && this->v->get(parent(index))->getKey() > this->v->get(index)->getKey())
	{
		KeyValue *temp=new KeyValue();
		KeyValue *temp1, *temp2;
		temp2 =((KeyValue*)this->v->get(index));
		//temp = (KeyValue*)this->v->get(index);

		temp1 = (KeyValue*)(this->v->get(parent(index)));
		temp->setKey(temp1->getKey());
		temp->setValue(temp1->getValue());
		temp->setValues(temp1->getvalues());
		temp1->setKey(temp2->getKey());
		temp1->setValue(temp2->getValue());
		temp1->setValues(temp2->getvalues());
		temp2->setKey(temp->getKey());
		temp2->setValue(temp->getValue());
		temp2 ->setValues(temp->getvalues());
		
		////this->v->setValues(index,temp1);
		//this->v->setValues(parent(index), temp);
		upheapify(parent(index));
	
	}
}

void Heap::downheapify(int index)
{
	int lchild = this->left(index);
	int rchild = this->right(index);
	if (lchild >= 0 && rchild >= 0 && (this->v->get(lchild)->getKey()) > (this->v->get(rchild)->getKey()))

	{
		lchild = rchild;
	}

	if( (lchild > 0) && this->v->get(index)->getKey()>(this->v->get(lchild)->getKey()))
	{
		KeyValue *temp = new KeyValue();
		KeyValue *parentnode;
		KeyValue *childnode;
		parentnode = (KeyValue*)this->v->get(index);
		childnode=(KeyValue*)this->v->get(lchild);
		temp->setKey(parentnode->getKey());
		
		//temp->setValue(parentnode->getValue());
		int i = 0;
		while (temp->getvalues() != NULL && temp->getvalues()->get(i) != "")
		{
			temp->getvalues()->get(i) = "";
			i++;
		}



		temp->setValues(parentnode->getvalues());
		parentnode->setKey(childnode->getKey());
		//parentnode->setValue(childnode->getValue());
		i = 0;
		while (parentnode->getvalues() != NULL && parentnode->getvalues()->get(i) != "")
		{
			parentnode->getvalues()->get(i) = "";
			i++;
		}

		parentnode->setValues(childnode->getvalues());
		
		childnode->setKey(temp->getKey());
		//childnode->setValue(temp->getValue());
		i = 0;
		while (childnode->getvalues() != NULL && childnode->getvalues()->get(i) != "")
		{
			childnode->getvalues()->get(i) = "";
			i++;
		}



		childnode->setValues(temp->getvalues());

		//this->v->setValues(index, temp1);
		//this->v->setValues(lchild, temp);
		downheapify(lchild);
	}

}



void Heap::merge(IPriorityQueue * input_queue)
{
	
}
IVectorKeyValue * Heap::returnSorted()
{
	mergesort(0, this->sortedsize-1);
	return(this->sorted);

}
void Heap::deletemin()
{


}
int Heap::lowestKey()
{
	if (this->size() == 0)
	{
		return 2147483647;

	}
	
	
		return(this->v->get(0)->getKey());
	
}
IVectorString * Heap::lowestValues()
{
	KeyValue* t ;
	t = (KeyValue*)this->v->get(0);
	return(t->getvalues());
	//free(t);

	//return((VectorString*)(this->v->get(0))->getvalues())
}
void Heap ::dequeue()
{

	if (this->size() == 0)
		return;
	KeyValue *k, *k1;
	k1 = (KeyValue*)this->v->get(this->v->size() - 1);
	k = (KeyValue*) this->v->get(0);
	VectorKeyValue *tempsorted = new VectorKeyValue(sortedsize);
	int j = 0;
	int tempsize = 0;
	for (int i = 0; i < sortedsize; i++)
	{
		if (k->getKey() != this->sorted->get(i)->getKey())
		{
			tempsorted->get(j)->setKey(this->sorted->get(i)->getKey());
			tempsorted->get(j)->setValue(this->sorted->get(i)->getValue());

			int x = 0;
			while (((KeyValue*)(this->sorted->get(i)))->getvalues() != NULL && ((KeyValue*)(this->sorted->get(i)))->getvalues()->get(x) != "")
			{
				((KeyValue*)(this->sorted->get(i)))->getvalues()->get(i) = "";
				x++;
			}
			((KeyValue*)tempsorted->get(j))->setValues(((KeyValue*)this->sorted->get(i))->getvalues());

			tempsize++;
		}
	
	}
	this->sorted = new VectorKeyValue(tempsize);
	this->sortedsize = tempsize;
	for (int i = 0; i < sortedsize; i++)
	{
		this->sorted->get(i)->setKey(tempsorted->get(i)->getKey());
		this->sorted->get(i)->setValue(tempsorted->get(i)->getValue());
		((KeyValue*)this->sorted->get(i))->setValues(((KeyValue*)tempsorted->get(i))->getvalues());


	}






	k->setKey(k1->getKey());
	k->setValue(k1->getValue());
	int i = 0;
	while (k->getvalues() != NULL && k->getvalues()->get(i) != "")
	{
		k->getvalues()->get(i) = "";
		i++;
	}
	k->setValues(k1->getvalues());
	//this->v->setValues(0, (KeyValue*)this->v->get(this->size() - 1));
	//k1->setKey(NULL);
	//k1->setValues(NULL);
	this->v->pop_back();
	this->downheapify(0);
}
size_t Heap::size()
{
	return(this->v->size());
}
void Heap::mergesort(int low, int high )
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merging(low, mid, high);
     }
}
void Heap::merging(int low, int mid, int high)
{
	int h, i, j, k;
	VectorKeyValue *b = new VectorKeyValue(this->sortedsize);
	h = low;
	i = low;
	j = mid + 1;
	while ((h <= mid) && (j <= high))
	{
if (((this->sorted)->get(h))->getKey() <= ((this->sorted)->get(j))->getKey())
		
{
	KeyValue *k = (KeyValue*)((this->sorted)->get(h));
	KeyValue *k1 = (KeyValue*)(b)->get(i);
	k1->setKey(k->getKey());
	k1->setValue(k->getValue());
	while (k1->getvalues() != NULL && k1->getvalues()->get(i) != "")
	{
		k1->getvalues()->get(i) = "";
		i++;
	}

	k1->setValues( k->getvalues());

			//b->setValues(i, (KeyValue*)this->v->get(h));
			h++;
			 
			/*KeyValue *temp = new KeyValue();
			temp = (KeyValue*)(this->v)->get(h);
			b->set(i, temp);
			free(temp);
			h++;*/

		}
		else
		{
			KeyValue *k = (KeyValue*)((this->sorted)->get(j));
			KeyValue *k1 = (KeyValue*)(b)->get(i);
			k1->setKey(k->getKey());
			k1->setValue(k->getValue());
			while (k1->getvalues() != NULL && k1->getvalues()->get(i) != "")
			{
				k1->getvalues()->get(i) = "";
				i++;
			}

			k1->setValues(k->getvalues());
			
			//b->setValues(i, (KeyValue*)(this->v)->get(j));
			
			j++;


		}
		i++;
	}

	if (h > mid)
	{
		for (k = j; k <= high; k++)
		{
			KeyValue *k2 = (KeyValue*)((this->sorted)->get(k));
			KeyValue *k1 = (KeyValue*)(b)->get(i);
			k1->setKey(k2->getKey());
			k1->setValue(k2->getValue());
			while (k1->getvalues() != NULL && k1->getvalues()->get(i) != "")
			{
				k1->getvalues()->get(i) = "";
				i++;
			}

			k1->setValues(k2->getvalues());


			//b->setValues(i, (KeyValue*)this->v->get(k));
			i++;
			/*KeyValue * temp = new KeyValue();
			temp = (KeyValue*)(this->v)->get(k);
			b->set(i, temp);
			i++;
			free(temp);*/
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{
			KeyValue *k2 = (KeyValue*)((this->sorted)->get(k));
			KeyValue *k1 = (KeyValue*)(b)->get(i);
			k1->setKey(k2->getKey());
			k1->setValue(k2->getValue());
			while (k1->getvalues() != NULL && k1->getvalues()->get(i) != "")
			{
				k1->getvalues()->get(i) = "";
				i++;
			}

			k1->setValues(k2->getvalues());

			//b->setValues(i, (KeyValue*)this->v->get(k));
			i++;
			/*KeyValue *temp = new KeyValue();
			temp = (KeyValue*)(this->v)->get(k);
			b->set(i, temp);
			i++;
			free(temp);*/
		}
	}
	for (k = low; k <= high; k++)
	{
		KeyValue *k1 = (KeyValue*)b->get(k);
		KeyValue *k2 =(KeyValue*) this->sorted->get(k);
		k2->setKey(k1->getKey());
		k2->setValue(k1->getValue());
		while (k1->getvalues() != NULL && k1->getvalues()->get(i) != "")
		{
			k1->getvalues()->get(i) = "";
			i++;
		}

		k2->setValues(k1->getvalues());
		/*KeyValue *temp = new KeyValue();
		temp = (KeyValue*)b->get(k);
		(this->v)->setValues(k, temp);
		free(temp);*/
	}

}

//VectorKeyValue* VectorQueue:: getV()
//{
	//return (VectorKeyValue*)(this->v);
//}