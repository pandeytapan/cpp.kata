#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char **mexican_wave(const char *pPhrase)
{
    int nIndex = 0;
    int nLen = strlen(pPhrase);
    char **pMexicanWave = new char *[nLen - 1]();

    while (pPhrase[nIndex])
    {
        pMexicanWave[nIndex] = new char[nLen]();
        strcpy(pMexicanWave[nIndex], pPhrase);
        pMexicanWave[nIndex][nIndex] = toupper(pMexicanWave[nIndex][nIndex]);
        printf("\n%s", pMexicanWave[nIndex]);
        ++nIndex;
    }

    return pMexicanWave;
}