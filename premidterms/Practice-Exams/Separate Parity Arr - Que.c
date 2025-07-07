#include <stdio.h>
#define MAX 100

void main() {
    int list[MAX];
    int n;

    printf("Enter how many values: ");
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", list+i);
    }

    printf("Original {");
    for(int i = 0; i < n; ++i) {
        printf("%d", *(list + i));
        if(i < n-1) {
            printf(", ");
        }
    }
    printf("}\n");


}
