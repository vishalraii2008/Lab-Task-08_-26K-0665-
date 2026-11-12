#include <stdio.h>

void showRooms(void)
{
    printf("===== CITY HOSPITAL =====\n");
    printf("1. General Ward  - Rs. 1500/day\n");
    printf("2. Semi-Private  - Rs. 3500/day\n");
    printf("3. Private       - Rs. 6000/day\n");
}

int getRoomType(void)
{
    int r;
    do {
        printf("Enter room type (1-3): ");
        scanf("%d", &r);
    } while (r < 1 || r > 3);
    return r;
}

int getDays(void)
{
    int d;
    do {
        printf("Enter number of days (1-30): ");
        scanf("%d", &d);
    } while (d < 1 || d > 30);
    return d;
}

double roomCharges(int type, int days)
{
    double rate;
    if (type == 1)
        rate = 1500;
    else if (type == 2)
        rate = 3500;
    else
        rate = 6000;
    return rate * days;
}

double medicineCharge(double bill)
{
    return bill + bill * 0.05;
}

double applyDiscount(double total, int days)
{
    if (days >= 7)
        return total - total * 0.08;
    return total;
}

const char *roomName(int type)
{
    if (type == 1)
        return "General Ward";
    if (type == 2)
        return "Semi-Private";
    return "Private";
}

void printBill(const char *room, int days, double roomCost, double medCost, double finalAmount)
{
    printf("\n------ FINAL BILL ------\n");
    printf("Room            : %s\n", room);
    printf("Days            : %d\n", days);
    printf("Room Charges    : Rs. %.2f\n", roomCost);
    printf("Medicine Charges: Rs. %.2f\n", medCost);
    printf("Final Amount    : Rs. %.2f\n", finalAmount);
    printf("------------------------\n");
}

int main()
{
    showRooms();
    int type = getRoomType();
    int days = getDays();
    double medBill;
    do {
        printf("Enter medicine bill: ");
        scanf("%lf", &medBill);
    } while (medBill < 0);

    double roomCost = roomCharges(type, days);
    double medCost = medicineCharge(medBill);
    double finalAmount = applyDiscount(roomCost + medCost, days);

    char senior;
    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);
    if (senior == 'y' || senior == 'Y') {
        finalAmount -= 1000;
        if (finalAmount < 0)
            finalAmount = 0;
    }

    printBill(roomName(type), days, roomCost, medCost, finalAmount);
    return 0;
}
