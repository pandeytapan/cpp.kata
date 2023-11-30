#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define ENCRYPTION_FLAG L'!' // A unique flag to mark an encrypted string

// Function to transform and normalize characters
wchar_t transformChar(wchar_t input, bool encrypting)
{
    if (encrypting)
    {
        // Map characters to ASCII range 32-126, excluding '-'
        return (input % 94) + 32 + (input == '-' ? 1 : 0);
    }
    else
    {
        // Reverse the transformation
        return (input >= 33 && input <= 126) ? input - 32 : input;
    }
}

// Encrypt or decrypt the string
bool xorCipher(wchar_t *string, wchar_t *key, bool encrypting)
{
    if (!string || !key)
        return false;

    size_t strLength = wcslen(string);
    size_t keyLength = wcslen(key);

    if (strLength == 0 || keyLength == 0)
        return false;

    // Check if already encrypted or decrypted
    if ((encrypting && string[0] == ENCRYPTION_FLAG) || (!encrypting && string[0] != ENCRYPTION_FLAG))
    {
        return false;
    }

    for (size_t i = 0, keyIndex = 0; i < strLength; ++i)
    {
        // Skip white spaces
        if (string[i] == L' ')
            continue;

        // XOR operation
        wchar_t resultChar = string[i] ^ key[keyIndex];

        // Transform and normalize characters for ASCII range
        string[i] = transformChar(resultChar, encrypting);

        // Move to next key character, wrap around if needed
        keyIndex = (keyIndex + 1) % keyLength;
    }

    // Mark the string as encrypted or decrypted
    if (encrypting)
    {
        string[0] = ENCRYPTION_FLAG;
    }
    else if (string[0] == ENCRYPTION_FLAG)
    {
        string[0] = L' '; // Replace the flag with a space or any other character
    }

    return true;
}

bool encrypt(wchar_t *string, wchar_t *key)
{
    return xorCipher(string, key, true);
}

bool decrypt(wchar_t *string, wchar_t *key)
{
    return xorCipher(string, key, false);
}

int main()
{
    setlocale(LC_ALL, ""); // Set the locale for wide character support

    wchar_t testString[] = L"Hello World!";
    wchar_t key[] = L"key123";

    if (encrypt(testString, key))
    {
        wprintf(L"Encrypted: %ls\n", testString);
    }

    if (decrypt(testString, key))
    {
        wprintf(L"Decrypted: %ls\n", testString);
    }

    return 0;
}
