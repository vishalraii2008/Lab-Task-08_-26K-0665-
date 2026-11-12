#include <stdio.h>

void showRoutes(void)
{
    printf("===== BUS TICKET BOOKING =====\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}

int getRoute(void)
{
    int r;
    do {
        printf("Enter route number (1-3): ");
        scanf("%d", &r);
    } while (r < 1 || r > 3);
    return r;
}

int getSeats(void)
{
    int s;
    do {
        printf("Enter number of seats (1-6): ");
        scanf("%d", &s);
    } while (s < 1 || s > 6);
    return s;
}

double seatFare(int route)
{
    if (route == 1)
        return 800;
    if (route == 2)
        return 2200;
    return 3500;
}

double totalFare(double fare, int seats)
{
    return fare * seats;
}

double addSeatCharge(double total, char type)
{
    if (type == 'B')
        return total + total * 0.30;
    return total;
}

const char *routeName(int route)
{
    if (route == 1)
        return "Karachi to Hyderabad";
    if (route == 2)
        return "Karachi to Sukkur";
    return "Karachi to Multan";
}

void printTicket(const char *route, int seats, char type, double fare)
{
    printf("\n------ BUS TICKET ------\n");
    printf("Route     : %s\n", route);
    printf("Seats     : %d\n", seats);
    printf("Seat Type : %s\n", type == 'B' ? "Business" : "Economy");
    printf("Final Fare: Rs. %.2f\n", fare);
    printf("------------------------\n\n");
}

int main()
{
    double earnings = 0;
    int i;
    for (i = 1; i <= 2; i++) {
        printf("\nPassenger %d\n", i);
        showRoutes();
        int route = getRoute();
        int seats = getSeats();
        char type;
        do {
            printf("Seat type - Economy (E) or Business (B): ");
            scanf(" %c", &type);
            if (type == 'e') type = 'E';
            if (type == 'b') type = 'B';
        } while (type != 'E' && type != 'B');

        double fare = seatFare(route);
        double total = totalFare(fare, seats);
        double finalFare = addSeatCharge(total, type);
        printTicket(routeName(route), seats, type, finalFare);
        earnings += finalFare;
    }
    printf("Total earnings of the bus company: Rs. %.2f\n", earnings);
    return 0;
}
