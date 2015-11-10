/** test_failure_test.cpp --- 
 *
 * Copyright (C) 2015 Samuel B. Johnson
 *
 * Author: Samuel B. Johnson <sbj@Mondrian.attlocal.net>
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


// Standard header files

#include <iostream>


// Testility header files

#include <testility/tools.hpp>


int
test_test_failure()
{
    try
    {
	throw Testility::Test_failure( "Phoney Message!!!!" );
	std::cout << "The code should not reach this point." << std::endl;
	return 1;
    }
    catch( Testility::Test_failure& failure )
    {
	std::cout << "This is the correct exceptional path of execution." << std::endl;
	std::cout << failure.what() << std::endl;
	return 0;
    }
    catch( std::exception& e )
    {
	std::cout << "This is not the correct exceptional path of execution." << std::endl;
	std::cout << e.what() << std::endl;
	return 1;
    }
    return 0;
}


int
test_test_failure2()
{
    try
    {
	throw Testility::Test_failure( "Second Phoney Message!!!!" );
	std::cout << "The code should not reach this point." << std::endl;
	return 1;
    }
    catch( std::exception& e )
    {
	std::cout << "The test failure was correctly caught as a standard exception." << std::endl;
	std::cout << e.what() << std::endl;
	return 0;
    }
}



int
main( int argc, char** argv )
{
    if( test_test_failure() )
    {
	return 1;
    }
    else if( test_test_failure2() )
    {
	return 2;
    }
    else
    {
	return 0;
    }
}
