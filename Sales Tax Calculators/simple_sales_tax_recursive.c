/*
    Program instructions/info:
	    Compiled with GCC on Oracle VM Virtual Box (Linux Ubuntu (64-bit))
	        
	        How to compile in terminal:
		        gcc -std=c99 -o salestax simple_sales_tax_recursive.c
		    
		    How to run in the terminal:
		        ./salestax
*/
#include <stdio.h>

double finalTotal(double itemValue, int anotherItem);

int main()
{
    // We make a double value to store the price a user enters ($xx.xx),
    // so we can then determine the cost after Texas sales tax
    double itemValue;
    int anotherItem = 0;
    
    printf("Hello. This is a total cost calculator for when you are buying items!\n\tPlease enter the price of your item: ");
    scanf("%lf", &itemValue);
    
    // Now we do the math for generating the total cost of the item
    itemValue = itemValue + (itemValue * 0.0825);
    
    printf("\nThe total of your item(s) after a %%0.0825 sales tax is $%2.2f!\n", finalTotal(itemValue, anotherItem));
    
    return 0;
}

double finalTotal(double itemValue, int anotherItem)
{
    double newItem;
    double newTotal;
    
    printf("Would you like to add another item? 1 for yes, 0 for no: ");
    scanf("%d", &anotherItem);
    
    // If a user decides to add an item we need to recurvisly add the previous total to the new price until the
    // user decides they no longer want to add more prices
    if(anotherItem == 1)
    {
        printf("\tPlease enter the price of your next item: ");
        scanf("%lf", &newItem);
        newItem = newItem + (newItem * 0.0825);
        newTotal = newItem + itemValue;
        itemValue = finalTotal(newTotal, anotherItem); // recursive call to calculate the total for every new item added
    }
    else
    {
        return itemValue;
    }
}
