#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{

    int32_t u32_descriptor = open("short.poem.txt", O_RDONLY | S_IRUSR);
    if (u32_descriptor == -1)
    {
        printf("Error opening file %s", "short.poem.txt");
        return EXIT_FAILURE;
    }

    struct stat sb;
    if (fstat(u32_descriptor, &sb) == -1)
    {
        printf("Error opening file %s", "short.poem.txt");
        return EXIT_FAILURE;
    }

    const u_int8_t *p_mapped_memory = (const u_int8_t *)mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, u32_descriptor, 0);
    if (p_mapped_memory == MAP_FAILED)
    {
        printf("Error opening file %s", "short.poem.txt");
        return EXIT_FAILURE;
    }
    pid_t process_id = fork();
    u_int8_t u8_vowels = 0;
    u_int8_t u8_consonants = 0;

    if (!process_id)
        for (u_int8_t n8_idx = 0; n8_idx < sb.st_size; ++n8_idx)
        {
            if (tolower(p_mapped_memory[n8_idx]) == 'a' \
            || tolower(p_mapped_memory[n8_idx]) == 'e' \
            || tolower(p_mapped_memory[n8_idx]) == 'i' \
            || tolower(p_mapped_memory[n8_idx]) == 'o' \
            || tolower(p_mapped_memory[n8_idx]) == 'u')
                u8_vowels++;
        }
    else
        for (u_int8_t n8_idx = 0; n8_idx < sb.st_size; ++n8_idx)
        {
            if (tolower(p_mapped_memory[n8_idx]) >= 'a' && tolower(p_mapped_memory[n8_idx]) <= 'z')
                u8_consonants++;
        }

    munmap((void *)p_mapped_memory, sb.st_size);
    close(u32_descriptor);

    if(!process_id)
        printf("Vowels: %d\n", u8_vowels);
   else 
        printf("Consonants: %d\n", u8_consonants);

    return EXIT_SUCCESS;
}