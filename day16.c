#include <stdio.h>

/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count
*/

int main() {
    int n;
    scanf("%d", &n);

    int a[100], visited[100] = {0};

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        if(visited[i] == 1)
            continue;

        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}