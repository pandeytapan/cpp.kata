#include <cstdlib>
#include <cmath>

int main (int argc, char * argv[])
{ 
    float_t b = 231.4f;
    float_t r = 3.34f;
    float_t n = 2.1f;
    double_t a = b * pow(1 + r / 100, n);
    return EXIT_SUCCESS;
}