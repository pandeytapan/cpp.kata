#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./snippets_test/mem_macros.h"


TEST_CASE("Test with Zero length", "[safe_cpy_limit]")
{
    const int k_u32_MAXLEN = 5;
    char dest[k_u32_MAXLEN] = {0};

    /*We can use a constant*/
    int u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest));
    REQUIRE(u32_safe_cpy_len == 4);    

    /*We can use sizeof when total length isn't known*/
    u32_safe_cpy_len = safe_cpy_len(sizeof(dest), strlen(dest));
    REQUIRE(u32_safe_cpy_len == 4);
}

TEST_CASE("Test with within range length source", "[safe_cpy_limit]")
{
    
    const int k_u32_MAXLEN = 10;
    char dest[k_u32_MAXLEN] = {0};
    strcpy(dest,"Hello");

    
    int u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest));
    REQUIRE(u32_safe_cpy_len == 4);   
}

TEST_CASE("Test with outside range length source", "[safe_cpy_limit]")
{
    
    const int k_u32_MAXLEN = 10;
    char dest[k_u32_MAXLEN] = {0};
    strcpy(dest,"Hello");

    
    /*Offset 0*/
    int u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest));
    REQUIRE(u32_safe_cpy_len == 4);   


}