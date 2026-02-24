#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calcular L y S
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // Calcular el índice Coleman-Liau
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Imprimir el nivel de grado
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

int count_letters(string text)
{
    // Declarar un contador para las letras
    int letter_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    int word_count = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}

