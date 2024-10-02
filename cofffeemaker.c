#include <stdio.h>
/*Coffee Bean Grams*/
#define Esp_gram 8
#define Capp_gram 8
#define Moch_gram 8
/*Water (millimeters)*/
#define Esp_water 30
#define Capp_water 30
#define Moch_water 39
/*Milk (millimeters)*/
#define Esp_milk 0
#define Capp_milk 70
#define Moch_milk 160
/*Choco Syrup*/
#define Esp_choco 0
#define Capp_choco 0
#define Moch_choco 30
/*Price*/
#define Esp_price 3.5
#define Capp_price 4.5
#define Moch_price 5.5
/*Admin password*/
#define admin_pass "passwordforadmin@123"

/*total sales amount*/
#define total_amount 0
/*threshhold*/
#define choco_lowthresh 30
#define milk_lowthresh 160
#define Beans_lowthresh 8
void main()
int set ;
set = 0;

{   while (set){
        int option;
        printf("        SELECT A OPTION        \n");
        printf("1. Order a coffee type \n");
        printf("2. Admin mode for the coffee maker option \n");
        printf("3. End the application \n");
        printf("Enter the option you want to select \n");
        scanf( "%d", &option );
        switch (option){
            case 1:
                printf("1. Order a coffee type");
                break;
            case 2:
                printf("2. Admin mode for the coffee maker option");
                break;
            case 3:
                printf("3. End the application");
                set == 1;
                break;
        }
        printf("Enter the option you want to select: ");
        scanf( "%d", &option );
}
}
