
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2013-2020 Igor Mironchik

	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef ARGS__HELP_HPP__INCLUDED
#define ARGS__HELP_HPP__INCLUDED

// Args include.
#include "arg.hpp"
#include "help_printer_iface.hpp"
#include "context.hpp"
#include "utils.hpp"
#include "exceptions.hpp"
#include "types.hpp"
#include "command.hpp"

// C++ include.
#include <memory>

#ifdef ARGS_TESTING
	#ifndef ARGS_QSTRING_BUILD
		// C++ include.
		#include <sstream>
	#endif
#endif


namespace Args {

#ifdef ARGS_TESTING
	#ifdef ARGS_WSTRING_BUILD
		extern std::wstringstream g_argsOutStream;
	#elif defined( ARGS_QSTRING_BUILD )
		extern OutStreamType g_argsOutStream;
	#else
		extern std::stringstream g_argsOutStream;
	#endif
#else
	static OutStreamType & g_argsOutStream = outStream();
#endif // ARGS_TESTING


//
// Help
//

//! Help argument.
class Help
	:	public Arg
{
public:
	explicit Help( bool throwExceptionOnPrint = true );

	//! Set executable name.
	void setExecutable( const String & exe );

	//! Set description for the application.
	void setAppDescription( const String & desc );

	//! Set line length for the help.
	void setLineLength( String::size_type length );

	//! Set printer.
	void setPrinter( std::unique_ptr< HelpPrinterIface > p );

protected:
	/*!
		Process argument's staff, for example take values from
		context. This method invokes exactly at that moment when
		parser has found this argument.
	*/
	void process(
		//! Context of the command line.
		Context & context ) override;

	//! Set command line parser.
	void setCmdLine( CmdLine * cmdLine ) override
	{
		Arg::setCmdLine( cmdLine );

		m_printer->setCmdLine( cmdLine );
	}

private:
	//! Printer.
	std::unique_ptr< HelpPrinterIface > m_printer;
	//! Throw or not exception?
	bool m_throwExceptionOnPrint;
}; // class Help


//
// Help
//

inline void
Help::setExecutable( const String & exe )
{
	m_printer->setExecutable( exe );
}

inline void
Help::setAppDescription( const String & desc )
{
	m_printer->setAppDescription( desc );
}

inline void
Help::setLineLength( String::size_type length )
{
	m_printer->setLineLength( length );
}

inline void
Help::setPrinter( std::unique_ptr< HelpPrinterIface > p )
{
	m_printer.reset( p.release() );
}

inline void
Help::process( Context & context )
{
	if( !context.atEnd() )
	{
		String arg = *context.next();

		// Argument or flag.
		if( details::isArgument( arg ) || details::isFlag( arg ) )
			m_printer->print( arg, g_argsOutStream );
		// Command?
		else
		{
			auto * tmp = m_printer->findArgument( arg );

			// Command.
			if( tmp && tmp->type() == ArgType::Command )
			{
				bool printed = false;

				auto * cmd = static_cast< Command* > ( tmp );

				while( !context.atEnd() )
				{
					arg = *context.next();

					if( tmp && tmp->type() == ArgType::Command )
					{
						cmd = static_cast< Command* > ( tmp );

						// Argument or flag.
						if( details::isArgument( arg ) || details::isFlag( arg ) )
						{
							m_printer->print( arg, g_argsOutStream, cmd );

							printed = true;

							break;
						}
						// Command?
						else
							tmp = cmd->findChild( arg );
					}
					else
						break;
				}

				if( !printed )
				{
					if( tmp )
						m_printer->print( tmp->name(), g_argsOutStream,
							( cmd != tmp ? cmd : nullptr ) );
					else
						m_printer->print( g_argsOutStream );
				}
			}
			else
				m_printer->print( g_argsOutStream );
		}
	}
	else
		m_printer->print( g_argsOutStream );

	setDefined( true );

	if( m_throwExceptionOnPrint )
		throw HelpHasBeenPrintedException();
}

} /* namespace Args */

#endif // ARGS__HELP_HPP__INCLUDED
