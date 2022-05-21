/* Compile Instructions:
    gcc -std=c99 -o loan loanCalculator.c -lm

   Run:
    ./loan
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>   	// so we can use pow, need to use -lm when compiling
#include <locale.h> 	// so we can format the costs as $xxx,xxx.xx

int main()
{
    bool estimate_another_loan = 1;

    // As long as the user wants to continue esitmating loans, we continue this loop
    while(estimate_another_loan == 1)
    {
        printf("\nPlease enter the information as it is shown to you.\n");

        printf("\nHow much is the loan? ");
        double loanAmount;
        scanf("%lf", &loanAmount);

        printf("\nWhat is the yearly interest rate for the loan? ");
        double interestRate_Year;
        scanf("%lf", &interestRate_Year);

        // We need to change this interest rate to an accurate percentage
        double interestRate = ((interestRate_Year)/12) * 0.01;

        printf("\nHow many years do you have to pay off the loan? ");
        double paymentYears;
        scanf("%lf", &paymentYears);

        // We need to make a value for the payment period
        double paymentPeriods = paymentYears * 12; // They pay the loan every month

        //----------------------------------------------------------------------------------
        // Loan type used: Amortization
        // Link to Amortization loan interest calculation: https://www.vertex42.com/ExcelArticles/amortization-calculation.html
        //
        // For this type of loan calculation, we need to add a way to raise something
        // to a power for the MonthlyPayment equation. I did it this way so that monthlyPayment would look more clean.
        // temp takes ( 1 + InterestRate) and raises it to the power of PaymentPeriods.
        double temp = pow((1 + interestRate), paymentPeriods);
        double monthlyPayment = loanAmount * ((interestRate * temp) / (temp - 1));

        double finalCost = monthlyPayment * paymentPeriods;

        // Using setlocale with a ' in our print statements (%'d, for example), allows for a simple
        // conversion to the format of $xxx,xxx.xx
        setlocale(LC_NUMERIC, "");

        printf("\nThe total cost of this loan is $%'2.2f!\n", finalCost);

        double difference = finalCost - loanAmount;

        printf("\nThe difference between the inital loan amount to the final cost is $%'2.2f!", difference);
    
        printf("\n\n  Do you wish to estimate the cost of another loan? 1 for yes, 0 for no: ");
        int decider;
        scanf("%d", &decider);
        if(decider == 0 || decider == 1)
        {
            estimate_another_loan = decider;
        }
        else
        {
            printf("\nError: Wrong value entered (enter a value of 0 or 1). The program will now end.\n");
            estimate_another_loan = 0;
        }
    }
    
    return 0;
}
