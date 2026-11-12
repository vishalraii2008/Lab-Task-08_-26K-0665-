#include <stdio.h>
#include <string.h>

void readMarks(int *m1, int *m2, int *m3)
{
    do {
        printf("  Enter mark 1 (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);
    do {
        printf("  Enter mark 2 (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);
    do {
        printf("  Enter mark 3 (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest)
{
    *total = m1 + m2 + m3;
    *average = *total / 3.0;
    *highest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;
    *lowest = m1;
    if (m2 < *lowest) *lowest = m2;
    if (m3 < *lowest) *lowest = m3;
}

void swapMarks(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sortMarks(int *a, int *b, int *c)
{
    if (*a < *b) swapMarks(a, b);
    if (*b < *c) swapMarks(b, c);
    if (*a < *b) swapMarks(a, b);
}

void addGraceMarks(int *mark, int grace)
{
    int need;
    if (*mark >= 35 && *mark <= 39) {
        need = 40 - *mark;
        if (grace > 5)
            grace = 5;
        if (grace >= need)
            *mark += need;
    }
}

void findGrade(double avg, char *grade, char *remarks)
{
    if (avg >= 80) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    } else if (avg >= 50) {
        *grade = 'B';
        strcpy(remarks, "Good");
    } else {
        *grade = 'C';
        strcpy(remarks, "Needs Improvement");
    }
}

void incrementByValue(int x)
{
    x++;
}

void incrementByReference(int *x)
{
    (*x)++;
}

int main()
{
    int m1, m2, m3, total, highest, lowest, i;
    double average;
    char grade;
    char remarks[30];
    int totals[5];
    double averages[5];
    char grades[5];
    char allRemarks[5][30];

    for (i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);
        readMarks(&m1, &m2, &m3);
        addGraceMarks(&m1, 5);
        addGraceMarks(&m2, 5);
        addGraceMarks(&m3, 5);
        sortMarks(&m1, &m2, &m3);
        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);
        findGrade(average, &grade, remarks);
        printf("  Sorted marks: %d %d %d | Highest: %d | Lowest: %d\n", m1, m2, m3, highest, lowest);
        totals[i] = total;
        averages[i] = average;
        grades[i] = grade;
        strcpy(allRemarks[i], remarks);
    }

    printf("\n%-8s %-8s %-10s %-7s %s\n", "Student", "Total", "Average", "Grade", "Remarks");
    for (i = 0; i < 5; i++)
        printf("%-8d %-8d %-10.2f %-7c %s\n", i + 1, totals[i], averages[i], grades[i], allRemarks[i]);

    int num = 10;
    incrementByValue(num);
    printf("\nAfter incrementByValue: %d\n", num);
    incrementByReference(&num);
    printf("After incrementByReference: %d\n", num);
    printf("By value changes only a copy of the variable, so the original stays the same.\n");
    printf("By reference uses the address of the variable, so the original value is changed.\n");
    return 0;
}
