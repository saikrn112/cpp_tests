/*
 * QBExceptions.h
 *
 *  Created on: May 7, 2010
 *      Author: ekrel
 */

#ifndef QBEXCEPTIONS_H_
#define QBEXCEPTIONS_H_

#include <stdexcept>

namespace qb
{
	/**
	 * Need to keep error msgs to a maximum of 29 characters due to flex limitations.
	 */

	struct Exception: public std::logic_error
	{
		Exception( const std::string& t, const std::string& d ) :
			std::logic_error( d.size() ? t + "" + d : t ), type( t ), detail( d )
		{
		}
		virtual ~Exception() throw ()
		{
		}

		std::string type;
		std::string detail;
	};

	struct InvalidResource: public Exception
	{
		InvalidResource(const std::string& what = "") :
			Exception( "", what) {}
	};

	struct BadDestination: public Exception
	{
		BadDestination(const std::string& what = "") :
			Exception( "", what) {}
	};

	struct InvalidFilePath: public Exception
	{
		InvalidFilePath(const std::string& what = "") :
			Exception( "", what) {}
	};

	class SignalException : public std::runtime_error
	{
	public:
	   SignalException(const std::string& _message)
		  : std::runtime_error(_message)
	   {}
	};

	struct EnvironmentalVarNotSet: public std::runtime_error
	{
		EnvironmentalVarNotSet( const std::string& what = "" )
			: std::runtime_error( "Environmental variable not set " + what )
		{}
	};

	struct OperationFailed: public Exception
	{
		OperationFailed( const std::string& operation, const std::string& what ) :
			Exception("Opeartion failed: " + operation, what)
		{}
	};

	struct ValidationFailed: public Exception
	{
		ValidationFailed(const std::string& what ="") :
			Exception( "", what) {}
	};

    class SpreadInfoFailed: public Exception
    {
    public:
        SpreadInfoFailed(const std::string& what = "") :
            Exception( "", what) {}
    };

    struct SymbolNotFound: public Exception
    {
        SymbolNotFound(const std::string& sym, const std::string& what )
            : Exception("Symbol Not Found: " + sym, what) {}
    };
}

#endif /* QBEXCEPTIONS_H_ */
