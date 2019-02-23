#include <new>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
#include <string.h>
#include <ctype.h>

vector<pair<char, int>> orderedCounter_level1_010(const char * const pPhrase){
#define kALPHABET 52U
    map<char, int> freqHolder;
    
    for (char value: string(pPhrase)){
        map<char, int>::iterator itr = freqHolder.find(value);
        if(itr != freqHolder.end())
            itr->second++;
        else if(isalpha(value))
           freqHolder.insert(std::make_pair(value, 1));
    }

    vector<pair<char, int>> freq;
    int nIndex = 0;

    while (pPhrase[nIndex]){
        map<char, int>::iterator itr = freqHolder.find(pPhrase[nIndex++]);
        if(itr != freqHolder.end()){
            freq.push_back(make_pair(itr->first, itr->second));
            freqHolder.erase(itr);
        }
    }
    if(freq.empty()) freq.push_back(make_pair(NULL, 0));
    return freq;
}
