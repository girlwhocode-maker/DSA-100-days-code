/*
Problem Statement:
Given n stalls and k cows, place cows such that
minimum distance between any two cows is maximized.

Input Format:
n k
n space-separated stall positions

Output Format:
Maximum minimum distance possible

Sample Input:
5 3
1 2 8 4 9

Sample Output:
3

Explanation:
Place cows at 1, 4, 8 → min distance = 3 (maximum possible)
*/

#include <stdio.h>

// swap for sorting
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// simple sort (selection sort)
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}

// check if cows can be placed
int canPlace(int arr[], int n, int k, int dist) {
    int count = 1;
    int lastPos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= dist) {
            count++;
            lastPos = arr[i];
        }

        if (count >= k)
            return 1;
    }

    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    int low = 1, high = arr[n - 1] - arr[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(arr, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}