#include <cstdio>
#include <cstdlib>
#include <cctype>

int main()
{
    u_int8_t    u8_vowels = 0;
    u_int8_t    u8_consonants = 0;
    int8_t      n8_character = 0;
    u_int8_t    u8_others = 0;

    FILE *p_file = fopen("short.poem.txt", "r");
    
    if (p_file == NULL)
    {
        printf("Error opening file %s", "long.poem.txt");
        return EXIT_FAILURE;
    }
    while((n8_character = fgetc(p_file)) != EOF)
    {
        n8_character =  tolower(n8_character);
        if (n8_character == 'a' || n8_character == 'e' || n8_character == 'i' || n8_character == 'o' || n8_character == 'u')
            u8_vowels++;
        else if (n8_character >= 'a' && n8_character <= 'z')
            u8_consonants++;
        else
            u8_others++;
    }
    
    fclose(p_file);

    printf("Vowels: %d\n", u8_vowels);
    printf("Consonants: %d\n", u8_consonants);
    printf("Others: %d\n", u8_others);  
 
    return EXIT_SUCCESS;
}