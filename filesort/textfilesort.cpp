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

#include "textfilesort.h"

TextFileSort::~TextFileSort(void)
{
}

void TextFileSort::save()
{
	std::ofstream file(this->outputFile, std::ios::out | std::ios::trunc);

	if (file.good())
	{
		while (!this->items.empty())
		{
			file << std::any_cast<std::string>(this->items.back()) << this->delimeter;
			this->items.pop_back();
		}

		file.close();
	}
}
