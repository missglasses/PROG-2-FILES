#include <stdio.h>
#include <stdlib.h>
#include "pointy.h"

Points getMrPointyAndFriends(Points points) {
    Points result;
    initPoints(&result, points.count); // Initialize with same max size as input
    result.count = 0;
    
    if (points.count == 0) {
        return result;
    }
    
    MyPoint mrPointy = points.points[0];
    int mrPointyLocation = identifyPoint(mrPointy);
    
    // Add Mr. Pointy first
    result.points[result.count++] = mrPointy;
    
    // Find friends (points with same location)
    for (int i = 1; i < points.count; i++) {
        if (identifyPoint(points.points[i]) == mrPointyLocation) {
            result.points[result.count++] = points.points[i];
        }
    }
    
    return result;
}

void main() {
    Points points = createPoints(30);
    Points friends;
    int x, y;

    populatePoints(&points);

    printf("Enter x - coordinate: ");
    scanf("%d", &x);
    printf("Enter y - coordinate: ");
    scanf("%d", &y);

    // [1] Override the first value with Mr. Pointy's coordinates
    points.points[0] = createPoint(x, y);

    displayPointMsg(points.points[0]);
    // [3] Get Mr. Pointy and his friends
    friends = getMrPointyAndFriends(points);

    printf("Friends: ");
    // [4] Display friends starting from index 1 (skip Mr. Pointy himself)
    displayAllPointsWithStartIndex(friends, 1);
}
