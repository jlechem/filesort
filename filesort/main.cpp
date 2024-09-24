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


/*
		filesort - Takes a file and sorts it alphabetically in ascending or descending order
		
		Created by - Justin LeCheminant 9-1-2007

		Current Version 4.0.1

*/

#include <iostream>

#include "filesortfactory.h"
#include "cxxopts.h"

constexpr auto VERSION = "4.0.2";

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
			std::cout << std::endl << "error: no operation specified (use -h for help)" << std:: endl;
		}
		else
		{
			cxxopts::Options options("filesort", "Sorts a file in ascending/descending order");

			options.add_options()
				("i,input", "Source file to sort", cxxopts::value<std::string>())
				("o,output", "Destination file to write to", cxxopts::value<std::string>())
				("d,descending", "Sort file in descending order", cxxopts::value<bool>()->default_value("false"))
				("v,version", "Filesort version", cxxopts::value<bool>()->default_value("false"))
				("h,help", "Filesort help", cxxopts::value<bool>()->default_value("false"))
				("l,length", "Number of characters to read, overrides -w", cxxopts::value<int>())
				("w,word", "Reads data in per word rather than per line", cxxopts::value<bool>()->default_value("false"))
				("delim,delimeter", "Value to append to end of each sorted value defaults to newline", cxxopts::value<std::string>());

			auto& const result = options.parse(argc, argv);

			if (result.count("version"))
			{
				std::cout << std::endl << "filesort version - " << VERSION << std::endl;
			}

			if (result.count("help"))
			{
				std::cout << std::endl << options.help() << std::endl;
			}

			auto& const fileSort = FileSortFactory::CreateFileSort(result);

			std::cout << std::endl << "Loading file data";

			fileSort->load();

			std::cout << std::endl << "Done loading file data";
			std::cout << std::endl << "Sorting data";

			fileSort->sort();

			std::cout << std::endl << "Done sorting data";
			std::cout << std::endl << "Writing file data";
			
			fileSort->save();

			std::cout << std::endl << "Done Writing file data" << std::endl;

		}
		return 0;

	}
	catch (const std::exception& ex)
	{
		std::cerr << std::endl << ex.what();
		return 1;
	}
}
