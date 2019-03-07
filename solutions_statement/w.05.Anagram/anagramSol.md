![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week #5 `Anagram` Solution

Hello &#x1F44B;

If you have still not attempted, I advise you to write at least a few solutions before moving forward with this solution document. For others here are the solutions &#x1F381; for you.

# Ground Solutions

Let us start with legacy C/ C++ solutions. These are straight forward and easy to implement if you have always followed language only construct and not any library. So these solutions go like this &#x1F680;

# Solution 1

```C++
01: bool is_anagram(const char *pFirst, const char *pSecond)
02: {
03:     #define ALPHABETS 26
04:  
05:     int nFirst[ALPHABETS] = {0};
06:     int nSecond[ALPHABETS] = {0};
07:     int nIndex = 0;
08:
09:     while (pFirst[nIndex])
10:         ++nFirst[(pFirst[nIndex++]|32) - 'a'];
11:
12:     nIndex = 0;
13:     while (pSecond[nIndex])
14:         ++nSecond[(pSecond[nIndex++]|32) - 'a'];
15:
16:     nIndex = 0;
17:     while (nIndex < ALPHABETS)
18:     {
19:         if (nFirst[nIndex] != nSecond[nIndex])
20:             break;
21:         ++nIndex;
22:     }
23:     return nIndex == ALPHABETS;
24: }

```

## Solution 1: Commentry

This is one of the weakest approach to discover anagram among strings. Here, we have designed our function `is_anagram` to take two strings arguments that we need to test. Strings have a usual way of passing which is as a **[pointer](https://www.programiz.com/cpp-programming/pointers)** to characters. Since pointer will not change, we have kept it as **[constant](https://docs.microsoft.com/en-us/cpp/cpp/const-cpp?view=vs-2017)**. Our function returns **[boolean](https://docs.microsoft.com/en-us/cpp/cpp/bool-cpp?view=vs-2017)** value indicating if strings are anagram or not.

To start with, our algorithm first iterates the arguments and stores the count of an individual alphabet (converting alphabets to small temporarily) into two arrays i.e. `int nFirst[ALPHABETS]` and `int nSecond[ALPHABETS]`. _See line number 05 to 14_. Just try to think why both these arrays have size `ALPHABETS`.

Next, our algorithm iterates both the arrays `nFirst[ALPHABETS]` and `nSecond[ALPHABETS]` from 0 to 26 until we meet first non matching locations. _See line number 16 to 22_. If both the passed arguments i.e. `const char *pFirst` and `const char *pSecond` are anagram then `nIndex` will cover all the locations.

Our return value is a boolean expression that validates if `nIndex` iterated successfully or not.
The integer arrays that we have defined in last solution _See line number 05 and 06_ are not required we can do without it. Lets see in our next solution.

---
If you see in the last example we have written solution that is quite plain, difficult to read and understand. Our next solution tries to do things in other ways. Here we go &#x1F680;

# Solution 2

```C++
01: #include <string.h>
02:
03: bool is_anagram(const char *pFirst, const char *pSecond){
04:     int nFirstIndex = 0;
05:
06:     if (strlen(pFirst) != strlen(pSecond))
07:         return false;
08:
09:     while( pFirst[nFirstIndex])
10:     {
11:         int nSecondIndex = 0;
12:         while(pSecond[nSecondIndex])
13:         {
14:             if((pFirst[nFirstIndex]|32) == (pSecond[nSecondIndex]|32))
15:                 break;  
16:             ++nSecondIndex;
17:         }
18:         if(!pSecond[nSecondIndex])
19:             break;
20:         ++nFirstIndex;
21:     }
22:     return !pFirst[nFirstIndex];
23: }

```

## Solution 2: Commentry

In this version of our solution, we have initially checked using **[strlen](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l?view=vs-2017)** if both strings are of equal length or not. If not, we can safely return false. _See line 06 and 07_.

Next we have matched each alphabet of `pFirst` with each alphabet of `pSecond`. _See line 09 and 21_. Since, the passed strings may contain both lower and upper case characters we have normalized the individual alphabets to lower case temporarily at time of comparison. _See line 14 and 15_. If we have iterated the `pSecond` completely that means there is non matching alphabet in `pFirst`. We have checked this fact and stopped matching further since it is clear that passed arguments are not anagram. _See line 18 to 22_.

This solution is very costly as the calculation time for anagram matching is very high. Our next solution is not the elegent one and  

---  

If you have paid attention to the code then our last two solutions rely on the alphabet index to create a `Mexican Wave`. Obviously, that is a natural solution to the problem at hand. Although I won't recommend, let us see a solution that uses alphabet matching to get the desired result. Although it is much costlier. Let's see how here we go &#x1F680;

# Solution 3

```C++
01: #include <vector>
02: #include <algorithm>
03: using namespace std;
04: 
05: std::vector<std::string> mexican_wave(std::string szPhrase)
06: {
07:     std::vector<std::string> mexicanWave;
08:     for (char target : szPhrase)
09:     {
10: 
11:         std::string szDestinationPhrase(szPhrase);
12: 
13:         std::transform(szPhrase.begin(), szPhrase.end(), szDestinationPhrase.begin(), [target](char &ch) { return target == ch ? std::toupper(ch) : ch; });
14:         mexicanWave.push_back(szDestinationPhrase);
15:     }
16:     return mexicanWave;
17: }

```

## Solution 3: Commentry

There are a few things worth looking here. First, we have modified the signature of the function to accept a string instead of a char pointer. This is a perfectly acceptable and much better way to accept the character array intended to be a string. _See line 05_. C++ **[STL](https://docs.microsoft.com/en-us/previous-versions/c191tb28(v=vs.140))** is a great library with many algorithms that we can make use of to further reduce the space for bugs :bug: and at the same time achieve desired results and make our code more readable. AS we are dealing with a **[container](http://www.cplusplus.com/reference/stl/)** we can safely use **[range based loop](https://en.cppreference.com/w/cpp/language/range-for)**. _See line 08_. Next, we are making a new string out of `szPhrase` and using **[std::transform](http://www.cplusplus.com/reference/algorithm/transform/)** to convert particular alphabet to uppercase. Nw this is very costly as we are comparing values sequentially instead of directly changing alphabet using an index. Remember both vector and string are sequences i.e you can use the index operator to access value directly. Rest of code is self-explanatory. 

---

Let's now move on to Level Up.

# Level 1 Solution

Our last ground solution has already given up a huge jump to reach level 1. Although quite self-explanatory let's discuss it also. Here we go &#x1F680;


## Solution 1 

```C++
File: lvl1_010.cpp
01: #include <string>
02: #include <vector>
03: #include <algorithm>
04: using namespace std;
05: 
06: std::vector<std::string> mexican_wave_lvl1_010(std::string szPhrase)
07: {
08:     std::vector<std::string> mexicanWave;
09:     std::string::iterator start = szPhrase.begin();
10:     while (start != szPhrase.end())
11:     {
12:         if (!isspace(*start))
13:         {
14:             std::string szDestinationPhrase(szPhrase);
15:             szDestinationPhrase[start - szPhrase.begin()] = toupper(szDestinationPhrase[start - szPhrase.begin()]);
16:             mexicanWave.push_back(szDestinationPhrase);
17:         }
18:         ++start;
19:     }
20:     return mexicanWave;
21: }

```
 

## Solution 1: Commentry

In this solution, we have to deal with space characters other than alphabets. We have taken a lesson from our last solutions and moved back to indexing instead of comparing alphabets as it is not that good. Well as all containers in C++ STL use **[iterators](https://en.cppreference.com/w/cpp/iterator)** to enumerate the collection we have taken a **[bidirectonal iterator](https://en.cppreference.com/w/cpp/iterator/BidirectionalIterator)** for our passed argument `szString`. An iterator can move to next element in container till **[end()](https://en.cppreference.com/w/cpp/iterator/end)**. __See line 09 to 10__. Now iterators, when negated, return the distance in terms of the number of locations. We have just this fact to our advantage for calculating the index. Though this is also costly this is done intentionally to show you operations on iterators. __See line 15__. Rest of code is self-explanatory except line 18 that I am leaving to your imagination. 
 
----
# Other Comments

To test all the ground up and level solutions I have created two helper functions (actually an overloaded one :grin:). They basically compare the values until the matching lasts. For a successful match, in the first one should come zero, in the second one it should come equal length. 

```C++
bool assertEqual(const char **pIterable1, const char **pIterable2, int nLen)
{
    /*Write normalization and comparison code here*/
    /*Return comparison result*/
    do
    {
        if (strcmp(pIterable1[nLen - 1], pIterable2[nLen - 1]))
            break;
    } while (--nLen);

    return !nLen;
}
bool assertEqual(vector<string> szIterable1, const char **pIterable2)
{
    int nIndex = 0;

    for (auto szString : szIterable1)
        if (szString.compare(pIterable2[nIndex++]))
            break;
    int nC = szIterable1.size();
    return nIndex == szIterable1.size();
}
```   

The test script for the solution can be **[found here](https://1drv.ms/u/s!An6FDnpXbnZ80kn5g1XGO_rWprbl)**

Hope you have liked this problem and its solutions. See you next Monday. Till then 

Happy programming (Days):wink: