#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<std::string> mexican_wave_lvl1_010(std::string szPhrase)
{
    std::vector<std::string> mexicanWave;
    std::string::iterator start = szPhrase.begin();
    while (start != szPhrase.end())
    {
        if (!isspace(*start))
        {
            std::string szDestinationPhrase(szPhrase);
            szDestinationPhrase[start - szPhrase.begin()] = toupper(szDestinationPhrase[start - szPhrase.begin()]);
            mexicanWave.push_back(szDestinationPhrase);
        }
        ++start;
    }
    return mexicanWave;
}