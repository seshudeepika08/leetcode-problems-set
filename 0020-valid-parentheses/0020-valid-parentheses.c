#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);

    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        else {
            // Stack empty → invalid
            if (top == -1) {
                free(stack);
                return false;
            }

            char topChar = stack[top--];

            // Check matching
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);
    free(stack);
    return valid;
}