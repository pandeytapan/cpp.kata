#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./snippets_test/mem_macros.h"


TEST_CASE("Test with Zero length", "[safe_cpy_limit]")
{
    const int MAXLEN = 8;
    char dest[MAXLEN] = {0};
    strcpy(dest,"Hello");

    char *src = "";
    int u32_safe_cpy_len = safe_cpy_len(MAXLEN, strlen(dest), strlen(src), 1);
    REQUIRE(u32_safe_cpy_len == 0);    
}

TEST_CASE("Test with Safe length", "[safe_cpy_limit]")
{
    const int MAXLEN = 10;
    char dest[MAXLEN] = {0};
    strcpy(dest,"Hello");

    const char * src = "Bye";

    /*Offset 1*/
    int u32_safe_cpy_len = safe_cpy_len(MAXLEN, strlen(dest), strlen(src), 1);
    REQUIRE(u32_safe_cpy_len == 0);   

    memset(dest, 0, MAXLEN); 
}