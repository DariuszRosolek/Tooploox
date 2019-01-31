CXX	= g++
CXXFLAGS = -g

all: median

median: main.o extTable.o medianTable.o
	$(CXX) $(CXXFLAGS) -o median main.o extTable.o medianTable.o
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o 

extTable.o: extTable.cpp
	$(CXX) $(CXXFLAGS) -c extTable.cpp -o extTable.o 
	
medianTable.o: medianTable.cpp
	$(CXX) $(CXXFLAGS) -c medianTable.cpp -o medianTable.o 	

clean: clean-custom
	$(RM) *.o median	