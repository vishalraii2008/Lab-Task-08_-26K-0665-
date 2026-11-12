#include <stdio.h>

void showRules(void)
{
    printf("===== TAXI FARE CALCULATOR =====\n");
    printf("Base fare: Rs. 150\n");
    printf("First 10 km: Rs. 60 per km\n");
    printf("After 10 km: Rs. 45 per km\n");
}

double getDistance(void)
{
    double d;
    do {
        printf("Enter distance in km (0-200]: ");
        scanf("%lf", &d);
    } while (d <= 0 || d > 200);
    return d;
}

int getWaiting(void)
{
    int w;
    do {
        printf("Enter waiting time in minutes (0-120): ");
        scanf("%d", &w);
    } while (w < 0 || w > 120);
    return w;
}

double distanceCharge(double km)
{
    double charge = 150;
    if (km <= 10)
        charge += km * 60;
    else
        charge += 10 * 60 + (km - 10) * 45;
    return charge;
}

double waitingCharge(int minutes)
{
    if (minutes <= 5)
        return 0;
    return (minutes - 5) * 10;
}

int getHour(void)
{
    int h;
    do {
        printf("Enter hour of the trip (0-23): ");
        scanf("%d", &h);
    } while (h < 0 || h > 23);
    return h;
}

double addNightCharge(double fare, int hour)
{
    if (hour >= 22 || hour < 6)
        return fare + fare * 0.25;
    return fare;
}

void printReceipt(double km, int wait, double fare)
{
    printf("\n------ TRIP RECEIPT ------\n");
    printf("Distance    : %.2f km\n", km);
    printf("Waiting Time: %d min\n", wait);
    printf("Final Fare  : Rs. %.2f\n", fare);
    printf("--------------------------\n\n");
}

int main()
{
    double total = 0, highest = 0;
    int i;
    for (i = 1; i <= 3; i++) {
        printf("\nTrip %d\n", i);
        showRules();
        double km = getDistance();
        int wait = getWaiting();
        int hour = getHour();
        double fare = distanceCharge(km) + waitingCharge(wait);
        fare = addNightCharge(fare, hour);
        printReceipt(km, wait, fare);
        total += fare;
        if (fare > highest)
            highest = fare;
    }
    printf("Total earnings : Rs. %.2f\n", total);
    printf("Highest fare   : Rs. %.2f\n", highest);
    return 0;
}
