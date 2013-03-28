/*

	Copyright 2010 Justin LeCheminant

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

/*
	Class: FileSort
	A class that sorts a file into ascending or descending order.
*/
class FileSort
{
public:

	/*
		Constructor: FileSort
	
		Initializes the object.

		Parameters:

		oldFileName - The name of the file to read data from.
		newFilename - The name of the file to write output to.
		ascending - True for sorting in ascending order, otherwise false for descending order.
		readLength - The length (in bytes) of data to read at a time.
	*/
	FileSort( wstring oldFileName, wstring newFilename, bool ascending, long readLength );

	/*
		Constructor: FileSort
	
		Initializes the object.

		Parameters:

		oldFilename - The name of the file to read data from.
		ascending - True for sorting in ascending order, otherwise false for descending order.
	*/
	FileSort( wstring oldFilename, bool ascending );

	/*
		Destructor: ~FileSort
	
		Destroys the object.

	*/
	~FileSort(void);

	/*
		Function: Sort
	
		Sorts the data into ascending or descending order.

	*/
	void Sort(void);

private:

	wfstream file;

	bool isNewFile;
	bool isAscending;

	int readLength;

	wstring newFilename;
	wstring oldFilename;

	list<wstring> items;

	/*
		Function: Load
	
		Loads the data from the file into the array list.

	*/
	void Load( void );
	
	/*
		Function: Save
	
		Saves the sorted data to the output file.

	*/
	void Save( void );
	
	/*
		Function: CleanString
	
		Cleans the wstring passed into the function of any whitespace.

		Parameters:

		value - The wstring to be cleaned.
		
		Returns:
		
		A wstring that has been cleaned of all whitespace.

	*/
	wstring CleanString(wstring value);

	/*
		Function: ClearWhitespace
	
		Clears whitespace from the beginning of a file.
	*/
	void ClearWhitespace(void);

};

