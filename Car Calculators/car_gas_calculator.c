/*
    This program was made by Robert Carr. Although simple and basic, it simplifies something that I always wonder when
	    wanting to know how much money in gas has been spent on a certain car. This program was made just for fun and it's
	    accuracy depends on the accuracy of the information entered. The reason I made it was because while I was riding home
	    from Big Bend National Park with a friend, I wondered how much money has been put into my friends truck on gas. This
	    is what I came up with.

    Program instructions/info:
	    Compiled with GCC on Oracle VM Virtual Box (Linux Ubuntu (64-bit))
	        
	        How to compile in terminal:
		        gcc -std=c99 -o car_gas_calculator car_gas_calculator.c
		    
		    How to run in the terminal:
		        ./car_gas_calculator
*/
#include <stdio.h>

int main()
{
    /*
    To calculate the total amount of money in gas has been spent on a certain car, we have a few variables. We have to know the amount of gallons the tank can hold.
        We can name this variable gallonsInTank. Another variable we need to use is the average miles per gallon, we can name this variable milesPerGallon. Finally,
        we need to know the average price of gas, we can call this variable averageGasPrice.
        
        From the above varibles we can generate two more varibles, totalMilesPerTank and totalGallonsUsed. With all of this information we can estimate the amount
        of money in gas has been spent on a certain car.
    */
    
    printf("Hello. This is a total cost calculator for how much money has gone into your gas tank!\nPlease enter the following information.");
    printf("\n\n\tGallons your car tank holds: ");
    double gallonsInTank;
    scanf("%lf", &gallonsInTank);
    
    printf("\tMiles per gallon for your vehicle: ");
    int milesPerGallon;
    scanf("%d", &milesPerGallon);
    
    printf("\tMiles driven: ");
    int milesDriven;
    scanf("%d", &milesDriven);
    
    printf("\tAverage gas price per gallon: ");
    double averageGasPrice;
    scanf("%lf", &averageGasPrice);
    
    // Now we do the math for generating the total cost of the gas
    double totalMilesPerTank = gallonsInTank * milesPerGallon;
    double totalGallonsUsed = milesDriven / totalMilesPerTank; // We need to convert total miles driven to total gallons used
    
    double totalCost = totalGallonsUsed * averageGasPrice;
    
    printf("\nWith the information you have entered for this calculator, you have put $%2.2f into your car in gas alone!\n", totalCost);
    
    return 0;
}
