#include <algorithm>
#include <memory>
#include <string.h>
using namespace std;

bool is_anagram_021(const char *pFirst, const char *pSecond)
{
    std::unique_ptr<char[]> first(new char[strlen(pFirst)]);
    std::unique_ptr<char[]> second(new char[strlen(pSecond)]);

    strcpy(first.get(), pFirst);
    strcpy(second.get(), pSecond);

    std::transform(first.get(), first.get() + strlen(first.get()), first.get(), ::tolower);
    std::transform(second.get(), second.get() + strlen(second.get()), second.get(), ::tolower);
    std::sort(first.get(), first.get() + strlen(first.get()));
    std::sort(second.get(), second.get() + strlen(second.get()));

    return !strcmp(first.get(), second.get());
}
