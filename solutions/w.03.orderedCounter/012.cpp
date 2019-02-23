#include <string.h>
#include <ctype.h>
#include <new>
using namespace std;

int * orderedCounter_012(const char * const pPhrase){
#define kALPHABET 52U
    int szAlphabets [kALPHABET] = {0};
    int nIndex;
    int nFrequency;

    for (nIndex = 0; pPhrase[nIndex]; ++nIndex)
        if (isupper(pPhrase[nIndex]))
            szAlphabets [pPhrase[nIndex] - 'A'] ++;
        else if (islower(pPhrase[nIndex]))
            szAlphabets [pPhrase[nIndex] - 'a' + 26] ++;

    nFrequency = 0;    
    for (nIndex = 0 ; nIndex < 52; ++nIndex)
        if(szAlphabets [nIndex])
            ++nFrequency;
   
    int *szFreq = new int[nFrequency + 1]();
    nIndex = 0;
    for (nFrequency = nIndex = 0 ; nIndex < strlen(pPhrase); ++nIndex)
        if (isalpha(pPhrase[nIndex]))
            if (szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26]){
                szFreq [nFrequency++] = szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26];
                szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] = 0;
            }
 
    return szFreq;
}