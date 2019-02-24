#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"

bool assertIterableEqual (char []]pIterable1, char *[]pIterable2){
    /*Write normalization and comparison code here*/
    /*Return comparison result*/ 
}


TEST_CASE( "Test with Zero Letters Word", "[mexicanWave:Ground]" ) 
{
    const char * const pInput = "";
    char * pMexicanWave[] = {""};

    /*example call: You can write more of your solutions*/ 
    REQUIRE (assertIterableEqual(mexican_wave(pInput), pMexicanWave) == true);

}


TEST_CASE( "Test with Single Word", "[mexicanWave:Ground]" ) 
{
    const char * const pInput = "wave";
    char * pMexicanWave[] = {"Wave", "wAve", "waVe", "wavE"};

    /*example call: You can write more of your solutions*/ 
    REQUIRE (assertIterableEqual(mexican_wave(pInput), pMexicanWave) == true);
}

TEST_CASE( "Test with Double Word", "[mexicanWave:Level#1]" ) 
{
    const char * const pInput = "mexican wave";
    char * pMexicanWave[] = {"Mexican wave", "mExican wave", "meXican wave", "mexIcan wave",
                             "mexiCan wave", "mexicAn wave", "mexicaN wave", "mexican Wave",
                             "mexican wAve", "mexican waVe", "mexican wavE"};

    /*example call: You can write more of your solutions*/ 
    REQUIRE (assertIterableEqual(mexican_wave(pInput), pMexicanWave) == true);
}