#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 30
int s[MAXSIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAXSIZE - 1;
}
void push(int item)
{
    if (!isFull())
    {
        s[++top] = item;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}
int pop()
{
    if (!isEmpty())
    {
        return s[top--];
    }
    else
    {
        printf("Stack Underflow\n");
        return 0; // Return 0 as default in case of underflow
    }
}

// Function to check if a character is a digit
int isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

int op(int op1, int op2, char symbol)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    default:
        printf("Invalid operator\n");
        return 0;
    }
}

// Main function
int main()
{
    char symbol, postfix[MAXSIZE];
    int a, b, res, i;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (isDigit(symbol))
        {
            push(symbol - '0'); // Convert character digit to integer
        }
        else
        {
            // Ensure there are enough operands on the stack
            if (top < 1)
            {
                printf("Error: Insufficient operands\n");
                return 1;
            }
            a = pop();
            b = pop();
            res = op(b, a, symbol);
            push(res);
        }
    }

    // Final result
    if (top == 0)
    {
        printf("The result of the expression is: %d\n", pop());
    }
    else
    {
        printf("Error: Invalid postfix expression\n");
    }

    return 0;
}
