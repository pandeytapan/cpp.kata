#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"

TEST_CASE("Test with Initialized Point", "[Point:Ground]")
{
    /*This is sample test case. You can write more of yours below*/
    REQUIRE(compare_points(Point(),Point(0, 0)) == true);
}

TEST_CASE("Test with Quadrant", "[Point:Ground]")
{
    /*This is sample test case. You can write more of yours below*/
    REQUIRE(compare_points(Point(12, 4),"First") == true);
}
