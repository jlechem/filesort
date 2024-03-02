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
	this->delimeter = "\n";
	this->readLength = 0;
}

FileSort::FileSort(int readLength)
{
	this->delimeter = "\n";
	this->readLength = readLength;
}

FileSort::~FileSort(void)
{
}

void FileSort::save(std::string_view fileName)
{
	std::ofstream FILE(fileName.data(), std::ios::out | std::ios::trunc);

	std::ostream_iterator<std::string> it(FILE, this->delimeter.data());

	std::copy(this->items.begin(), this->items.end(), it);

	FILE.close();
}

void FileSort::setDelimeter(std::string delimeter)
{
	this->delimeter = delimeter;
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