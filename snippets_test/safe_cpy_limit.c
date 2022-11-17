#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define safe_cpy_len(_in_dest_max, _in_dest_cur, _in_src, _in_offset) \
    ( (_in_dest_max) - (_in_dest_cur) > (_in_src) ? \
       _in_src : (_in_dest_max) - (_in_dest_cur) - _in_offset )

int main()
{
    const int MAXLEN = 8;
    char dest[MAXLEN] = {0};
    const char *src = "howdy";
    strcpy(dest, "hellow");

    uint16_t u16_src_len = strlen(src);
    uint16_t u16_dest_len = strlen(dest);
    
    strncat(dest, src, safe_cpy_len(MAXLEN, u16_dest_len, u16_src_len, 2));
    printf("\nDestination: %s\n\n", dest);
    return 0;

}