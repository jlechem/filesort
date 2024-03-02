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

class FileSort
{
public:
	FileSort();

	~FileSort(void);

	void sort(bool isAscending);
	void save(std::string_view fileName);
	void load(std::string_view fileName);

	void set_read_length(int length);

private:
	int readLength;

	std::vector<std::string> items;

	void load_by_line(std::string_view fileName);
	void load_by_length(std::string_view fileName);

};

#endif