/*
Problem Statement:
Given n books with pages and m students,
allocate books such that:
- each student gets at least one book
- books are allocated in contiguous order
- minimize the maximum pages assigned to a student

Input Format:
n m
n space-separated integers (pages)

Output Format:
Minimum possible maximum pages

Sample Input:
4 2
12 34 67 90

Sample Output:
113

Explanation:
Student1: 12+34+67 = 113
Student2: 90
Max = 113 (minimum possible)
*/

#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];

            if (students > m)
                return 0;
        } else {
            sum += arr[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int total = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    int low = max, high = total;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}