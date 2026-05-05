/*
Problem Statement:
Implement a hash table using quadratic probing:

h(k, i) = (h(k) + i*i) % m

Input Format:
- First line: m (table size)
- Second line: n (number of operations)
- Next n lines: operations (INSERT x / SEARCH x)

Output Format:
- Print result of SEARCH operations:
  FOUND / NOT FOUND

Sample Input:
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output:
FOUND
NOT FOUND

Explanation:
Collisions resolved using i^2 jumps.
*/

#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int hash(int key, int m) {
    return key % m;
}

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int table[m];

    // initialize hash table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            int h = hash(key, m);

            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m;

                if (table[idx] == EMPTY || table[idx] == DELETED) {
                    table[idx] = key;
                    break;
                }
            }
        }

        else if (strcmp(op, "SEARCH") == 0) {
            int h = hash(key, m);
            int found = 0;

            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m;

                if (table[idx] == EMPTY) {
                    break; // stop early
                }

                if (table[idx] == key) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}