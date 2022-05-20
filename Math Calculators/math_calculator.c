/*
    This is a basic calculator that I decided to make because I was bored.
    
    This program was made by Robert Carr. This is a basic calculator that I decided to make because I was bored.

    Program instructions/info:
	    Compiled with GCC on Oracle VM Virtual Box (Linux Ubuntu (64-bit))
	        
	        How to compile in terminal:
		        gcc -std=c99 -o math math_calculator.c
		    
		    How to run in the terminal:
		        ./math
*/
#include <stdio.h>
#include <math.h> // for sqrt()
#include <locale.h> // allows for xxx,xxx,xxx... to be used in our prints of big numbers

void quadratic_equation_solver();
void pythagorean_theorem_equation_solver();
void factorial_solver();

int main()
{
    int solve_another_equation = 1;
    
    // While the user wants to continue solving equations, continue this loop
    while(solve_another_equation == 1)
    {
        printf("\nPlease select the following options for an equation solver:");

	printf("\n\n\t1: ax^2 + bx + c = 0"); // quadratic equation
        printf("\n\n\t2: a^2 + b^2 = c^2"); // pythagorean theorem
        printf("\n\n\t3: n!"); // factorial
    
        printf("\n\nPlease enter the number for the equation you want to solve: ");
        int selection;
        scanf("%d", &selection);
    
        if(selection == 1)
        {
            quadratic_equation_solver();
        }
        else if(selection == 2)
        {
            pythagorean_theorem_equation_solver();
        }
        else if(selection == 3)
        {
            factorial_solver();
        }
        else
        {
            printf("Please enter a valid number for an equation to solve.");  
        }
        
        printf("\n\nWould you like to solve another equation?\n\t1 for Yes, 0 for No: ");
        scanf("%d", &solve_another_equation);
    }
    return 0;
}

void quadratic_equation_solver()
{
    int solve_another_quadratic = 1;

    // While the user wants to solve a quadratic equation (solve_another_quadratic == 1) we need to repeat this loop,
    // if at the end of the loop, the user is done solving quadratic equations (solve_another_quadratic == 0), we end the loop
    while(solve_another_quadratic == 1)
    {
        printf("\nPlease enter the values for this equation.");
    
        printf("\n\tValue for a: ");
        double a;
        scanf("%lf", &a);
    
        printf("\tValue for b: ");
        double b;
        scanf("%lf", &b);
    
        printf("\tValue for c: ");
        double c;
        scanf("%lf", &c);

        int y = 0;
    
	// To solve quadratics we need the discriminant, and values for a, b, and c
	// Look here for an explanation on the process: https://www.mathsisfun.com/algebra/quadratic-equation.html
        double discriminant = (b * b) - (4 * a * c);
        double real_Number, imaginary_Number, first_Root, second_Root;

        //When discriminant > 0 there are two real roots.
        if(discriminant > 0)
        {
            first_Root = (-b + sqrt(discriminant)) / (2 * a);
            second_Root = (-b - sqrt(discriminant)) / (2 * a);
            printf("\nThe discriminant is greater than 0, so root 1 and root 2 only contain real numbers (real roots).\nTheir values are:");
            printf("\n\troot 1 = %.2lf\n\troot 2 = %.2lf\n", first_Root, second_Root);
        }
        //When discriminant = 0 there is one real root.
        else if(discriminant == 0)
        {
            first_Root = -b / (2 * a);
            printf("\nThe discriminant is equal to 0, so root 1 and root 2 are equal and only contain real numbers (real roots).\nTheir values are:");
            printf("\n\troot 1 = %.2lf\n\troot 2 = %.2lf", first_Root, first_Root);
        }
        //When discriminant < 0 there are two complex roots.
        else
        {
            real_Number = -b / (2 * a);
            imaginary_Number = sqrt(-discriminant) / (2 * a);
            printf("\nThe discriminant is less than 0, so root 1 and root 2 contain imaginary numbers (complex roots).\nTheir values are:");
            printf("\n\troot 1 = %.2lf + %.2lfi\n\troot 2 = %.2lf - %.2lfi", real_Number, imaginary_Number, real_Number, imaginary_Number);
        }
    
        printf("\n\nWould you like to solve another quadratic equation?\n\t1 for Yes, 0 for No: ");
        scanf("%d", &solve_another_quadratic);
    }
}

