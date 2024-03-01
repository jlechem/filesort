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
#include <string>
#include <cstring>
#include <memory>

#include "ObjectCreator.h"
#include "FileSort.h"
#include "DisplayMessages.h"

/*

Function: main 

The main entry point of the filesort program

Parameters:

argc - The number of command line arguments passed to the application.
argv - The command line arguments passed to the application.

Returns:

An integer represeting a pass/fail to the Operating System.

*/
int main( int argc, char* argv[] )
{
	try
	{
		if( argc == 1 )
		{
			DisplayMessages::PrintInvalidUsage();
		}
		else
		{
			if( argc < 2 && argc > 5 )
			{
				DisplayMessages::PrintInvalidUsage();
			}
			else if( argc == 2 && (argv[1] == "--help" || argv[1] == "--h"))
			{
				DisplayMessages::PrintHelp();
			}
			else if( argc == 2 && (argv[1] == "--version" || argv[1] == "--v"))
			{
				DisplayMessages::PrintVersion();
			}
			else
			{
				ObjectCreator creator;

				auto fileSort = creator.CreateFileSort( argv,  argc );

				if( fileSort )
				{
					fileSort->Sort();
				}
			}
		}

		return 0;

	}
	catch( ... )
	{
		std::cerr << std::endl << "An error has occured in the application please try running it again." << std::endl;
		return 1;
	}
}