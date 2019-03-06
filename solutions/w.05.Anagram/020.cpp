#include <ctype.h>

void sort(const char *pSequence)
{
    // for (int i = 0; pSequence[i]; ++i)
    // {
    //     for (int j = i + 1; pSequence[j]; ++j)
    //     {
    //         if ( pSequence [i] > pSequence [j] )
    //         {
    //             char ch = pSequence [i];
    //             pSequence [i] = pSequence [j];
    //             pSequence[j] = ch;
    //         }
    //     }
    // }
}

bool is_anagram_020(const char *pFirst, const char *pSecond)
{
    int nIndex = 0;
    char * pSortedFirst = new char [strlen(pFirst)];
    char * pSortedSecond = new char [strlen(pSecond)];

    strcpy(pSortedFirst, pFirst);
    strcpy(pSortedSecond, pSecond);
    
    sort(pSortedFirst);
    sort(pSortedSecond);

    while( pSortedFirst[nIndex] == pSortedSecond[nIndex])
        ++nIndex;

   return pSortedFirst[nIndex] ==  pSortedSecond[nIndex];
}