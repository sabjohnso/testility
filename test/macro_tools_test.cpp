/** macro_tools_test.cpp --- 
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

// Standard header files
#include <iostream>

// Testility header files
#include <testility/macro_tools.hpp>


/** Test for the macro TEST_TRUE. */
struct True_test
{
  True_test()
  {
    TEST_TRUE( true );
    try{
      TEST_TRUE( false );
    }
    catch( Testility::Test_failure& failure ){
      std::cout << "\n\nThe following is the test message, NOT an actual failure." << std::endl;
      std::cout << failure.what() << std::endl;
      std::cout << "This is the end of the test message.\n\n" << std::endl;
    }
  }
  operator int() const{ return 0; }
};


/** Test for the macro TEST_FALSE. */
struct False_test
{
  False_test()
  {
    TEST_FALSE( false );
    try{
      TEST_FALSE( true );
    }
    catch( Testility::Test_failure& failure ){
      std::cout << "\n\nThe following is the test message, NOT an actual failure." << std::endl;
      std::cout << failure.what() << std::endl;
      std::cout << "This is the end of the test message.\n\n" << std::endl;
    }
  }
  operator int() const{ return 0; }
};



/** Test for the macro TEST_EQUAL. */
struct Equal_test
{
  Equal_test()
  {
    TEST_EQUAL( 1.0, 1 );
    try{
      TEST_EQUAL( 1, 2.0 );
    }
    catch( Testility::Test_failure& failure ){
      std::cout << "\n\nThe following is the test message, NOT an actual failure." << std::endl;
      std::cout << failure.what() << std::endl;
      std::cout << "This is the end of the test message.\n\n" << std::endl;
    }
	
  }
  operator int() const{ return 0; }
};



/** Test for the macro TEST_LT. */
struct Less_than_test
{
  Less_than_test()
  {
    TEST_LT( 1, 2 );
    try{
      TEST_LT( 2, 1 );
    }
    catch( Testility::Test_failure& failure ){
      std::cout << "\n\nThe following is the test message, NOT an actual failure." << std::endl;
      std::cout << failure.what() << std::endl;
      std::cout << "This is the end of the test message.\n\n" << std::endl;
    }
	
  }
  operator int() const{ return 0; }
};



/** Test for the macro TEST_LE. */
struct Less_than_equal_test
{
  Less_than_equal_test()
  {
    TEST_LE( 1, 1 );
    TEST_LE( 1, 2 );
    try{
      TEST_LE( 2, 1 );
    }
    catch( Testility::Test_failure& failure ){
      std::cout << "\n\nThe following is the test message, NOT an actual failure." << std::endl;
      std::cout << failure.what() << std::endl;
      std::cout << "This is the end of the test message.\n\n" << std::endl;
    }
	
  }
  operator int() const{ return 0; }
};



/** Test for the macro TEST_GE. */
struct Greater_than_equal_test
{
  Greater_than_equal_test()
  {
    TEST_GE( 2, 2 );
    TEST_GE( 2, 1 );
    try{
      TEST_GE( 1, 2 );
    }
    catch( Testility::Test_failure& failure ){
      std::cout << "\n\nThe following is the test message, NOT an actual failure." << std::endl;
      std::cout << failure.what() << std::endl;
      std::cout << "This is the end of the test message.\n\n" << std::endl;
    }
	
  }
  operator int() const{ return 0; }
};


/** Test for the macro TEST_GT. */
struct Greater_than_test
{
  Greater_than_test()
  {
    TEST_GT( 2, 1 );
    try{
      TEST_GT( 1, 2 );
    }
    catch( Testility::Test_failure& failure ){
      std::cout << "\n\nThe following is the test message, NOT an actual failure." << std::endl;
      std::cout << failure.what() << std::endl;
      std::cout << "This is the end of the test message.\n\n" << std::endl;
    }
	
  }
  operator int() const{ return 0; }
};



int
main( int, char** )
{
  using Testility::Test_driver;
  return Test_driver<
    True_test,
    False_test,
    Equal_test,
    Less_than_test,
    Less_than_equal_test,
    Greater_than_equal_test,
    Greater_than_test
    >();
}



