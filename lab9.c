#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

struct node *first = NULL, *cur, *prev, *next;

void insertfront()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;

    printf("Enter the node to be inserted: \n");
    scanf("%d", &temp->info);

    if (first == NULL)
    {
        first = temp;
        return;
    }

    temp->rlink = first;
    first->llink = temp;
    first = temp;
}

void insertleft()
{
    int key;
    struct node *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;

    printf("Enter the key before which the node is to be inserted: \n");
    scanf("%d", &key);
    printf("Enter the node to be inserted: \n");
    scanf("%d", &temp->info);

    prev = NULL;
    cur = first;

    while (cur != NULL)
    {
        if (cur->info == key && cur == first)
        {
            temp->rlink = cur;
            cur->llink = temp;
            first = temp;
            return;
        }

        if (cur->info == key)
        {
            temp->rlink = cur;
            temp->llink = prev;
            cur->llink = temp;
            prev->rlink = temp;
            return;
        }

        prev = cur;
        cur = cur->rlink;
    }

    printf("Key not found.\n");
    free(temp);
}

void Delete1()
{
    int key;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the node to be deleted: \n");
    scanf("%d", &key);

    cur = first;

    while (cur != NULL)
    {
        if (cur->info == key)
        {
            if (cur == first)
            {
                first = first->rlink;
                if (first != NULL)
                {
                    first->llink = NULL;
                }
                printf("%d node is deleted.\n", key);
                free(cur);
                return;
            }

            if (cur->rlink == NULL)
            {
                prev = cur->llink;
                prev->rlink = NULL;
                printf("%d node is deleted.\n", key);
                free(cur);
                return;
            }

            prev = cur->llink;
            next = cur->rlink;
            prev->rlink = next;
            next->llink = prev;
            printf("%d node is deleted.\n", key);
            free(cur);
            return;
        }

        cur = cur->rlink;
    }

    printf("Key not found.\n");
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("List is: \n");
    cur = first;

    while (cur != NULL)
    {
        printf("%d\n", cur->info);
        cur = cur->rlink;
    }
}

int main()
{
    int ch;

    for (;;)
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert at front\n");
        printf("2. Insert before a node\n");
        printf("3. Delete a node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertfront();
            break;
        case 2:
            insertleft();
            break;
        case 3:
            Delete1();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
