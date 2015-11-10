/** test_failure.hpp --- Source file for test failure exceptions
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


#ifndef TEST_FAILURE_HPP_476162589884321501
#define TEST_FAILURE_HPP_476162589884321501 1


// Testility header files

#include <testility/import.hpp>


namespace Testility
{
  namespace Core
  {

    ////////////////////////////////////////////////////////////////////////
    //
    // ... Failure Template
    //
    

    /** A class template for building failure classes. 
	Failures are exceptions that are handedled by the
	test driver.  See the class template Test_driver for 
	details on how they are handled
    */
    template<

      /** A typename parameter providing the default failure message. */
      typename Default_message,
      
      /** A typename parameter providing the default message preface. */
      typename Default_preface

      >
    class Failure_kernel : public exception
    {
    public:
      using this_type = Failure_kernel;
      Failure_kernel( const std::string& message = Default_message()(),
		      const std::string& preface = Default_preface()() )
      {

	msg = preface+"\n"+message;
      }

      const char*
      what() const noexcept
      {
	return msg.c_str();
      }
    private:
      string msg;
    };



    ////////////////////////////////////////////////////////////////////////
    //
    // ... Test Failures
    //


    /** A struct to provide the default message for test failures.
     */
    struct Failure_default
    {
      /** Return the default message.*/
      string
      operator()() const
      {
	return "An unspecified test failure occurred.";
      }
    
    };

    /** A struct to provide the preface string for test failures. 
     */
    struct Failure_preface
    {
      /** Return the message preface. */
      string
      operator ()() const
      {
	return  "TEST FAILURE:";
      }
    };
    
    /** An exception indicating that a test failed. 
	See the class template Test_driver for specific details on the
	handling of critical test failures.
    */
    using Test_failure = Failure_kernel<Failure_default,Failure_preface>;



    ////////////////////////////////////////////////////////////////////////
    //
    // ... Critical Test Failures
    //


    /** A struct ot provide the default message for critical failures.
     */
    struct Critical_default
    {
      /** Return the default message.*/
      string operator ()()
      {
	return "An unspecified crictical failure occurred.";
      }
    };

    /** A struct to provide the message preface for critical failures. 
     */
    struct Critical_preface
    {
      /** Return the message preface.*/
      string operator()() const
      {
	return "CRITICAL FAILURE:";
      }
    };

    /** An exception indicating that a critical test failure occurred.
	See the class template Test_driver for specific details on the handling
	of critical test failures.
    */
    using Critical_test_failure = Failure_kernel<Critical_default, Critical_preface>;
    

    
  } // end of namespace Core
} // ned of namespace Testility



#endif // ! defined TEST_FAILURE_HPP_476162589884321501
