cmake_minimum_required( VERSION 3.0 )

project( TESTILITY )



option( BUILD_DOCUMENTATION "Build the documentation." ON )
option( BUILD_TESTS "Build the test suite?" ON )


set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake )


include( testility_version )
set( TESTILITY_VERSION
  "${TESTILITY_MAJOR_VERSION}.${TESTILITY_MINOR_VERSION}.${TESTILITY_REVISION_VERSION}" )


include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR} )


set( PRIMARY_SOURCE_DIR ${TESTILITY_SOURCE_DIR}/testility )
set( SOURCE_FILES
  ${PRIMARY_SOURCE_DIR}/import.hpp
  ${PRIMARY_SOURCE_DIR}/test_failure.hpp
  ${PRIMARY_SOURCE_DIR}/test_driver.hpp
  ${PRIMARY_SOURCE_DIR}/tools.hpp
  ${PRIMARY_SOURCE_DIR}/macro_tools.hpp )


if( NOT TESTILITY_INSTALL_INCLUDE_DIR )
  set( TESTILITY_INSTALL_INCLUDE_DIR
    include/testility-${TESTILITY_MAJOR_VERSION}.${TESTILITY_MINOR_VERSION}/testility )
endif( NOT TESTILITY_INSTALL_INCLUDE_DIR )

install( FILES ${SOURCE_FILES}
  DESTINATION ${TESTILITY_INSTALL_INCLUDE_DIR} )

#
# ... Optional test build
#
if( BUILD_TESTS )
  enable_testing()
  add_subdirectory( test )
endif()


#
# ... Optional documentation build
#
if( BUILD_DOCUMENTATION )

  option( BUILD_HTML_DOCUMENTS "Build html documentation for testility." ON )
  option( BUILD_MAN_PAGES "Build man pages for testility." ON )

  if( BUILD_HTML_DOCUMENTS OR BUILD_MAN_PAGES )
  

    if( BUILD_HTML_DOCUMENTS )
      set( GENERATE_HTML YES )
    else()
      set( GENERATE_HTML NO )
    endif()
    
    if( BUILD_MAN_PAGES )
      set( GENERATE_MAN YES )
    else()
      set( GENERATE_MAN NO )
    endif()
    
    set( DOCUMENTATION_SOURCE_DIR ${TESTILITY_SOURCE_DIR}/testility )
    set( DOCUMENTATION_BUILD_DIR ${TESTILITY_BINARY_DIR}/doc )
    set( HTML_DIR ${DOCUMENTATION_BUILD_DIR}/html )
    set( MAN3_DIR ${DOCUMENTATION_BUILD_DIR}/man/man3 )

    configure_file( Doxyfile.in Doxyfile )

    set( DOCUMENTED_FILES ${TESTILITY_SOURCE_DIR}/testility/test_driver.hpp )

    add_custom_command(
      OUTPUT ${DOCUMENTATION_BUILD_DIR}
      COMMAND doxygen Doxyfile
      MAIN_DEPENDENCY Doxyfile
      DEPENDS ${SOURCE_FILES} )

    add_custom_target(
      documentation ALL
      DEPENDS ${DOCUMENTATION_BUILD_DIR})

    #
    # ... compress the man pages
    #
    if( BUILD_MAN_PAGES )

      # add_custom_command(
      # 	OUTPUT ${MAN3_DIR}/Testility.3.gz
      # 	COMMAND gzip ${MAN3_DIR}/*.3
      # 	DEPENDS ${SOURCE_FILES})

      # add_custom_target( compress_man_pages ALL
      # 	DEPENDS ${MAN3_DIR}/Testility.3.gz )

      if( NOT MAN3_INSTALL_DIR )
	set( MAN3_INSTALL_DIR share/man )
      endif( NOT MAN3_INSTALL_DIR )
      install( DIRECTORY ${MAN3_DIR}
	DESTINATION ${MAN3_INSTALL_DIR} )

    endif( BUILD_MAN_PAGES )

  endif( BUILD_HTML_DOCUMENTS OR BUILD_MAN_PAGES )
endif( BUILD_DOCUMENTATION )








