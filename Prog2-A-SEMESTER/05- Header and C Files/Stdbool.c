#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isOnline = true;
    bool isAdmin = false;

    printf("Function: bool variable (isOnline) → %s\n", isOnline ? "true" : "false");
    printf("Function: bool variable (isAdmin) → %s\n", isAdmin ? "true" : "false");

    // Logic with bool
    if (isOnline && !isAdmin) {
        printf("Function: boolean logic → User is online but not admin\n");
    }

    return 0;
}
