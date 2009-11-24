#pragma once

#include <string>
#include "filesort.h"

class filesortCreator
{
public:
	static filesort CreateFileSort( string sourceFile, 
									string destinationFile, 
									bool ascending, 
									long readLength ); 
};
