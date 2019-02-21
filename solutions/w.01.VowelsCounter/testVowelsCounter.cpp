
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./../catch.hpp"

#include "./010.cpp"
#include "./020.cpp"
#include "./030.cpp"
#include "./040.cpp"
#include "./041.cpp"
#include "./042.cpp"
#include "./050.cpp"


TEST_CASE("[ZeroLengthString]", "VowelsCounterBaseTest") {
  REQUIRE(0 == vowel_counter_010(""));
  REQUIRE(0 == vowel_counter_020(""));
  REQUIRE(0 == vowel_counter_030(""));
  REQUIRE(0 == vowel_counter_041(""));
  REQUIRE(0 == vowel_counter_042(""));
  REQUIRE(0 == vowel_counter_050(""));
}

TEST_CASE("[LowerCaseString]", "VowelsCounterBaseTest") {
  REQUIRE(4 == vowel_counter_010("safetydance"));
  REQUIRE(4 == vowel_counter_020("safetydance"));
  REQUIRE(4 == vowel_counter_030("safetydance"));
  REQUIRE(4 == vowel_counter_041("safetydance"));
  REQUIRE(4 == vowel_counter_042("safetydance"));
  REQUIRE(4 == vowel_counter_050("safetydance"));
}

TEST_CASE("[UpperCaseString]", "VowelsCounterBaseTest") {
	REQUIRE(4 == vowel_counter_010("SAFETYDANCE"));
	REQUIRE(4 == vowel_counter_020("SAFETYDANCE"));
	REQUIRE(4 == vowel_counter_030("SAFETYDANCE"));
	REQUIRE(4 == vowel_counter_041("SAFETYDANCE"));
	REQUIRE(4 == vowel_counter_042("SAFETYDANCE"));
	REQUIRE(4 == vowel_counter_050("SAFETYDANCE"));
}

TEST_CASE("[MixedCaseString]", "VowelsCounterBaseTest") {
	REQUIRE(4 == vowel_counter_010("SaFetYDANCE"));
	REQUIRE(4 == vowel_counter_020("SaFetYDANCE"));
	REQUIRE(4 == vowel_counter_030("SaFetYDANCE"));
	REQUIRE(4 == vowel_counter_041("SaFetYDANCE"));
	REQUIRE(4 == vowel_counter_042("SaFetYDANCE"));
	REQUIRE(4 == vowel_counter_050("SaFetYDANCE"));
}

TEST_CASE("[DigitsString]", "VowelsCounterBaseTest") {
	REQUIRE(0 == vowel_counter_010("123"));
	REQUIRE(0 == vowel_counter_020("123"));
	REQUIRE(0 == vowel_counter_030("123"));
	REQUIRE(0 == vowel_counter_041("123"));
	REQUIRE(0 == vowel_counter_042("123"));
	REQUIRE(0 == vowel_counter_050("123"));
}