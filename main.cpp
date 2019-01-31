#include <cstdlib>
#include <iostream>
#include <sstream>
#include "medianTable.h"

int main(int argc, char** argv) 
{	
	std::cout<<"begin \n";
		
	medianTable array;
	std::string input;
	getline(cin, input);	
	std::istringstream strstr (input);

	for (std::string arg; std::getline(strstr, arg, ' '); )
	{
		if (arg == "q")
		{	
			cout<<"quit";
			return 0;
		}
		if (arg == "m")
		{
			cout<<array.calcMedian()<<endl;
			continue;
		}
		array.addElement(atoi(arg.data()));	
	}
	return 0;
}
