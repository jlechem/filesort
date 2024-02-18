CXX = g++

all: filesort

filesort: main.o DisplayMessages.o filesort.o ObjectCreator.o
	g++ -o filesort main.o DisplayMessages.o filesort.o ObjectCreator.o

DisplayMessages.o: DisplayMessages.cpp DisplayMessages.h
	$(CXX) -c DisplayMessages.cpp

filesort.o: filesort.cpp filesort.h
	$(CXX) -c filesort.cpp
	
ObjectCreator.o: ObjectCreator.cpp ObjectCreator.h
	$(CXX) -c ObjectCreator.cpp

main.o: main.cpp 
	$(CXX) -c main.cpp
	