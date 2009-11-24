#include "filesortCreator.h"

filesort filesortCreator::CreateFileSort(	string sourceFile, 
											string destinationFile, 
											bool ascending, 
											long readLength )
{
	return filesort( sourceFile, destinationFile, ascending, readLength );
}