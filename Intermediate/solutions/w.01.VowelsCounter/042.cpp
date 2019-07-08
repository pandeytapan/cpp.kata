#include <string>
#include <regex>
using namespace std;

int vowel_counter_042(const char * pPhrase)
{
	string objPhrase = pPhrase;
	smatch objMatch;
	regex expr("[aeiou]");
	int nVowels = 0;
	std::for_each(objPhrase.begin(), objPhrase.end(), [](char & val) { val =::tolower(val); });
	while (std::regex_search(objPhrase, objMatch, expr)){
		objPhrase = objMatch.suffix().str();
		++nVowels;
	}
	return nVowels;
}

