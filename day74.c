/*
Problem Statement:
Given an array of candidate names where each name
represents a vote cast for that candidate, determine
the candidate who received the maximum number of votes.

In case of a tie, return the lexicographically smallest
candidate name.

Input Format:
First line contains integer n (number of votes).
Second line contains n space-separated strings
(candidates names).

Output Format:
Print winner name followed by number of votes.

Sample Input:
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output:
john 4

Explanation:
john and johnny both have 4 votes, but john is
lexicographically smaller, so john wins.
*/

#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[50];
    int count;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Candidate arr[1000];
    int size = 0;

    char name[50];

    for (int i = 0; i < n; i++) {
        scanf("%s", name);

        int found = 0;

        for (int j = 0; j < size; j++) {
            if (strcmp(arr[j].name, name) == 0) {
                arr[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(arr[size].name, name);
            arr[size].count = 1;
            size++;
        }
    }

    int maxVotes = 0;
    char winner[50] = "";

    for (int i = 0; i < size; i++) {
        if (arr[i].count > maxVotes) {
            maxVotes = arr[i].count;
            strcpy(winner, arr[i].name);
        }
        else if (arr[i].count == maxVotes) {
            if (strcmp(arr[i].name, winner) < 0) {
                strcpy(winner, arr[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}