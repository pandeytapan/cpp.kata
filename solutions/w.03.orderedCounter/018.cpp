#include <new>
#include <vector>
using namespace std;
#include <string.h>
#include <ctype.h>

vector<int> orderedCounter_018(const char * const pPhrase){
#define kALPHABET 52U
    int szAlphabets [kALPHABET] = {0};
    int nIndex;

    for (auto value: string(pPhrase))
        if (isupper(value)) szAlphabets[value - 'A'] ++;
        else if (islower(value)) szAlphabets [value - 'a' + 26] ++;
  
    vector<int> freq;
    nIndex = 0;
    for (nIndex = 0 ; nIndex < strlen(pPhrase); ++nIndex)
        if (isalpha(pPhrase[nIndex]))
            if (szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26])
            {
                freq.push_back(szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26]);
                szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] = 0;
            }
    
    if(freq.empty()) freq.push_back(0);
    return freq;
}
