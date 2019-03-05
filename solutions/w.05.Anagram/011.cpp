bool is_anagram_011(const char *pFirst, const char *pSecond){
    int nFirstIndex = 0;

    while( pFirst[nFirstIndex])
    {
        int nSecondIndex = 0;
        while(pSecond[nSecondIndex])
        {
            if((pFirst[nFirstIndex]|32) == (pSecond[nSecondIndex]|32))
                break;  
            ++nSecondIndex;
        }
        if(!pSecond[nSecondIndex])
            break;
        ++nFirstIndex;
    }
    return pFirst[nFirstIndex] == pSecond[nFirstIndex];
}