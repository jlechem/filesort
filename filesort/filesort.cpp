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

#include "filesort.h"

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

void FileSort::sort(bool isAscending)
{
	// since we write the files from vector end to front
	  // we need to kind of reverse based on the ascending flag
	if (isAscending)
	{
		std::sort(std::execution::par_unseq, this->items.rbegin(), this->items.rend(),
			[](const std::any& leftHand, const std::any& rightHand) 
			{ 
				auto& leftHandType = leftHand.type();
				auto& rightHandType = rightHand.type();
				return std::type_index(leftHandType) < std::type_index(rightHandType); 
			});
	}
	else
	{
		std::sort(std::execution::par_unseq, this->items.begin(), this->items.end(),
			[](const std::any& leftHand, const std::any& rightHand)
			{
				auto& leftHandType = leftHand.type();
				auto& rightHandType = rightHand.type();
				return std::type_index(leftHandType) < std::type_index(rightHandType);
			});
	}
}

void FileSort::set_delimeter(std::string delimeter) 
{
    this->delimeter = delimeter; 
}