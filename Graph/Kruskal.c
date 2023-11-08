#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[99][99], parent[99];

int find(int);
int uni(int, int);
int display(int);

int main() {
    printf("\n\t\tKruskal's algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter the weight of edge from [%d] to [%d]: ", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\n");
    display(n);  // Display the adjacency matrix

    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("Edge %d : [%d] -> [%d] weight : %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum weight: %d\n\n", mincost);
}

int display(int size) {
    printf("Adjacency Matrix:\n");
    for (i = 1; i <= size; i++) {
        for (j = 1; j <= size; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
            printf("\n");

}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
