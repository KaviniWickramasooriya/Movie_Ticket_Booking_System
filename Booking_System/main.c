#include <stdio.h>

#define NUM_HALLS 4
#define NUM_ROWS 10
#define NUM_SEATS_PER_ROW 10

// Implementation of the displaySeats function to show the current status of seats in each hall.

void displaySeats(int seats[NUM_HALLS][NUM_ROWS][NUM_SEATS_PER_ROW]) {
    printf("\nCurrent Seat Status:\n");

    for (int hall = 0; hall < NUM_HALLS; hall++)
    {
        printf("Hall %d:\n", hall + 1);
        for (int row = 0; row < NUM_ROWS; row++)
        {
            for (int seat = 0; seat < NUM_SEATS_PER_ROW; seat++)
            {
                if (seats[hall][row][seat] == 0)
                    printf("O ");   // Available seat
                else
                    printf("X ");   // Booked seat
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Implementation of the bookSeat function to book a seat.

int bookSeat(int seats[NUM_HALLS][NUM_ROWS][NUM_SEATS_PER_ROW], int hall, int row, int seat) {
    if (hall < 1 || hall > NUM_HALLS || row < 1 || row > NUM_ROWS || seat < 1 || seat > NUM_SEATS_PER_ROW)
        printf("\nInvalid seat selection.\n\n");    // Invalid input
    else if (seats[hall - 1][row - 1][seat - 1] == 0)
    {
        seats[hall - 1][row - 1][seat - 1] = 1;
        // Book the seat
        printf("\nSeat in Hall %d, Row %d, Seat %d.\n",hall,row,seat);
        printf("Seat booked successfully!\n\n");    // Booking successful
    } else
        printf("\nSorry, the seat is already booked.\n\n");   // Seat already booked
}

// main function

int main() {
    int seats[NUM_HALLS][NUM_ROWS][NUM_SEATS_PER_ROW] = {0};   // Initialize all seats as available
    int choice;
    int hall, row, seat;

    do {
        printf("-----------------------\n");
        printf("Movie Ticket Booking System\n");
        printf("-----------------------\n");

        printf("1. Show Seat Status\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");   //Take user input
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displaySeats(seats);    //Call to the displaySeats function
                break;
            case 2:
                printf("Enter Hall, Row, and Seat: ");   //Take user input
                scanf("%d %d %d", &hall, &row, &seat);

                bookSeat(seats, hall, row, seat);   //Call to the bookSeat function
                break;
            case 3:
                printf("\nThank you for using the ticket booking system...!\n");    //Exiting..
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");    //Invalid input
        }
    } while (choice != 3);     //Repeat the process until the user decides to exit the program.

    return 0;
}
