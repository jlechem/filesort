/*

	copyright 2024 Justin LeCheminant

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
#include <typeindex>

class FileSort
{
public:
	FileSort();

	FileSort(int readLength, std::string inputFile, std::string outputFile, std::string delimeter, bool descending);

	virtual ~FileSort(void) = 0;

	virtual void sort();

	virtual void save() = 0;

	virtual void load() = 0;

protected:
	int readLength;

	std::string delimeter;

	std::string inputFile;

	std::string outputFile;

	std::vector<std::any> items;

	bool descending;

};

#endif