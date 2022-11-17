#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "./mem_macros.h"
#define MAXLEN 10
int main()
{
    char dest[MAXLEN] = {0};
    const char *src = "Bye";
    strcpy(dest, "Hello");

    uint16_t u16_src_len = strlen(src);
    uint16_t u16_dest_len = strlen(dest);
    
    int u32_safe_cpy_len = safe_cpy_len(MAXLEN, u16_dest_len, u16_src_len, 0);

    printf("\nDestination max length: %d", MAXLEN - 1);
    printf("\nDestination current length: %d", u16_dest_len);
    printf("\nSource length: %d", u16_src_len);
    printf("\nSafe copy length: %d", u32_safe_cpy_len);
    printf("\nSrc: %s", src);
    printf("\nDest: %s", dest);
    strncat(dest, src, u32_safe_cpy_len);
    printf("\nFinal: %s\n\n", dest);

    memset(dest, 0, MAXLEN);
    return 0;

}