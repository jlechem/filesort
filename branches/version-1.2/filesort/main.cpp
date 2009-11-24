/*
	Copyright 2008 Justin LeCheminant
*/

/*
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
		Modified by - Justin LeCheminant 11-24-2009

		Current Version 1.2.1

*/

// pre-compiled headers
#include <iostream>
#include <fstream>
#include <string>

// custom headers
#include "ObjectCreator.h"
#include "FileSort.h"
#include "DisplayMessages.h"

using namespace std;

int main( int argc, char* argv[] )
{
	string param1, param2, param3;

	FileSort* fileSort;
	ObjectCreator creator;

	try
	{
		// set the window title
		system("title filesort (c)Justin LeCheminant 2007");

		// check for a valid number of parameters first
		if( argc < 2 && argc > 5 )
		{
			DisplayMessages::printInvalidUsage();
		}//end if
		else if( argc == 2 && ( strcmp(argv[1],"/?" ) == 0 ) )
		{
			DisplayMessages::printHelp();
		}//end else if
		else if( argc == 2 && ( strcmp( argv[1],"/v" ) == 0 ) )
		{
			DisplayMessages::printVersion();
		}//end else if
		else
		{
			// use the class factory to create a filesort object
			fileSort = creator.createFileSort( argv, argc );

			// check if that object is null
			// null means some bad juju happened
			if( fileSort != NULL )
			{
				cout << endl << "Beginning Sort";

				// sort then save the data
				fileSort->Sort();

				cout << "\tSort Ended\tSaving File" << endl;

				delete fileSort;
			}//end if
		}//end else

		// bail back to the OS
		return 0;

	}//end try
	catch( ... )
	{
		cout << endl << "An error has occured in the application please try running it again." << endl;
		return 0;
	}//end catch
}//end function main