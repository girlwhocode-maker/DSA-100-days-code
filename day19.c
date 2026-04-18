#include <stdio.h>
#include <stdlib.h>

/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero
*/

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = 1000000000;
    int x = 0, y = 0;

    while(left < right) {
        int sum = a[left] + a[right];

        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            x = a[left];
            y = a[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);

    return 0;
}