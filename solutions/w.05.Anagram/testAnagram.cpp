#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"

TEST_CASE("Test with Zero Letters Word", "[anagram:Ground]")
{
    /*example call: You can write more of your solutions*/
    REQUIRE(assertEqual(is_anagram("","") == true);
}

TEST_CASE("Test with Single Word", "[anagram:Ground]")
{
    /*example call: You can write more of your solutions*/
    REQUIRE(assertEqual(is_anagram("Listen","Silent") == true);
}

TEST_CASE("Test with Double Word", "[anagram:Ground]")
{
    /*example call: You can write more of your solutions*/
    REQUIRE(assertEqual(is_anagram("Madam Curie","Radium came") == true);
}