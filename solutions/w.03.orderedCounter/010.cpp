#include <string.h>
#include <new>
using namespace std;


int * orderedCounter_010(const char * const pPhrase){
#define kALPHABET 52U
    int szAlphabets [kALPHABET] = {0};
    int nIndex;
    int nFrequency;

    for (nIndex = 0; pPhrase[nIndex]; ++nIndex)
        if (pPhrase[nIndex]>='A' && pPhrase[nIndex]<='Z')
            szAlphabets [pPhrase[nIndex] - 'A'] ++;
        else if (pPhrase[nIndex]>='a' && pPhrase[nIndex]<='z')
            szAlphabets [pPhrase[nIndex] - 'a' + 26] ++;

    nFrequency = 0;    
    for (nIndex = 0 ; nIndex < 52; ++nIndex)
        if(szAlphabets [nIndex])
            ++nFrequency;
   
    int *szFreq = new int[nFrequency + 1]();
    nIndex = 0;
    for (nFrequency = nIndex = 0 ; nIndex < strlen(pPhrase); ++nIndex)
        if ((pPhrase[nIndex]>='A' && pPhrase[nIndex]<='Z') || (pPhrase[nIndex]>='a' && pPhrase[nIndex]<='z'))
            if (szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26])
            {
                szFreq [nFrequency++] = szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26];
                szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] = 0;
            }
    return szFreq;
}
