/*
Problem:
Find the integer square root of a given non-negative integer
using Binary Search.

Integer square root = greatest integer whose square
is <= n.

Input:
- First line: integer n

Output:
- Print integer square root of n

Examples:
Input:
64
Output:
8

Input:
20
Output:
4

Input:
1
Output:
1

Explanation:
Binary search on range [0, n].
Check mid*mid with n and adjust search space.
*/

#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        }
        else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}