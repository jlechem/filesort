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
		filesearch - Takes a file and sorts it alphabetically in ascending or descending order
		
		usage:
		filesearch /? - displays help
		filesearch filename newfilename - sorts file in ascending order
		filesearch /d filename newfilename - sorts the file in descending order
		
		the new filename param is optional if the user wishes to sort the file into a new filename
		
		Created by - Justin LeCheminant 9-1-2007
		Modified by - Justin LeCheminant 5-16-2008
		Modified by - Justin LeCheminant 6-5-2008
		Modified by - Justin LeCheminant 02-15-2024

		Current Version 1.2.1

*/

// pre-compiled headers
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// custom headers
#include "ObjectCreator.h"
#include "FileSort.h"
#include "DisplayMessages.h"


string ctow( const char* src );

using namespace std;

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
	string param1, param2, param3;

	FileSort* fileSort;
	ObjectCreator creator;

	try
	{
		// set the window title
		system("title filesort (c)Justin LeCheminant 2021");

		string param;

		// check for a valid number of parameters first
		if( argc == 1 )
		{
			DisplayMessages::PrintInvalidUsage();
		}
		else
		{
			param = ctow( argv[1] );
		
			if( argc < 2 && argc > 5 )
			{
				DisplayMessages::PrintInvalidUsage();
			}
			else if( argc == 2 && param == "/?" )
			{
				DisplayMessages::PrintHelp();
			}
			else if( argc == 2 && param == "/v" )
			{
				DisplayMessages::PrintVersion();
			}
			else
			{
				// convert char* to string
				string* params = new string[argc];

				for( int i = 0; i < argc; i++ )
				{
					params[i] = ctow( argv[i] );
				}
			
				// use the class factory to create a filesort object
				fileSort = creator.CreateFileSort( params,  argc );

				// check if that object is null
				// null means some bad juju happened
				if( fileSort != NULL )
				{
					wcout << endl << "Beginning Sort";

					// sort then save the data
					fileSort->Sort();

					wcout << "\tSort Ended\tSaving File" << endl;

					delete fileSort;

				}
			}
		}

		// bail back to the OS
		return 0;

	}
	catch( ... )
	{
		wcout << endl << "An error has occured in the application please try running it again." << endl;
		return 0;
	}
}


string ctow( const char* src )
{
    return std::string( src, src + strlen(src) );
}
