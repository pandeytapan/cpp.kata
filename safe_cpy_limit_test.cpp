#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./snippets_test/mem_macros.h"


TEST_CASE("Test with Zero length source", "[safe_cpy_limit]")
{
    const int k_u32_MAXLEN = 5;
    char dest[k_u32_MAXLEN] = {0};
    strcpy(dest,"DEAD");

    const char *src = "";
    int u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 0);
    REQUIRE(u32_safe_cpy_len == 0);    

    /*Offset doesn't matters with empty source*/
    u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 4);
    REQUIRE(u32_safe_cpy_len == 0);
}

TEST_CASE("Test with within range length source", "[safe_cpy_limit]")
{
    
    const int k_u32_MAXLEN = 10;
    char dest[k_u32_MAXLEN] = {0};
    strcpy(dest,"Hello");

    const char * src = "Bye";

    /*Offset 0*/
    int u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 0);
    REQUIRE(u32_safe_cpy_len == 3);   

    /*Offset 3: This means we are reserving a buffer of 3 bytes in destination*/
    u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 3);
    REQUIRE(u32_safe_cpy_len == 1);   

    /*Offset 5: This means we are reserving a buffer of 5 bytes in destination*/
    /*With safe max we have avoided the stack crash*/
    u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 5);
    REQUIRE(u32_safe_cpy_len == -1);   

    u32_safe_cpy_len = safe_max(0, u32_safe_cpy_len);
    REQUIRE(u32_safe_cpy_len == 0);
}

TEST_CASE("Test with outside range length source", "[safe_cpy_limit]")
{
    
    const int k_u32_MAXLEN = 10;
    char dest[k_u32_MAXLEN] = {0};
    strcpy(dest,"Hello");

    const char * src = "Hola Amigos";

    /*Offset 0*/
    int u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 0);
    REQUIRE(u32_safe_cpy_len == 4);   

    /*Offset 2: This means we are reserving a buffer of 2 bytes in destination*/
    u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 2);
    REQUIRE(u32_safe_cpy_len == 2);   

    /*Offset 5: This means we are reserving a buffer of 5 bytes in destination*/
    /*With safe max we have avoided the stack crash*/
    u32_safe_cpy_len = safe_cpy_len(k_u32_MAXLEN, strlen(dest), strlen(src), 5);
    REQUIRE(u32_safe_cpy_len == -1);   
    u32_safe_cpy_len = safe_max(0, u32_safe_cpy_len);
    REQUIRE(u32_safe_cpy_len == 0);
}