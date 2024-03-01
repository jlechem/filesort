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

#include "ObjectCreator.h"

ObjectCreator::ObjectCreator(void)
{
}

ObjectCreator::~ObjectCreator(void)
{
}

std::unique_ptr<FileSort> ObjectCreator::CreateFileSort(char* params[], int length)
{
	
	
	try
	{
		

		



		return std::move(std::unique_ptr<FileSort>(new FileSort(sourceFile, destinationFile, isAscending, readLength)));

	}
	catch (const std::exception& ex)
	{
		std::cerr << std::endl << ex.what();
		return std::move(std::unique_ptr<FileSort>(nullptr));
	}

	return std::move(std::unique_ptr<FileSort>(nullptr));

}

bool ObjectCreator::ValidateFileExists(std::string fileName)
{
	std::fstream file;

	try
	{
		file.open(fileName);

		if (file.good())
		{
			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}