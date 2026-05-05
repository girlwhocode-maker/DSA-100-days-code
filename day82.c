/*
Problem:
Given a sorted array and target x,
find:
1) Lower Bound -> first index where arr[i] >= x
2) Upper Bound -> first index where arr[i] > x

Input:
- n (size of array)
- sorted array
- x (target)

Output:
- print lower bound index and upper bound index

Example:
Input:
7
1 2 4 4 4 5 7
4

Output:
2 5
*/

#include <stdio.h>

// Lower bound function
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n;

    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

// Upper bound function
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n;

    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}