#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESTINATIONS 10
#define MAX_ACTIVITIES 5
#define MAX_ACCOMMODATIONS 5
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    char activities[MAX_ACTIVITIES][MAX_LENGTH];
    char accommodations[MAX_ACCOMMODATIONS][MAX_LENGTH];
    char weather[MAX_LENGTH];
} Destination;

Destination destinations[MAX_DESTINATIONS];
int destinationCount = 0;

void initDestinations() {
    strcpy(destinations[0].name, "Paris");
    strcpy(destinations[0].weather, "Sunny, 22°C");
    strcpy(destinations[0].activities[0], "Visit the Eiffel Tower");
    strcpy(destinations[0].activities[1], "Louvre Museum tour");
    strcpy(destinations[0].accommodations[0], "Hotel Le Meurice");
    strcpy(destinations[0].accommodations[1], "The Ritz Paris");
    
    strcpy(destinations[1].name, "Tokyo");
    strcpy(destinations[1].weather, "Cloudy, 18°C");
    strcpy(destinations[1].activities[0], "Explore Shibuya");
    strcpy(destinations[1].activities[1], "Visit Senso-ji Temple");
    strcpy(destinations[1].accommodations[0], "Park Hyatt Tokyo");
    strcpy(destinations[1].accommodations[1], "The Peninsula Tokyo");
    
    destinationCount = 2; // Add more destinations as needed
}

void recommendDestinations(char *interest) {
    printf("Recommended Destinations:\n");
    for (int i = 0; i < destinationCount; i++) {
        printf("- %s\n", destinations[i].name);
    }
}

void showWeather(char *destination) {
    for (int i = 0; i < destinationCount; i++) {
        if (strcmp(destinations[i].name, destination) == 0) {
            printf("Weather in %s: %s\n", destination, destinations[i].weather);
            return;
        }
    }
    printf("Weather information not available for %s.\n", destination);
}

void generateItinerary(char *destination) {
    for (int i = 0; i < destinationCount; i++) {
        if (strcmp(destinations[i].name, destination) == 0) {
            printf("Itinerary for %s:\n", destination);
            for (int j = 0; j < MAX_ACTIVITIES && strlen(destinations[i].activities[j]) > 0; j++) {
                printf("- %s\n", destinations[i].activities[j]);
            }
            return;
        }
    }
    printf("Itinerary information not available for %s.\n", destination);
}

void suggestAccommodations(char *destination) {
    for (int i = 0; i < destinationCount; i++) {
        if (strcmp(destinations[i].name, destination) == 0) {
            printf("Recommended Accommodations in %s:\n", destination);
            for (int j = 0; j < MAX_ACCOMMODATIONS && strlen(destinations[i].accommodations[j]) > 0; j++) {
                printf("- %s\n", destinations[i].accommodations[j]);
            }
            return;
        }
    }
    printf("Accommodation suggestions not available for %s.\n", destination);
}

int main() {
    char command[50];
    char interest[MAX_LENGTH];
    char destination[MAX_LENGTH];

    initDestinations();

    printf("Welcome to your travel chatbot! How can I assist you today?\n");

    while (1) {
        printf("\nEnter a command (recommend, weather, itinerary, accommodations, exit): ");
        scanf("%s", command);

        if (strcmp(command, "recommend") == 0) {
            printf("What are your interests (e.g., culture, adventure, relaxation)? ");
            scanf("%s", interest);
            recommendDestinations(interest);
        } else if (strcmp(command, "weather") == 0) {
            printf("Enter the destination: ");
            scanf("%s", destination);
            showWeather(destination);
        } else if (strcmp(command, "itinerary") == 0) {
            printf("Enter the destination: ");
            scanf("%s", destination);
            generateItinerary(destination);
        } else if (strcmp(command, "accommodations") == 0) {
            printf("Enter the destination: ");
            scanf("%s", destination);
            suggestAccommodations(destination);
        } else if (strcmp(command, "exit") == 0) {
            printf("Thank you for using the travel chatbot. Safe travels!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
