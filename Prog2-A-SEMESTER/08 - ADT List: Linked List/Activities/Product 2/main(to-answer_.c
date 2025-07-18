#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mylib.h"
#include "mydate.h"

bool addItemSortedByMFG (ProductList *list, Product p) {
    // 1 - to do code logic here

}

int main() {
    ProductList productList, sortedProductList;
    int option;
    int count;

    printf("Enter option: ");
    scanf("%d", &option);
    printf("Enter count: ");
    scanf("%d", &count);

    productList = populateProductList(option, count);

    // 2 - to do code logic here

    printf("\nOriginal List:\n");
    displayProducts(productList);

    printf("\nSorted List (MFG):\n");
    // 3 - to do code logic here

    return 0;
}
