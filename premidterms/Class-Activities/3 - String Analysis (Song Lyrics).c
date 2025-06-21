#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strCtr(char str[]);                 // counts every character apil space
int vowelCtr(char str[]);               // vowel letter counter
int ifVowel(char ch);                   // vowel or naur
void changeStr(char str[], char vowel); // change vowel to another letter
int letterCtr(char str[]);              //  letters only counter??
// int letterCtr(char str[], char letter);
int wordCtr(char str[]); // words only counter

int main()
{
    char str[100] = "Leron Leron sinta buko ng papaya, dala-dalay buslo";
    char letter = 'a';

    printf("Before string: %s\n", str);
    printf("Vowel Count: %d\n", vowelCtr(str));
    printf("Word Count: %d\n", wordCtr(str));
    printf("Letter Count: %d\n", letterCtr(str));
    printf("Character Count: %d\n", strCtr(str));

    // printf("Letter : '%c' Count: %d\n", letter, letterCtr(str, letter));

    changeStr(str, 'e'); // change all vowels to 'e'
    printf("After string: %s\n", str);

    return 0;
}

int ifVowel(char ch)
{
    // returns 1 if vowel or
    char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    for (int i = 0; i < 10; i++)
    {
        if (ch == vowels[i])
            return 1;
    }
    return 0;
}

int strCtr(char str[])
{
    // count everthing including spaces
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

void changeStr(char str[], char vowel)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (ifVowel(str[i]))
        {
            str[i] = vowel;
        }
        i++;
    }
}

int wordCtr(char str[])
{
    int count = 0, flag = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            flag = 0;
        }
        else if (flag == 0)
        {
            flag = 1;
            count++;
        }
        i++;
    }
    return count;
}

int vowelCtr(char str[])
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (ifVowel(str[i]))
        {
            count++;
        }
        i++;
    }
    return count;
}

int letterCtr(char str[])
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (isalpha(str[i]))
        { /// letter occurnece
            count++;
        }
        i++;
    }
    return count;
}
