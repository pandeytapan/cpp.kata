#include <stdio.h>
#include <string.h>

int main()
{
    char * p_dest = nullptr;
    size_t u32_dest_buf_size = 0;
    ssize_t u32_dest_len = 0;
    FILE * p_file = fopen("old.mac.donald.txt", "r");

    u32_dest_len = getline(&p_dest, &u32_dest_buf_size, p_file);
    printf("u32_dest_len = %lu, pp_dest = %s, u32_dest_buf_size=%lu", u32_dest_len, p_dest, u32_dest_buf_size);

    return 0;
}
