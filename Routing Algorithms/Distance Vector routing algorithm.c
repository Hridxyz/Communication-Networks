#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 10
#define INF 999

void inputCostMatrix(int cost[MAX_NODES][MAX_NODES], int n) {
    printf("Enter the cost matrix for the network:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(i == j)
                cost[i][j] = 0; // Cost to self is zero
            else if(cost[i][j] == 0)
                cost[i][j] = INF; // No direct link between nodes
        }
    }
}

void calculateDistanceVectors(int cost[MAX_NODES][MAX_NODES], int distanceVectors[MAX_NODES][MAX_NODES], int n) {
    int count, updated;

    // Initialize distance vectors with direct costs
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            distanceVectors[i][j] = cost[i][j];
        }
    }

    // Update distance vectors
    do {
        updated = 0;
        for(int i = 0; i < n; i++) { // For each node
            for(int j = 0; j < n; j++) { // For each destination
                for(int k = 0; k < n; k++) { // Check via each node
                    if(distanceVectors[i][j] > cost[i][k] + distanceVectors[k][j]) {
                        distanceVectors[i][j] = cost[i][k] + distanceVectors[k][j];
                        updated = 1;
                    }
                }
            }
        }
    } while(updated);
}

void printDistanceVectors(int distanceVectors[MAX_NODES][MAX_NODES], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nDistance vector for node %d:\n", i);
        for(int j = 0; j < n; j++) {
            if(distanceVectors[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", distanceVectors[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int cost[MAX_NODES][MAX_NODES], distanceVectors[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes in the network: ");
    scanf("%d", &n);

    inputCostMatrix(cost, n);
    calculateDistanceVectors(cost, distanceVectors, n);
    printDistanceVectors(distanceVectors, n);

    return 0;
}
