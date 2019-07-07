#include <string>
#include <regex>

int vowel_counter_040(const char * pPhrase)
{
	std::string objPhrase = (std::string(pPhrase));
	std::smatch objMatch;
	std::regex expr("[aeiouAEIOU]");
	int nVowels = 0;
	while (std::regex_search(objPhrase, objMatch, expr)){
		objPhrase = objMatch.suffix().str();
		++nVowels;
	}
	return nVowels;
}

