#pragma once

#include "extTable.h"
#include <string>

class medianTable
{
	public:
		medianTable();
		~medianTable();
		
		string calcMedian();		
		void addElement(const uint16_t& elem);
		
	private:
		
		string output;
		extTable table;
};

