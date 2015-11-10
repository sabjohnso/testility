/** macro_tools.hpp --- Macro tools for testing.
 *
 * Copyright (C) 2015 Samuel B. Johnson
 *
 * Author: Samuel B. Johnson <sabjohnso@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */


#ifndef MACRO_TOOLS_HPP_399344170869900894
#define MACRO_TOOLS_HPP_399344170869900894 1


// Testility header files

#include <testility/test_failure.hpp>
#include <testility/tools.hpp>


#define TESTILITY_QUOTE_AUX( ... ) #__VA_ARGS__
#define TESTILITY_QUOTE( ... ) TESTILITY_QUOTE_AUX( __VA_ARGS__ )


#define TEST_TRUE( ... )						\
    do{									\
	auto result = (__VA_ARGS__);					\
	if( ! result )							\
	{								\
	    throw Testility::Core::Test_failure(			\
		__FILE__ ":"						\
		TESTILITY_QUOTE( __LINE__ )				\
		":0: failure: the test expression is not true\n"	\
		TESTILITY_QUOTE( __VA_ARGS__ ));			\
	}								\
    }while(false)

#define TEST_FALSE( ... )						\
    do{									\
	auto result = (__VA_ARGS__);					\
	if( result )							\
	{								\
	    throw Testility::Core::Test_failure(			\
		__FILE__ ":"						\
		TESTILITY_QUOTE( __LINE__ )				\
		":0: failure: the test expression is not false\n"	\
		TESTILITY_QUOTE( __VA_ARGS__ ));			\
	}								\
    }while(false)

#define TEST_EQUAL( a, b )						\
    do{									\
	auto result = Testility::Core::make_pair((a),(b));		\
	if( !( result.first == result.second ))				\
	{								\
	    throw Testility::Core::Test_failure(			\
		__FILE__ ":"						\
		TESTILITY_QUOTE( __LINE__ )				\
		":0: failure: equality test failed \n"			\
		TESTILITY_QUOTE( a) " == " TESTILITY_QUOTE( b )		\
		"\t(fails)");						\
	}								\
    }while( false )


#define TEST_LT( a, b )							\
    do{									\
	auto result = Testility::Core::make_pair((a),(b));		\
	if( !( result.first < result.second ))				\
	{								\
	    throw Testility::Core::Test_failure(			\
		__FILE__ ":"						\
		TESTILITY_QUOTE( __LINE__ )				\
		":0: failure: < test failed \n"			\
		TESTILITY_QUOTE( a) " < " TESTILITY_QUOTE( b )		\
		"\t(fails)");						\
	}								\
    }while( false )


#define TEST_LE( a, b )							\
    do{									\
	auto result = Testility::Core::make_pair((a),(b));		\
	if( !( result.first <= result.second ))				\
	{								\
	    throw Testility::Core::Test_failure(			\
		__FILE__ ":"						\
		TESTILITY_QUOTE( __LINE__ )				\
		":0: failure: <= test failed \n"			\
		TESTILITY_QUOTE( a) " <= " TESTILITY_QUOTE( b )		\
		"\t(fails)");						\
	}								\
    }while( false )


#define TEST_GE( a, b )							\
    do{									\
	auto result = Testility::Core::make_pair((a),(b));		\
	if( !( result.first >= result.second ))				\
	{								\
	    throw Testility::Core::Test_failure(			\
		__FILE__ ":"						\
		TESTILITY_QUOTE( __LINE__ )				\
		":0: failure: >= test failed \n"			\
		TESTILITY_QUOTE( a) " >= " TESTILITY_QUOTE( b )		\
		"\t(fails)");						\
	}								\
    }while( false )


#define TEST_GT( a, b )							\
    do{									\
	auto result = Testility::Core::make_pair((a),(b));		\
	if( !( result.first > result.second ))				\
	{								\
	    throw Testility::Core::Test_failure(			\
		__FILE__ ":"						\
		TESTILITY_QUOTE( __LINE__ )				\
		":0: failure: > test failed \n"				\
		TESTILITY_QUOTE( a) " > " TESTILITY_QUOTE( b )		\
		"\t(fails)");						\
	}								\
    }while( false )


#endif // MACRO_TOOLS_HPP_399344170869900894
