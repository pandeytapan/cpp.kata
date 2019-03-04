#include <vector>
#include <algorithm>
using namespace std;

std::vector<std::string> mexican_wave_015(const char *pPhrase)
{
    std::string szPhrase = pPhrase;
    std::vector<std::string> mexicanWave;
    for (int x = 0; x < szPhrase.size(); ++x)
    {
        std::string szDestinationPhrase = pPhrase;
        szDestinationPhrase.at(x) = std::toupper(szDestinationPhrase.at(x));
        mexicanWave.push_back(szDestinationPhrase);
    }
    return mexicanWave;
}