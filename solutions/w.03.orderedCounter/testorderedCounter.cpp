#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "./010.cpp"
#include "./012.cpp"
#include "./015.cpp"
#include "./018.cpp"
#include "./020.cpp"
#include "./030.cpp"

bool assertIterableEqual (int *pIterable1, int *pIterable2, int nCount){

    while (*pIterable1++ == *pIterable2++)
        --nCount;
    return !nCount;
}

TEST_CASE( "Test with Zero Letters Word", "[OrderedCounter]" ) 
{
    const char * const pInput = "";
    int nOutput[] = {};

    REQUIRE (assertIterableEqual(orderedCounter_010(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_012(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(unique_ptr<int[]>(orderedCounter_015(pInput)).get(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_018(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_020(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_030(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
}


TEST_CASE( "Test with Single Word", "[OrderedCounter]" ) 
{
    const char * const pInput = "mozzarella";
    int nOutput[] = {1, 1, 2, 2, 1, 1, 2};

    REQUIRE (assertIterableEqual(orderedCounter_010(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_012(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(unique_ptr<int[]>(orderedCounter_015(pInput)).get(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_018(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_020(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_030(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
}

TEST_CASE( "Test with Double Word", "[OrderedCounter]" ) 
{
    const char * const pInput = "Crime scene";
    int nOutput[] = {1, 1, 1, 1, 3, 1, 1, 1};
    REQUIRE (assertIterableEqual(orderedCounter_010(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_012(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);   
    REQUIRE (assertIterableEqual(unique_ptr<int[]>(orderedCounter_015(pInput)).get(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_018(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_020(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_030(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
}