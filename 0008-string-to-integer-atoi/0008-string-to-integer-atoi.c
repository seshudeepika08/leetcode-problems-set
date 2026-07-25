#include <limits.h>
#include <ctype.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // 1. Skip whitespace
    while (s[i] == ' ') {
        i++;
    }

    // 2. Handle sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. Convert digits
    while (isdigit(s[i])) {
        int digit = s[i] - '0';

        // 4. Check overflow
        if (result > INT_MAX / 10 || 
           (result == INT_MAX / 10 && digit > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    // 5. Apply sign
    return result * sign;
}