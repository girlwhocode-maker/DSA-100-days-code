/*
Problem:
For each element in an array, count how many smaller
elements appear on the right side.

Approach:
Use Merge Sort technique to count inversions per element.

Input:
- First line: n
- Second line: n space-separated integers

Output:
- Print count of smaller elements on right for each index

Example:
Input:
5
5 2 6 1 3

Output:
3 1 2 0 0
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int *count;

void merge(Pair arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    Pair *L = (Pair*)malloc(n1 * sizeof(Pair));
    Pair *R = (Pair*)malloc(n2 * sizeof(Pair));

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    int rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].idx] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].idx] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Pair arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Pair arr[n];
    count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}