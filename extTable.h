#pragma once

#include<stdint.h>

static const uint16_t granularity = 32;//128;

using namespace std;

class extTable
{
	public:
		extTable();
		~extTable();
		void addElement(const uint16_t&);
		uint16_t getElement(const uint16_t&);
		uint16_t getAmount();
		
	private:
		extTable(const extTable&);
		extTable& operator=(const extTable&);
				
		uint16_t getPlaceIndicator(const uint16_t& elem, const uint16_t& begin,
								   const uint16_t& end);
		
		uint16_t max;
		uint16_t amount;
		uint16_t* elements;
};

