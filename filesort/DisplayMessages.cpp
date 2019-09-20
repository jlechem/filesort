/*
	Copyright 2019 Justin LeCheminant

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

/// <summary>
/// Initializes a new instance of the <see cref="DisplayMessages"/> class.
/// </summary>
DisplayMessages::DisplayMessages(void)
{
}

/// <summary>
/// Finalizes an instance of the <see cref="DisplayMessages"/> class.
/// </summary>
DisplayMessages::~DisplayMessages(void)
{
}

/// <summary>
/// Prints the name of the invalid file.
/// </summary>
/// <param name="fileName">Name of the file.</param>
void DisplayMessages::PrintInvalidFileName(wstring fileName)
{
	wcout << endl << "Unable to open file: '" << fileName << "' for sorting." << endl
		 << "Please check the file exists and try again." << endl;
}

/// <summary>
/// Prints the invalid usage.
/// </summary>
void DisplayMessages::PrintInvalidUsage(void)
{
	wcout << endl << "Invalid usage, please use help switch <filesort /?> for more details." << endl;
}

/// <summary>
/// Prints the version.
/// </summary>
void DisplayMessages::PrintVersion()
{
	wcout << endl << "Current FileSort version is 2.0.0" << endl << endl;
}

/// <summary>
/// Prints the help.
/// </summary>
void DisplayMessages::PrintHelp(void)
{
	wcout << endl << "Sorts a file into ascending or descending order." << endl
		 << "Items are sorted using white space and ascending order by default." << endl
		 << "White space and sort order can be overriden using the appropriate switches." << endl << endl
		 << "FILESORT [source file][output file][/d][/cX]" << endl
		 << "[/d]\tSpecifies descending sort order." << endl
		 << "[/cX]\tSpecifies X number of characters to be read instead of whitespace." << endl << endl;
}

/// <summary>
/// Prints the invalid input file.
/// </summary>
/// <param name="fileName">Name of the file.</param>
void DisplayMessages::PrintInvalidInputFile(wstring fileName)
{
	wcout << endl << "An error occurred with the input file: " << fileName << endl << "Please verify the filename and try running the application again." << endl;
}

/// <summary>
/// Prints the invalid output file.
/// </summary>
/// <param name="fileName">Name of the file.</param>
void DisplayMessages::PrintInvalidOutputFile(wstring fileName)
{
	wcout << endl << "An error occurred with the output file: " << fileName << endl << "Please verify the filename and try running the application again." << endl;
}