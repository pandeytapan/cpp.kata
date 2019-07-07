#include <assert.h>

int splitCount(int nNum, int nDigit){
    if(nNum)
        return (nNum % 10 == nDigit) + splitCount(nNum / 10, nDigit);
    return (nNum == nDigit);
}

int countDigit_020(int nNum, int nDigit)
{
    assert(nNum >= 0);
    assert(0<=nDigit<=9);
    int nDigitCount = 0;
    while (nNum > -1)
    {
        nDigitCount += splitCount(nNum*nNum, nDigit);
        --nNum;
    }
    return nDigitCount;
}