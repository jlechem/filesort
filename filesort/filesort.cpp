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

void FileSort::save(void)
{
	std::ofstream FILE(this->newFilename, std::ios::out | std::ios::trunc);
	std::ostream_iterator<std::string> it(FILE,"\n");
	std::copy(this->items.begin(), this->items.end(), it);
	FILE.close();
}

void FileSort::load(void)
{
	this->items.clear();

	if (this->readLength == 0 )
	{
		this->load_by_line();
	}
	else
	{
		this->load_by_length();
	}
} 

void FileSort::sort(void)
{
	std::cout << std::endl << "Loading file data";

	this->load();

	std::cout << std::endl << "Done loading file data";
	std::cout << std::endl << "Sorting data";

	if (this->isAscending) 
	{
		std::sort(std::execution::par_unseq, this->items.begin(), this->items.end());
	} 
	else
	{
		std::sort(std::execution::par_unseq, this->items.rbegin(), this->items.rend());
	}

	std::cout << std::endl << "Done sorting data";
	std::cout << std::endl << "Writing file data";

	this->save();

	std::cout << std::endl << "Done Writing file data";
}

void FileSort::load_by_line(void)
{
	std::ifstream file(this->oldFilename, std::ios::in);

	if (file.good())
	{
		std::string line;

		while (std::getline(file, line))
		{
			if (!line.empty())
			{
				this->items.push_back(line);
			}
		}

		file.close();
	}

}

void FileSort::load_by_length(void)
{
	std::ifstream file(this->oldFilename, std::ios::in);

	if (file.good())
	{
		while (!file.eof())
		{
			std::string newString(this->readLength, ' ');
			file.read(&newString[0], this->readLength);

			if (!newString.empty())
			{
				this->items.push_back(newString);
			}
		}

		file.close();
	}
}