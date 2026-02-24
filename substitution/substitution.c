#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// the key is DTMYSBKUGLOFXRIHQVCZAWNPJE
char get_cipher_char(char plain_char, string key);
void encrypt_text(string plaintext, string key);
bool check_length(string key);
bool check_alphabetic(string key);
bool check_uniqueness(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!check_length(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (!check_alphabetic(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    if (!check_uniqueness(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    encrypt_text(plaintext, argv[1]);

    return 0;
}

char get_cipher_char(char plain_char, string key)
{
    if (isalpha(plain_char))
    {
        int index = tolower(plain_char) - 'a';
        return islower(plain_char) ? tolower(key[index]) : toupper(key[index]);
    }
    return plain_char;
}

void encrypt_text(string plaintext, string key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", get_cipher_char(plaintext[i], key));
    }
    printf("\n");
}

bool check_length(string key)
{
    return strlen(key) == 26;
}

bool check_alphabetic(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}

bool check_uniqueness(string key)
{
    bool seen[26] = {false};
    for (int i = |0; i < 26; i++)
    {
        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }
    return true;
}

