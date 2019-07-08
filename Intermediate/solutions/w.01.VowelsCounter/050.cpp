#include <string>
#include <regex>
#include <functional>
using namespace std;


int vowel_counter_050(const char * pPhrase)
{
	string objPhrase = pPhrase;
	return std::count_if(objPhrase.begin(), objPhrase.end(), [](char ch) {return strchr("aeiou", ch | 32); });
}
