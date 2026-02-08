/*
Problem: Given a sorted array of n integers, remove duplicates in-place. 
Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include <stdio.h>

int main() {
    int n;
    int arr[100];

    // Read number of elements
    scanf("%d", &n);

    // Read sorted array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: if only one element
    if(n == 0) {
        return 0;
    }

    // Two-pointer approach
    int j = 0; // index for unique elements

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for(int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
