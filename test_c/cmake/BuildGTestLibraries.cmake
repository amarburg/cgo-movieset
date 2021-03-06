#
# Build a local copy of gtest
#
# By the googletest FAQ
# (https://github.com/google/googletest/blob/master/googletest/docs/V1_7_FAQ.md)
# " Instead, each project should compile Google Test itself such that it
# can be sure that the same flags are used for both Google Test and the tests."

include(ExternalProject)

ExternalProject_Add( gtest_ext
			PREFIX ${CMAKE_BINARY_DIR}/gtest
			GIT_REPOSITORY "https://github.com/google/googletest"
			CMAKE_ARGS -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/gtest -DBUILD_SHARED_LIBS:bool=ON
			BUILD_COMMAND ${EXTERNAL_PROJECT_MAKE_COMMAND}
			INSTALL_DIR ${CMAKE_BINARY_DIR}/gtest )

ExternalProject_Get_Property( gtest_ext INSTALL_DIR )

set( GTEST_INCLUDE_DIRS ${INSTALL_DIR}/include  )
set( GTEST_LIBRARY gtest  )
set( GTEST_MAIN_LIBRARY gtest_main )
set( GTEST_BOTH_LIBRARIES ${GTEST_MAIN_LIBRARY} ${GTEST_LIBRARY} )

set( GTEST_LIBRARY_DIR ${CMAKE_BINARY_DIR}/gtest/lib )
link_directories( ${GTEST_LIBRARY_DIR} )

# set( GTEST_BOTH_LIBRARIES gtest gtest_main )
set_target_properties(gtest_ext PROPERTIES EXCLUDE_FROM_ALL TRUE)
