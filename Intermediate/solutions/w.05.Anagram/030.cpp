#include <algorithm>
#include <memory>
#include <string>
using namespace std;

bool is_anagram_030(std::string first, std::string second)
{

    std::transform(first.begin(), first.end(), first.begin(), ::tolower);
    std::transform(second.begin(), second.end(), second.begin(), ::tolower);
    
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    return !first.compare(second);
}
