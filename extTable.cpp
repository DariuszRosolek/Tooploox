#include "extTable.h"
#include <cstring>

extTable::extTable():
	max(granularity),
	amount(0)
{
	elements = new uint16_t[max];
}

extTable::~extTable()
{
	delete[] elements;
}

void extTable::addElement(const uint16_t& elem)
{
	if (amount == 0)
	{
		elements[0] = elem;
		amount++;
		return;
	}	
		
	if (amount == max)
	{
		max = max + granularity;
		uint16_t* temp = elements;
		elements = new uint16_t[max];
		memcpy(elements, temp, (amount)*sizeof (uint16_t) );
		delete[] temp;	

	}

	uint16_t i = getPlaceIndicator(elem, 0, amount);
	if (i != amount)
	{
		memmove(elements+i+1, elements+i, (amount-i)*sizeof (uint16_t));
	}
	elements[i] = elem;	
	amount++;
}

uint16_t extTable::getElement(const uint16_t& i)
{
	return elements[i];
}

uint16_t extTable::getAmount()
{
	return amount;
}

uint16_t extTable::getPlaceIndicator(const uint16_t& elem, const uint16_t& begin,
									 const uint16_t& end)
{
	if ((begin+1) == end)
	{
		return (elem < elements[begin]) ? begin : end;
	}
	uint16_t mid = (begin + end) / 2;
	return (elem < elements[mid]) ? getPlaceIndicator(elem, begin, mid) : getPlaceIndicator(elem, mid, end);	
}
