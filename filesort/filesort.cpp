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

void FileSort::Save(void)
{
	std::ofstream FILE(this->newFilename, std::ios::out | std::ios::trunc);
	std::ostream_iterator<std::string> it(FILE,"\n");
	std::copy(this->items->begin(), this->items->end(), it);
	FILE.close();
}

void FileSort::Load(void)
{
	auto fileContents = this->ReadFile(this->oldFilename);

	if (this->readLength > 0)
	{
		auto numberOfSubstrings = fileContents.length() / this->readLength;

		for (auto i = 0; i < numberOfSubstrings; i++)
		{
			this->items->push_back(fileContents.substr(i * this->readLength, this->readLength));
		}

		// If there are leftover characters, create a shorter item at the end.
		if (fileContents.length() % this->readLength != 0)
		{
			this->items->push_back(fileContents.substr(this->readLength * numberOfSubstrings));
		}
	}
	else
	{
		std::istringstream iss(fileContents);

		this->items = std::unique_ptr<std::vector<std::string>>(new std::vector<std::string>{ std::istream_iterator<std::string>{iss},
																							  std::istream_iterator<std::string>{}, });
	}

	fileContents.clear();

} 

void FileSort::Sort(void)
{
	std::cout << std::endl << "Loading file data";

	this->Load();

	std::cout << std::endl << "Done loading file data";
	std::cout << std::endl << "Sorting data";

	if (this->isAscending) 
	{
		std::sort(std::execution::par_unseq, this->items->begin(), this->items->end());
	} 
	else
	{
		std::sort(std::execution::par_unseq, this->items->rbegin(), this->items->rend());
	}

	std::cout << std::endl << "Done sorting data";
	std::cout << std::endl << "Writing file data";

	this->Save();

	std::cout << std::endl << "Done Writing file data";
}

std::string FileSort::ReadFile(std::string_view path)
{
	constexpr auto read_size = std::size_t{ 4096 };
	auto stream = std::ifstream{ path.data() };
	stream.exceptions(std::ios_base::badbit);

	auto out = std::string{};
	auto buf = std::string(read_size, '\0');

	while (stream.read(&buf[0], read_size)) {
		out.append(buf, 0, stream.gcount());
	}

	out.append(buf, 0, stream.gcount());

	return out;
}