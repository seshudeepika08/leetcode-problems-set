#include <stdlib.h>
#include <string.h>

void backtrack(char** result, int* returnSize, char* current,
               int open, int close, int n) {
    
    // If valid combination formed
    if (strlen(current) == 2 * n) {
        result[*returnSize] = (char*)malloc((2 * n + 1));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    // Add '('
    if (open < n) {
        int len = strlen(current);
        current[len] = '(';
        current[len + 1] = '\0';

        backtrack(result, returnSize, current, open + 1, close, n);

        current[len] = '\0'; // backtrack
    }

    // Add ')'
    if (close < open) {
        int len = strlen(current);
        current[len] = ')';
        current[len + 1] = '\0';

        backtrack(result, returnSize, current, open, close + 1, n);

        current[len] = '\0'; // backtrack
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;

    // Max combinations for n=8 is 1430
    char** result = (char**)malloc(1500 * sizeof(char*));
    char current[20] = "";

    backtrack(result, returnSize, current, 0, 0, n);

    return result;
}