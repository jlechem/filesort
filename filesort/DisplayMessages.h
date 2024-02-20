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

#ifndef DISPLAYMESSAGES_H
#define DISPLAYMESSAGES_H

#include <iostream>

class DisplayMessages
{
public:
	DisplayMessages(void);

	~DisplayMessages(void);
	
	static void PrintInvalidFileName( const std::string filename );

	static void PrintInvalidUsage(void);

	static void PrintInvalidOutputFile( const std::string fileName );
	
	static void PrintInvalidInputFile( const std::string fileName );

	static void PrintHelp();
	
	static void PrintVersion();
};

#endif