#include <stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_COFFEE_TYPES 3

const char *coffeeTypes[MAX_COFFEE_TYPES] = {"Espresso", "Cappuccino", "Mocha"};
const int coffeeIngredients[MAX_COFFEE_TYPES][4] = {{8, 30, 0, 0}, {8, 30, 70, 0}, {8, 39, 160, 30}};
double coffeePrices[MAX_COFFEE_TYPES] = {3.5, 4.5, 5.5};

const int minCoffeeBeans = 10;
const int minWater = 50;
const int minMilk = 50;
const int minChocolateSyrup = 10;

int coffeeBeans = 250;
int water = 250;
int milk = 250;
int chocolateSyrup = 100;

double totalSalesAmount = 0;

const char *adminPass = "admin@123";

void orderCoffee() {
    while (1) {

        printf("Available Coffee Types:\n");
        for (int i = 0; i < MAX_COFFEE_TYPES; i++) {
            if (coffeeBeans >= coffeeIngredients[i][0] &&
                water >= coffeeIngredients[i][1] &&
                milk >= coffeeIngredients[i][2] &&
                chocolateSyrup >= coffeeIngredients[i][3]) {
                printf("%d. %s - AED %.2f\n", i + 1, coffeeTypes[i], coffeePrices[i]);
            } else {
                printf("%d. %s - Unavailable due to temporarily insufficient ingredients\n", i + 1, coffeeTypes[i]);
            }
        }

        int canServeCoffee = 0;
        for (int i = 0; i < MAX_COFFEE_TYPES; i++) {
            if (coffeeBeans >= coffeeIngredients[i][0] &&
                water >= coffeeIngredients[i][1] &&
                milk >= coffeeIngredients[i][2] &&
                chocolateSyrup >= coffeeIngredients[i][3]) {
                canServeCoffee = 1;
                break;
            }
        }
        if (!canServeCoffee) {
            printf("No coffee can be served. Exiting...\n");
            return;
        }

        int choice;
        do {
            printf("Enter your selection (1-%d or 0 to exit): ", MAX_COFFEE_TYPES);
            scanf("%d", &choice);
        } while (choice < 0 || choice > MAX_COFFEE_TYPES);

        if (choice == 0) {
            return;
        }

        if (coffeeBeans >= coffeeIngredients[choice - 1][0] &&
            water >= coffeeIngredients[choice - 1][1] &&
            milk >= coffeeIngredients[choice - 1][2] &&
            chocolateSyrup >= coffeeIngredients[choice - 1][3]) {

            char confirm;
            do {
                printf("You selected %s. Confirm? (y/n): ", coffeeTypes[choice - 1]);
                scanf(" %c", &confirm);
            } while (confirm != 'y' && confirm != 'n');

            if (confirm == 'y') {

                double totalAmount = coffeePrices[choice - 1];
                double paidAmount = 0;

                while (paidAmount < totalAmount) {
                    printf("Insert a coin (1 or 0.5 AED): ");
                    double coinValue;
                    scanf("%lf", &coinValue);

                    if (!isdigit(coinValue) && coinValue != 1 && coinValue != 0.5) {
                        printf("Invalid coin. Please insert a valid coin.\n");
                    } else {
                        paidAmount += coinValue;
                    }
                }

                coffeeBeans -= coffeeIngredients[choice - 1][0];
                water -= coffeeIngredients[choice - 1][1];
                milk -= coffeeIngredients[choice - 1][2];
                chocolateSyrup -= coffeeIngredients[choice - 1][3];
                totalSalesAmount += totalAmount;

                printf("You have bought a %s.\n", coffeeTypes[choice - 1]);
                printf("Price: AED %.2f\n", coffeePrices[choice - 1]);
                printf("Paid: AED %.2f\n", paidAmount);
                printf("Change: AED %.2f\n", paidAmount - coffeePrices[choice - 1]);
            }
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }
}

void adminMode() {
    char adminPassword[20];

    printf("Enter admin password: ");
    scanf("%s", adminPassword);

    if (strcmp(adminPassword, adminPass) == 0) {

        printf("Welcome to admin mode!\n");

        int adminChoice;
        do {

            if (coffeeBeans <= minCoffeeBeans) {
                printf("Warning: Low coffee beans remaining. Please refill soon.\n");
            }
            if (water <= minWater) {
                printf("Warning: Low water remaining. Please refill soon.\n");
            }
            if (milk <= minMilk) {
                printf("Warning: Low milk remaining. Please refill soon.\n");
            }
            if (chocolateSyrup <= minChocolateSyrup) {
                printf("Warning: Low chocolate syrup remaining. Please refill soon.\n");
            }

            printf("\n--- Admin Menu ---\n");
            printf("1. Refill coffee beans\n");
            printf("2. Refill water\n");
            printf("3. Refill milk\n");
            printf("4. Refill chocolate syrup\n");
            printf("5. View total sales\n");
            printf("6. Change coffee prices\n");
            printf("7. Logout\n");
            printf("Enter your selection: ");
            scanf("%d", &adminChoice);

            switch (adminChoice) {
                case 1:

                    printf("Enter refill amount for coffee beans: ");
                    int refillAmount;
                    scanf("%d", &refillAmount);
                    coffeeBeans += refillAmount;
                    printf("Coffee beans refilled successfully. Current amount: %d grams\n", coffeeBeans);
                    break;

                case 2:

                    printf("Enter refill amount for water: ");
                    scanf("%d", &refillAmount);
                    water += refillAmount;
                    printf("Water refilled successfully. Current amount: %d ml\n", water);
                    break;

                case 3:

                    printf("Enter refill amount for milk: ");
                    scanf("%d", &refillAmount);
                    milk += refillAmount;
                    printf("Milk refilled successfully. Current amount: %d ml\n", milk);
                    break;

                case 4:

                    printf("Enter refill amount for chocolate syrup: ");
                    scanf("%d", &refillAmount);
                    chocolateSyrup += refillAmount;
                    printf("Chocolate syrup refilled successfully. Current amount: %d ml\n", chocolateSyrup);
                    break;

                case 5:

                    printf("Total sales amount: AED %.2f\n", totalSalesAmount);
                    break;

                case 6:

                    printf("Current coffee prices:\n");
                    for (int i = 0; i < MAX_COFFEE_TYPES; i++) {
                        printf("%d. %s - AED %.2f\n", i + 1, coffeeTypes[i], coffeePrices[i]);
                    }

                    int coffeeChoice;
                    printf("Select the coffee type to change price (1-%d): ", MAX_COFFEE_TYPES);
                    scanf("%d", &coffeeChoice);

                    if (coffeeChoice > 0 && coffeeChoice <= MAX_COFFEE_TYPES) {
                        printf("Enter new price for %s: AED ", coffeeTypes[coffeeChoice - 1]);
                        double newPrice;
                        scanf("%lf", &newPrice);
                        coffeePrices[coffeeChoice - 1] = newPrice;
                        printf("Price updated successfully for %s. New price: AED %.2f\n", coffeeTypes[coffeeChoice - 1], newPrice);
                    } else {
                        printf("Invalid coffee selection.\n");
                    }
                    break;

                case 7:

                    printf("Logging out of admin mode...\n");
                    break;

                default:
                    printf("Invalid selection. Please try again.\n");
                    break;
            }
        } while (adminChoice != 7); 
    } else {
        printf("Incorrect password. Access denied.\n");
        return;
    }
}

int main() {
    int option;

    do {
        printf("        SELECT AN OPTION        \n");
        printf("1. Order a coffee type \n");
        printf("2. Admin mode for the coffee maker option \n");
        printf("3. End the application \n");
        printf("Enter the option you want to select \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                orderCoffee();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting App...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}
