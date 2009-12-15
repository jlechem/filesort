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

#pragma once

#include <string>
#include <iostream>

using namespace std;

/*
	Class: DisplayMessages
	A class that displays messages to the user via the standard output.
*/
class DisplayMessages
{
public:
	/*
		Constructor: DisplayMessages
		Initializes the object.
    */
	DisplayMessages(void);

	/*
		Destructor: ~DisplayMessages
		Destroys the object.
    */
	~DisplayMessages(void);
	
	/*
		Function: PrintInvalidFileName
	
		Prints an error if the specified filename cannot be found or opened.

		Parameters:

		filename - The name of the file.
	*/
	static void PrintInvalidFileName( string filename );

	/*
		Function: PrintInvalidUsage
	
		Prints the standard usage options if inavalid command line parameters are passed to the applicaiton.
	*/
	static void PrintInvalidUsage(void);

	/*
		Function: PrintInvalidOutputFile
	
		Prints an error if the specified output file cannot be found or created.

		Parameters:

		filename - The name of the file.
	*/
	static void PrintInvalidOutputFile( string fileName );
	
	/*
		Function: PrintInvalidInputFile
	
		Prints an error if the specified input file cannot be found or opened.

		Parameters:

		filename - The name of the file.
	*/
	static void PrintInvalidInputFile( string fileName );
	
	/*
		Function: PrintHelp
	
		Prints the stanard help output on how to use the application.
	*/
	static void PrintHelp();
	
	/*
		Function: PrintVersion
	
		Prints the current version of the application.
	*/
	static void PrintVersion();
};

