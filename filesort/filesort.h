/*
	This file is part of filesort.

    filesort is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    filesort is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with filesort.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

class FileSort
{
public:
	FileSort( string oldFileName, string newFilename, bool ascending, long readLength );
	FileSort( string oldFilename, bool ascending );
	~FileSort(void);

	// sorts the array list in ascending/descending order
	void Sort(void);

private:

	fstream file;

	bool isNewFile;
	bool isAscending;

	int readLength;

	string newFilename;
	string oldFilename;

	list<string> items;

	// loads the data from the file into the array list
	void Load( void );
	
	// saves the array list to the file
	void Save( void );
	
	// cleans the string passed into the function of any whitespace
	string CleanString(string value);
	void ClearWhitespace(void);
};

