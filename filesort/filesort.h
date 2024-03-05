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

#ifndef FILESORT_H
#define FILESORT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <execution>
#include <string_view>
#include <sstream>
#include <iterator>
#include <any>

class FileSort
{
public:
	FileSort();

	FileSort(int readLength);

	virtual ~FileSort(void) = 0;

	virtual void sort(bool isAscending);

	virtual void save(std::string_view fileName) = 0;

	virtual void load(std::string_view fileName) = 0;

	void set_delimeter(std::string delimeter);

protected:
	int readLength;

	std::string delimeter;

	std::vector<std::any> items;

};

#endif