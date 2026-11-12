#include <stdio.h>
#include <stdlib.h>

void display(int *a, int n)
{
    int i;
    printf("\nStock:\n");
    for (i = 0; i < n; i++)
        printf("Item %d: %d\n", i + 1, *(a + i));
}

void report(int *a, int n)
{
    int total = 0, i;
    int *lowest;
    if (n == 0) {
        printf("Total stock: 0\nNo items in stock\n");
        return;
    }
    lowest = a;
    for (i = 0; i < n; i++) {
        total += *(a + i);
        if (*(a + i) < *lowest)
            lowest = a + i;
    }
    printf("Total stock: %d\n", total);
    printf("Lowest stock: item %d with %d\n", (int)(lowest - a) + 1, *lowest);
}

void sortStock(int *a, int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (*(a + j) > *(a + j + 1)) {
                t = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = t;
            }
}

int main()
{
    int n, i, choice, pos, val;
    int *stock, *temp;

    do {
        printf("Enter starting size (3-8): ");
        scanf("%d", &n);
    } while (n < 3 || n > 8);

    stock = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        printf("Enter stock of item %d: ", i + 1);
        scanf("%d", stock + i);
    }

    do {
        printf("\n1. Display stock\n");
        printf("2. Update stock of one item\n");
        printf("3. Insert a new item\n");
        printf("4. Delete an item\n");
        printf("5. Sort stock\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(stock, n);
                break;
            case 2:
                printf("Enter position (1-%d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position\n");
                    break;
                }
                printf("Enter new value: ");
                scanf("%d", &val);
                *(stock + pos - 1) = val;
                report(stock, n);
                break;
            case 3:
                printf("Enter position to insert (1-%d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position\n");
                    break;
                }
                printf("Enter stock value: ");
                scanf("%d", &val);
                temp = (int *)malloc((n + 1) * sizeof(int));
                for (i = 0; i < pos - 1; i++)
                    *(temp + i) = *(stock + i);
                *(temp + pos - 1) = val;
                for (i = pos - 1; i < n; i++)
                    *(temp + i + 1) = *(stock + i);
                free(stock);
                stock = temp;
                n++;
                report(stock, n);
                break;
            case 4:
                if (n == 0) {
                    printf("No items to delete\n");
                    break;
                }
                printf("Enter position to delete (1-%d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position\n");
                    break;
                }
                temp = (int *)malloc((n - 1 > 0 ? n - 1 : 1) * sizeof(int));
                for (i = 0; i < pos - 1; i++)
                    *(temp + i) = *(stock + i);
                for (i = pos; i < n; i++)
                    *(temp + i - 1) = *(stock + i);
                free(stock);
                stock = temp;
                n--;
                report(stock, n);
                break;
            case 5:
                sortStock(stock, n);
                display(stock, n);
                report(stock, n);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    free(stock);
    stock = NULL;
    printf("Memory released. Goodbye.\n");
    return 0;
}
