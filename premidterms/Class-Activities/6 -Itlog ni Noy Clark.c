#include <stdio.h>
// #define STOCK 10
// #define MAX_ORDER 50

typedef struct {
    int id;
    char etlogType[20];
    float price;
} Menu;

typedef struct {
    int order_no; // choice
    int quantity;
    float total_cost;
} Order;

int main() {
     // int etlog_stocks[3] = {STOCK, STOCK, STOCK};
    Menu etlog[] = {
        {0, "EXIT", 0},
        {1, "Balut #16", 12.50},
        {2, "Balut #18", 15.00},
        {3, "Penoy", 10.00}
    };
    int etlogArrSize = sizeof(etlog) / sizeof(etlog[0]);

    int customerCtr = 1; // no. of customers
    int nextCustomer = 'y';

    while (customerCtr) {
        printf("\t\t\tITLOG NI NOY CLARK\n");
        printf("\t\t=================================\n");
        printf("\t\t[0] EXIT\n");
        printf("\t\t[1] Balut #16\t\t(P12.50)\n");
        printf("\t\t[2] Balut #18\t\t(P15.00)\n");
        printf("\t\t[3] Penoy\t\t\t(P10.00)\n");
        // printf("\t\t[0] EXIT\n");
        printf("\t\t=================================\n\n\n");

        Order orders[50];
        int orderCtr = 0;
        float grand_total = 0;
        
        //take orders
        while (1) {
            printf("Please enter your order #%d (0 to exit): ", orderCtr + 1);
            scanf("%d", &orders[orderCtr].order_no);

            if (orders[orderCtr].order_no == 0) break;

            if (orders[orderCtr].order_no < 1 || orders[orderCtr].order_no >= etlogArrSize) {
                printf("Invalid order!.\n");
                continue;
            }

            printf("Please enter quantity: ");
            scanf("%d", &orders[orderCtr].quantity);

            orderCtr++;
        }
        // printf("\nDo you want next customer? (y/n): ");
        // scanf(" %c", &nextCustomer);
        
       
         // display receipt
        printf("\t\t=================================\n");
        printf("\t\t\tYour Order\n");
        
        for (int i = 0; i < orderCtr; i++) {
            int item_id = orders[i].order_no;
            orders[i].total_cost = etlog[item_id].price * orders[i].quantity;
            grand_total += orders[i].total_cost;

            printf("\t\t%d. %s (x%d)\tP%.2f\n",
                   i + 1,
                   etlog[item_id].etlogType,
                   orders[i].quantity,
                   orders[i].total_cost);
        }
        printf("\t\tTotal Cost: P%.2f\n", grand_total);

        //payment
        float payment;
        printf("\n\t\tEnter Amount: ");
        scanf("%f", &payment);
        printf("\t\tChange: P%.2f\n", payment - grand_total);
        
        printf("\t\t=================================\n");

        printf("\nDo you want next customer? (y/n): ");
        scanf(" %c", &nextCustomer); 
         if (nextCustomer == 'n' || nextCustomer == 'N') {
            break;
        }

    }

    return 0;
}
