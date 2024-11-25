#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
int s[MAX_SIZE], top = -1;
void push()
{
    int x;
    if (top == MAX_SIZE - 1)
    {
        printf("stack overflow \n");
        return;
    }
    printf("enter the element: ");
    printf("\n");
    scanf("%d", &x);
    top++;
    s[top] = x;
}
void pop()
{
    if (top == -1)
    {
        printf("stack undeflow \n");
        return;
    }
    printf("pop elements is : %d", s[top]);
    top--;
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("stack is empty");
        return;
    }
    else
    {
        printf("elements of the arrays are!! \n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d", s[i]);
            printf(" ");
        }
    }
}

int main()
{
    int ch, x;
    for (;;)
    {
        printf("\n 1.Push \t 2. Pop \t 3. Display \t 4. Exit \n");
        printf("enter the choice: ");
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
        case 4:
            exit(0);
            break;
        }
    }
}
