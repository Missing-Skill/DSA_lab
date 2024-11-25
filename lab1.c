#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    int n, i, ch, searchid;
    struct employee emp[5];
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the employee id: ");
        scanf("%d", &emp[i].id);
        printf("Enter the employee name: ");
        scanf("%s", emp[i].name);
        printf("Enter the salary of the employee: ");
        scanf("%f", &emp[i].salary);
        printf("\n");
    }
    while (1) {
        printf("\n1. Display \t 2. Search \t 3. Exit \n");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            for (i = 0; i < n; i++) {
                printf("\nEmployee id: %d, Name: %s, Salary: Rs. %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
            }
            break;

        case 2:
            printf("Enter the id of the employee you want to search: ");
            scanf("%d", &searchid);
            for (i = 0; i < n; i++) {
                if (emp[i].id == searchid) {
                    printf("\nEmployee id: %d, Name: %s, Salary: Rs. %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
                    break;
                }
            }
            if (i == n) {
                printf("Employee not found.\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
