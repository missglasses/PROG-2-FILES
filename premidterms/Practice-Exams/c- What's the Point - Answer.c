#include <stdio.h>
// add your structure here
typedef struct{
    int x;
    int y;
}Point;

// add your function prototypes here
void identifyPoint(Point p);
void displayPoint(Point p);
Point createPoint(int x, int y);


void main() {
    int x, y;

    printf("Enter x - coordinate: ");
    scanf("%d", &x);
    printf("Enter y - coordinate: ");
    scanf("%d", &y);

    //insert code here
    Point p =createPoint(x,y);
    displayPoint(p);
    identifyPoint(p);
}

// add your function definitions here
void identifyPoint(Point p){
    if (p.x == 0 && p.y == 0) {
        printf(" is in Origin.\n");
    } else if (p.x > 0 && p.y > 0) {
        printf(" is in Q1.\n");
    } else if (p.x < 0 && p.y > 0) {
        printf(" is in Q2.\n");
    } else if (p.x < 0 && p.y < 0) {
        printf(" is in Q3.\n");
    } else if (p.x > 0 && p.y < 0) {
        printf(" is in Q4.\n");
    } else if (p.y == 0) {
        printf(" is on x-axis.\n");
    } else {
        printf(" is on y-axis.\n");
    }
    
}

void displayPoint(Point p){
    printf("The point (%d, %d)", p.x, p.y);
}

Point createPoint(int x, int y){
    Point p;
    p.x=x;
    p.y=y;
    return p;
}

