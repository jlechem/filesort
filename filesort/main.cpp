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


/*
		FileSort - Takes a file and sorts it alphabetically in ascending or descending order
		
		Created by - Justin LeCheminant 9-1-2007

		Current Version 4.0.0

*/

#include <iostream>

#include "FileSort.h"
#include "cxxopts.h"

constexpr auto VERSION = "4.0.0";

/*

Function: main 

The main entry point of the filesort program

Parameters:

argc - The number of command line arguments passed to the application.
argv - The command line arguments passed to the application.

Returns:

An integer represeting a pass/fail to the Operating System.

*/
int main(int argc, char* argv[])
{
	try
	{
		if (argc == 1)
		{
			std::cout << std::endl << "Invalid usage, please use help switch <filesort --help> for more details.";
		}
		else
		{
			cxxopts::Options options("FileSort", "Sorts a file in ascending/descending order");

			options.add_options()
				("i,input", "Source file to sort", cxxopts::value<std::string>())
				("o,output", "Destination file to write to", cxxopts::value<std::string>())
				("d,descending", "Sort file in descending order", cxxopts::value<bool>()->default_value("false"))
				("v,version", "Filesort version", cxxopts::value<bool>()->default_value("false"))
				("h,help", "Filesort help", cxxopts::value<bool>()->default_value("false"))
				("l,length", "Number of characters to read", cxxopts::value<int>());

			auto result = options.parse(argc, argv);

			if (result.count("version"))
			{
				std::cout << std::endl << "FileSort version - " << VERSION;
			}

			if (result.count("help"))
			{
				std::cout << std::endl << options.help();
			}

			std::string sourceFile;
			std::string destinationFile;
			bool isAscending = true;
			int readLength = 0;

			if (result.count("input"))
			{
				sourceFile = result["input"].as<std::string>();
			}
			else
			{
				std::cout << std::endl << "No input file specified";
				return 0;
			}

			if (result.count("output"))
			{
				destinationFile = result["output"].as<std::string>();
			}
			else
			{
				destinationFile = sourceFile;
			}

			if (result.count("descending"))
			{
				isAscending = false;
			}

			if (result.count("length"))
			{
				readLength = result["length"].as<int>();
			}

			FileSort fileSort(sourceFile, destinationFile, isAscending, readLength);
			fileSort.Sort();

		}

		return 0;

	}
	catch (const std::exception& ex)
	{
		std::cerr << std::endl << ex.what();
		return 1;
	}
}