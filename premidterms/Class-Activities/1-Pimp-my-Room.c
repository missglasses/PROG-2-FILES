//JUNE 17 2025
#include <stdio.h>
#include <stdlib.h>
#define CEIL_COST 12.5
#define FLOOR_COST 5
#define WALL_COST  8.25

float getArea(float l, float w);
float costCalc(float l, float w, float cost);

int main() {
    // NOTE: ceiling = floor; walls are equal
    float len, wdh, hgt; 
    float cc, cf, cw, totalCost;  
    
    printf("Enter length(m): ");  
    scanf("%f", &len);  
    printf("Enter width(m): ");
    scanf("%f", &wdh);
    printf("Enter height(m): ");
    scanf("%f", &hgt);

    // Calculate costs
    cc = costCalc(len, wdh, CEIL_COST);
    cf = costCalc(len, wdh, FLOOR_COST);
    cw = costCalc(hgt, wdh, WALL_COST) * 2;  
    float cw2 = costCalc(hgt, len, WALL_COST) * 2; 

    printf("Cost of ceiling: Php %.2f\n", cc);  
    printf("Cost of floor: Php %.2f\n", cf);
    printf("Cost of wall 1: Php %.2f\n", costCalc(hgt, wdh, WALL_COST));
    printf("Cost of wall 2: Php %.2f\n", costCalc(hgt, len, WALL_COST));

    totalCost = cc + cf + cw + cw2;
    printf("Total Cost: Php %.2f\n", totalCost);

    return 0;
}

float getArea(float l, float w) {
    return l * w;
}

float costCalc(float l, float w, float cost) {
    return getArea(l, w) * cost; 
}
