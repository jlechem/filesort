CXX = g++
CXXFLAGS = -std=c++17

all: filesort

filesort: main.o filesort.o
	$(CXX) $(CXXFLAGS) -o filesort main.o filesort.o

filesort.o: filesort.cpp filesort.h
	$(CXX) $(CXXFLAGS) -c filesort.h filesort.cpp

main.o: main.cpp cxxopts.h
	$(CXX) $(CXXFLAGS) -c main.cpp cxxopts.h

.PHONY : clean
clean :
	-rm *.o filesort
	