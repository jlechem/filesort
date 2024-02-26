/*
	Copyright 2021 Justin LeCheminant

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

FileSort::FileSort(std::string oldFilename, std::string newFilename, bool ascending, long readLength)
{
	// set the internal data members
	this->isAscending = ascending;
	this->isNewFile = true;
	this->newFilename = newFilename;
	this->oldFilename = oldFilename;
	this->readLength = readLength;

}

FileSort::FileSort(std::string oldFilename, bool ascending)
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

void FileSort::Save(void)
{
	file.open( this->newFilename, std::ios::out | std::ios::trunc );

	if( file.is_open() )
	{
		for (auto & element : this->items) 
  		{
    		file.clear();
			file << element << std::endl;
  		}
		
		file.close();
	}
}

void FileSort::Load(void)
{
	this->items.clear();

	file.open(this->oldFilename, std::ios::in);

	if (file.is_open())
	{
		if (this->readLength > 0)
		{
			while (!file.eof())
			{
				this->ClearWhitespace();

				std::string newString(this->readLength, ' ');
				file.read(&newString[0], this->readLength);

				this->CleanString(newString);

				if (newString != "")
				{
					this->items.push_back(newString);
				}
			}
		}
		else
		{
			std::string item;

			while (std::getline(file, item))
			{
				this->CleanString(item);

				if (item != "")
				{
					this->items.push_back(item);
				}
			}
		}
	}

	file.close();

}

void FileSort::Sort(void)
{
	this->Load();

	if (this->isAscending) 
	{
		std::sort(this->items.begin(), this->items.end());
	} 
	else
	{
		std::sort(this->items.rbegin(), this->items.rend());
	}

	this->Save();

}

void FileSort::CleanString( std::string& value)
{
	int index = 0;

	while( (index = value.find('\n') ) > 0 )
	{
		value[index] = ' ';
	}

	while( (index = value.find('\t') ) > 0 )
	{
		value[index] = ' ';
	}
}

void FileSort::ClearWhitespace(void)
{
	// make sure we don't run into any newlines, spaces, or tabs
	while(	file.peek() == '\n' || 
			file.peek() == ' '  ||
			file.peek() == '\t' )
	{
		char c[1];
		file.read( c, 1 );
	}
}