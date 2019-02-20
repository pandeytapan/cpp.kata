#include <string.h>
int vowel_counter_010(const char * pPhrase){
	int nLen = strlen(pPhrase);
	int nVowels = 0;

	for (int i = 0; i < nLen; ++i) {
		if (pPhrase[i] == 'a' || pPhrase[i] == 'A' ||
			pPhrase[i] == 'e' || pPhrase[i] == 'E' ||
			pPhrase[i] == 'i' || pPhrase[i] == 'I' ||
			pPhrase[i] == 'o' || pPhrase[i] == 'O' ||
			pPhrase[i] == 'u' || pPhrase[i] == 'U')
			++nVowels;
	}
	return nVowels;
}
