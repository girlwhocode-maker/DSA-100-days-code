/*
Problem Statement:
Given n boards and k painters,
each painter paints contiguous boards.

Painting 1 unit length takes 1 unit time.

Find minimum time required to paint all boards.

Input Format:
n k
n space-separated integers (board lengths)

Output Format:
Minimum time required

Sample Input:
4 2
10 20 30 40

Sample Output:
60

Explanation:
Painter 1: 10 + 20 + 30 = 60
Painter 2: 40
*/

#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > maxTime)
            return 0;

        if (sum + arr[i] > maxTime) {
            painters++;
            sum = arr[i];

            if (painters > k)
                return 0;
        } else {
            sum += arr[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}