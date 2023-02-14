#include <gtest/gtest.h>
#include "index.h"
TEST(SurfaceMesh, load)
{
	EXPECT_NO_THROW(CGALBeginTests::SurfaceMesh::load());
}

TEST(Triangulations, for_loop_2)
{
	EXPECT_NO_THROW(CGALBeginTests::Triangulations::for_loop_2());
}

TEST(Triangulations, terrain)
{
	EXPECT_NO_THROW(CGALBeginTests::Triangulations::terrain());
}