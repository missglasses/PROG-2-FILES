#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 20

// to do structure for Product
typedef struct {
    int productID;
    char productName[20];
    int productQty;
    float productPrice;
}Product;

Product newProduct(int id, char* name, int qty, float price);
void addProduct(Product *list,int *count, Product p);
void displayProductsLessThan(Product* list, int count, float amount);

int main() {
    Product prodList[20];
    int count=0;

    addProduct(prodList,&count, newProduct(1, "Converse Chuck", 0, 5000));
    // add the rest of the addProduct()
    addProduct(prodList, &count, newProduct(2, "Nyke Water Force 1s", 0, 6000)); //0 is for quantity
    addProduct(prodList, &count, newProduct(3, "AirPods", 0, 9500));
    addProduct(prodList, &count, newProduct(4, "Marshmallows", 0, 150));
    addProduct(prodList, &count, newProduct(5, "Netflix Giftcard", 0, 500));
    addProduct(prodList, &count, newProduct(6, "Speakers", 0, 2000));
    addProduct(prodList, &count, newProduct(7, "Alarm Clock", 0, 1500));
    addProduct(prodList, &count, newProduct(8, "Backpack", 0, 1000));
    addProduct(prodList, &count, newProduct(9, "Smart Watch", 0, 7000));
    addProduct(prodList, &count, newProduct(10, "Self-Help Book", 0, 300));

    // make a call of the display product with 2000 as the amount value
    displayProductsLessThan(prodList, count, 2000); //count ??

    return 0;
}

Product newProduct(int id, char* name, int qty, float price) {
  //To Do
  Product p;
  p.productID=id;
  strcpy(p.productName, name);
  p.productQty=qty;
  p.productPrice=price;
  
  return p;
  
}



void addProduct(Product *list,int *count, Product p) {
 //To Do
 if (*count<MAX_PRODUCTS){
     list[*count]=p;
     (*count)++;
 }
}

void displayProductsLessThan(Product* list, int count, float amount) {
    // to do code logic for display
    //int count=0;
    for (int i=0; i<count; i++){ 
        if(list[i].productPrice<amount){ //value of amount @func call
                printf("%d - %s - Php %.2f\n", list[i].productID, list[i].productName, list[i].productPrice);
        }
    }
        
    }
