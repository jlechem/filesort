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

#include "DisplayMessages.h"

DisplayMessages::DisplayMessages(void)
{
}

DisplayMessages::~DisplayMessages(void)
{
}

void DisplayMessages::printInvalidFileName( string fileName )
{
	cout << endl << "Unable to open file: " << fileName << " for sorting." << endl
		 << "Please check the file exists and try again." << endl;
}

void DisplayMessages::printInvalidUsage(void)
{
	cout << endl << "Invalid usage, please see help options (/?) for more details." << endl;
}

void DisplayMessages::printHelp(void)
{
	cout << endl << "Sorts a file into ascending or descending order." << endl
		 << "Items are sorted using white space and ascending order by default." << endl
		 << "White space and sort order can be overriden using the appropriate switches." << endl << endl
		 << "FILESORT [source file][output file][/d][/cX]" << endl
		 << "[/d]\tSpecifies descending sort order." << endl
		 << "[/cX]\tSpecifies X number of characters to be read instead of whitespace." << endl << endl;
}

void DisplayMessages::printInvalidInputFile( string fileName )
{
	cout << endl << "An error occurred with the input file: " << fileName << endl << "Please verify the filename and try running the application again." << endl;
}//end function

void DisplayMessages::printInvalidOutputFile( string fileName )
{
	cout << endl << "An error occurred with the output file: " << fileName << endl << "Please verify the filename and try running the application again." << endl;
}//end function