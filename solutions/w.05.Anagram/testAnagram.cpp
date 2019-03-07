#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "./005.cpp"
#include "./010.cpp"
#include "./011.cpp"
#include "./020.cpp"
#include "./021.cpp"
#include "./030.cpp"


TEST_CASE("Test with Zero Letters Word", "[anagram:Ground]")
{
    REQUIRE(is_anagram_005("","") == true);
    REQUIRE(is_anagram_010("","") == true);
    REQUIRE(is_anagram_011("","") == true);
    REQUIRE(is_anagram_020("","") == true);
    REQUIRE(is_anagram_021("","") == true);
    REQUIRE(is_anagram_030("","") == true);
}

TEST_CASE("Test with Single Word", "[anagram:Ground]")
{
    REQUIRE(is_anagram_005("Listen","Silent") == true);
    REQUIRE(is_anagram_010("Listen","Silent") == true);
    REQUIRE(is_anagram_011("Listen","Silent") == true);
    REQUIRE(is_anagram_020("Listen","Silent") == true);
    REQUIRE(is_anagram_021("Listen","Silent") == true);
    REQUIRE(is_anagram_030("Listen","Silent") == true);
}

TEST_CASE("Test with Double Word", "[anagram:Ground]")
{
    REQUIRE(is_anagram_005("Madam Curie","Radium came") == true);
    REQUIRE(is_anagram_010("Madam Curie","Radium came") == true);
    REQUIRE(is_anagram_011("Madam Curie","Radium came") == true);
    REQUIRE(is_anagram_020("Madam Curie","Radium came") == true);
    REQUIRE(is_anagram_021("Madam Curie","Radium came") == true);
    REQUIRE(is_anagram_030("Madam Curie","Radium came") == true);
}