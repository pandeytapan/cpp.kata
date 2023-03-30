#include <stdio.h>
#include <stdlib.h>

#include <stddef.h>

#include <stddef.h>

void packto7bit(const unsigned char *p_u8_inbuf, unsigned char *p_u8_outbuf, size_t n_sms_len, size_t *pn_len)
{
    size_t count = 0, i = 0;
    unsigned char c;
    *pn_len = 0;

    for (; i < n_sms_len; i++)
    {
        c = p_u8_inbuf[i] & 0x7F;

        if (count == 7)
        {
            p_u8_outbuf[*pn_len] |= c;
            count = 0;
            (*pn_len)++;
        }
        else
        {
            p_u8_outbuf[*pn_len] |= c << (7 - count);
            p_u8_outbuf[*pn_len + 1] = c >> (count + 1);
            count++;
            if (count == 7) (*pn_len)++;
        }
    }
    if (count > 0) (*pn_len)++;
}




#include <stddef.h>

void unpackto8bit(const unsigned char *p_u7_inbuf, unsigned char *p_u8_outbuf, size_t n_packed_len, size_t *pn_len)
{
    size_t count = 0;
    *pn_len = 0;

    for (size_t i = 0; i < n_packed_len; i++)
    {
        unsigned char c = p_u7_inbuf[i];

        p_u8_outbuf[*pn_len] |= (c >> (7 - count)) & (0x7F >> count);
        (*pn_len)++;

        if (count < 6)
        {
            p_u8_outbuf[*pn_len] = (c << (count + 1)) & 0x7F;
        }
        else
        {
            count = 0;
            continue;
        }

        count = (count + 1) % 7;
    }

    if (count > 0) (*pn_len)++;
}


#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

// Include packto7bit and unpackto8bit functions here

int main()
{
    // Original 8-bit message
    const char *orig_msg = "Hello, world!";
    size_t orig_len = strlen(orig_msg);

    // Pack the 8-bit message to 7-bit
    unsigned char packed[256] = {0};
    size_t packed_len;
    packto7bit((const unsigned char *)orig_msg, packed, orig_len, &packed_len);

    printf("Packed message: ");
    for (size_t i = 0; i < packed_len; i++)
    {
        printf("%02X ", packed[i]);
    }
    printf("\n");

    // Unpack the 7-bit message back to 8-bit
    unsigned char unpacked[256] = {0};
    size_t unpacked_len;
    unpackto8bit(packed, unpacked, packed_len, &unpacked_len);

    printf("Unpacked message: %s\n", unpacked);

    return 0;
}


