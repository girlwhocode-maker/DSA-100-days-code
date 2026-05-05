/*
Problem Statement:
Implement Heap Sort using a Max Heap to sort an array
in ascending order.

Approach:
1. Build a Max Heap from the given array.
2. Repeatedly swap root (maximum element) with last element.
3. Reduce heap size and heapify again.
4. Final array will be sorted in ascending order.

Input:
- First line: integer n (size of array)
- Second line: n space-separated integers

Output:
- Print sorted array in ascending order

Example:
Input:
5
40 10 30 50 20

Output:
10 20 30 40 50
*/

#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for max heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // Move max to end
        heapify(arr, i, 0);       // Heapify reduced heap
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(" ");
    }
}

int main() {
    int n;

    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}