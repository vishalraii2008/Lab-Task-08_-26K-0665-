#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    do {
        printf("How many days of temperature to store (1-10): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    double *temp = (double *)malloc(n * sizeof(double));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        do {
            printf("Enter temperature for day %d (-10 to 55): ", i + 1);
            scanf("%lf", &temp[i]);
        } while (temp[i] < -10 || temp[i] > 55);
    }

    printf("\n");
    for (i = 0; i < n; i++)
        printf("Day %d: %.1f at address %p\n", i + 1, temp[i], (void *)&temp[i]);

    double *ptr = temp;
    double hottest = *ptr, coldest = *ptr;
    int hotDays = 0;
    for (i = 0; i < n; i++) {
        if (*ptr > hottest)
            hottest = *ptr;
        if (*ptr < coldest)
            coldest = *ptr;
        if (*ptr > 40)
            hotDays++;
        ptr++;
    }

    printf("\nHottest: %.1f\n", hottest);
    printf("Coldest: %.1f\n", coldest);
    printf("Days hotter than 40: %d\n", hotDays);

    free(temp);
    temp = NULL;
    printf("\nMemory has been released successfully.\n");
    return 0;
}
