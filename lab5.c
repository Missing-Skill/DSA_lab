#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

int f = -1, r = -1, q[MAXSIZE];

void insert()
{
    int item;
    if (r == MAXSIZE - 1)
    {
        printf("OVERFLOW!!!\n");
    }
    else
    {
        if (f == -1)
            f = 0;
        printf("Enter the item to be inserted:\n");
        scanf("%d", &item);
        q[++r] = item;
    }
}

void delete1()
{
    if (f == -1)
    {
        printf("UNDERFLOW!!!\n");
    }
    else if (f > r)
    {
        f = r = -1;
        printf("UNDERFLOW!!!\n");
    }
    else
    {
        printf("Item deleted = %d\n", q[f++]);
    }
}

void display()
{
    int i;
    if (f == -1)
    {
        printf("UNDERFLOW!!!\n");
    }
    else
    {
        printf("The elements are: \n");
        for (i = f; i <= r; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    for (;;)
    {
        printf("\n1: INSERT\n2: DELETE\n3: DISPLAY\n4: EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("INSERTION\n");
            insert();
            break;
        case 2:
            printf("DELETION\n");
            delete1();
            break;
        case 3:
            printf("DISPLAY\n");
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
