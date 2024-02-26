CXX = g++

all: filesort

filesort: main.o DisplayMessages.o filesort.o ObjectCreator.o
	g++ -o filesort main.o DisplayMessages.o filesort.o ObjectCreator.o

DisplayMessages.o: DisplayMessages.cpp DisplayMessages.h
	$(CXX) -c DisplayMessages.h DisplayMessages.cpp

filesort.o: filesort.cpp filesort.h
	$(CXX) -c filesort.h filesort.cpp
	
ObjectCreator.o: ObjectCreator.cpp ObjectCreator.h
	$(CXX) -c ObjectCreator.h ObjectCreator.cpp

main.o: main.cpp 
	$(CXX) -c main.cpp

.PHONY : clean
clean :
	-rm *.o filesort
	