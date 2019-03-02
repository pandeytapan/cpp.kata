#include <string.h>
#include <ctype.h>
#include <cstdio>
using namespace std;

char** mexican_wave_010(const char *pPhrase)
{
        
    int nIndex = 0;
    int nLen = strlen(pPhrase);
    
    char **pMexicanWave = new char *[nLen ? nLen - 1 :nLen + 1]{const_cast<char *>("")};

    while (pPhrase[nIndex])
    {
        pMexicanWave[nIndex] = new char[nLen]();
        strcpy(pMexicanWave[nIndex], pPhrase);
        pMexicanWave[nIndex][nIndex] = toupper(pMexicanWave[nIndex][nIndex]);
        ++nIndex;
    }

    return pMexicanWave;
}