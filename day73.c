/*
Problem Statement:
Given a string s consisting of lowercase English letters,
find and return the first character that does not repeat.

If all characters repeat, return '$'.

Input Format:
A single string s.

Output Format:
Print the first non-repeating character
or '$' if none exists.

Sample Input:
geeksforgeeks

Sample Output:
f

Explanation:
'f' occurs only once and appears before
any other non-repeating character.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    int n = strlen(s);

    // count frequency
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // find first non-repeating
    for (int i = 0; i < n; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("$\n");

    return 0;
}