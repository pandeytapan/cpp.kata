#include <stdio.h>
#include <string.h>

#define MAX_MSISDN_LEN 10


unsigned char getDigit(char c) {
    return c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10;
}

int dec_to_bcd_str(char * psz_in_dec, unsigned char * psz_out_bcd) {
    int len = strlen(psz_in_dec);
    int i, j;
    for (i = 0, j = 0; i < len; i += 2, j++) {
        psz_out_bcd[j] = (getDigit(psz_in_dec[i]) << 4) | getDigit(psz_in_dec[i+1]);
    }
    if (len % 2) {
        psz_out_bcd[j-1] |= 0xf0;
    }
    return (len + 1) / 2;
}

void bcd_to_dec_str(unsigned char * psz_in_bcd, char * psz_out_dec, int n_bcd_len) {
    int i, j;
    for (i = 0, j = 0; i < n_bcd_len; i++, j += 2) {
        psz_out_dec[j] = (psz_in_bcd[i] >> 4) + '0';
        psz_out_dec[j+1] = (psz_in_bcd[i] & 0x0f) + '0';
    }
    if (psz_out_dec[j-1] == '0') {
        psz_out_dec[j-1] = '\0';
    } else {
        psz_out_dec[j] = '\0';
    }
}
int main() {
    char input[] = "1234567890";
    unsigned char output[MAX_MSISDN_LEN];
    int length = dec_to_bcd_str(input, output);
    printf("Input: %s\n", input);
    printf("Output: ");
    for(int i=0; i<length; i++) {
        printf("%02X ", output[i]);
    }
    printf("\n");

    char output2[MAX_MSISDN_LEN];
    bcd_to_dec_str(output, output2, length);
    printf("Output2: %s\n", output2);
    return 0;
}
