
// Description: This program will print "Hello World!" twice.
#include <cstdio>
#include <unistd.h>
int main ()
{
    printf("Good times!\n");
    fork();
    printf("Hello World!\n");
    for (int i = 0; i < 10; i++)
        printf("%u\n", i);
    
    return 0;
}