int vowel_counter_020(const char * pPhrase){
	int nVowels = 0;

	for (int i = 0; pPhrase[i]; ++i){
		if ((pPhrase[i] | 32) == 'a' ||
			(pPhrase[i] | 32) == 'e' ||
			(pPhrase[i] | 32) == 'i' ||
			(pPhrase[i] | 32) == 'o' ||
			(pPhrase[i] | 32) == 'u')
			++nVowels;
	}
	return nVowels;
}