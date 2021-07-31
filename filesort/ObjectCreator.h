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

#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "FileSort.h"
#include "DisplayMessages.h"

using namespace std;

/*
	Class: ObjectCreator
	A class that creates an instance of the FileSort class.

	See Also:
		<FileSort>

*/
class ObjectCreator
{
public:
	/*
		Constructor: ObjectCreator
	
		Initializes the object.
	*/
	ObjectCreator(void);

	/*
		Destructor: ~ObjectCreator
	
		Destroys the object.

	*/
	~ObjectCreator(void);

	/*
		Function: CreateFileSort
	
		Creates an instance of the FileSort class.

		Parameters:

		params - The command line parameters passed to the application.
		length - The number of command line parameters passed to the appliation.

		Returns:

		A pointer to a FileSort object.

		See Also:

		<FileSort>

	*/
	FileSort* CreateFileSort( string params[], int length );

private:
	/*
		Function: ValidateFileExists
	
		Validates that the specified file exists and can be opened.

		Parameters:

		fileName - The name of the file to validte.

		Returns:

		True if the file exists and could be opened, false if not.
	*/
	bool ValidateFileExists( string fileName );
	
	/*
		Function: ValidateOutputFile
	
		Validates that the specified output file exists or can be created.

		Parameters:

		fileName - The name of the output file to validte.

		Returns:

		True if the file was found or could be created, false if not.
	*/
	bool ValidateOutputFile( string fileName );
	
	/*
		Function: ValidateSwitch
	
		Validates the command line argument value passed to it is valid.

		Parameters:

		value - The command line argument to be validated.

		Returns:

		True if the switch is valid, false if not.
	*/
	bool ValidateSwitch( string value );
	
	/*
		Function: ValidateDescendingSwitch
	
		Validates the descending switch command line argument is valid.

		Parameters:

		value - The descending switch command line argument passed to the application.

		Returns:

		True if the switch is valid, false if not.
	*/
	bool ValidateDescendingSwitch( string value );
	
	/*
		Function: ValidateLengthSwitch
	
		Validates the read length command line argument is greater than 0.

		Parameters:

		value - The read length command line argument passed to the application.

		Returns:

		True if the length is greater than 0, false if not.
	*/
	bool ValidateLengthSwitch( string value );
	
	/*
		Function: GetReadLength
	
		Gets the read length specified by the command line argument.

		Parameters:

		value - The read length command line argument passed to the application.

		Returns:

		The integer value of the read length.
	*/
	int GetReadLength(string value);
	
	/*
		Function: GetSwitchValue
	
		Converts the string from the command line arguments to the appropriate character based switch code.

		Parameters:

		value - The string value to convert to a character.

		Returns:

		The character value of the switch command.
		
	*/
	char GetSwitchValue(string value);

};

