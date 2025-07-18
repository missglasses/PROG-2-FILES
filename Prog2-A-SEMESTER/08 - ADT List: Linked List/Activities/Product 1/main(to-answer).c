#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mylib.h"

int main() {
    ProductList productList;
    int option;
    int count;

    printf("Enter option: ");
    scanf("%d", &option);
    printf("Enter count: ");
    scanf("%d", &count);

    productList = populateProductList(option, count);

    printf("\nOriginal List:\n");
    displayProducts(productList);

    printf("\nSecond Product:\n");
    displayProduct(productList.prods[1]);

    return 0;
}
