#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./snippets_test/mem_macros.h"
#include <string.h>

TEST_CASE("Test with length", "[get_line_test]")
{
    char * p_dest = nullptr;
    size_t u32_dest_buf_size = 0;
    ssize_t u32_dest_len = 0;

    FILE * p_file = fopen("old.mac.donald.txt", "r");
    REQUIRE(p_file != nullptr);

    u32_dest_len =  getline(&p_dest, &u32_dest_buf_size, p_file);
    REQUIRE(u32_dest_len == 25);
    REQUIRE(p_dest[u32_dest_len] == '\0');

}
