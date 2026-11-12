#include <stdio.h>

void showPacks(void)
{
    printf("===== PREPAID RECHARGE =====\n");
    printf("1. Rs. 100\n");
    printf("2. Rs. 200\n");
    printf("3. Rs. 500\n");
    printf("4. Rs. 1000\n");
}

int getPackNumber(void)
{
    int p;
    do {
        printf("Enter pack number (1-4): ");
        scanf("%d", &p);
    } while (p < 1 || p > 4);
    return p;
}

long long getMobile(void)
{
    long long m;
    do {
        printf("Enter mobile number (11 digits): ");
        scanf("%lld", &m);
    } while (m < 1000000000LL || m > 99999999999LL);
    return m;
}

int getAmount(int pack)
{
    int amount;
    switch (pack) {
        case 1: amount = 100; break;
        case 2: amount = 200; break;
        case 3: amount = 500; break;
        case 4: amount = 1000; break;
        default: amount = 0;
    }
    return amount;
}

double calcTax(double amount)
{
    return amount * 0.15;
}

double calcBonus(double amount)
{
    if (amount >= 500)
        return amount * 0.10;
    return 0;
}

void printSlip(long long mobile, double amount, double tax, double balance)
{
    printf("\n------ RECHARGE SLIP ------\n");
    printf("Mobile Number : %lld\n", mobile);
    printf("Amount        : Rs. %.2f\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Total Balance : Rs. %.2f\n", balance);
    printf("---------------------------\n\n");
}

int main()
{
    double totalSpent = 0;
    int i;
    for (i = 1; i <= 3; i++) {
        printf("\nRecharge %d of 3\n", i);
        showPacks();
        int pack = getPackNumber();
        long long mobile = getMobile();
        double amount = getAmount(pack);
        double tax = calcTax(amount);
        double bonus = calcBonus(amount);
        double balance = amount + bonus;
        printSlip(mobile, amount, tax, balance);
        totalSpent += amount + tax;
    }
    printf("Total money spent: Rs. %.2f\n", totalSpent);
    return 0;
}
