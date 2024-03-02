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

FileSort::FileSort()
{
	this->readLength = 0;

}

FileSort::~FileSort(void)
{
}

void FileSort::save(std::string_view fileName)
{
	std::ofstream FILE(fileName.data(), std::ios::out | std::ios::trunc);
	std::ostream_iterator<std::string> it(FILE,"\n");
	std::copy(this->items.begin(), this->items.end(), it);
	FILE.close();
}

void FileSort::set_read_length(int length)
{
	this->readLength = length;
}

void FileSort::load(std::string_view fileName)
{
	this->items.clear();

	if (this->readLength == 0 )
	{
		this->load_by_line(fileName);
	}
	else
	{
		this->load_by_length(fileName);
	}
} 

void FileSort::sort(bool isAscending)
{
	if (isAscending) 
	{
		std::sort(std::execution::par_unseq, this->items.begin(), this->items.end());
	} 
	else
	{
		std::sort(std::execution::par_unseq, this->items.rbegin(), this->items.rend());
	}
}

void FileSort::load_by_line(std::string_view fileName)
{
	std::ifstream file(fileName.data(), std::ios::in);

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

void FileSort::load_by_length(std::string_view fileName)
{
	std::ifstream file(fileName.data(), std::ios::in);

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