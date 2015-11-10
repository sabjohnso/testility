/** test_driver_test.cpp --- 
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


//  Testility header files
#include <testility/tools.hpp>

using namespace Testility;


// A Test that passes
struct Test1
{
    Test1(){}
    operator int(){ return 0; }

};


// A test that fails by returning an error signal
struct Test2
{
    Test2(){}
    operator int(){ return 1; }
};


// A test that fails by throwing a test failure exception
struct Test3
{
    Test3(){ throw Test_failure( "Yikes, that was a fake failure!" ); }
    operator int() const { return 0; }
};



struct Test4
{
    Test4(){ throw Critical_test_failure( "Yikes, that was a fake critical failure!" ); }
    operator int() const { return 0; }
};



    




int
main( int, char**  )
{
    if( Test_driver< Test1 >() != 0 ){ return 1; }
    else if( Test_driver< Test2 >() !=  1 ){ return 2; }
    else if( Test_driver< Test3 >() !=  1 ){ return 3; }
    else if( Test_driver< Test4 >() != -1 ){ return 4; }
    else{ return 0; }


    

}
