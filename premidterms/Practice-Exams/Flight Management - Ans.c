#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for Plane information
typedef struct {
    char model[50];
    int capacity;
    int max_range; // in miles
    int fuel_capacity; // in gallons
    char registration[20];
} Plane;

// Structure for Passenger information
typedef struct {
    char name[100];
    int age;
    char passport[20];
    char seat_number[5];
} Passenger;

// Structure for Flight information
typedef struct {
    char flight_number[10];
    char origin[50];
    char destination[50];
    char departure_time[6]; // HH:MM format
    char arrival_time[6];   // HH:MM format
    int duration;           // in minutes
    int distance;           // in miles
    Plane aircraft;
    Passenger *passengers;  // Array of passengers
    int passenger_count;
    int max_passengers;
} Flight;

// Function prototypes
Flight create_flight(const char* flight_number, const char* origin, const char* destination,
                     const char* departure, const char* arrival, int duration, int distance,
                     Plane aircraft, int max_passengers);
void add_passenger(Flight *flight, Passenger passenger);
void print_flight_info(Flight flight);
void print_passenger_list(Flight flight);
void free_flight_resources(Flight *flight);
int seats_available(Flight flight);

// Main function
int main() {
    // Create a sample plane
    Plane plane1 = {
        .model = "Boeing 737-800",
        .capacity = 162,
        .max_range = 3000,
        .fuel_capacity = 6875,
        .registration = "N12345"
    };

    // Create a flight
    Flight flight1 = create_flight("AA123", "JFK", "LAX", "08:00", "11:30", 210, 2475, plane1, plane1.capacity);

    // Create some passengers
    Passenger p1 = {"John Doe", 35, "P12345678", "12A"};
    Passenger p2 = {"Jane Smith", 28, "P87654321", "12B"};
    Passenger p3 = {"Bob Johnson", 42, "P56781234", "14C"};

    // Add passengers to the flight
    add_passenger(&flight1, p1);
    add_passenger(&flight1, p2);
    add_passenger(&flight1, p3);

    // Print flight information
    print_flight_info(flight1);

    // Print passenger list
    print_passenger_list(flight1);

    // Check available seats
    printf("\nAvailable seats: %d\n", seats_available(flight1));

    // Free allocated memory
    free_flight_resources(&flight1);

    return 0;
}

// Function to create a new flight
Flight create_flight(const char* flight_number, const char* origin, const char* destination,
                     const char* departure, const char* arrival, int duration, int distance,
                     Plane aircraft, int max_passengers) {
    Flight flight;

    strncpy(flight.flight_number, flight_number, sizeof(flight.flight_number) - 1);
    flight.flight_number[sizeof(flight.flight_number) - 1] = '\0';

    strncpy(flight.origin, origin, sizeof(flight.origin) - 1);
    flight.origin[sizeof(flight.origin) - 1] = '\0';

    strncpy(flight.destination, destination, sizeof(flight.destination) - 1);
    flight.destination[sizeof(flight.destination) - 1] = '\0';

    strncpy(flight.departure_time, departure, sizeof(flight.departure_time) - 1);
    flight.departure_time[sizeof(flight.departure_time) - 1] = '\0';

    strncpy(flight.arrival_time, arrival, sizeof(flight.arrival_time) - 1);
    flight.arrival_time[sizeof(flight.arrival_time) - 1] = '\0';

    flight.duration = duration;
    flight.distance = distance;
    flight.aircraft = aircraft;
    flight.max_passengers = max_passengers;
    flight.passenger_count = 0;

    flight.passengers = (Passenger*)malloc(sizeof(Passenger) * max_passengers);
    if (flight.passengers == NULL) {
        printf("Memory allocation failed for passengers.\n");
        exit(1);
    }

    return flight;
}

// Function to add a passenger to a flight
void add_passenger(Flight *flight, Passenger passenger) {
    if (flight->passenger_count >= flight->max_passengers) {
        printf("Cannot add more passengers. Flight is full.\n");
        return;
    }

    flight->passengers[flight->passenger_count] = passenger;
    flight->passenger_count++;
}

// Function to print flight information
void print_flight_info(Flight flight) {
    printf("\nFlight Information:\n");
    printf("------------------\n");
    printf("Flight No: %s\n", flight.flight_number);
    printf("Route: %s to %s\n", flight.origin, flight.destination);
    printf("Departure: %s, Arrival: %s (Duration: %d minutes)\n",
           flight.departure_time, flight.arrival_time, flight.duration);
    printf("Distance: %d miles\n", flight.distance);
    printf("Aircraft: %s (Registration: %s)\n", flight.aircraft.model, flight.aircraft.registration);
    printf("Capacity: %d/%d passengers\n", flight.passenger_count, flight.max_passengers);
}

// Function to print list of passengers
void print_passenger_list(Flight flight) {
    printf("\nPassenger List for Flight %s:\n", flight.flight_number);
    printf("----------------------------\n");
    for (int i = 0; i < flight.passenger_count; i++) {
        Passenger p = flight.passengers[i];
        printf("%d. %s (Passport: %s, Age: %d, Seat: %s)\n",
               i + 1, p.name, p.passport, p.age, p.seat_number);
    }
}

// Function to free allocated memory
void free_flight_resources(Flight *flight) {
    if (flight->passengers != NULL) {
        free(flight->passengers);
        flight->passengers = NULL;
    }
}

// Function to check available seats
int seats_available(Flight flight) {
    return flight.max_passengers - flight.passenger_count;
}
  
