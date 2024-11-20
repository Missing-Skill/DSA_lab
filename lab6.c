#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

// Function to allocate memory for a new node
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

// Function to free a node
void freenode(NODE x)
{
    free(x);
}

// Function to insert an item at the front of the list
NODE insert_front(int item, NODE first)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

// Function to delete an item from the front of the list
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("The deleted item is %d\n", temp->info);
    freenode(temp);
    return first;
}

// Function to insert an item at the rear of the list
NODE insert_rear(int item, NODE first)
{
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

// Function to delete an item from the rear of the list
NODE delete_rear(NODE first)
{
    NODE cur = first, prev = NULL;
    if (cur == NULL)
    {
        printf("List is empty\n");
        return first;
    }
    if (cur->link == NULL) // If there is only one node
    {
        printf("The deleted item is %d\n", cur->info);
        freenode(cur);
        return NULL;
    }
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("The deleted item is %d\n", cur->info);
    freenode(cur);
    prev->link = NULL;
    return first;
}

// Function to display the list
void display(NODE first)
{
    NODE temp = first;
    if (first == NULL)
    {
        printf("No nodes in the list!!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

// Main function
int main()
{
    NODE first = NULL;
    int choice, item;

    for (;;)
    {
        printf("\n1. INSERT FRONT\n2. INSERT REAR\n3. DELETE FRONT\n4. DELETE REAR\n5. DISPLAY\n6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item: ");
            scanf("%d", &item);
            first = insert_front(item, first);
            break;
        case 2:
            printf("Enter the item: ");
            scanf("%d", &item);
            first = insert_rear(item, first);
            break;
        case 3:
            first = delete_front(first);
            break;
        case 4:
            first = delete_rear(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
