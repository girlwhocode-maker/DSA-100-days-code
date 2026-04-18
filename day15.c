#include <stdio.h>

/*
Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements
*/

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int sum = 0;

    for(int i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }

    printf("%d", sum);

    return 0;
}