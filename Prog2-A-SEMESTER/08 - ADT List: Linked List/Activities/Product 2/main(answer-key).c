#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mylib.h"
#include "mydate.h"

bool addItemSortedByMFG (ProductList *list, Product p) {
 // 1 - to do code logic here
    if (list->count == list->max) {
        return false;
    }

    int insertPos = 0;
    while (insertPos < list->count) {
 
        if (p.prodMFG.year > list->prods[insertPos].prodMFG.year) {
            break;
        } else if (p.prodMFG.year < list->prods[insertPos].prodMFG.year) {
            insertPos++;
            continue;
        }
        if (p.prodMFG.month > list->prods[insertPos].prodMFG.month) {
            break;
        } else if (p.prodMFG.month < list->prods[insertPos].prodMFG.month) {
            insertPos++;
            continue;
        }
    
        if (p.prodMFG.date > list->prods[insertPos].prodMFG.date) {
            break;
        }
        insertPos++;
    }

    // shift elements to the right
    for (int i = list->count; i > insertPos; i--) {
        list->prods[i] = list->prods[i - 1];
    }

    // Insert the new product
    list->prods[insertPos] = p;
    list->count++;
    return true;
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

    sortedProductList.max = productList.max;
    sortedProductList.count = 0;
    sortedProductList.prods = (Product *)malloc(sortedProductList.max * sizeof(Product));
    if (sortedProductList.prods == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < productList.count; i++) {
        if (!addItemSortedByMFG(&sortedProductList, productList.prods[i])) {
            printf("Failed to add product to sorted list.\n");
            break;
        }
    }

    printf("\nOriginal List:\n");
    displayProducts(productList);

    printf("\nSorted List (MFG):\n");
    displayProducts(sortedProductList);
     // 3 - to do code logic here


    free(sortedProductList.prods);
    free(productList.prods);

    return 0;
}
