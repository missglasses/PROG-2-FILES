#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char copy[50];
    char joined[100];

    // strlen
    printf("Function: strlen → %lu\n", strlen(str1));

    // strcpy
    strcpy(copy, str1);
    printf("Function: strcpy → %s\n", copy);

    // strcmp
    int cmp = strcmp(str1, str2);
    printf("Function: strcmp → %d (0 means equal, <0 means str1 < str2, >0 means str1 > str2)\n", cmp);

    // strcat
    strcpy(joined, str1);       // First copy str1 to joined
    strcat(joined, " ");        // Add a space
    strcat(joined, str2);       // Append str2
    printf("Function: strcat → %s\n", joined);

    // strchr
    char *ch = strchr(str1, 'l');
    if (ch != NULL)
        printf("Function: strchr → Found 'l' at index %ld\n", ch - str1);
    else
        printf("Function: strchr → Character not found\n");

    // strstr
    char *substr = strstr(joined, "lo Wo");
    if (substr != NULL)
        printf("Function: strstr → Found 'lo Wo' starting at index %ld\n", substr - joined);
    else
        printf("Function: strstr → Substring not found\n");

    // memcpy
    char block1[10] = "Brooo";
    char block2[10];
    memcpy(block2, block1, strlen(block1) + 1);  // Include null terminator
    printf("Function: memcpy → %s\n", block2);

    return 0;
}
