/** tools.hpp --- 
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

#ifndef TOOLS_HPP_2280599234176117093
#define TOOLS_HPP_2280599234176117093 1


// Testility header files

#include <testility/test_failure.hpp>
#include <testility/test_driver.hpp>



namespace Testility
{

  /** Test failure exception */
  using Core::Test_failure;

  /** Critical test failure exception */
  using Core::Critical_test_failure;

  /** Test Driver */
  using Core::Test_driver;
  
} // end of namespace Testility





#endif // TOOLS_HPP_2280599234176117093
