#include <string>
using namespace std;
int vowel_counter_030(const char * pPhrase){	
	int nVowels = 0;

	for (auto i: string(pPhrase))
		switch (i | 32){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++nVowels;
		}
	return nVowels;
}

