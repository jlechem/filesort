/*
	Copyright 2010 Justin LeCheminant

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

#include "ObjectCreator.h"

ObjectCreator::ObjectCreator(void)
{
}

ObjectCreator::~ObjectCreator(void)
{
}


FileSort* ObjectCreator::CreateFileSort( char* params[], int length)
{
	string sourceFile;
	string param1;
	string param2;
	string param3;
	string param4;

	long readLength = 0;

	bool isAscending = false;	

	try
	{
		// make sure we have a valid count
		if( length < 2 || length > 5 )
		{
			DisplayMessages::PrintInvalidUsage();
			return NULL;
		}//end if

		// get the passed in filename
		sourceFile = params[1];

		// validate the filename
		if( !this->ValidateFileExists( sourceFile ) )
		{
			DisplayMessages::PrintInvalidFileName( sourceFile );
			return NULL;
		}//end if

		// based on the number we get setup the filesort object
		switch( length )
		{
			// filesort filename
			case 2:
				return new FileSort( sourceFile, true );
				break;

			// filesort srcFile destFile
			// filesort srcFile /d
			// filesort srcFile /cX
			case 3:
				// get the params
				param2 = params[2];

				// if we have a valid switch do the switch
				if( this->ValidateSwitch( param2 ) )
				{
					// determine the switch used based on the char
					switch( this->GetSwitchValue( param2 ) )
					{
						case 'd':
							
							// descending no length sort into same file
							return new FileSort( sourceFile, sourceFile, false, 0);
							break;

						case 'c':
							// ascending length sort into same file
							return new FileSort( sourceFile, sourceFile, true, this->GetReadLength( param2 ) );
							break;
					}//end switch
				}//end if
				else
				{
					// otherwise we're trying to do an output file
					if( this->ValidateOutputFile( param2 ) )
					{
						// ascending no length sort into a new file
						return new FileSort( sourceFile, param2, true, 0 );
					}//end if
					else
					{
						DisplayMessages::PrintInvalidOutputFile( param2 );
						return NULL;
					}//end else
				}//end else

				break;
			
			// filesort sourceFile destFile /d
			// filesort sourceFile destFile /cX
			// filesort sourceFile /d /cX
			case 4:
				// get the params;
				param1 = params[2];
				param2 = params[3];

				// check if we have two valid switches
				if( this->ValidateSwitch( param1 ) && this->ValidateSwitch( param2 ) )
				{
					int readVal = 0;

					// get the read lenth from the right param
					if( this->GetSwitchValue( param1 ) == 'c' )
					{
						readVal = this->GetReadLength( param1 );
					}//end if
					else if( this->GetSwitchValue( param2 ) == 'c' )
					{
						readVal = this->GetReadLength( param2 );
					}//end else if

					// two valid switches means descending, specified length, same file sort
					return new FileSort( sourceFile, sourceFile, false, readVal );

				}//end if
				else
				{
					// both aren't switched, we're trying to do a destfile then switch
					if( this->ValidateOutputFile( param1 ) )
					{
						// validate they used a good switch
						if( this->ValidateSwitch( param2 ) )
						{
							// get the read lenth from the right param
							if( this->GetSwitchValue( param2 ) == 'c' )
							{
								// ascending length sort into new file
								return new FileSort( sourceFile, param1, true, this->GetReadLength( param2 ) );
							}//end if
							else if( this->GetSwitchValue( param2 ) == 'd' )
							{
								// descending no length sort into new file
								return new FileSort( sourceFile, param1, false, 0 );
							}//end else if
						}//end if
						else
						{
							DisplayMessages::PrintInvalidUsage();
							return NULL;
						}//end else
					}//end if
					else
					{
						DisplayMessages::PrintInvalidOutputFile( param2 );
						return NULL;
					}//end if
				}//end else

				break;

			// filesort sourceFile destFile /d /cX
			case 5:
				param1 = params[2];
				param2 = params[3];
				param3 = params[4];

				// validate the output file
				if( this->ValidateOutputFile( param1 ) )
				{
					// validate we have two correct switches
					if( this->ValidateSwitch( param2 ) && this->ValidateSwitch( param3 )  )
					{
						// get the right value from the b switch
						long readVal = 0;

						// get the read lenth from the right param
						if( this->GetSwitchValue( param2 ) == 'c' )
						{
							readVal = this->GetReadLength( param2 );
						}//end if
						else if( this->GetSwitchValue( param3 ) == 'c' )
						{
							readVal = this->GetReadLength( param3 );
						}//end else if

						// descending length based sort into new file
						return new FileSort( sourceFile, param1, false, readVal );
					}//end if
					else
					{
						DisplayMessages::PrintInvalidUsage();
						return NULL;
					}//end else
				}//end if
				else
				{
					DisplayMessages::PrintInvalidOutputFile( param1 );
					return NULL;
				}//end else
				
				break;

			// some kind of weird fucked up param pass-in
			default:
				DisplayMessages::PrintInvalidUsage();
				return NULL;	

		}//end switch
	}//end try
	catch( ... )
	{
		return NULL;
	}

	// somehow if we get here we're fucked so drop back a NULL
	return NULL;

}

bool ObjectCreator::ValidateFileExists(string fileName)
{
	fstream file;

	try
	{
		// try and open the file
		file.open( fileName.c_str() );

		// get the file and tyr to open it
		if( file.is_open() )
		{
			file.close();
			return true;
		}//end if
		else
		{
			return false;
		}//end else
	}//end try
	catch( ... )
	{
		return false;
	}
}

bool ObjectCreator::ValidateSwitch( string value )
{
	return ( this->ValidateDescendingSwitch( value ) || this->ValidateLengthSwitch( value ) );
}

bool ObjectCreator::ValidateDescendingSwitch( string value )
{
	try
	{
		if( value == "/d" )
		{
			return true;
		}//end if
		else
		{
			return false;
		}//end else
	}//end try
	catch( ... )
	{
		return false;
	}//end catch
}

bool ObjectCreator::ValidateLengthSwitch( string value )
{
	try
	{
		// get the first 2 chars from the string
		string switchValue( value, 0, 2 );

		if( switchValue == "/c" )
		{
			return true;
		}//end if
		else
		{
			return false;
		}//end else
	}//end try
	catch( ... )
	{
		return false;
	}//end catch
}

int ObjectCreator::GetReadLength(string value)
{
	try
	{
		// get the first 2 chars from the string
		string switchValue( value, 2, value.length() );

		return atoi( switchValue.c_str() );
	}//end try
	catch( ... )
	{
		return 0;
	}//end catch
}

char ObjectCreator::GetSwitchValue(string value)
{
	try
	{
		return value[1];
	}//end try
	catch( ... )
	{
		return '~';
	}//end catch
}

bool validateOutputfile( string fileName )
{
	fstream fout;

	bool flag = false;

	try
	{
		// try and open the file
		fout.open( fileName.c_str(), ios::out );
	
		// if it's open we have a valid file
		if( fout.is_open() )
		{
			flag=true;
		}//end if
			
		// always close the file
		fout.close();

		// return our flag
		return flag;
	}//end try
	catch( ... )
	{
		return false;
	}//end catch
}//end function

bool ObjectCreator::ValidateOutputFile( string fileName )
{
	try
	{
		// create the file
		fstream file( fileName.c_str(), ios::out|ios::trunc );

		// check if we opened it
		if( !file )
		{
			return false;
		}//end if
		else
		{
			file.close();
			return true;
		}//end else
	}//end try
	catch( ... )
	{
		return false;
	}//end catch
}//end function
