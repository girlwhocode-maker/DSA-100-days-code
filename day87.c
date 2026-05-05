/*
Problem:
Implement Binary Search Iterative.

Input:
- First line: n (number of elements)
- Second line: n space-separated integers
- Third line: key to search

Output:
- If found: index of element
- If not found: -1

(Also sorting is done first if needed)

Example:
Input:
5
64 34 25 12 22
25

Output:
2
*/

#include <stdio.h>

// Bubble sort (to ensure sorted array)
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary search iterative
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    scanf("%d", &key);

    // sort array first
    sort(arr, n);

    int result = binarySearch(arr, n, key);

    printf("%d\n", result);

    return 0;
}