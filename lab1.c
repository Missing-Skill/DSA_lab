#include <stdio.h>
#include <stdlib.h>
struct employee
{
    int id;
    char name[20];
    float salary;
};
void main()
{
    int i, n, ch, searchid;
    struct employee emp[5];
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    printf("Enter %d employee details: \n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter employee id: ");
        scanf("%d", &emp[i].id);
        printf("Enter employee name: ");
        scanf("%s", emp[i].name);
        printf("Enter employee salary: ");
        scanf("%f", &emp[i].salary);
    }
    while (1)
    {
printf("\n1. Display 2. Search 3. Exit ");
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
    case 1:
        for (i = 0; i < n; i++)
        {
            printf("\nEmployee id: %d, Name: %s, Salary: Rs.%f", emp[i].id, emp[i].name,
                   emp[i].salary);
        }
        break;
    case 2:
        printf("Enter Employee ID to be searched:");
        scanf("%d", &searchid);
        for (i = 0; i < n; i++)
        {
            if (emp[i].id == searchid)
            {
                printf("\nEmployee id: %d, Name: %s, Salary: Rs.%f", emp[i].id,
                       emp[i].name, emp[i].salary);
                break;
            }
        }
        if (i == n)
            break;
    case 3:
        exit(0);
        printf("Employee ID not found");
}
    }
}