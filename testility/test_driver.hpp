/** test_driver.hpp --- Source file for a Test_driver class template
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


#ifndef TEST_DRIVER_HPP_2055037689207517216
#define TEST_DRIVER_HPP_2055037689207517216 1

// Testility header files

#include <testility/test_failure.hpp>


namespace Testility
{
  namespace Core
  {

  
    /** A class to run a number of tests and accumulated the number of failures.
	
	The tests are specified as template parameters where each type in the 
	template parameter list is a test that can fail in one of four ways:
	- when cast as an int, the test will be nonzero
	- the test can throw a Test_failure exception
	- the test can throw a Critical_test failure exception
	- the test can throw some other exception.
	In the caes where the test fails by throwing a Test_failure exception, the
	exception message will be printed to standard out and the subsequent tests
	will still be executed.  In the case that the test fails by throwing a
	Critical_test_failure, the exception message will be printed to standard out,
	but the subsquent tests will not be executed.  In the case that any other exception 
	is thrown, the exception will not be handled in any whay by the Testility code.
    */
    template<
      
      /** A variadic list of tests. */
      typename ... Tests
      
      >
    class Test_driver
    {

      /** A struct to carry the list of types for the tests as a single type.  */
      template< typename ... Ts >
      struct TestList{};
      
    public:
	  
      /** A variadic template constructor. 
	  Each of the types in the test list is passed the 
	  input argument at construction time.
      */
      
      template< typename ... Args >
      Test_driver( const Args& ... args )
	: failure_count( aux0( TestList< Tests ... >{}, args ... ))
      {}

      /** Coercion to an int. 
	  When coerced to an int, an instance of Test_driver returns the accummulated number
	  of test failures, or -1 in the case that a critical test failure is encountered.
      */
      operator int() const
      {
	return failure_count;
      }

    private:

      
      template< typename ... Test_types, typename ... Args >
      size_t
      aux0( TestList<Test_types...>&&, const Args& ... args )
      {
	try{ return aux( 0, TestList< Test_types ...>(), args ... ); }
	catch( Critical_test_failure& failure ){
	  cout << failure.what() << endl;
	  return -1;
	}
	    
      }

      template< typename  ... Args >
      static size_t
      aux( size_t accum, TestList<>&&, const Args& ... )
      {
	return accum;
      }

      template< typename Test_type, typename ... Test_types, typename ... Args >
      static size_t
      aux( size_t accum, TestList< Test_type, Test_types ... >&&, const Args& ... args )
      {
	
	int res = 0;
	
	try{
	  res = Test_type( args ... );
	}
	
	catch( Test_failure& failure ){
	  cout << failure.what() << endl;
	  res = 1;
	}
	
	return aux( accum+res, TestList<Test_types ... >(), args ... );
	
      }

      /** A variable used to store the number of test failures. */
      size_t failure_count;
            
    };

	
  } // end of namespace Core
} // end of namespace Testility



#endif // TEST_DRIVER_HPP_2055037689207517216
