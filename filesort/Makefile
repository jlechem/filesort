#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

all: filesort

filesort: main.o filesort.o lengthfilesort.o linefilesort.o wordfilesort.o
	$(CXX) $(CXXFLAGS) -o filesort main.o filesort.o lengthfilesort.o linefilesort.o wordfilesort.o

filesort.o: filesort.cpp filesort.h
	$(CXX) $(CXXFLAGS) -c filesort.h filesort.cpp

lengthfilesort.o: lengthfilesort.cpp lengthfilesort.h
	$(CXX) $(CXXFLAGS) -c lengthfilesort.h lengthfilesort.cpp

linefilesort.o: linefilesort.cpp linefilesort.h
	$(CXX) $(CXXFLAGS) -c linefilesort.h linefilesort.cpp

wordfilesort.o: wordfilesort.cpp wordfilesort.h
	$(CXX) $(CXXFLAGS) -c wordfilesort.h wordfilesort.cpp

main.o: main.cpp cxxopts.h
	$(CXX) $(CXXFLAGS) -c main.cpp cxxopts.h

.PHONY : clean
clean :
	-rm *.o filesort
	