![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week #3 `Ordered Counter` Solution

Hello &#x1F44B;

If you have still not attempted, I advise you to write at least a few solutions before moving forward with this solution document. For others here are the solutions &#x1F381; for you.

# Ground Solutions
To start with, if you are coming from plain C/ C++ &#x1F310; then most possibly you may have written your **First** solution like this &#x1F680;

# Solution 1 

```C++
01: #include <string.h>
02: #include <new>
03: using namespace std;
04: 
05: 
06: int * orderedCounter(const char * const pPhrase){
07: #define kALPHABET 52U
08:     int szAlphabets [kALPHABET] = {0};
09:     int nIndex;
10:     int nFrequency;
11: 
12:     for (nIndex = 0; pPhrase[nIndex]; ++nIndex)
13:         if (pPhrase[nIndex]>='A' && pPhrase[nIndex]<='Z')
14:             szAlphabets [pPhrase[nIndex] - 'A'] ++;
15:         else if (pPhrase[nIndex]>='a' && pPhrase[nIndex]<='z')
16:             szAlphabets [pPhrase[nIndex] - 'a' + 26] ++;
17: 
18:     nFrequency = 0;    
19:     for (nIndex = 0 ; nIndex < kALPHABET; ++nIndex)
20:         if(szAlphabets [nIndex])
21:             ++nFrequency;
22:    
23:     int *szFreq = new int[nFrequency + 1]();
24:     nIndex = 0;
25:     for (nFrequency = nIndex = 0 ; nIndex < strlen(pPhrase); ++nIndex)
26:         if ((pPhrase[nIndex]>='A' && pPhrase[nIndex]<='Z') || (pPhrase[nIndex]>='a' && pPhrase[nIndex]<='z'))
27:             if (szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26])
28:             {
29:                 szFreq [nFrequency++] = szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26];
30:                 szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] = 0;
31:             }
32:     return szFreq;
33: }

```
## Solution 1: Commentry

We have designed our function `orderedCounter` to take one argument which is a **[pointer](https://www.programiz.com/cpp-programming/pointers)** to characters. Since nor pointer or values will change both are kept as **[constant](https://docs.microsoft.com/en-us/cpp/cpp/const-cpp?view=vs-2017)**. Our function returns a pointer to an integer, which is a standard way to return arrays in C / C++. Recall we cannot return the size of array this way. 

To start with, our algorithm first iterates the argument and stores the count of an individual alphabet (both capital and small) in an array. _See line number 08 to 16_. 

Next, we added the total times all alphabets are coming in the argument. _See line number 18 to 21_. For this, we only have enumerated the array that we have prepared earlier i.e. `szAlphabets`.  

Further, we allocated an array using [new](https://docs.microsoft.com/en-us/cpp/cpp/new-operator-cpp?view=vs-2017) operator having size exactly equal to summation last calculated + 1 byte. _See line 23_.We didn't used and static array because we need to create a data structure that stores count exactly in the same order as the alphabets are coming in the phrase. We have to note here also that 0 < summation < length of the phrase. So, if you are tempted to create an array equal to the length of phrase statically, it will not only introduce bugs but memory also, in cases when alphabets are repeating mostly. e.g. "recess".

At last, we have copied the frequency of individual alphabet from `szAlphabets` into `szFreq` making use of `pPhrase` as the lookup key in `szAlphabets`.

---
If you see the last example we have written certain comparison codes that are not only difficult to read but can also be a welcome point for bugs if opt written carefully. Whenever possible we should replace such statements with better alternatives. Out next solution shows us how to do it.  Here we go &#x1F680;     
  
# Solution 2 

```C++
01: #include <string.h>
02: #include <ctype.h>
03: #include <new>
04: using namespace std;
05: 
06: int * orderedCounter(const char * const pPhrase){
07: #define kALPHABET 52U
08:     int szAlphabets [kALPHABET] = {0};
09:     int nIndex;
10:     int nFrequency;
11: 
12:     for (nIndex = 0; pPhrase[nIndex]; ++nIndex)
13:         if (isupper(pPhrase[nIndex]))
14:             szAlphabets [pPhrase[nIndex] - 'A'] ++;
15:         else if (islower(pPhrase[nIndex]))
16:             szAlphabets [pPhrase[nIndex] - 'a' + 26] ++;
17: 
18:     nFrequency = 0;    
19:     for (nIndex = 0 ; nIndex < 52; ++nIndex)
20:         if(szAlphabets [nIndex])
21:             ++nFrequency;
22:    
23:     int *szFreq = new int[nFrequency + 1]();
24:     nIndex = 0;
25:     for (nFrequency = nIndex = 0 ; nIndex < strlen(pPhrase); ++nIndex)
26:         if (isalpha(pPhrase[nIndex]))
27:             if (szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26]){
28:                 szFreq [nFrequency++] = szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26];
29:                 szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] = 0;
30:             }
31:  
32:     return szFreq;
33: }

```

## Solution 2: Commentry

In this version of our solutions, we have replaced certain character comparison statements with library functions. C/ C++ library had a rich set of **[character](https://www.programiz.com/c-programming/library-function/ctype.h)** manipulation function that every developer should pay attention to when working with characters.

We have used **[isupper](https://www.programiz.com/c-programming/library-function/ctype.h/isupper)** and **[islower](https://www.programiz.com/c-programming/library-function/ctype.h/islower)** to verify if character is uppercase alphabet or lowercase. _See line 13 and 15_. Further, we have used **[isalpha](https://www.programiz.com/c-programming/library-function/ctype.h/isalpha)** to verify if the character is an alphabet or not. As evident from code itself not only it is more readable but now there is less room for bugs. 

---  

If you have paid attention to the code then our last two solutions have a major bug enjoying the time there. It is the **memory leakage** :japanese_goblin: that is happening in form of our returned array of alphabet frequency. _See line 32 in the last two solutions__. 

Memory management has always been a headache :worried: for many C/ C++ developers in past. They say it is a place where even angels :angel: fear to tread. Well, the good news is that Modern C++ :muscle: has introduced many new technologies to handle this in form of smart pointers. Let's see how here we go &#x1F680; 

# Solution 3 

```C++
01: #include <new>
02: #include <memory>
03: using namespace std;
04: #include <string.h>
05: #include <ctype.h>
06: 
07: unique_ptr<int[]> orderedCounter(const char * const pPhrase){
08: #define kALPHABET 52U
09:     int szAlphabets [kALPHABET] = {0};
10:     int nIndex;
11:     int nFrequency;
12: 
13:     for (nIndex = 0; pPhrase[nIndex]; ++nIndex)
14:         if (isupper(pPhrase[nIndex]))
15:             szAlphabets [pPhrase[nIndex] - 'A'] ++;
16:         else if (islower(pPhrase[nIndex]))
17:             szAlphabets [pPhrase[nIndex] - 'a' + 26] ++;
18: 
19:     nFrequency = 0;    
20:     for (auto a : szAlphabets)
21:         if(a) ++nFrequency;
22:    
23:     unique_ptr<int[]> freq (new int[nFrequency + 1]());
24:     nIndex = 0;
25:     for (nFrequency = nIndex = 0 ; nIndex < strlen(pPhrase); ++nIndex)
26:         if (isalpha(pPhrase[nIndex]))
27:             if (szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26]){
28:                 freq [nFrequency++] = szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26];
29:                 szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] = 0;
30:             }
31: 
32:     return freq;
33: }
```

## Solution 3: Commentry

What we have done here is that instead of just allocating raw bytes and using it we have now passed the allocated memory to **[unique_ptr](https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=vs-2017)**. It is one of the new smart pointer class for automatic handling of allocated memory. Bingo! the memory will we reclaimed once goes out of scope. The only difference from the last examples is the usage of the smart pointer instead of a raw pointer. _See line 23_. 

---

C++ STL library is a rich resource to many constructs and containers that we can make use of to further reduce the space for bugs :bug: to grow and at the same time make our code more readable. Let's see how we do it. Here we go &#x1F680; 

# Solution 4 

```C++
01: #include <new>
02: #include <vector>
03: using namespace std;
04: #include <string.h>
05: #include <ctype.h>
06: 
07: vector<int> orderedCounter(const char * const pPhrase){
08: #define kALPHABET 52U
09:     int szAlphabets [kALPHABET] = {0};
10:     int nIndex;
11: 
12:     for (auto value: string(pPhrase))
13:         if (isupper(value)) szAlphabets[value - 'A'] ++;
14:         else if (islower(value)) szAlphabets [value - 'a' + 26] ++;
15:   
16:     vector<int> freq;
17:     nIndex = 0;
18:     for (nIndex = 0 ; nIndex < strlen(pPhrase); ++nIndex)
19:         if (isalpha(pPhrase[nIndex]))
20:             if (szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26]){
21:                 freq.push_back(szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26]);
22:                 szAlphabets[pPhrase[nIndex]<'a'? pPhrase[nIndex] - 'A': pPhrase[nIndex] - 'a' + 26] = 0;
23:             }
24:     
25:     if(freq.empty()) freq.push_back(0);
26:     return freq;
```

## Solution 4: Commentry

C++ STL's **[vector](https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=vs-2017)** class is a sequential container that can grow as we add new elements. Thus we can use it, instead of static arrays or dynamically allocated arrays (as we have done in our last solutions), in places where do not make a prior estimate of elements in the sequential container. As you can see we are not making use of total frequency counting and memory allocation as we have done in the last examples. 

The **[push_back](https://docs.microsoft.com/en-us/previous-versions/8wt934f9(v=vs.140))** method of **[vector](https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=vs-2017)** class will make vector to grow as new elements will come. :smiley:

If you are paying attention to our solutions from the last few weeks we are making use of **[colletions loop](https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html)**. We have again used it in Solution 3 and 4.     

---

Till now in solutions, we have used an array `szAlphabets` to store the frequency of individual alphabets. When we know that many of locations in this array will remain 0 since not all alphabets from a to z are going to be part of the argument. In our next example, we have come up with a plan to get rid of this array entirely. Let see how. Here we go &#x1F680; 

# Solution 5 

```C++
01: #include <new>
02: #include <vector>
03: #include <algorithm>
04: #include <string>
05: using namespace std;
06: 
07: #include <string.h>
08: #include <ctype.h>
09: 
10: class VALUETYPE {
11:     private:
12:         int m_nFreq;
13:         char m_cLetter;
14: 
15:     public:
16:         VALUETYPE (int nFreq, char cLetter):m_nFreq(nFreq), m_cLetter(cLetter){}
17:         int frequency()const{return m_nFreq;}
18:         char letter()const{return m_cLetter;}
19:         void incrementFrequency(){m_nFreq += 1;}
20:         void setLetter(char cLetter){m_cLetter += cLetter;}
21:         bool operator == (char const &cLetter){ return m_cLetter == cLetter;}
22: 
23: };
24: 
25: vector<int> orderedCounter(const char * const pPhrase){
26: 
27:     vector<VALUETYPE> freqHolder;
28:     
29:     for (char value: string(pPhrase)){
30: 
31:         vector<VALUETYPE>::iterator itr = std::find(freqHolder.begin(), freqHolder.end(),value);
32:         if(itr != freqHolder.end())
33:             itr->incrementFrequency();
34:         else if(isalpha(value))
35:            freqHolder.push_back(VALUETYPE(1, value));
36:     }
37: 
38:     vector<int> freq;
39:     for (auto value: freqHolder)
40:         freq.push_back(value.frequency());
41:     
42:     if(freq.empty()) freq.push_back(0);
43:     return freq;
44: }
```

## Solution 5: Commentry

We have written a class `VALUETYPE` that will store each character occurring in argument `pPhrase` as well as its frequency. _see line 10 to 23_. We are also using a vector now _see line 27_ to store the occurrence of each alphabet in the passed argument. Now instead of having an array of 52 integers (as we doing in last solutions), we are storing an exact number of character as per frequency. This has made our code more robust and resilient to bugs :bug: Now we are also using **[find](https://docs.microsoft.com/en-us/cpp/standard-library/algorithm-functions?view=vs-2017#find)** algorithm to lookup an alphabet in vector and change its occurrence. This code is much cleaner, better, faster and easier to read.  See how we have **[overloaded = operator](https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=vs-2017)**:sunglasses: that is going to help us in implementing **[find](https://docs.microsoft.com/en-us/cpp/standard-library/algorithm-functions?view=vs-2017#find)** operation.

---   

**[STL](https://docs.microsoft.com/en-us/previous-versions/c191tb28(v=vs.140))** is a great boon to build structures of our concepts. It is like a **[Lego Brick](https://shop.lego.com/en-US/Bricks-Home)** that you can use to create forms and shapes as you wish. Let see how. Here we go &#x1F680; 

# Solution 6 

```C++
01: #include <new>
02: #include <vector>
03: #include <map>
04: #include <algorithm>
05: #include <string>
06: using namespace std;
07: #include <string.h>
08: #include <ctype.h>
09: 
10: vector<int> orderedCounter(const char * const pPhrase){
11:     map<char, int> freqHolder;
12:     
13:     for (char value: string(pPhrase)){
14:         map<char, int>::iterator itr = freqHolder.find(value);
15:         if(itr != freqHolder.end())
16:             itr->second++;
17:         else if(isalpha(value))
18:            freqHolder.insert(std::make_pair(value, 1));
19:     }
20: 
21:     vector<int> freq;
22:     int nIndex = 0;
23: 
24:     while (pPhrase[nIndex]){
25:         map<char, int>::iterator itr = freqHolder.find(pPhrase[nIndex++]);
26:         if(itr != freqHolder.end()){
27:             freq.push_back(itr->second);
28:             freqHolder.erase(itr);
29:         }
30:     }
31: 
32:     if(freq.empty()) freq.push_back(0);
33:     return freq;
34: }
35: 
```

## Solution 6: Commentry

In this last of ground solution we have replaced the `VALUETYPE` with **[STL](https://docs.microsoft.com/en-us/previous-versions/c191tb28(v=vs.140))**'s very own **[map](https://docs.microsoft.com/en-us/cpp/standard-library/map-class?view=vs-2017)**. If you have read about it by now, then **[map](https://docs.microsoft.com/en-us/cpp/standard-library/map-class?view=vs-2017)** is a container that works on the logic of key-value pair.

For our example, we have taken alphabet as key and frequency as value. Since every element in the map is a pair, we have taken help of **[make_pair](https://msdn.microsoft.com/ja-jp/library/cc406591(v=vs.71).aspx)** to store the values inside the map.

Using map has helped us to get rid of `VALUETYPE` class, had written incorrectly, it would have introduced bugs :bug: to our code. Also, our code is much easier to maintain and has become a pleasureful read.

Let's now move on to Level Up.

# Level 1 Solutions

Our last ground solution has already given up a huge jump to reach level 1. Although quite self-explanatory let's discuss it also. Here we go &#x1F680;


## Solution 1 

```C++
01: #include <new>
02: #include <vector>
03: #include <map>
04: #include <algorithm>
05: #include <string>
06: using namespace std;
07: #include <string.h>
08: #include <ctype.h>
09: 
10: vector<pair<char, int>> orderedCounter_level1_010(const char * const pPhrase){
11: #define kALPHABET 52U
12:     map<char, int> freqHolder;
13:     
14:     for (char value: string(pPhrase)){
15:         map<char, int>::iterator itr = freqHolder.find(value);
16:         if(itr != freqHolder.end())
17:             itr->second++;
18:         else if(isalpha(value))
19:            freqHolder.insert(std::make_pair(value, 1));
20:     }
21: 
22:     vector<pair<char, int>> freq;
23:     int nIndex = 0;
24: 
25:     while (pPhrase[nIndex]){
26:         map<char, int>::iterator itr = freqHolder.find(pPhrase[nIndex++]);
27:         if(itr != freqHolder.end()){
28:             freq.push_back(make_pair(itr->first, itr->second));
29:             freqHolder.erase(itr);
30:         }
31:     }
32:     if(freq.empty()) freq.push_back(make_pair(NULL, 0));
33:     return freq;
34: }
```
 

## Solution 1: Commentry

In this solution, we have to return not only the frequency but also the alphabet in order of occurrence. That means we need a sequential container with heterogeneous values in a pair. The solution is quite easy to write as we have used our beloved vector to store the frequency. The catch is that instead of storing only frequency we have stored both alphabet and frequency as a pair. Again we went shopping at STL and came with **[std::pair](https://docs.microsoft.com/en-us/cpp/standard-library/pair-structure?view=vs-2017)** to do the job. Rest of code is the same except for return type that I guess you would have understood by now.

----
# Other Comments

To test all the ground up and level solutions I have created two helper functions (actually an overloaded one :grin:). They basically compare the values till matching lasts and return the count of letters remaining. For a successful match, it should come zero. 

```C++
bool assertIterableEqual (int *pIterable1, int *pIterable2, int nCount){

    while (*pIterable1++ == *pIterable2++)
        --nCount;
    return !nCount;
}

bool assertIterableEqual (std::pair<char,int> *pIterable1, std::pair<char,int> *pIterable2, int nCount){
    while(pIterable1->first == pIterable2->first && pIterable1->second == pIterable2->second){
        ++pIterable1;
        ++pIterable2;
        --nCount;
    }
    
    return !nCount;
}
```   

The test script for the solution can be **[found here](https://1drv.ms/u/s!An6FDnpXbnZ80kdag1dqL5jAZLNS)**

Hope you have liked this problem and its solutions. See you next Monday. Till then 

Happy programming (Days):wink: