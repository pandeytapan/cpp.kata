#include <ctype.h>

bool is_anagram_005(const char *pFirst, const char *pSecond)
{
    #define ALPHABETS 26
 
    int nFirst[ALPHABETS] = {0};
    int nSecond[ALPHABETS] = {0};
    int nIndex = 0;

    while (pFirst[nIndex])
        ++nFirst[(pFirst[nIndex++]|32) - 'a'];

   nIndex = 0;
    while (pSecond[nIndex])
        ++nSecond[(pSecond[nIndex++]|32) - 'a'];

    nIndex = 0;
    while (nIndex < ALPHABETS)
    {
        if (nFirst[nIndex] != nSecond[nIndex])
            break;
        ++nIndex;
    }

    return nIndex == ALPHABETS;
}