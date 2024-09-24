#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C++ compiler to use
CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g -O3

PREFIX = /usr/local

all: filesort

filesort.o: filesortfactory.cpp filesortfactory.h
	$(CXX) $(CXXFLAGS) -c filesortfactory.cpp
	
filesort.o: filesort.cpp filesort.h
	$(CXX) $(CXXFLAGS) -c filesort.cpp

textfilesort.o: textfilesort.cpp textfilesort.h
	$(CXX) $(CXXFLAGS) -c textfilesort.cpp

lengthfilesort.o: lengthfilesort.cpp lengthfilesort.h
	$(CXX) $(CXXFLAGS) -c lengthfilesort.cpp

linefilesort.o: linefilesort.cpp linefilesort.h
	$(CXX) $(CXXFLAGS) -c linefilesort.cpp

wordfilesort.o: wordfilesort.cpp wordfilesort.h
	$(CXX) $(CXXFLAGS) -c wordfilesort.cpp

main.o: main.cpp cxxopts.h
	$(CXX) $(CXXFLAGS) -c main.cpp

filesort: main.o filesort.o textfilesort.o lengthfilesort.o linefilesort.o wordfilesort.o filesortfactory.o
	$(CXX) $(CXXFLAGS) -o filesort textfilesort.o main.o filesort.o lengthfilesort.o linefilesort.o wordfilesort.o filesortfactory.o
	
.PHONY : clean
clean :
	-rm *.o filesort

.PHONY: install  
install: filesort
	cp filesort $(PREFIX)/bin

.PHONY: uninstall  
uninstall: filesort
	rm -r $(PREFIX)/bin/filesort
    
