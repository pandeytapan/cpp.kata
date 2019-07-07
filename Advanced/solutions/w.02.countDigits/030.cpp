#include <assert.h>
#include <algorithm>
#include <vector>

int countDigit_030(int nNum, int nDigit)
{
    assert(nNum >= 0);
    assert(0<=nDigit<=9);
    std::vector <int> digits;
    auto matcher = [nDigit](int x)  { return x == nDigit;};
    while(nNum > -1)
    {
        int nSqr = nNum * nNum;
        do
        {
            digits.push_back(nSqr%10);
            nSqr /=10;
        }
        while(nSqr);
        --nNum;
    }
    return std::count_if(digits.begin(), digits.end(), matcher);
}