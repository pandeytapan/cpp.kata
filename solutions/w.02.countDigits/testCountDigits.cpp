#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"

#include "./010.cpp"
#include "./020.cpp"
#include "./030.cpp"
#include "./040.cpp"

#include <iostream>
using namespace std;


TEST_CASE( "Test Zero", "[Count Digit]" ) {
    REQUIRE( countDigit_010(0,0) == 1);
    REQUIRE( countDigit_020(0,0) == 1);
    REQUIRE( countDigit_030(0,0) == 1);
    REQUIRE( countDigit_040(0,0) == 1);
}

TEST_CASE( "Test Single Digit Number", "[Count Digit]" ) {
    REQUIRE( countDigit_010(4,1) == 2);
    REQUIRE( countDigit_020(9,1) == 3);
    REQUIRE( countDigit_030(8,6) == 3);
    REQUIRE( countDigit_040(9,9) == 2);
}


TEST_CASE( "Test Double Digit", "[Count Digit]" ) {
    REQUIRE( countDigit_010(10,1) == 4);
    REQUIRE( countDigit_020(20,4) == 7);
    REQUIRE( countDigit_030(15,6) == 5);
    REQUIRE( countDigit_040(15,6) == 5);
}

