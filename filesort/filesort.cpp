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

#include "FileSort.h"

FileSort::FileSort( string oldFilename, string newFilename, bool ascending, long readLength )
{
	// set the internal data members
	this->isAscending = ascending;
	this->isNewFile = true;
	this->newFilename = newFilename;
	this->oldFilename = oldFilename;
	this->readLength = readLength;

}

FileSort::FileSort( string oldFilename, bool ascending )
{
	this->isAscending = ascending;
	this->isNewFile = false;
	this->oldFilename = oldFilename;
	this->newFilename = oldFilename;
	this->readLength = 0;

}

FileSort::~FileSort(void)
{
}


// saves the array list to the file
void FileSort::Save(void)
{
	string item;

	// open the file in output mode
	file.open( this->newFilename.c_str(), ios::out | ios::trunc );

	// check if the file is open
	if( file.is_open() )
	{
		if( this->items.size() > 0 )
		{
			// loop the items and write contents to file
			while( this->items.size() > 1 )
			{
				// check if we're doing an ascending or descending sort
				if( this->isAscending )
				{
					// get the front item
					item = this->items.front();

					// write item to file
					file.clear();
					file << item << endl;

					// remove the front item
					this->items.pop_front();
				}//end if
				else
				{
					// get the back item
					item = this->items.back();

					// write item to file
					file.clear();
					file << item << endl;

					// remove the back item
					this->items.pop_back();
				}//end else
			}//end while

			// get the last front item
			item = this->items.front();

			// write item to file
			file.clear();
			file << item;
	
		}//end if

		// close the file
		file.close();
	}//end if
}//end function

// loads the data from the file into the array list
void FileSort::Load(void)
{
	string item;

	// clear the items
	this->items.clear();

	// load the data from the file into the array list
	file.open( this->oldFilename.c_str(), ios::in );

	// check if the file is open
	if( file.is_open() )
	{
		if( this->readLength > 0 )
		{
			// loop the file and put it into the list
			while( !file.eof() )
			{
				this->ClearWhitespace();

				// create a new buffer
				// read the value from the file
				// then null term the string
				char* buffer = new char[this->readLength ];
				file.read( buffer, this->readLength );
				buffer[this->readLength] = '\0';

				// clean our string
				string newString( this->CleanString( buffer ) );

				// don't let blank values in
				if( newString != "" )
				{
					this->items.push_back( newString );
				}//end if

				this->ClearWhitespace();
				
			}//end while
		}//end if
		else
		{
			while( ( file >> item ) != NULL )
			{
				this->items.push_back( item );
			}
		}//end else
	}//end if

	// close the file
	file.close();

}

// sorts the array list in ascending/descending order
void FileSort::Sort(void)
{
	// load the data
	this->Load();

	// sort the list
	this->items.sort();

	// save the data
	this->Save();

}//end function FileSort::Sort

string FileSort::CleanString( string value )
{
	int index = 0;

	while( (index = value.find('\n') ) > 0 )
	{
		value[index] = ' ';
	}//end while

	while( (index = value.find('\t') ) > 0 )
	{
		value[index] = ' ';
	}//end while

	return value;

}

void FileSort::ClearWhitespace(void)
{
	// make sure we don't run into any newlines, spaces, or tabs
	while(	file.peek() == '\n' || 
			file.peek() == ' '  ||
			file.peek() == '\t' )
	{
		char c[1];
		file.read(c,1);
	}//end while
}
