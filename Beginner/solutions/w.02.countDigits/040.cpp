#include <assert.h>
#include <algorithm>
#include <vector>
#include <string>

int counter(std::string szDigits, char cDigit)
{
    return std::count(szDigits.begin(), szDigits.end(), cDigit);
}

int countDigit_040(int nNum, int nDigit)
{
    assert(nNum >= 0);
    assert(0<=nDigit<=9);
    
    int nDigitCount = 0;
    std::vector <std::string> digits;
    char szbuf[10] = {};

    while(nNum > -1)
    {
        itoa(nNum * nNum, szbuf, 10);
        digits.push_back(szbuf);
        --nNum;
    }
    for (auto &str:digits)
       nDigitCount += counter(str, (char) nDigit + 48);     
    
    return nDigitCount;
}