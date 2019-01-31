#include <sstream>
#include <iomanip>
#include "medianTable.h"

medianTable::medianTable()
{
}

medianTable::~medianTable()
{
}

string medianTable::calcMedian()
{
	uint16_t capacity = table.getAmount();
	float median = (capacity % 2) ? (static_cast<float> (table.getElement(capacity/2))) :
		(static_cast<float> (table.getElement(capacity/2)) + static_cast<float> (table.getElement(capacity/2 - 1))) /2.0;

	std::ostringstream ss;
	ss <<std::setprecision(1)<<std::fixed<<median;
	std::string s(ss.str());
	output = output + s + " ";

	return output;
}

void medianTable::addElement(const uint16_t& elem)
{
	table.addElement(elem);
}
