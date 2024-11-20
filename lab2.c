#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2
int s[MAX_SIZE], top = -1;
void push()
{
    int x;
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    top = top + 1;
    s[top] = x;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element is %d", s[top]);
    top = top - 1;
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    else
    {
        printf("Contents of the stack: \n");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", s[i]);
        }
    }
}
int main()
{
    int ch, x;
    for (;;)
    {
        printf("1.Push 2.Pop 3.Display");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}