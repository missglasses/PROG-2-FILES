#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'A';
    char d = '8';
    char e = 'b';
    char f = '#';

    // tolower
    printf("Function: tolower('%c') → %c\n", c, tolower(c));

    // toupper
    printf("Function: toupper('%c') → %c\n", e, toupper(e));

    // isdigit
    printf("Function: isdigit('%c') → %s\n", d, isdigit(d) ? "true" : "false");

    // isalpha
    printf("Function: isalpha('%c') → %s\n", c, isalpha(c) ? "true" : "false");
    printf("Function: isalpha('%c') → %s\n", f, isalpha(f) ? "true" : "false");

    // isalnum
    printf("Function: isalnum('%c') → %s\n", d, isalnum(d) ? "true" : "false");
    printf("Function: isalnum('%c') → %s\n", f, isalnum(f) ? "true" : "false");

    // islower
    printf("Function: islower('%c') → %s\n", e, islower(e) ? "true" : "false");
    printf("Function: islower('%c') → %s\n", c, islower(c) ? "true" : "false");

    // isupper
    printf("Function: isupper('%c') → %s\n", c, isupper(c) ? "true" : "false");
    printf("Function: isupper('%c') → %s\n", e, isupper(e) ? "true" : "false");

    return 0;
}
