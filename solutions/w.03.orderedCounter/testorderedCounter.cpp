#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "./010.cpp"

bool assertIterableEqual (int *pIterable1, int *pIterable2, int nCount){
    while (*pIterable1++ == *pIterable2++)
        --nCount;
    return !nCount;
}

TEST_CASE( "Test with Single Word", "[OrderedCounter]" ) 
{
    int nOutput[] = {1, 1, 2, 2, 1, 1, 2};
    REQUIRE (assertIterableEqual(orderedCounter_010("mozzarella"), nOutput, sizeof(nOutput)/sizeof(int)) == true);
   
}