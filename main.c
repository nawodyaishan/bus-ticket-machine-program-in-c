#include<stdio.h>
#include<stdlib.h>

int main(void) {
    //Loop the entire code one time to get back to the main menu
    while (1) {

        //Variables
        int userSelection;
        int initialFare = 7;
        int farePerKM = 2;
        int customerCount = 1;
        int totalPassengers = 0;
        int totalIncome = 0;
        int distanceArray[] = {0, 2, 5, 9, 15};
        int startStation = 0;
        int endStation = 0;
        int passengerCount = 0;
        int distance = 0;
        int farePer = 0;
        int totalFare = 0;
        char nextCustomer = ' ';
        char subMenu = ' ';

        //Main Interface
        printf("    .______________________________________________________________.\n");
        printf("    |      	             --Ticketing Machine--                                    	 |\n");

        printf("    |_____________________________________________________________|\n\n");
        printf("\n");
        printf("\n	1.Print the ticket");
        printf("\n	2.View the distance table and Fares");
        printf("\n	0.Exit");
        printf("\n\n	Enter Your Choice: ");
        scanf("%d", &userSelection);
        //Selection-Print the Ticket
        if (userSelection == 1) {
            //Execute a loop until user decide to exit
            while (nextCustomer != 'E') {

                //User inputs
                printf("\n\n   	-- Ticket Number - %d --", customerCount);
                printf("\n\n 	Enter the Starting Station : ");
                scanf("%d", &startStation);

                printf(" 	Enter the Destination : ");
                scanf("%d", &endStation);

                printf(" 	Number of Passengers : ");
                scanf("%d", &passengerCount);
                //Calculations
                distance = (distanceArray[endStation - 1] - distanceArray[startStation - 1]);

                //To get rid of minus distnces
                if (distance < 0) {
                    distance = -1 * (distanceArray[endStation - 1] - distanceArray[startStation - 1]);
                }
                farePer = (initialFare + ((distance - 1) * farePerKM));
                totalFare = (farePer * passengerCount);

                //Displaying the ticket
                printf("\n\n---------Customer ID. %d-------------------\n", customerCount);
                printf("\n         	Starting Station 	: %d\n", startStation);
                printf("  Destination Station  : %d\n", endStation);
                printf("  Distance Travelling  : %dkm\n", distance);
                printf("  Number of Passengers : %d\n", passengerCount);
                printf("  Fare per a person	: Rs.%d.00\n", farePer);
                printf("  Total Fare           : Rs.%d.00\n", totalFare);
                printf("------------------------------------\n\n");
                //More options
                printf("   Enter'N' for next customer. \n   Enter 'E' to Print Report and Go to Main Menu.");
                printf("\n\n   Please enter your choice: ");
                scanf(" %c", &nextCustomer);

                totalIncome += totalFare;
                totalPassengers += passengerCount;

                customerCount++;

            }

            //Displaying the report
            printf("\n\n-----------------REPORT-------------------\n");
            printf("  Total Number of Customers  : %d\n", customerCount - 1);
            printf("  Total Passengers travelled : %d\n", totalPassengers);
            printf("  Total Income           	: Rs.%d.00\n", totalIncome);

            printf("------------------------------------------------\n\n");
        }

        //Selection-Preview of the distance table and Fares
        if (userSelection == 2) {
            printf("\n-----------Distance Table---------------------\n");
            printf("    	1 ---> 2  2km\n");
            printf("    	1 ---> 3  5km\n");
            printf("    	1 ---> 4  9km\n");
            printf("    	1 ---> 5  15km\n");
            printf("----------------------------------------------\n");
            printf("	* Fare per 1st km : Rs.%d.00\n    * Fare per each other km : Rs.%d.00\n", initialFare,
                   farePerKM);
            printf("----------------------------------------------\n\n");
            while (subMenu != 'B') {

                printf("\n\n	Enter 'B' to Go back : ");
                scanf(" %c", &subMenu);
            }
            printf("\n\n                    	Main Menu \n\n\n");

        }
        //Selection-Exit from the programme
        if (userSelection == 0) {
            printf("\n	Press any key to Exit\n");
            exit(0);
        }
    }
    return 0;
}

