#include <stdio.h>

int findMax(int *p, int n)
{
    int max = *p, i;
    for (i = 1; i < n; i++)
        if (*(p + i) > max)
            max = *(p + i);
    return max;
}

int findMin(int *p, int n)
{
    int min = *p, i;
    for (i = 1; i < n; i++)
        if (*(p + i) < min)
            min = *(p + i);
    return min;
}

double findAverage(int *p, int n)
{
    int sum = 0, i;
    for (i = 0; i < n; i++)
        sum += *(p + i);
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg)
{
    int count = 0, i;
    for (i = 0; i < n; i++)
        if (*(p + i) > avg)
            count++;
    return count;
}

void reverseArray(int *p, int n)
{
    int *start = p;
    int *end = p + n - 1;
    int t;
    while (start < end) {
        t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (*(p + i) == key)
            return i;
    return -1;
}

void printArray(int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(p + i));
    printf("\n");
}

int countPass(int *p, int n)
{
    int count = 0, i;
    for (i = 0; i < n; i++)
        if (*(p + i) >= 40)
            count++;
    return count;
}

int main()
{
    int marks[10], i, key, pos;
    for (i = 0; i < 10; i++) {
        do {
            printf("Enter marks of student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);
        } while (marks[i] < 0 || marks[i] > 100);
    }

    double avg = findAverage(marks, 10);
    printf("\nHighest mark: %d\n", findMax(marks, 10));
    printf("Lowest mark: %d\n", findMin(marks, 10));
    printf("Average: %.2f\n", avg);
    printf("Students above average: %d\n", countAbove(marks, 10, avg));
    printf("Students passed (40 or more): %d\n", countPass(marks, 10));

    printf("\nEnter a mark to search: ");
    scanf("%d", &key);
    pos = searchMark(marks, 10, key);
    if (pos == -1)
        printf("Mark not found\n");
    else
        printf("Mark found at position %d (roll number %d)\n", pos, pos + 1);

    printf("\nBefore reversing: ");
    printArray(marks, 10);
    reverseArray(marks, 10);
    printf("After reversing : ");
    printArray(marks, 10);
    return 0;
}
