#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 30
int s[MAXSIZE];
int top = -1;

int pop()
{
    if (top != -1)
        return s[top--];
    else
    {
        printf("Stack underflow\n");
        return 0;
    }
}

void push(int item)
{
    if (top != MAXSIZE - 1)
    {
        s[++top] = item;
    }
    else
    {
        printf("\nStack Overflow\n");
    }
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
        if (op2 != 0)
            return op1 / op2;
        else
        {
            printf("Division by zero error\n");
            return 0;
        }
    default:
        printf("Invalid operator\n");
        return 0;
    }
}

int isdig(char symbol1)
{
    return (symbol1 >= '0' && symbol1 <= '9');
}

int main()
{
    char symbol, postfix[100];
    int a, b, res, i;

    printf("Enter postfix expression\n");
    fgets(postfix, sizeof(postfix), stdin);

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (symbol == ' ' || symbol == '\n')
        {
            continue;
        }
        else if (isdig(symbol))
        {
            push(symbol - '0');
        }
        else
        {
            a = pop();
            b = pop();
            res = op(b, a, symbol);
            push(res);
        }
    }

    printf("The result of the expression is: ");
    printf("%d\n", pop());
    return 0;
}