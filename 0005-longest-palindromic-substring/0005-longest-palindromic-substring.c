#include <string.h>

void expand(char* s, int left, int right, int* start, int* maxLen) {
    int n = strlen(s);

    while (left >= 0 && right < n && s[left] == s[right]) {
        if (right - left + 1 > *maxLen) {
            *start = left;
            *maxLen = right - left + 1;
        }
        left--;
        right++;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 2) return s;

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        expand(s, i, i, &start, &maxLen);     // odd length
        expand(s, i, i + 1, &start, &maxLen); // even length
    }

    s[start + maxLen] = '\0';  // truncate
    return s + start;
}