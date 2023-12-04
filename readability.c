#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// main functions protoypes
int count_letters(string text);
int count_words(string words);
int count_sentences(string sentences);

//variables
string prompt = "";
int letter_count = 0;
int word_count = 1;
int sentence_count = 0;
float index = 0;
float L = 0;
float S = 0;


int main(void)
{
    do
    {
        prompt = get_string("Text: ");
    }
    while (strlen(prompt) <= 0);

    // calls function count_letters
    int count = count_letters(prompt);

    // calls function count_words
    int wrd_count = count_words(prompt);

    //calls function count_sentences
    int sent_count = count_sentences(prompt);

    //calculates average L and S
    L = (letter_count / (float)word_count) * 100;
    S = (sentence_count / (float)word_count) * 100;

    //Coleman-Leau formula
    index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded = round(index);

    if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (rounded <= 16)
    {
        printf("Grade %i\n", rounded);
    }

    else
    {
        printf("Grade 16+\n");
    }


}

int count_sentences(string sentences)
{
    for (int i = 0; i < strlen(sentences); i ++)
    {
        if (sentences[i] == '.' || sentences[i] == '!' || sentences[i] == '?')
        {
            sentence_count ++;
        }
    }

    return sentence_count;
}

int count_words(string words)
{
    for (int i = 0; i < strlen(words); i ++)
    {
        if (isblank(words[i]))
        {
            word_count ++;
        }
    }

    return word_count;

}

int count_letters(string text)
{

    for (int i = 0; i < strlen(text); i ++)
    {
        if (isalpha(text[i]))
        {
            letter_count ++;
        }
    }

    return letter_count;

}

