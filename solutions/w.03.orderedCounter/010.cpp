#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <new>
using namespace std;

int * orderedCounter(const char *pPhrase){
    int szAlphabets [52];
    int nIndex;
    for (int nX = 0 ; nX < 52; ++ nX)
        szAlphabets [nX] = 0;

    for (nIndex = 0; pPhrase[nIndex]; ++nIndex)
        szAlphabets [pPhrase[nIndex]<'a'?pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] ++;

   int *szFreq = new int[6];
    for (int nX = 0 ; nX < 6; ++ nX)
        szFreq [nX] = szAlphabets[pPhrase[nX]<'a'? pPhrase[nX] - 'A': pPhrase[nX] - 'a' + 26];

 
    return szFreq;
}

int main()
{
    int x = 0;
    int * pPhrase = orderedCounter("Tapan");

    for (x = 0; x < 5; x++){
        cout << x << ". " << pPhrase [x] << endl;
    } 
}

