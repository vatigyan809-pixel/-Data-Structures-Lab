
#include <stdbool.h>
#include <string.h>

// LeetCode provides the function signature
bool isValid(char* s) {
    int n = strlen(s);
    char stack[n + 1];
    int top = -1;
    int i;

    // Traverse every character in the string
    for (i = 0; i < n; i++) {
        char ch = s[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }

        // Check closing brackets
        else {
            // No opening bracket is available
            if (top == -1) {
                return false;
            }

            char open = stack[top--];

            // Check whether brackets match
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                return false;
            }
        }
    }

    // Valid only when no opening brackets remain
    return top == -1;
}
