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

#include "ObjectCreator.h"

ObjectCreator::ObjectCreator(void)
{
}

ObjectCreator::~ObjectCreator(void)
{
}

FileSort* ObjectCreator::CreateFileSort(string params[], int length)
{
	string sourceFile;
	string param1;
	string param2;
	string param3;
	string param4;

	try
	{
		if( length < 2 || length > 5 )
		{
			DisplayMessages::PrintInvalidUsage();
			return NULL;
		}

		sourceFile = params[1];

		if( !this->ValidateFileExists( sourceFile ) )
		{
			DisplayMessages::PrintInvalidFileName( sourceFile );
			return NULL;
		}

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
					}
				}
				else
				{
					// otherwise we're trying to do an output file
					if( this->ValidateOutputFile( param2 ) )
					{
						// ascending no length sort into a new file
						return new FileSort( sourceFile, param2, true, 0 );
					}
					else
					{
						DisplayMessages::PrintInvalidOutputFile( param2 );
						return NULL;
					}
				}

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
					}
					else if( this->GetSwitchValue( param2 ) == 'c' )
					{
						readVal = this->GetReadLength( param2 );
					}

					// two valid switches means descending, specified length, same file sort
					return new FileSort( sourceFile, sourceFile, false, readVal );

				}
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
							}
							else if( this->GetSwitchValue( param2 ) == 'd' )
							{
								// descending no length sort into new file
								return new FileSort( sourceFile, param1, false, 0 );
							}
						}
						else
						{
							DisplayMessages::PrintInvalidUsage();
							return NULL;
						}
					}
					else
					{
						DisplayMessages::PrintInvalidOutputFile( param2 );
						return NULL;
					}
				}

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
						}
						else if( this->GetSwitchValue( param3 ) == 'c' )
						{
							readVal = this->GetReadLength( param3 );
						}

						// descending length based sort into new file
						return new FileSort( sourceFile, param1, false, readVal );
					}
					else
					{
						DisplayMessages::PrintInvalidUsage();
						return NULL;
					}
				}
				else
				{
					DisplayMessages::PrintInvalidOutputFile( param1 );
					return NULL;
				}
				
				break;

			// some kind of weird fucked up param pass-in
			default:
				DisplayMessages::PrintInvalidUsage();
				return NULL;	

		}
	}
	catch( ... )
	{
		return NULL;
	}

	return NULL;

}

bool ObjectCreator::ValidateFileExists(string fileName)
{
	fstream file;

	try
	{
		file.open( fileName );

		if( file.is_open() )
		{
			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch( ... )
	{
		return false;
	}
}

bool ObjectCreator::ValidateSwitch(string value)
{
	return ( this->ValidateDescendingSwitch( value ) || this->ValidateLengthSwitch( value ) );
}

bool ObjectCreator::ValidateDescendingSwitch(string value)
{
	try
	{
		if( value == "/d" )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch( ... )
	{
		return false;
	}
}

bool ObjectCreator::ValidateLengthSwitch(string value)
{
	try
	{
		string switchValue( value, 0, 2 );

		if( switchValue == "/c" )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch( ... )
	{
		return false;
	}
}

int ObjectCreator::GetReadLength(string value)
{
	try
	{
		string switchValue( value, 2, value.length() );

		return stoi( switchValue.c_str() );
	}
	catch( ... )
	{
		return 0;
	}
}

char ObjectCreator::GetSwitchValue(string value)
{
	try
	{
		return value[1];
	}
	catch( ... )
	{
		return '~';
	}
}

bool validateOutputfile(string fileName)
{
	fstream fout;

	bool flag = false;

	try
	{
		fout.open( fileName.c_str(), ios::out );
	
		if( fout.is_open() )
		{
			flag=true;
		}
			
		fout.close();

		return flag;

	}
	catch( ... )
	{
		return false;
	}
}

bool ObjectCreator::ValidateOutputFile(string fileName)
{
	try
	{
		fstream file( fileName.c_str(), ios::out|ios::trunc );

		if( !file )
		{
			return false;
		}
		else
		{
			file.close();
			return true;
		}
	}
	catch( ... )
	{
		return false;
	}
}
