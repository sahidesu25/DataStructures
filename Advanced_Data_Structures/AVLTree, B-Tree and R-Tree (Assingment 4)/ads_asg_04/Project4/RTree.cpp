

#include "RTree.h"

void RTree::hilbertSort(std::vector<IPoint *>& points)
{
}

void RTree::bulkInsert(std::vector<IPoint *>& points)
{
	_points = points;
}

std::vector<IPoint *> RTree::findWithin(IPoint * top_left, IPoint * bottom_right)
{
	std::vector<IPoint *> vector;
	int counter = 0;
	while (counter<_points.size())
	{
		IPoint *temp = _points.at(counter);
		if ((temp->getX() >= top_left->getX() && temp->getX() <= bottom_right->getX() && temp->getY() >= top_left->getY() && temp->getY() <= bottom_right->getY()))
		{
			
				vector.push_back(temp);
			
		}
		counter++;
	}
	return vector;
}