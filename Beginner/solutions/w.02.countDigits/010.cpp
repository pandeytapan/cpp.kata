#include <assert.h>

int countDigit_010(int nNum, int nDigit)
{
    assert(nNum >= 0);
    assert(0<=nDigit<=9);
    int nDigitCount = 0;
    
    while (nNum > -1)
    {
        int nSqr = nNum * nNum;
        do
        {
            if (nSqr % 10 == nDigit)
                ++nDigitCount;
            nSqr /=10;
        }
        while(nSqr);
        --nNum;
    }
    return nDigitCount;
}