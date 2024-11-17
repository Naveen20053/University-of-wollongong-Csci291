#include <stdio.h>
#include <string.h>

#define NUM_TEAMS 5
#define SQUAD_SIZE 11

typedef struct {
    int day;
    int month;
    int year;
} date_t;

typedef struct {
    char name[26];
    int kitNumber;
    char country[26];
    date_t dob;
    char position[20];
} player_t;

typedef struct {
    char teamName[21];
    player_t players[SQUAD_SIZE];
    int activeSize;
} team_t;

team_t teams[NUM_TEAMS];
int teamCount = 0;

void display_menu() {
    printf("\n--- League Team Application ---\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Search and Update Player\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void enroll_club() {
    if (teamCount >= NUM_TEAMS) {
        printf("Maximum number of teams enrolled.\n");
        return;
    }

    printf("Enter the name of the new club: ");
    scanf(" %[^\n]", teams[teamCount].teamName);
    teams[teamCount].activeSize = 0;
    teamCount++;
    printf("Club enrolled successfully.\n");
}

void add_player() {
    if (teamCount == 0) {
        printf("No clubs enrolled yet.\n");
        return;
    }

    printf("Select a club to add a player:\n");
    for (int i = 0; i < teamCount; i++) {
        printf("%d. %s\n", i + 1, teams[i].teamName);
    }

    int clubIndex;
    printf("Enter club number: ");
    scanf("%d", &clubIndex);

    if (clubIndex < 1 || clubIndex > teamCount) {
        printf("Invalid club number.\n");
        return;
    }

    clubIndex--;

    if (teams[clubIndex].activeSize >= SQUAD_SIZE) {
        printf("Team is full.\n");
        return;
    }

    player_t newPlayer;
    printf("Enter player's name: ");
    scanf(" %[^\n]", newPlayer.name);
    printf("Enter player's kit number (1-99): ");
    scanf("%d", &newPlayer.kitNumber);
    printf("Enter player's Country: ");
    scanf(" %[^\n]", newPlayer.country);
    printf("Enter player's date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &newPlayer.dob.day, &newPlayer.dob.month, &newPlayer.dob.year);
    printf("Enter player's position: ");
    scanf(" %[^\n]", newPlayer.position);

    for (int i = 0; i < teams[clubIndex].activeSize; i++) {
        if (strcmp(teams[clubIndex].players[i].name, newPlayer.name) == 0 || 
            teams[clubIndex].players[i].kitNumber == newPlayer.kitNumber) {
            printf("Duplicate player name or kit number found.\n");
            return;
        }
    }

    teams[clubIndex].players[teams[clubIndex].activeSize] = newPlayer;
    teams[clubIndex].activeSize++;
    printf("Player added successfully.\n");
}

void  {
    if (teamCount == 0) {
        printf("No clubs enrolled yet.\n");
        return;
    }

    char searchName[26];
    int searchKit;
    int found = 0;

    printf("Enter player's name (or type '-' to search by kit number): ");
    scanf(" %[^\n]", searchName);

    if (strcmp(searchName, "-") == 0) {
        printf("Enter kit number to search: ");
        scanf("%d", &searchKit);
    }

    for (int i = 0; i < teamCount; i++) {
        for (int j = 0; j < teams[i].activeSize; j++) {
            if ((strcmp(searchName, "-") == 0 && teams[i].players[j].kitNumber == searchKit) ||
                strcasecmp(teams[i].players[j].name, searchName) == 0) {
                found = 1;
                printf("\nPlayer found in team %s:\n", teams[i].teamName);
                printf("Name: %s\n", teams[i].players[j].name);
                printf("Kit Number: %d\n", teams[i].players[j].kitNumber);
                printf("Country: %s\n", teams[i].players[j].country);
                printf("Date of Birth: %02d/%02d/%04d\n", teams[i].players[j].dob.day,
                       teams[i].players[j].dob.month, teams[i].players[j].dob.year);
                printf("Position: %s\n", teams[i].players[j].position);

                printf("Do you want to update this player's position? (y/n): ");
                char updateChoice;
                scanf(" %c", &updateChoice);
                if (updateChoice == 'y' || updateChoice == 'Y') {
                    printf("Enter new position: ");
                    scanf(" %[^\n]", teams[i].players[j].position);
                    printf("Player position updated successfully.\n");
                }
                return;
            }
        }
    }

    if (!found) {
        printf("Player not found.\n");
    }
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enroll_club();
                break;
            case 2:
                add_player();
                break;
            case 3:
                search_update();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
