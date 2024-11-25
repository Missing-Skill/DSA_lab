#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top = -1;
char stack[40];

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int prior(char x) {
    if (x == '(' || x == '#') return 1;
    if (x == '+' || x == '-') return 2;
    if (x == '*' || x == '/') return 3;
    if (x == '^' || x == '$') return 4;
    return 0; 
}

int main() {
    char infix[30], postfix[30];
    int i, j = 0;

    printf("Enter the infix expression:\n");
    if (!fgets(infix, sizeof(infix), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }
    size_t len = strlen(infix);
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    push('#'); 

    for (i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i])) { 
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else { 
            while (prior(stack[top]) >= prior(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (stack[top] != '#') { 
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 

    printf("The postfix expression is:\n%s\n", postfix);

    return 0;
}
