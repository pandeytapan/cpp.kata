#include <vector>
#include <algorithm>
using namespace std;

std::vector<std::string> mexican_wave_018(std::string szPhrase)
{
    std::vector<std::string> mexicanWave;
    for (char target : szPhrase)
    {

        std::string szDestinationPhrase(szPhrase);

        std::transform(szPhrase.begin(), szPhrase.end(), szDestinationPhrase.begin(), [target](char &ch) { return target == ch ? std::toupper(ch) : ch; });
        mexicanWave.push_back(szDestinationPhrase);
    }
    return mexicanWave;
}