#include <stdio.h>

int main()
{
    double costPrice, sellPrice, quantity;
    double totalCost, totalSales, profit, percent;
    double *pCost = &costPrice;
    double *pSell = &sellPrice;
    double *pQty = &quantity;
    double *pTotalCost = &totalCost;
    double *pTotalSales = &totalSales;
    double *pProfit = &profit;
    double *pPercent = &percent;

    printf("Enter cost price: ");
    scanf("%lf", pCost);
    printf("Enter selling price: ");
    scanf("%lf", pSell);
    printf("Enter quantity sold: ");
    scanf("%lf", pQty);

    *pTotalCost = *pCost * *pQty;
    *pTotalSales = *pSell * *pQty;
    *pProfit = *pTotalSales - *pTotalCost;

    if (*pProfit > 0)
        printf("\nProfit\n");
    else if (*pProfit < 0)
        printf("\nLoss\n");
    else
        printf("\nNo profit no loss\n");

    printf("Total Cost  : %.2f\n", *pTotalCost);
    printf("Total Sales : %.2f\n", *pTotalSales);
    printf("Profit/Loss : %.2f\n", *pProfit);

    if (*pTotalCost != 0)
        *pPercent = (*pProfit / *pTotalCost) * 100;
    else
        *pPercent = 0;
    printf("Profit Percentage: %.2f%%\n", *pPercent);

    double *pLarger;
    const char *name;
    if (*pCost > *pSell) {
        pLarger = pCost;
        name = "costPrice";
    } else {
        pLarger = pSell;
        name = "sellPrice";
    }
    printf("\nLarger pointer points to %s with value %.2f\n", name, *pLarger);

    printf("\n%-14s %-20s\n", "Name", "Address");
    printf("%-14s %p\n", "costPrice", (void *)&costPrice);
    printf("%-14s %p\n", "sellPrice", (void *)&sellPrice);
    printf("%-14s %p\n", "quantity", (void *)&quantity);
    printf("%-14s %p\n", "totalCost", (void *)&totalCost);
    printf("%-14s %p\n", "totalSales", (void *)&totalSales);
    printf("%-14s %p\n", "profit", (void *)&profit);
    printf("%-14s %p\n", "percent", (void *)&percent);
    printf("%-14s %p\n", "pCost", (void *)&pCost);
    printf("%-14s %p\n", "pSell", (void *)&pSell);
    printf("%-14s %p\n", "pQty", (void *)&pQty);
    printf("%-14s %p\n", "pTotalCost", (void *)&pTotalCost);
    printf("%-14s %p\n", "pTotalSales", (void *)&pTotalSales);
    printf("%-14s %p\n", "pProfit", (void *)&pProfit);
    printf("%-14s %p\n", "pPercent", (void *)&pPercent);
    printf("%-14s %p\n", "pLarger", (void *)&pLarger);
    return 0;
}
