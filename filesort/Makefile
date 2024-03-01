CXX = g++
CXXFLAGS = -std=c++17

all: filesort

filesort: main.o DisplayMessages.o filesort.o ObjectCreator.o
	$(CXX) $(CXXFLAGS) -o filesort main.o DisplayMessages.o filesort.o ObjectCreator.o

DisplayMessages.o: DisplayMessages.cpp DisplayMessages.h
	$(CXX) $(CXXFLAGS) -c DisplayMessages.h DisplayMessages.cpp

filesort.o: filesort.cpp filesort.h
	$(CXX) $(CXXFLAGS) -c filesort.h filesort.cpp
	
ObjectCreator.o: ObjectCreator.cpp ObjectCreator.h
	$(CXX) $(CXXFLAGS) -c ObjectCreator.h ObjectCreator.cpp

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

.PHONY : clean
clean :
	-rm *.o filesort
	