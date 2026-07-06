#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 50
#define MAX_NAME 100
#define MAX_BOOKINGS 200

typedef struct {
    int eventId;
    char name[MAX_NAME];
    char location[MAX_NAME];
    int totalSeats;
    int seatsAvailable;
} Event;

typedef struct {
    int bookingId;
    int eventId;
    char customerName[MAX_NAME];
    int tickets;
} Booking;

static Event events[MAX_EVENTS];
static Booking bookings[MAX_BOOKINGS];
static int eventCount = 0;
static int bookingCount = 0;
static int nextEventId = 1;
static int nextBookingId = 1;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

void trimNewline(char *text) {
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

void readLine(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    trimNewline(buffer);
}

int findEventIndexById(int id) {
    for (int i = 0; i < eventCount; i++) {
        if (events[i].eventId == id) {
            return i;
        }
    }
    return -1;
}

int findBookingIndexById(int id) {
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == id) {
            return i;
        }
    }
    return -1;
}

void addEvent(void) {
    if (eventCount >= MAX_EVENTS) {
        printf("Maximum number of events reached.\n");
        return;
    }

    Event newEvent;
    newEvent.eventId = nextEventId++;

    printf("Enter event name: ");
    readLine(newEvent.name, MAX_NAME);
    if (strlen(newEvent.name) == 0) {
        printf("Event name cannot be empty.\n");
        return;
    }

    printf("Enter event location: ");
    readLine(newEvent.location, MAX_NAME);
    if (strlen(newEvent.location) == 0) {
        printf("Event location cannot be empty.\n");
        return;
    }

    printf("Enter total seats: ");
    if (scanf("%d", &newEvent.totalSeats) != 1 || newEvent.totalSeats <= 0) {
        printf("Invalid seat count.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    newEvent.seatsAvailable = newEvent.totalSeats;
    events[eventCount++] = newEvent;
    printf("Event added successfully with ID %d.\n", newEvent.eventId);
}

void displayEvent(const Event *event) {
    printf("Event ID: %d\n", event->eventId);
    printf("Name: %s\n", event->name);
    printf("Location: %s\n", event->location);
    printf("Total seats: %d\n", event->totalSeats);
    printf("Seats available: %d\n", event->seatsAvailable);
    printf("----------------------------------------\n");
}

void displayAllEvents(void) {
    if (eventCount == 0) {
        printf("No events available.\n");
        return;
    }

    printf("Available events:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < eventCount; i++) {
        displayEvent(&events[i]);
    }
}

void bookTickets(void) {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("Maximum number of bookings reached.\n");
        return;
    }

    int eventId;
    printf("Enter event ID to book: ");
    if (scanf("%d", &eventId) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    int eventIdx = findEventIndexById(eventId);
    if (eventIdx == -1) {
        printf("Event with ID %d not found.\n", eventId);
        clearInputBuffer();
        return;
    }

    int tickets;
    printf("Enter number of tickets: ");
    if (scanf("%d", &tickets) != 1 || tickets <= 0) {
        printf("Invalid ticket count.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    if (tickets > events[eventIdx].seatsAvailable) {
        printf("Not enough seats available. Only %d left.\n", events[eventIdx].seatsAvailable);
        return;
    }

    Booking newBooking;
    newBooking.bookingId = nextBookingId++;
    newBooking.eventId = eventId;
    newBooking.tickets = tickets;

    printf("Enter customer name: ");
    readLine(newBooking.customerName, MAX_NAME);
    if (strlen(newBooking.customerName) == 0) {
        printf("Customer name cannot be empty. Booking not created.\n");
        return;
    }

    events[eventIdx].seatsAvailable -= tickets;
    bookings[bookingCount++] = newBooking;
    printf("Booking created successfully with Booking ID %d.\n", newBooking.bookingId);
}

void displayBooking(const Booking *booking) {
    printf("Booking ID: %d\n", booking->bookingId);
    printf("Event ID: %d\n", booking->eventId);
    printf("Customer: %s\n", booking->customerName);
    printf("Tickets: %d\n", booking->tickets);
    printf("----------------------------------------\n");
}

void displayAllBookings(void) {
    if (bookingCount == 0) {
        printf("No bookings found.\n");
        return;
    }

    printf("Current bookings:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < bookingCount; i++) {
        displayBooking(&bookings[i]);
    }
}

void cancelBooking(void) {
    int bookingId;
    printf("Enter booking ID to cancel: ");
    if (scanf("%d", &bookingId) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int bookingIdx = findBookingIndexById(bookingId);
    if (bookingIdx == -1) {
        printf("Booking with ID %d not found.\n", bookingId);
        return;
    }

    int eventIdx = findEventIndexById(bookings[bookingIdx].eventId);
    if (eventIdx != -1) {
        events[eventIdx].seatsAvailable += bookings[bookingIdx].tickets;
    }

    for (int i = bookingIdx; i < bookingCount - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    bookingCount--;
    printf("Booking %d has been canceled.\n", bookingId);
}

void showMenu(void) {
    printf("\nTicket Booking System\n");
    printf("1. Add event\n");
    printf("2. Display all events\n");
    printf("3. Book tickets\n");
    printf("4. Display all bookings\n");
    printf("5. Cancel booking\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main(void) {
    int option;

    while (1) {
        showMenu();
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number from 1 to 6.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (option) {
            case 1:
                addEvent();
                break;
            case 2:
                displayAllEvents();
                break;
            case 3:
                bookTickets();
                break;
            case 4:
                displayAllBookings();
                break;
            case 5:
                cancelBooking();
                break;
            case 6:
                printf("Exiting ticket booking system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose between 1 and 6.\n");
                break;
        }
    }

    return 0;
}
