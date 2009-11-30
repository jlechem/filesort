/*
	Copyright 2009 Justin LeCheminant
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

#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "FileSort.h"
#include "DisplayMessages.h"

using namespace std;

class ObjectCreator
{
public:
	ObjectCreator(void);
	~ObjectCreator(void);

	FileSort* createFileSort( char* [], int );

private:
	bool validateFileExists( string fileName );
	bool validateOutputFile( string fileName );
	bool validateSwitch( string value );
	bool validateDescendingSwitch( string value );
	bool validateLengthSwitch( string value );
	
	int getReadLength(string value);
	
	char getSwitchValue(string value);

};
