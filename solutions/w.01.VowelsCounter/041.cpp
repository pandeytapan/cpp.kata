#include <string>
#include <regex>
using namespace std;

int vowel_counter_041(const char * pPhrase)
{
	string objPhrase = pPhrase;
	smatch objMatch;
	regex expr("[aeiou]");
	int nVowels = 0;

	std::transform(objPhrase.begin(), objPhrase.end(), objPhrase.begin(), ::tolower);
	while (std::regex_search(objPhrase, objMatch, expr)){
		objPhrase = objMatch.suffix().str();
		++nVowels;
	}
	return nVowels;
}

