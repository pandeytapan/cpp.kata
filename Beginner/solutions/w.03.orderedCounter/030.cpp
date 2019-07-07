#include <new>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
#include <string.h>
#include <ctype.h>

vector<int> orderedCounter_030(const char * const pPhrase){
    map<char, int> freqHolder;
    
    for (char value: string(pPhrase)){
        map<char, int>::iterator itr = freqHolder.find(value);
        if(itr != freqHolder.end())
            itr->second++;
        else if(isalpha(value))
           freqHolder.insert(std::make_pair(value, 1));
    }

    vector<int> freq;
    int nIndex = 0;

    while (pPhrase[nIndex]){
        map<char, int>::iterator itr = freqHolder.find(pPhrase[nIndex++]);
        if(itr != freqHolder.end()){
            freq.push_back(itr->second);
            freqHolder.erase(itr);
        }
    }

    if(freq.empty()) freq.push_back(0);
    return freq;
}
