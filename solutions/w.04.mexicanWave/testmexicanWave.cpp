#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "./010.cpp"
#include "./015.cpp"
#include "./018.cpp"

bool assertEqual(const char **pIterable1, const char **pIterable2, int nLen)
{
    /*Write normalization and comparison code here*/
    /*Return comparison result*/
        do
        {
            if(strcmp(pIterable1[nLen - 1], pIterable2[nLen - 1]))
                break;
        }
        while(--nLen);

    return !nLen;
}
bool assertEqual(vector <string> szIterable1, const char **pIterable2)
{
    int nIndex = 0;
    
    for (auto szString: szIterable1)
        if(szString.compare(pIterable2[nIndex++]))
            break;
    int nC = szIterable1.size();
    return nIndex == szIterable1.size();
}

TEST_CASE("Test with Zero Letters Word", "[mexicanWave:Ground]")
{
    const char *const pInput = "";
    const char *pMexicanWave[] = {""};

    /*example call: You can write more of your solutions*/
    REQUIRE(assertEqual(const_cast<const char **>(mexican_wave_010(pInput)), pMexicanWave, sizeof(pMexicanWave)/sizeof(pMexicanWave[0])) == true);
    REQUIRE(assertEqual(mexican_wave_015(pInput), pMexicanWave) == true);
    REQUIRE(assertEqual(mexican_wave_018(pInput), pMexicanWave) == true);
}

TEST_CASE("Test with Single Word", "[mexicanWave:Ground]")
{
    const char *const pInput = "wave";
    const char *pMexicanWave[] = {"Wave", "wAve", "waVe", "wavE"};

    /*example call: You can write more of your solutions*/
    REQUIRE(assertEqual(const_cast<const char **>(mexican_wave_010(pInput)), pMexicanWave, sizeof(pMexicanWave)/sizeof(pMexicanWave[0])) == true);
    REQUIRE(assertEqual(mexican_wave_015(pInput), pMexicanWave) == true);
    REQUIRE(assertEqual(mexican_wave_018(pInput), pMexicanWave) == true);
}

// TEST_CASE("Test with Double Word", "[mexicanWave:Level#1]")
// {
//     const char *const pInput = "mexican wave";
//     const char *pMexicanWave[] = {"Mexican wave", "mExican wave", "meXican wave", "mexIcan wave",
//                                   "mexiCan wave", "mexicAn wave", "mexicaN wave", "mexican Wave",
//                                   "mexican wAve", "mexican waVe", "mexican wavE"};

//     /*example call: You can write more of your solutions*/
//     REQUIRE(assertEqual(mexican_wave(pInput), pMexicanWave) == true);
// }