//including libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//setting variables
const char *coffeeType1 = "Espresso";
const char *coffeeType2 = "Cappuccino";
const char *coffeeType3 = "Mocha";

int coffeeBeansEspresso = 8, waterEspresso = 30, milkEspresso = 0, chocolateSyrupEspresso = 0;
int coffeeBeansCappuccino = 8, waterCappuccino = 30, milkCappuccino = 70, chocolateSyrupCappuccino = 0;
int coffeeBeansMocha = 8, waterMocha = 39, milkMocha = 160, chocolateSyrupMocha = 30;

float priceEspresso = 3.5;
float priceCappuccino = 4.5;
float priceMocha = 5.5;

int minCoffeeBeans = 10;
int minWater = 50;
int minMilk = 50;
int minChocolateSyrup = 10;

int coffeeBeans = 250;
int water = 250;
int milk = 250;
int chocolateSyrup = 100;

float totalSalesAmount = 0;

char *adminPass = "admin@123";
//creating a user defined function for ordering a coffee
void orderCoffee() {
    while (1) {

        printf("Available Coffee Types:\n");

        if (coffeeBeans >= coffeeBeansEspresso && water >= waterEspresso) {
            printf("1. %s - AED %.2f\n", coffeeType1, priceEspresso);
        } else {
            printf("1. %s - Unavailable due to temporarily insufficient ingredients\n", coffeeType1);
        }

        if (coffeeBeans >= coffeeBeansCappuccino && water >= waterCappuccino && milk >= milkCappuccino) {
            printf("2. %s - AED %.2f\n", coffeeType2, priceCappuccino);
        } else {
            printf("2. %s - Unavailable due to temporarily insufficient ingredients\n", coffeeType2);
        }

        if (coffeeBeans >= coffeeBeansMocha && water >= waterMocha && milk >= milkMocha && chocolateSyrup >= chocolateSyrupMocha) {
            printf("3. %s - AED %.2f\n", coffeeType3, priceMocha);
        } else {
            printf("3. %s - Unavailable due to temporarily insufficient ingredients\n", coffeeType3);
        }

        if (!(coffeeBeans >= coffeeBeansEspresso && water >= waterEspresso) &&
            !(coffeeBeans >= coffeeBeansCappuccino && water >= waterCappuccino && milk >= milkCappuccino) &&
            !(coffeeBeans >= coffeeBeansMocha && water >= waterMocha && milk >= milkMocha && chocolateSyrup >= chocolateSyrupMocha)) {
            printf("No coffee can be served. Exiting...\n");
            return;
        }

        int choice;
        do {
            printf("Enter your selection (1-3 or 0 to exit): ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 3);

        if (choice == 0) {
            return;
        }

        if (choice == 1 && coffeeBeans >= coffeeBeansEspresso && water >= waterEspresso) {
            double totalAmount = priceEspresso;
            char confirm;
            do {
                printf("You selected %s. Confirm? (y/n): ", coffeeType1);
                scanf(" %c", &confirm);
            } while (confirm != 'y' && confirm != 'n');

            if (confirm == 'y') {
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

                coffeeBeans -= coffeeBeansEspresso;
                water -= waterEspresso;
                totalSalesAmount += totalAmount;
                printf("You have bought a %s.\n", coffeeType1);
                printf("Change: AED %.2f\n", paidAmount - totalAmount);
            }
        } else if (choice == 2 && coffeeBeans >= coffeeBeansCappuccino && water >= waterCappuccino && milk >= milkCappuccino) {
            double totalAmount = priceCappuccino;
            char confirm;
            do {
                printf("You selected %s. Confirm? (y/n): ", coffeeType2);
                scanf(" %c", &confirm);
            } while (confirm != 'y' && confirm != 'n');

            if (confirm == 'y') {
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

                coffeeBeans -= coffeeBeansCappuccino;
                water -= waterCappuccino;
                milk -= milkCappuccino;
                totalSalesAmount += totalAmount;
                printf("You have bought a %s.\n", coffeeType2);
                printf("Change: AED %.2f\n", paidAmount - totalAmount);
            }
        } else if (choice == 3 && coffeeBeans >= coffeeBeansMocha && water >= waterMocha && milk >= milkMocha && chocolateSyrup >= chocolateSyrupMocha) {
            double totalAmount = priceMocha;
            char confirm;
            do {
                printf("You selected %s. Confirm? (y/n): ", coffeeType3);
                scanf(" %c", &confirm);
            } while (confirm != 'y' && confirm != 'n');

            if (confirm == 'y') {
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

                coffeeBeans -= coffeeBeansMocha;
                water -= waterMocha;
                milk -= milkMocha;
                chocolateSyrup -= chocolateSyrupMocha;
                totalSalesAmount += totalAmount;
                printf("You have bought a %s.\n", coffeeType3);
                printf("Change: AED %.2f\n", paidAmount - totalAmount);
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
                    printf("1. %s - AED %.2f\n", coffeeType1, priceEspresso);
                    printf("2. %s - AED %.2f\n", coffeeType2, priceCappuccino);
                    printf("3. %s - AED %.2f\n", coffeeType3, priceMocha);

                    int coffeeChoice;
                    printf("Select the coffee type to change price (1-3): ");
                    scanf("%d", &coffeeChoice);

                    if (coffeeChoice == 1) {
                        printf("Enter new price for %s: AED ", coffeeType1);
                        double newPrice;
                        scanf("%lf", &newPrice);
                        priceEspresso = newPrice;
                        printf("Price updated successfully for %s. New price: AED %.2f\n", coffeeType1, newPrice);
                    } else if (coffeeChoice == 2) {
                        printf("Enter new price for %s: AED ", coffeeType2);
                        double newPrice;
                        scanf("%lf", &newPrice);
                        priceCappuccino = newPrice;
                        printf("Price updated successfully for %s. New price: AED %.2f\n", coffeeType2, newPrice);
                    } else if (coffeeChoice == 3) {
                        printf("Enter new price for %s: AED ", coffeeType3);
                        double newPrice;
                        scanf("%lf", &newPrice);
                        priceMocha = newPrice;
                        printf("Price updated successfully for %s. New price: AED %.2f\n", coffeeType3, newPrice);
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
