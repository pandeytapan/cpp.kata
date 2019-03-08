#include <algorithm>
using namespace std;
#include <string.h>
#include <ctype.h>

void sort(char *pSequence)
{
    std::transform(pSequence, pSequence + strlen(pSequence), pSequence, ::tolower);
    int nLen = strlen(pSequence);

    for (int i = 0; i < nLen - 1; ++i)
        for (int j = i + 1; j < nLen; ++j)
            if (pSequence[i] > pSequence[j])
                swap(pSequence[i], pSequence[j]);
}

bool is_anagram_020(const char *pFirst, const char *pSecond)
{
    char *pSortedFirst = new char[strlen(pFirst)]();
    char *pSortedSecond = new char[strlen(pSecond)]();

    strcpy(pSortedFirst, pFirst);
    strcpy(pSortedSecond, pSecond);

    sort(pSortedFirst);
    sort(pSortedSecond);

    int nIndex = 0;
    while (pSortedFirst[nIndex] && pSortedFirst[nIndex] == pSortedSecond[nIndex])
        ++nIndex;

    bool bIsMatch = pSortedFirst[nIndex] == pSortedSecond[nIndex];
    delete[] pSortedFirst;
    delete[] pSortedSecond;

    return bIsMatch;
}
