#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top = -1;
char stack[40];

void push(char x)
{
    stack[++top] = x; 
}

char pop()
{
    return stack[top--];
}
int prior(char x)
{
    if (x == '(' || x == '#')
    {
        return 1;
    }
    if (x == '+' || x == '-')
    {
        return 2;
    }
    if (x == '/' || x == '*')
    {
        return 3;
    }
    if (x == '^' || x == '$')
    {
        return 4;
    }
    return 0;
}

int main()
{
    char infix[30], postfix[30];
    int i, j = 0;
    printf("enter the infix expression: \n");
    gets(infix);
    push('#');
    for (int i = 0; i < strlen(infix); i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
                
            }
            pop();
        }
        else
        {
            while (prior(stack[top]) >= prior(infix[i]))
            {
                postfix[j++] = pop();
                
            }
            push(infix[i]);
        }
    }
    while (stack[top] != '#')
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("the postfix expression is : \n");
    puts(postfix);
}
