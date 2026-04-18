#include <stdio.h>

/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array
*/

int main() {
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;

    int temp[100];
    int index = 0;

    for(int i = n - k; i < n; i++) {
        temp[index++] = a[i];
    }

    for(int i = 0; i < n - k; i++) {
        temp[index++] = a[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}