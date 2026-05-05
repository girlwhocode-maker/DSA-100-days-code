/*
Problem Statement:
Given a string s consisting of lowercase letters,
find the first repeated character in the string.

A character is considered repeated if it appears
more than once, and among all such characters,
the one whose second occurrence has the smallest index
should be returned.

Input Format:
A single string s.

Output Format:
Print the first repeated character.
If no character is repeated, print -1.

Sample Input:
geeksforgeeks

Sample Output:
e
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int index[26];

    // initialize with -1
    for (int i = 0; i < 26; i++) {
        index[i] = -1;
    }

    int minSecondIndex = 100000;
    char result = '\0';

    for (int i = 0; i < strlen(s); i++) {
        int pos = s[i] - 'a';

        if (index[pos] == -1) {
            index[pos] = i;
        }
        else {
            // repeated character found
            if (i < minSecondIndex) {
                minSecondIndex = i;
                result = s[i];
            }
        }
    }

    if (result == '\0')
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}