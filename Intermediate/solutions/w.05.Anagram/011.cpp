#include <ctype.h>

bool is_anagram_011(const char *pFirst, const char *pSecond)
{
    int nFirstIndex = 0;

    while( pFirst[nFirstIndex])
    {
        int nSecondIndex = 0;
        while(pSecond[nSecondIndex])
        {
            if(tolower(pFirst[nFirstIndex]) == tolower(pSecond[nSecondIndex]))
                break;  
            ++nSecondIndex;
        }
        if(!pSecond[nSecondIndex])
            break;
        ++nFirstIndex;
    }
    return pFirst[nFirstIndex] == pSecond[nFirstIndex];
}