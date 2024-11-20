#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 10
int insertion(int item, int a[], int n)
{
    int c, p;
    if (n == MAXSIZE)
    {
        printf(“HEAP IS FULL !!!\n”);
        return;
    }
    c = n;
    p = (c - 1) / 2;
    while (c != 0 && item > a[p])
    {
        a[c] = a[p];
        c = p;
        p = (c - 1) / 2;
    }
    a[c] = item;
    return n + 1;
}
void display(int a[], int n)
{
    int i;
    if (n == 0)
    {
        printf(“HEAP IS EMPTY !!!\n”);
        return;
    }
    printf(“The array elements are \n”);
    for (i = 0; i < n; i++)
        printf(“% d”, a[i]);
}
void main()
{
    int a[MAXSIZE], n = 0, ch, item;
    for (;;)
    {
        printf(“\n1.INSERT\n2.DISPLAY\nEXIT\n”);
        scanf(“% d”, &ch);
        switch (ch)
        {
        case 1:
            printf(“Enter the element”);
            scanf(“% d” & item);
            n = insertion(item, a, n);
            break;
        case 2:
            display(a, n);
            break;
        default:
            exit(0);
        }
    }
}