#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    
    // Edge case
    if (numRows == 1 || numRows >= len) {
        return s;
    }

    // Allocate memory for rows
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* colSize = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int currRow = 0;
    int direction = 1; // 1 = down, -1 = up

    for (int i = 0; i < len; i++) {
        rows[currRow][colSize[currRow]++] = s[i];

        if (currRow == 0) direction = 1;
        else if (currRow == numRows - 1) direction = -1;

        currRow += direction;
    }

    // Build result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < colSize[i]; j++) {
            result[pos++] = rows[i][j];
        }
    }

    result[pos] = '\0';

    // Free memory
    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);
    free(colSize);

    return result;
}