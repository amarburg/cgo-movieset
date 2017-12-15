#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "liblazyquicktime.h"
#include "types.h"

#include "test_data_paths.h"

using std::endl;
using std::cout;

TEST( GetFrame, NullConstructor )
{
  char url[] = "";
  ImageBuffer img;

  // This should fail!
  ASSERT_EQ( GetFrame(url, 1, &img), -1 );

  // And the result will be invalid
  ASSERT_EQ( img.valid, 0 );

}

// TEST( GetFrame, LocalFileZeroFrame )
// {
//   // TODO: How to set this path..?
//   ImageBuffer img = GetFrame( localFilePath, 0 );
//   ASSERT_EQ( img.valid, 0 );
// }

void validateCamHDFrame( ImageBuffer &img )
{
  ASSERT_EQ( img.valid, 1 );

  ASSERT_EQ( img.width, 1920 );
  ASSERT_EQ( img.height, 1080 );
  ASSERT_TRUE( img.data != nullptr );
  ASSERT_EQ( img.channels, 4 );
  ASSERT_EQ( img.depth, IMG_8U );
}

// Test against a real movie
TEST( GetFrame, GetFrameFromLocalFile )
{
  ImageBuffer img;

ASSERT_EQ( GetFrame( LOCAL_TEST_MOV, 1, &img ), 0 );

  validateCamHDFrame( img );

  free( img.data );
}

// Test against a real movie
TEST( GetFrame, GetFrameFromHTTPFile )
{
  ImageBuffer img;
  ASSERT_EQ( GetFrame( CI_TEST_MOVIE_URL, 1, &img ), 0 );

  validateCamHDFrame( img );

  free( img.data );
}


// Test against a multimov
TEST( GetFrame, GetFrameFromLocalMultimov )
{
  ImageBuffer img;
  ASSERT_EQ( GetFrame( LOCAL_TEST_MULTIMOV, 1, &img ), 0 );

  validateCamHDFrame( img );

  free( img.data );
}