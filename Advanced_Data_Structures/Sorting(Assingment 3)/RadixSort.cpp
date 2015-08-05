#include "Interfaces03.h"
#include "RadixSort.h"
using namespace std;

std::vector<string> sortedvec;
 int charindex = 0;
void _sort(std::vector<std::string> * line, int index);
void _sort(std::vector<std::string> * line, int index)
{

	//vector<vector<string>> buckets(96);

	vector<string> buckets[96];

	bool valid = false;
	
	for(int k = 0; k < line->size(); k++)

	{
		
		if (index >= line->at(k).size())
		{
			buckets[0].push_back(line->at(k));
		}
		else
		{
			buckets[(int)((line->at(k)))[index] - 31].push_back(line->at(k));
			valid = true;
		}
	}
	if (valid==false)
	{
		for (int k = 0; k < line->size(); k++)
		{


			sortedvec.push_back(line->at(k));
		}
	}
	else
	{

		for (int p = 0; p < 96; p++)

		{

			_sort(&(buckets[p]), index + 1); 
		}

		



	}
}
void RadixSort::sort(std::vector<std::string> & data)
{
	_sort(&data,charindex);
	data = sortedvec;
	sortedvec.clear();
	
	
}


