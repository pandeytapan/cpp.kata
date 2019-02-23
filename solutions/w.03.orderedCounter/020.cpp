#include <new>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#include <string.h>
#include <ctype.h>

class VALUETYPE 
{
    private:
        int m_nFreq;
        char m_cLetter;

    public:
        VALUETYPE (int nFreq, char cLetter):m_nFreq(nFreq), m_cLetter(cLetter){}
        int frequency()const{return m_nFreq;}
        char letter()const{return m_cLetter;}
        void incrementFrequency(){m_nFreq += 1;}
        void setLetter(char cLetter){m_cLetter += cLetter;}
        bool operator == (char const &cLetter){ return m_cLetter == cLetter;}

};

vector<int> orderedCounter_020(const char * const pPhrase){
#define kALPHABET 52U
    vector<VALUETYPE> freqHolder;
    
    for (char value: string(pPhrase)){

        vector<VALUETYPE>::iterator itr = std::find(freqHolder.begin(), freqHolder.end(),value);
        if(itr != freqHolder.end())
            itr->incrementFrequency();
        else
           freqHolder.push_back(VALUETYPE(1, value));
    }

    vector<int> freq;
    for (auto value: freqHolder)
        freq.push_back(value.frequency());
    
    if(freq.empty()) freq.push_back(0);
    return freq;
}