void pythagorean_theorem_equation_solver()
{
    int solve_another_pythagorean_theorem = 1;
    
    // While the user wants to solve a pythagorean theorem problem (solve_another_pythagorean_theorem == 1) we need to repeat this loop,
    // if at the end of the loop, the user is done solving pythagorean theorem problems (solve_another_pythagorean_theorem == 0), we end the loop
    while(solve_another_pythagorean_theorem == 1)
    {
        printf("\nWhat side of the triangle do you want to solve for?");
        printf("\n\tA\n\tB\n\tC");
    
        printf("\nEnter the side you wish to solve for: ");
        char triangle_Side;
        scanf(" %c", &triangle_Side); // The space before %c allows for this to work
    
        double A, B, C;
    
	if(triangle_Side == 'A')
        {
            printf("\tEnter the sides of the triangle as they are shown:");
            printf("\n\tB: ");
            scanf("%lf", &B);
        
            printf("\n\tC: ");
            scanf("%lf", &C);
        
	    // This is the equation used to solve for the length of A
	    // Look here for an explination: https://www.calculatorsoup.com/calculators/geometry-plane/pythagorean-theorem.php
            A = sqrt((C * C) - (B * B));
            
	    // TODO: Improve this if/else with A = ... in the last else
            if(C < 1 || B < 1)
            {
               printf("A cannot be solved because B and C have to be a positive value.\n");
            }
            else if(C < B)
            {
                printf("A cannot be solved because C has to be greater than B.\n");
            }
            else
            {
                printf("\nThe value for A is: %.2lf", A);
            }
        }
        else if(triangle_Side == 'B')
        {
            printf("\tEnter the sides of the triangle as they are shown:");
            printf("\n\tA: ");
            scanf("%lf", &A);
        
            printf("\n\tC: ");
            scanf("%lf", &C);
        
	    // This is the equation used to solve for the length of B
	    // Look here for an explination: https://www.calculatorsoup.com/calculators/geometry-plane/pythagorean-theorem.php
            B = sqrt((C * C) - (A * A));
            
	    // TODO: Improve this if/else with A = ... in the last else
            if(C < 1 || A < 1)
            {
               printf("B cannot be solved because A and C have to be a positive value.\n");
            }
            else if(C < B)
            {
                printf("B cannot be solved because C must be bigger than the value of A.\n");
            }
            else
            {
                printf("\nThe value for A is: %.2lf", B);
            }
        }
        else if(triangle_Side == 'C')
        {
            printf("\tEnter the sides of the triangle as they are shown:");
            printf("\n\tA: ");
            scanf("%lf", &A);
        
            printf("\n\tB: ");
            scanf("%lf", &B);

	    // This is the equation used to solve for the length of C
	    // Look here for an explination: https://www.calculatorsoup.com/calculators/geometry-plane/pythagorean-theorem.php
            C = (A * A) + (B * B);
            
	    // TODO: Move this as a check before C is calculated, don't do the calculation if it is not legal
            if(A < 1 || B < 1)
            {
                printf("C cannot be solved because A and B need to be positive vales.\n");
            }
            printf("\nThe value for C, the hypotenuse is: %.2lf", C);
        }
        else
        {
            printf("This was not a valid choice.\n");   
        }
        
        printf("\n\nDo you want to solve another pythagorean theorem?\n\t1 for Yes, 0 for No:");
        scanf("%d", &solve_another_pythagorean_theorem);
    }
}

void factorial_solver()
{
    int solve_another_factorial = 1;
    
    while(solve_another_factorial == 1)
    {
        printf("\nI want to know the factorial for: ");
        int factorial;
        scanf("%d", &factorial);
        
        unsigned long long factorial_answer = 1; // Factorials can get huge
        for(int i = 1; i <= factorial; i++)
        {
            factorial_answer *= i;
        }
        
        if(factorial < 0)
        {
            printf("\nThe factorial must be a positive integer.");
        }
        else if(factorial >= 21)
        {
            printf("\nOh no! The answer to the factorial is larger than 18,446,744,073,709,551,615!\n");
            printf("\tThis means it is too big to store in the unsigned long long data type!\n");
        }
        else
        {
            setlocale(LC_ALL,""); // formating could cause issues, allows us to format output with ,'s' (xxx,xxx,xxx,...)
            printf("\n\tThe answer to %d! is : %'llu", factorial, factorial_answer);
        }
        
        printf("\nDo you want to solve another factorial?\n\t1 for Yes, 0 for No: ");
        scanf("%d", &solve_another_factorial);
    }
}
