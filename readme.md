# Release versions

Note that `main` is generally a work in progress, and you probably want to use a tagged release version.

# Version 4 breaking changes

If you have used version 3 or below, there are breaking changes in version 4. The entire command line arguments has been re-worked to be more in line with the unix/linux standards.

# Quick start
To use filesort you pass in the name of the file you want sorted along with several optional parameters.

* -i, --input arg,   Source file to sort
* -o, --output arg,  Destination file to write to
* -d, --descending,  Sort file in descending order
* -v, --version,     Filesort version
* -h, --help,        Filesort help
* -l, --length arg,  Number of characters to read, overrides -w
* -w, --word,        Reads data in per word rather than per line
*    --delim arg,   Value to append to end of each sorted value defaults to newline

## Example
* `filesort -i test.txt` Sorts the file test.txt in ascending order
* `filesort -i test.txt -o output.txt -d` Reads the data from test.txt and writes it in descending order to output.txt

# Requirements

The only build requirement is a C++ compiler that supports C++17. I have tested using Visual Studio 2019 and GCC 13.2.0.

## Building
* Windows - Open the filesort.sln solution file in Visual Studio and build accordingly.
* Unix/Linux - In the filesort directory is a MAKEFILE, this should be used to build the project. Note it is currently set to GCC, clang etc. have not been tested,
  The following make commands are supported
  `make`
  `make clean`
  `make install`
