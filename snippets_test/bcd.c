#include <stdio.h>

/**
 * decimal_to_bcd - Convert a decimal number to binary coded decimal (BCD) representation
 * @decimal: Decimal number to convert
 *
 * Return: BCD representation of the decimal number
 */
unsigned char decimal_to_bcd(unsigned char decimal) {
    return ((decimal / 10) << 4) | (decimal % 10);
}

/**
 * decimals_to_bcds - Convert an array of decimal numbers to an array of BCD representations
 * @decimals: Array of decimal numbers to convert
 * @bcds: Array to store BCD representations
 */
void decimals_to_bcds(unsigned char *decimals, unsigned char *bcds) {
    int i = 0;
    while (*decimals) {
        *bcds++ = decimal_to_bcd(*decimals++);
        i++;
    }
}

int main(void) {
    unsigned char decimals[] = {12, 34, 56, 78, 90};
    int size = sizeof(decimals) / sizeof(decimals[0]);
    unsigned char bcds[size];
    decimals_to_bcds(decimals, bcds);
    printf("BCD representation of decimals:");
    int i;
    for (i = 0; i < size; i++) {
        printf(" %02X", bcds[i]);
    }
    printf("\n");
    return 0;
}
