#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "./010.cpp"
#include "./012.cpp"
#include "./015.cpp"
#include "./018.cpp"
#include "./020.cpp"
#include "./030.cpp"
#include "./level1_010.cpp"

bool assertIterableEqual (int *pIterable1, int *pIterable2, int nCount){

    while (*pIterable1++ == *pIterable2++)
        --nCount;
    return !nCount;
}

bool assertIterableEqual (std::pair<char,int> *pIterable1, std::pair<char,int> *pIterable2, int nCount){
    while(pIterable1->first == pIterable2->first && pIterable1->second == pIterable2->second){
        ++pIterable1;
        ++pIterable2;
        --nCount;
    }
    
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
    vector<pair<char, int>> vecOutput {make_pair('m', 1), make_pair('o', 1), make_pair('z', 2), make_pair('a', 2), make_pair('r', 1), make_pair('e', 1), make_pair('l', 2)};
    // Ground Test    
    REQUIRE (assertIterableEqual(orderedCounter_010(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_012(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(unique_ptr<int[]>(orderedCounter_015(pInput)).get(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_018(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_020(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_030(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    // Level # 1
    REQUIRE (assertIterableEqual(orderedCounter_level1_010(pInput).data(), vecOutput.data(), vecOutput.size()) == true);

}

TEST_CASE( "Test with Double Word", "[OrderedCounter]" ) 
{
    const char * const pInput = "Crime scene";
    int nOutput[] = {1, 1, 1, 1, 3, 1, 1, 1};
    vector<pair<char, int>> vecOutput 
    {
        make_pair('C', 1), make_pair('r', 1), 
        make_pair('i', 1), make_pair('m', 1), 
        make_pair('e', 3), make_pair('s', 1), 
        make_pair('c', 1), make_pair('n', 1)
    };
     // Ground Test 
    REQUIRE (assertIterableEqual(orderedCounter_010(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_012(pInput), nOutput, sizeof(nOutput)/sizeof(int)) == true);   
    REQUIRE (assertIterableEqual(unique_ptr<int[]>(orderedCounter_015(pInput)).get(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_018(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_020(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    REQUIRE (assertIterableEqual(orderedCounter_030(pInput).data(), nOutput, sizeof(nOutput)/sizeof(int)) == true);
    // Level # 1
    REQUIRE (assertIterableEqual(orderedCounter_level1_010(pInput).data(), vecOutput.data(), vecOutput.size()) == true);

}