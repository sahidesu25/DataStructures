#include "Interfaces04.h"
#include "Point.h"

class RTree : public IRTree {
public:


	RTree() {}
	~RTree() {}
	void hilbertSort(std::vector<IPoint *>& points);
	void bulkInsert(std::vector<IPoint *>& points);
	std::vector<IPoint *> findWithin(IPoint * top_left, IPoint * bottom_right);

private:
	std::vector<IPoint *> _points;
};